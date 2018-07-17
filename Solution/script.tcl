############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project dev_fused
set_top dev_digits_classify
add_files dev_digits.cpp
add_files dev_digits.h
add_files operators.h
add_files weights_biases.h
add_files -tb dev_digits_test.cpp -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas"
open_solution "solution4"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./dev_fused/solution4/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
