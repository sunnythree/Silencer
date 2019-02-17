#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Common.hpp"
#include "Graph.hpp"



using std::shared_ptr;
using std::vector;
using std::string;
using std::cout;
using std::endl;

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
	void Graph<DType>::BroadScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out)
	{
		return;
	}

	template<typename DType>
	void Graph<DType>::DeepScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out)
	{
		if (in == nullptr || out == nullptr) {
			return;
		}
		vector<shared_ptr<Edge<DType>>> in_edges = in->get_in_edges();
		if (in_edges.empty()) {
			vector<shared_ptr<Edge<DType>>> out_edges = in->get_out_edges();
			if (out_edges.empty()) {
				return;
			}
			in->set_visited(true);
			cout << "node name is " << in->get_name() << endl;
			for (auto tmp1 : out_edges) {
				DeepScan(tmp1->get_out(),out);
			}
		}
		else {
			if (in == out) {
				in->set_visited(true);
				cout << "node name is " << in->get_name() << endl;
				return;
			}
			for (auto tmp : in_edges) {
				if (!tmp->get_in()->is_visited()) {
					DeepScan(tmp->get_out(), out);
				}
			}
			in->set_visited(true);
			cout << "node name is " << in->get_name() << endl;
			vector<shared_ptr<Edge<DType>>> out_edges = in->get_out_edges();
			for (auto tmp1 : out_edges) {
				DeepScan(tmp1->get_out(), out);
			}
		}
	}

	template<typename DType>
	void Graph<DType>::Build(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out)
	{
		DeepScan(in,out);
	}

	TEMPLATE_CLASS_INITIALIZE(Graph);
	

}