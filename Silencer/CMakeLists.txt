# CMakeList.txt: Silencer 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 头文件查找目录
include_directories("include")

# 包含子项目。
add_subdirectory ("src")

# 将源代码添加到此项目的可执行文件。
add_executable (Silencer "Silencer.cpp" "Silencer.h")
target_link_libraries(Silencer Libsilencer)

# TODO: 如有需要，请添加测试并安装目标。
