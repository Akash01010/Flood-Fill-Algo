#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"

class AdjacencyList_node{
public:
	int vertex;
	class AdjacencyList_node * next;
	AdjacencyList_node(){
		vertex=0;
		next=NULL;
	};
     ~AdjacencyList_node(){

     };
};
class AdjacencyList : public GraphAdjacencyBase {

	AdjacencyList_node **al;
	AdjacencyList_node *temp;
	int n,count;
public:
	AdjacencyList(){
		count=0;
	};


  ~AdjacencyList(){

  };

	void create(int v){
          n=v;
		al=new AdjacencyList_node*[n]();
          return;
	};
  /*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
     bool edgeExists(int i, int j){
     	temp=al[i];
     	while(temp!=NULL){
     		if (temp->vertex!=j)
     		{
     			temp=temp->next;
     		}
     		else{
     			return true;
     		}
     	}
     	return false;
     };
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
     int vertices(){
     	return n;
     };
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
     int edges(){
     	return count;
     };
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
     void add(int i, int j){
          if (edgeExists(i,j))
          {
               return;
          }
     	temp=new  AdjacencyList_node;
     	temp->vertex=j;
     	temp->next=al[i];
     	al[i]=temp;
     	count++;
     	return;
     };
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
     void remove(int i, int j){
     	AdjacencyList_node *temp1=NULL;
     	temp=al[i];
     	try{
     		while(temp!=NULL && temp->vertex !=j){
     		    temp1=temp;
     		    temp=temp->next;
     		}
	     	if (temp!=NULL)
	     	{
                    if (temp1==NULL)
                    {
                         al[i]=temp->next;
                         delete temp;
                         count--;
                         return;
                    }
	     		temp1->next=temp->next;
	     		delete temp;
                    count--;
	     		return;
	     	}
	     	else{
	     		throw 20;
	     		//return;	//no edge between i and j
	     	}
	     }
	     catch(int e){
	     	std::cout<<"No edge between "<<i<<" and "<<j<<"\n";
	     }
     };
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
     int degree(int i){
     	return this->outdegree(i);
     };

     int indegree(int i){
     	int deg=0;
     	for (int j = 0; j < n; ++j)
     	{
     		temp=al[j];
     		while(temp!=NULL){
     			if (temp->vertex ==i)
     			{
     				deg++;
     				break;
     			}
     			else{
     				temp=temp->next;
     			}
     		}
     	}
     	return deg;
     };
     int outdegree(int i){
     	int deg=0;
     	temp=al[i];
     	while(temp!=NULL){
     		temp=temp->next;
     		deg++;
     	}
     	return deg;
     };
};
#endif /* ifndef ADJACENCY_LIST */
