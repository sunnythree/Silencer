#pragma once

#include <iostream>
#include <memory>
#include "Edge.hpp"
#include "Node.hpp"

using std::shared_ptr;
using std::make_shared;

namespace Silencer {
	template<typename DType>
	class Graph
	{
	public:
		enum GRAPH_SCAN
		{
			DEEP,
			BROAD,
		};

		Graph();
		~Graph();
		void Build(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out, GRAPH_SCAN scan_mode);
		
	private:
		void BroadScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out);
		void DeepScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out);
	};


}
