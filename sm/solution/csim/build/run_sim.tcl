# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
# Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
# ==============================================================
set ::env(PATH) "$::env(PATH);C:/Xilinx/Vitis_HLS/2021.2/win64/tools/fpo_v7_0"
set ::env(PATH) "$::env(PATH);C:/Xilinx/Vitis_HLS/2021.2/win64/tools/fft_v9_1"
set ::env(PATH) "$::env(PATH);C:/Xilinx/Vitis_HLS/2021.2/win64/tools/fir_v7_0"
set ::env(PATH) "$::env(PATH);C:/Xilinx/Vitis_HLS/2021.2/win64/tools/dds_v6_0"
set ::env(PATH) "$::env(PATH);C:/Xilinx/Vitis_HLS/2021.2/win64/csim"

# Define source files
set CSIM_SRC_FILES "../../updated_4.c ../../no_os_spi.c ../../ad9516.c ../../xil_cache.c"

# Define include paths
set CSIM_INCLUDE_PATHS "-I../../ -I../../../../ -IC:/Xilinx/Vitis_HLS/2021.2/include"

# Compilation and linking flags
set CSIM_CFLAGS "-std=c99"
set CSIM_LDFLAGS ""

# Run compilation
foreach src_file $CSIM_SRC_FILES {
    puts "   Compiling(apcc) $src_file in debug mode"
    exec apcc.exe $CSIM_CFLAGS $CSIM_INCLUDE_PATHS -c $src_file -o obj/[file tail $src_file].o
}

# Link the executable
puts "   Generating csim.exe"
exec g++.exe obj/*.o -o csim.exe $CSIM_LDFLAGS

# Run the simulation
if {![file exists csim.exe]} {
    puts "@E C-simulation is not set up properly. Please re-run csim."
    return -code error
}

set ret [catch {eval exec ./csim.exe | tee temp0.log >&@ stdout} err]
set logfile "temp0.log"

if {$ret || $err != ""} {
    if { [lindex $::errorCode 0] eq "CHILDSTATUS"} {
        set status [lindex $::errorCode 2]
        if {$status != ""} {
            puts "@E Simulation failed: Function 'main' returns nonzero value '$status'."
            set ::AESL_CSIM::gnonzeroRetErr 1
            return -code error
        } else {
            puts "@E Simulation failed."
            return -code error
        }
    } else {
        if { [regexp {segmentation violation} $err] } {
            puts "@E Simulation failed: SIGSEGV."
        } else {
            puts "@E Simulation failed."
        }
        return -code error
    }
}

if {[file exists $logfile]} {
    set cmdret [catch {eval exec "grep \"Error:\" $logfile"} err]
    if {$cmdret == 0} {
        puts "@E Simulation failed."
        return -code error
    }
}
