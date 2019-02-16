#pragma once
#include<iostream>
#include"Tensor.hpp"

using std::shared_ptr;
using std::make_shared;

namespace Silencer {
	template<typename DType>
	class Node;

	template<typename DType>
	class Edge
	{
	public:
		Edge();
		~Edge();
		void set_data(shared_ptr<Tensor<DType>> data);
		shared_ptr<Tensor<DType>> get_data();
		void set_diff(shared_ptr<Tensor<DType>> diff);
		shared_ptr<Tensor<DType>> get_diff();
		void set_in(shared_ptr<Node<DType>> in);
		shared_ptr<Node<DType>> get_in();
		void set_out(shared_ptr<Node<DType>> out);
		shared_ptr<Node<DType>> get_out();
	private:
		shared_ptr<Tensor<DType>> data;
		shared_ptr<Tensor<DType>> diff;
		shared_ptr<Node<DType>> in;
		shared_ptr<Node<DType>> out;
	};
}