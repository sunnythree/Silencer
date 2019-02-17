#include "Node.hpp"
#include "Common.hpp"

namespace Silencer {

	template<typename DType>
	Node<DType>::Node():
		visited(false)
	{
	}

	template<typename DType>
	Node<DType>::Node(string local_name):
		name(local_name),
		visited(false)
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

	template<typename DType>
	vector<shared_ptr<Edge<DType>>>& Node<DType>::get_in_edges()
	{
		return in_edges;
	}

	template<typename DType>
	vector<shared_ptr<Edge<DType>>>& Node<DType>::get_out_edges()
	{
		return out_edges;
	}

	template<typename DType>
	string Node<DType>::get_name()
	{
		return name;
	}

	template<typename DType>
	bool Node<DType>::is_visited()
	{
		return this->visited;
	}

	template<typename DType>
	void Node<DType>::set_visited(bool visited)
	{
		this->visited = visited;
	}

	TEMPLATE_CLASS_INITIALIZE(Node);

}
