############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project 07
set_top fir_filter_systolic
add_files ../ACA2021_Lab1_Team1/src/shift_class.h
add_files ../ACA2021_Lab1_Team1/src/pe_class.hpp
add_files ../ACA2021_Lab1_Team1/src/fir_filter.h
add_files ../ACA2021_Lab1_Team1/src/07_fir_filter_systolic.cpp
add_files -tb ../ACA2021_Lab1_Team1/src/07_fir_filter_systolic_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
source "./07/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
