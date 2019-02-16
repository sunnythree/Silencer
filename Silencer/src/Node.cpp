#include "Node.hpp"
#include "Common.hpp"

namespace Silencer {

	template<typename DType>
	Node<DType>::Node()
	{
	}

	template<typename DType>
	Node<DType>::Node(string local_name):name(local_name)
	{

	}

	template<typename DType>
	Node<DType>::~Node()
	{
	}

	template<typename DType>
	void Node<DType>::add_in_edge(shared_ptr<Edge<DType>>& in_edge)
	{
		in_edges.push_back(in_edge);
	}

	template<typename DType>
	void Node<DType>::add_out_edge(shared_ptr<Edge<DType>>& out_edge)
	{
		out_edges.push_back(out_edge);
	}


	TEMPLATE_CLASS_INITIALIZE(Node);

}
