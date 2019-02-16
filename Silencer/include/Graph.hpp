#pragma once

#include <iostream>
#include <memory>
#include "Node.hpp"

using std::shared_ptr;
using std::make_shared;

namespace Silencer {
	template<typename DType>
	class Graph
	{
	public:
		Graph();
		~Graph();
		void build(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out);
	private:
		void BroadScan(shared_ptr<Node<DType>> in);
		void DeepScan(shared_ptr<Node<DType>> in);
	};


}
