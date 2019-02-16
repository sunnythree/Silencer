// Silencer.cpp: 定义应用程序的入口点。
//

#include "Silencer.h"
#include "Node.hpp"
#include "Edge.hpp"
#include "Common.hpp"

using std::cout;
using std::endl;

using Silencer::Node;
using Silencer::Edge;
using Silencer::operator<<;

int main()
{
	shared_ptr<Node<float>> node1 = make_shared<Node<float>>();
	shared_ptr<Node<float>> node2 = make_shared<Node<float>>();
	node1 << node2;
	
	cout << "Hello CMake。" << endl;
	system("pause");
	return 0;
}
