#pragma once
#include<iostream>
#include<memory>
#include"Edge.hpp"
namespace Silencer {
	template<typename DType>
	class Node:std::enable_shared_from_this<DType>
	{
	public:
		Node();
		~Node();

	private:

	};

}