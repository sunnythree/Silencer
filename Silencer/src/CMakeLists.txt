#build a variable to save the filename that need build 
set(	
	SRC_LIST_MODULE1 
	Edge.cpp
	Node.cpp
	)
add_library  (Libsilencer ${SRC_LIST_MODULE1})