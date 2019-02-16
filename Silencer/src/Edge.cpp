#include "Edge.hpp"
#include "Node.hpp"
#include "Common.hpp"

namespace Silencer {

	template<typename DType>
	Edge<DType>::Edge()
	{
	}

	template<typename DType>
	Edge<DType>::~Edge()
	{
	}

	template<typename DType>
	void Edge<DType>::set_data(shared_ptr<Tensor<DType>> data)
	{
		this->data = data;
	}

	template<typename DType>
	shared_ptr<Tensor<DType>> Edge<DType>::get_data()
	{
		return data;
	}

	template<typename DType>
	void Edge<DType>::set_diff(shared_ptr<Tensor<DType>> diff)
	{
		this->diff = diff;
	}

	template<typename DType>
	shared_ptr<Tensor<DType>> Edge<DType>::get_diff()
	{
		return diff;
	}

	template<typename DType>
	void Edge<DType>::set_in(shared_ptr<Node<DType>> in)
	{
		this->in = in;
	}

	template<typename DType>
	shared_ptr<Node<DType>> Edge<DType>::get_in()
	{
		return in;
	}

	template<typename DType>
	void Edge<DType>::set_out(shared_ptr<Node<DType>> out)
	{
		this->out = out;
	}

	template<typename DType>
	shared_ptr<Node<DType>> Edge<DType>::get_out()
	{
		return out;
	}


	TEMPLATE_CLASS_INITIALIZE(Edge);
}
