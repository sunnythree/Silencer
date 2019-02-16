#include <iostream>
#include <memory>
#include "Common.hpp"
#include "Graph.hpp"

namespace Silencer {

	template<typename DType>
	Graph<DType>::Graph()
	{
	}

	template<typename DType>
	Graph<DType>::~Graph()
	{
	}

	template<typename DType>
	void Graph<DType>::BroadScan(shared_ptr<Node<DType>> in)
	{
		return;
	}

	template<typename DType>
	void Graph<DType>::DeepScan(shared_ptr<Node<DType>> in)
	{
		
	}

	template<typename DType>
	void Graph<DType>::build(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out)
	{
		
	}

	TEMPLATE_CLASS_INITIALIZE(Graph);
	

}