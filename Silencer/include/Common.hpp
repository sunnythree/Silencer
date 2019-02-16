#pragma once
#include <iostream>
#include <memory>
#include "Node.hpp"
#include "Edge.hpp"

using std::shared_ptr;
using std::make_shared;

namespace Silencer {

	#define TEMPLATE_CLASS_INITIALIZE(classname) \
	template class classname<float>;\
	template class classname<double>

	template<typename DType>
	inline shared_ptr<Node<DType>>& operator<<(shared_ptr<Node<DType>>& in, shared_ptr<Node<DType>>& out)
	{
		shared_ptr<Edge<DType>> edge = make_shared<Edge<DType>>();
		edge->set_in(in);
		edge->set_out(out);
		in->add_out_edge(edge);
		out->add_in_edge(edge);
		return out;
	}
}
