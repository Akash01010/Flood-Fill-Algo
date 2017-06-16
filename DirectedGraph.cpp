#include <iostream>
#include "DirectedGraph.hpp"

int main(int argc, char const *argv[])
{
	char ch,temp;
	int n,x,y,i;
	std::cout<<"Enter graph representation('M' for Adjacency Matrix representation and 'L' for Adjacency List representation)\n";
	std::cin>>ch;
	std::cout<<"Enter the number of vertices in the graph\n";
	std::cin>>n;
	DirectedGraph graph(n,ch);

	//Taking input of Graph
	while(1){
		std::cout<<"How do you want to enter the graph\nPress:\n 1.For inserting a nxn matrix\n2. For entering the edges in the graph\n";
		std::cin>>i;
		if (i==1)
		{
			for (i = 0; i < n; ++i)
			{
				for (int j = 0; j <n; ++j)
				{
					std::cin>>x;
					if (x==0)
					{
						continue;
					}
					else{				//if x will be any other integer than 1 than it will be counted as edge
						graph.add(i,j);
					}
				}
			}
			break;
		}
		else if(i==2){
			std::cout<<"Enter the edges in the graph:\n";
			//std::cin>>ch;
			i=1;
			while(i){
				std::cout<<"Enter two vertices to add edge between them(0 to n-1):\n";
				std::cin>>x>>y;
				graph.add(x,y);
				std::cout<<"Press 1 to continue and -1 to stop adding more edges\n";
				std::cin>>i;
				if(i==-1)
		            break;
			}
			break;
		}
		else{
			continue;
		}
	}
	while(1){
		std::cout<<"Enter 1: To get indegree of a node\n2: To get outdegree of a node\n3: To check if edge exists between a pair of nodes or not\n4: To check total number of edges in graph\n5: To get total number of vertices in graph\n6: To add an edge in graph\n7: To remove an edge from graph\n8: For applying DFS on graph\n9: For applying BFS on graph\n10: To exit\n";
		std::cin>>x;
		switch(x){
			case 1:
				std::cout<<"Enter the node(0 to n-1)\n";
				std::cin>>y;
				std::cout<<graph.indegree(y)<<"\n";
				break;
			case 2:
				std::cout<<"Enter the node(0 to n-1)\n";
				std::cin>>y;
				std::cout<<graph.outdegree(y)<<"\n";
				break;
			case 3:
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>x;
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>y;
				std::cout<<graph.edgeExists(x,y)<<"\n";
				break;
			case 4:
				std::cout<<"Total number of edges in graph are: "<<graph.edges()<<"\n";
				break;
			case 5:
				std::cout<<"Total number of vertices in graph are: "<<graph.vertices()<<"\n";
				break;
			case 6:
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>x;
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>y;
				graph.add(x,y);
				break;
			case 7:
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>x;
				std::cout<<"Enter the node1(0 to n-1)\n";
				std::cin>>y;
				graph.remove(x,y);
				break;
			case 8:
				graph.dfs();
				break;
			case 9:
				graph.bfs();
				break;
			case 10:
				return 0;
		}
	}
	return 0;
}
