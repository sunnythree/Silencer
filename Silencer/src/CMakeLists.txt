#build a variable to save the filename that need build 

# ��������Ŀ��
add_subdirectory ("layers")
add_subdirectory ("io")
set(	
	SRC_LIST_SILENCER
	Edge.cpp
	Node.cpp
	Graph.cpp
	Session.cpp
	Shape.cpp
	Tensor.cpp
	Log.cpp
	)
add_library  (Libsilencer ${SRC_LIST_SILENCER})