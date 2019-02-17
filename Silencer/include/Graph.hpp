#pragma once

#include <iostream>
#include <memory>
#include <vector>
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
		void report();
		
	private:
		vector<shared_ptr<Node<DType>>> forward_pipeline;
		vector<shared_ptr<Node<DType>>> backward_pipeline;
		void ForwardBroadScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out);
		void ForwardDeepScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out);
		void BackwardBroadScan(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out);
		void BackwardDeepScan(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out);
	};


}
