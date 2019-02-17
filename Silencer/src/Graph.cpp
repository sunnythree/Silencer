#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <queue>
#include "Common.hpp"
#include "Graph.hpp"
#include "Log.hpp"



using std::shared_ptr;
using std::vector;
using std::string;
using std::queue;


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
	void Graph<DType>::ForwardBroadScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out)
	{
		if (in == nullptr || out == nullptr) {
			return;
		}
		queue<shared_ptr<Node<DType>>> work_queue;
		work_queue.push(in);
		while (!work_queue.empty()) {
			shared_ptr<Node<DType>> node = work_queue.front();
			work_queue.pop();
			vector<shared_ptr<Edge<DType>>> in_edges = node->get_in_edges();
			if (in_edges.empty()) {
				node->set_visited(true);
				forward_pipeline.push_back(node);
			}
			else {
				if (in == out) {
					node->set_visited(true);
					forward_pipeline.push_back(node);
					return;
				}
				bool can_visited = true;
				for (auto tmp : in_edges) {
					if (!tmp->get_in()->is_visited()) {
						can_visited = false;
						work_queue.push(tmp->get_in());
					}
				}
				if (can_visited) {
					node->set_visited(true);
					forward_pipeline.push_back(node);
				}
				else {
					work_queue.push(node);
				}
			}
			vector<shared_ptr<Edge<DType>>> out_edges = node->get_out_edges();
			if (out_edges.empty()) {
				continue;
			}
			for (auto tmp : out_edges) {
				if (!tmp->get_out()->is_visited()) {
					work_queue.push(tmp->get_out());
				}
			}
		}
	}

	template<typename DType>
	void Graph<DType>::ForwardDeepScan(shared_ptr<Node<DType>> in,shared_ptr<Node<DType>> out)
	{
		if (in == nullptr || out == nullptr) {
			return;
		}
		vector<shared_ptr<Edge<DType>>> in_edges = in->get_in_edges();
		if (in_edges.empty()) {
			in->set_visited(true);
			forward_pipeline.push_back(in);
		}
		else {
			if (in == out) {
				in->set_visited(true);
				forward_pipeline.push_back(in);
				return;
			}
			for (auto tmp : in_edges) {
				if (!tmp->get_in()->is_visited()) {
					ForwardDeepScan(tmp->get_out(), out);
				}
			}
			in->set_visited(true);
			forward_pipeline.push_back(in);
		}
		vector<shared_ptr<Edge<DType>>> out_edges = in->get_out_edges();
		if (out_edges.empty()) {
			return;
		}
		for (auto tmp1 : out_edges) {
			ForwardDeepScan(tmp1->get_out(), out);
		}
	}

	template<typename DType>
	void Graph<DType>::BackwardBroadScan(shared_ptr<Node<DType>> out, shared_ptr<Node<DType>> in)
	{
		if (in == nullptr || out == nullptr) {
			return;
		}
		queue<shared_ptr<Node<DType>>> work_queue;
		work_queue.push(out);
		while (!work_queue.empty()) {
			shared_ptr<Node<DType>> node = work_queue.front();
			work_queue.pop();
			vector<shared_ptr<Edge<DType>>> out_edges = node->get_out_edges();
			if (out_edges.empty()) {
				node->set_visited(false);
				backward_pipeline.push_back(node);
			}
			else {
				if (in == out) {
					node->set_visited(false);
					backward_pipeline.push_back(node);
					return;
				}
				bool can_visited = true;
				for (auto tmp : out_edges) {
					if (tmp->get_out()->is_visited()) {
						can_visited = false;
						work_queue.push(tmp->get_out());
					}
				}
				if (can_visited) {
					node->set_visited(false);
					backward_pipeline.push_back(node);
				}
				else {
					work_queue.push(node);
				}
			}
			vector<shared_ptr<Edge<DType>>> in_edges = node->get_in_edges();
			if (in_edges.empty()) {
				continue;
			}
			for (auto tmp : in_edges) {
				if (tmp->get_in()->is_visited()) {
					work_queue.push(tmp->get_in());
				}
			}
		}
	}

	template<typename DType>
	void Graph<DType>::BackwardDeepScan(shared_ptr<Node<DType>> out, shared_ptr<Node<DType>> in)
	{
		if (in == nullptr || out == nullptr) {
			return;
		}
		vector<shared_ptr<Edge<DType>>> out_edges = out->get_out_edges();
		if (out_edges.empty()) {
			out->set_visited(false);
			backward_pipeline.push_back(out);
		}
		else {
			if (in == out) {
				out->set_visited(false);
				backward_pipeline.push_back(out);
				return;
			}
			for (auto tmp : out_edges) {
				if (tmp->get_out()->is_visited()) {
					BackwardDeepScan( tmp->get_out(),in);
				}
			}
			out->set_visited(false);
			backward_pipeline.push_back(out);
		}
		vector<shared_ptr<Edge<DType>>> in_edges = out->get_in_edges();
		if (in_edges.empty()) {
			return;
		}
		for (auto tmp1 : in_edges) {
			BackwardDeepScan(tmp1->get_in(),in);
		}
	}


	template<typename DType>
	void Graph<DType>::Build(shared_ptr<Node<DType>> in, shared_ptr<Node<DType>> out, GRAPH_SCAN scan_mode)
	{
		if (scan_mode == DEEP) {
			ForwardDeepScan(in,out);
			BackwardDeepScan(out,in);
		}
		else {
			ForwardBroadScan(in, out);
			BackwardBroadScan(out,in);
		}
	}

	template<typename DType>
	void Graph<DType>::report()
	{
		Log::d("Graph","forward_pipeline: ");
		string tmp_string;
		for (auto tmp : forward_pipeline) {
			tmp_string += tmp->get_name() + " ";
		}
		Log::d("Graph", tmp_string);
		tmp_string = "";
		Log::d("Graph", "backward_pipeline: ");
		for (auto tmp : backward_pipeline) {
			tmp_string += tmp->get_name() + " ";
		}
		Log::d("Graph", tmp_string);
	}

	TEMPLATE_CLASS_INITIALIZE(Graph);
	

}