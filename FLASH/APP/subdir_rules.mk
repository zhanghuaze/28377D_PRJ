################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/%.obj: ../APP/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/ti/c2000/C2000Ware_26_01_00_00/driverlib/f2837xd/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_26_01_00_00/driverlib/f2837xd/driverlib" --include_path="C:/Users/62519/workspace_ccstheia/28377d_driverlib_PRJ_LED/BSP" --include_path="C:/Users/62519/workspace_ccstheia/28377d_driverlib_PRJ_LED/APP" --include_path="C:/Users/62519/workspace_ccstheia/28377d_driverlib_PRJ_LED/device" --include_path="C:/Users/62519/workspace_ccstheia/28377d_driverlib_PRJ_LED" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=_FLASH --define=CPU1 --define=__TMS320C28XX__ --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="APP/$(basename $(<F)).d_raw" --obj_directory="APP" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


