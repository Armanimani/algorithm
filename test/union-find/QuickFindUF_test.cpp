#include "union-find/QuickFind.hpp"
#include "union-find/QuickUnion.hpp"
#include "union-find/QuickUnionWeighted.hpp"
#include "union-find/QuickUnionPathComp.hpp"
#include "union-find/QuickUnionWeightedPathComp.hpp"
#include <iostream>

int main()
{
	algorithm::unionFind::QuickUnionWeightedPathComp uf(10);

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
