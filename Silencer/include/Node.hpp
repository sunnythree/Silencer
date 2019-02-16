#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include"Edge.hpp"

using std::vector;
using std::shared_ptr;
using std::string;
using std::initializer_list;

namespace Silencer {
	template<typename DType>
	class Node:std::enable_shared_from_this<DType>
	{
	public:
		Node();
		Node(string name);
		~Node();
		void add_in_edge(shared_ptr<Edge<DType>>& in_edge);
		void add_out_edge(shared_ptr<Edge<DType>>& out_edge);
		vector<shared_ptr<Edge<DType>>>& get_in_edges();
		vector<shared_ptr<Edge<DType>>>& get_out_edges();
		
	private:
		vector<shared_ptr<Edge<DType>>> in_edges;
		vector<shared_ptr<Edge<DType>>> out_edges;
		string name;
	};

}