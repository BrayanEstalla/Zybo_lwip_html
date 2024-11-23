# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\brayan\Desktop\smr-3891\labs_laptop\labLwip\design_1_wrapper\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\brayan\Desktop\smr-3891\labs_laptop\labLwip\design_1_wrapper\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {design_1_wrapper}\
-hw {C:\Users\brayan\Desktop\smr-3891\labs_laptop\labLwip\design_1_wrapper.xsa}\
-fsbl-target {psu_cortexa53_0} -out {C:/Users/brayan/Desktop/smr-3891/labs_laptop/labLwip}

platform write
domain create -name {freertos10_xilinx_ps7_cortexa9_0} -display-name {freertos10_xilinx_ps7_cortexa9_0} -os {freertos10_xilinx} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {freertos_lwip_echo_server}
platform generate -domains 
platform active {design_1_wrapper}
domain active {zynq_fsbl}
domain active {freertos10_xilinx_ps7_cortexa9_0}
platform generate -quick
