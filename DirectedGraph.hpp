#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "queue.hpp"
//#include <stdlib.h>
/*
* A class to represent a directed graph.
*/

class DirectedGraph : public AbstractGraph{

    int **a;    //for storing all the information required in DFS
    int time_;  //for tracking time in DFS
    int n;      //no of vertices in Directed graph
    char ch;    //To keep track of List or Matrix representation of Graph
    AdjacencyMatrix dgm;
    AdjacencyList dgl;
    
public:
    /*
    * Constructor: DirectedGraph
    *
    * Parameters: mode
    * Used to decide which representation to use
    * 'm' for AdjacencyMatrix
    * 'l' for AdjacencyList
    */

    DirectedGraph(int numVertices, char rep){
    	n=numVertices;
        ch = rep;
        if (rep== 'm' || rep=='M')
        {
            dgm.create(numVertices);
        }
        else
        {
            dgl.create(numVertices);
        }
    };
    /*
    * Function: indegree
    * Returns the indegree of a vertex
    */
    int indegree(int i){
        if (ch== 'm' || ch=='M')
        {
            return dgm.indegree(i);
        }
        else{
            return dgl.indegree(i);
        }
    };
    /*
    * Function: outdegree
    * Returns the outdegree of a vertex.
    */
    int outdegree(int j){
        if (ch== 'm' || ch=='M')
        {
            return dgm.outdegree(j);
        }
        else{
            return dgl.outdegree(j);
        }
    };




    /*
    * Function: edgeExists
    * Returns true if an edge exists between vertices i and j, false otherwise.
    */
    bool edgeExists(int i, int j){
        if (ch== 'm' || ch=='M')
        {
            return dgm.edgeExists(i,j);
        }
        else{
            return dgl.edgeExists(i,j);
        }
    };
    /*
    * Function: edges
    * Returns the number of edges in the adjacency structure.
    */
    int edges(){
        if (ch== 'm' || ch=='M')
        {
            return dgm.edges();
        }
        else{
            return dgl.edges();
        }
    };
    /*
    * Function: vertices
    * Returns the number of vertices in the adjacency structure.
    */
    int vertices(){
        if (ch== 'm' || ch=='M')
        {
            return dgm.vertices();
        }
        else{
            return dgl.vertices();
        }
    };
    /*
    * Function add:
    * Adds an edge between vertices i and j
    */
    void add(int i, int j){
        if (ch== 'm' || ch=='M')
        {
            return dgm.add(i,j);
        }
        else{
            return dgl.add(i,j);
        }
    };
    /*
    * Function: remove
    * Deleted the edge between vertices i and j
    */
    void remove(int i, int j){
        if (ch== 'm' || ch=='M')
        {
            return dgm.remove(i,j);
        }
        else{
            return dgl.remove(i,j);
        }
    };
    /*
    * Function dfs:
    * Does a depth first traversal of the entire graph.
    * Runs the given function work, with the value of each vertex.
    */
    void dfs(){//void (*work)(int&)
	        int i;
            a=new int*[n];
            for(int i=0; i<n; i++){
                a[i]=new int[4];
            }
            for (i = 0; i < n; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    a[i][j]=-1;
                }
            }
            //0=predecessor,1=color,2=Discovery time,3=Finishing time
            //-1=white,0=grey,1=Black,for predecessor -1=no predessor till yet
            //-1 distance means not reachable
            time_=0;
            DFS_VISIT(0); //if source vertex is given then shayad yaha par dfs-visit call hoga
            for (int i = 0; i < n; ++i)
            {
                if (a[i][1]==-1)
                {
                    DFS_VISIT(i);
                }
            }
            //print the a matrix along with number see for self loop and forests
            i=0;
            std::cout<<"\n"<<"Vertex"<<"\t"<<"Predecessor"<<"\t"<<"Color"<<"\t"<<"Discovery Time"<<"\t"<<"Finishing Time"<<"\n";
            for (i = 0; i < n; ++i)
            {
                std::cout<<i<<"\t";
                for (int j = 0; j < 4; ++j)
                {
                    std::cout<<a[i][j]<<"\t";
                }
                std::cout<<"\n";
            }
    };

    //helper function for DFS
    void DFS_VISIT(int i){
        if (ch== 'm' || ch=='M')
        {
            a[i][1]=0;
            a[i][2]=time_;
            std::cout<<i<<"\t";
            //int **temp= dg.head();
            //node* temp=dgl.List_head(i);//temp[0];
            for(int k=0; k<n;k++){
                if (dgm.edgeExists(i,k))
                {
                    if (a[k][1]==-1)
                    {
                        a[k][0]=i;
                        DFS_VISIT(k);
                    }
                }

            }
            a[i][1]=1;
            time_++;
            a[i][3]=time_;
        }
        else{
            a[i][1]=0;
            a[i][2]=time_;
            std::cout<<i<<"\t";
            //int **temp= dg.head();
            //node* temp=dgl.List_head(i);//temp[0];
            for(int k=0; k<n;k++){
                if (dgl.edgeExists(i,k))
                {
                    if (a[k][1]==-1)
                    {
                        a[k][0]=i;
                        DFS_VISIT(k);
                    }
                }

            }
            a[i][1]=1;
            time_++;
            a[i][3]=time_;
    }
    }
    /*
    * Function bfs:
    * Does a breadth first traversal of the entire graph.
    * Runs the given function work, with the value of each vertex.
    */
    void bfs()
    {   //void (*work)(int&)
        if (ch== 'm' || ch=='M')
        {
            queue<int> que;
            int i,b[n][3];
            for (i = 0; i < n; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    b[i][j]=-1;
                }
            }
            //0=predecessor, 1=color,2=distance
            //-1=white,0=grey,1=Black,for predecessor -1=no predessor till yet
            int s=0;//yaha ek source vertex aayegi let it be s
            b[s][1]=0;
            b[s][2]=0;
            que.push(s);
            while(!que.empty())
            {
                i=que.pop();
                std::cout<<i<<"\t";
                b[i][1]=1;
                //node* temp=dgl.List_head(i);//temp[0];
                for(int k=0; k<n;k++){
                    if (dgm.edgeExists(i,k))
                    {
                            if (b[k][1]==-1)
                            {
                                b[k][0]=i;
                                b[k][1]=0;
                                b[k][2]=b[i][2]+1;
                                que.push(k);
                            }
                    }
                }
            }
        }
        else{
            queue<int> que;
            int i,b[n][3];
            for (i = 0; i < n; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    b[i][j]=-1;
                }
            }
            //0=predecessor, 1=color,2=distance
            //-1=white,0=grey,1=Black,for predecessor -1=no predessor till yet
            int s=0;//yaha ek source vertex aayegi let it be s
            b[s][1]=0;
            b[s][2]=0;
            que.push(s);
            while(!que.empty())
            {
                i=que.pop();
                std::cout<<i<<"\t";
                b[i][1]=1;
                //node* temp=dgl.List_head(i);//temp[0];
                for(int k=0; k<n;k++){
            		if (dgl.edgeExists(i,k))
            		{
                    		if (b[k][1]==-1)
                    		{
                        		b[k][0]=i;
		                        b[k][1]=0;
                		        b[k][2]=b[i][2]+1;
                		        que.push(k);
                	        }
                	}
                }
            }
            return;
        }
    };
};
#endif /* ifndef DIRECTED_GRAPH */
