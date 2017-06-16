#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include <limits.h>
#include <stdlib.h>

class AdjacencyMatrix : public GraphAdjacencyBase {

	int **am;
	int n,count;


public:
     //Constructor
	AdjacencyMatrix(){
          count=0;
	};
     ~AdjacencyMatrix(){
          
     };

	void create(int v){
          n=v;
          count=0;
          am=(int**)malloc(n*sizeof(int*));
          for(int k=0; k<n; k++){
             am[k]=new int[n]();//(int*)calloc(n,sizeof(int));
          }
		return;
	};
    /*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
     bool edgeExists(int i, int j){
     	return am[i][j];
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
          if (am[i][j]==1)
          {
               return;
          }
     	am[i][j]=1;
     	count++;
     	return;
     };
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
     void remove(int i, int j){
          if (am[i][j]==0)
          {
               return;
          }
     	am[i][j]=0;
     	count--;
     	return;
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
     		deg+=am[i][j];
     	}
     	return deg;
     };

     int outdegree(int i){
     	int deg=0;
     	for (int j = 0; j < n; ++j)
     	{
     		deg+=am[j][i];
     	}
     	return deg;
     };
};
#endif /* ifndef ADJACENCY_MATRIX */
