# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_examples_SRCS 变量
aux_source_directory(. DIR_examples_SRCS)

include_directories(../lib/Config)
include_directories(../lib/GUI)
include_directories(../lib/LCD)
include_directories(../lib/INA219)
include_directories(../lib/MP28167)
include_directories(../lib/PCF85063A)
include_directories(../lib/Power_Management_Lib)
# 生成链接库
add_library(examples ${DIR_examples_SRCS})
target_link_libraries(examples PUBLIC Config LCD GUI Fonts INA219 PCF85063A MP28167 Power_Management_Lib pico_multicore)