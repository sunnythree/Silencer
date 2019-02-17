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
	node1 << node2 << node3;

	shared_ptr<Graph<float>> graph = make_shared<Graph<float>>();
	graph->Build(node1,node3,Graph<float>::DEEP);
	
	cout << "Hello CMake。" << endl;
	system("pause");
	return 0;
}
