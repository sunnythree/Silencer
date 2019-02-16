#build a variable to save the filename that need build 

# 包含子项目。
add_subdirectory ("layers")
add_subdirectory ("io")
set(	
	SRC_LIST_SILENCER
	Edge.cpp
	Node.cpp
	)
add_library  (Libsilencer ${SRC_LIST_SILENCER})