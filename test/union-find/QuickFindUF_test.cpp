#include "union-find/UnionFind.hpp"
#include <iostream>

int main()
{
	algorithm::unionFind::QuickUnion_weightedPathComp uf(10);

	uf.connect(1, 2);
	uf.connect(3, 4);
	uf.connect(5, 6);
	uf.connect(7, 8);
	uf.connect(7, 9);
	uf.connect(8, 1);
	uf.connect(5, 0);
	uf.addNode();
	uf.addNode(3);

	std::cout << std::boolalpha << uf.isConnected(5, 6) << " " << uf.isConnected(1, 0) << " " << std::endl;
}
