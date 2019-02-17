// Silencer.cpp: 定义应用程序的入口点。
//

#include "Silencer.h"
#include "Node.hpp"
#include "Edge.hpp"
#include "Common.hpp"
#include "Graph.hpp"

using std::cout;
using std::endl;

using Silencer::Node;
using Silencer::Edge;
using Silencer::Graph;
using Silencer::operator<<;

int main()
{
	shared_ptr<Node<float>> node1 = make_shared<Node<float>>("node1");
	shared_ptr<Node<float>> node2 = make_shared<Node<float>>("node2");
	shared_ptr<Node<float>> node3 = make_shared<Node<float>>("node3");
	shared_ptr<Node<float>> node4 = make_shared<Node<float>>("node4");
	shared_ptr<Node<float>> node5 = make_shared<Node<float>>("node5");
	shared_ptr<Node<float>> node6 = make_shared<Node<float>>("node6");
	shared_ptr<Node<float>> node7 = make_shared<Node<float>>("node7");
	shared_ptr<Node<float>> node8 = make_shared<Node<float>>("node8");

	node1 << node2 << node3 << node4 << node5 << node6 << node7 << node8;

	shared_ptr<Graph<float>> graph = make_shared<Graph<float>>();
	graph->Build(node1,node8,Graph<float>::BROAD);
	graph->report();
	
	cout << "Hello CMake。" << endl;
	system("pause");
	return 0;
}
