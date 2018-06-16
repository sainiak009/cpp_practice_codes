//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "graph.h"
#include <iostream>
using namespace std;

int main(){
	Graph G(8);

	G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(2,5);
	G.addEdge(5,6);
	G.addEdge(5,7);
	G.addEdge(6,7);
	G.addEdge(3,4);
	
}