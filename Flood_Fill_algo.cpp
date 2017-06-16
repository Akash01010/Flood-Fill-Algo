#include <iostream>
#include <cstdlib>

using namespace std;

bool **ans;
bool **visited;
int **matrix;
bool DFS(int x,int  y, int n, int m,int dest_x,int dest_y){
	    if(x == dest_x && y == dest_y)
	        return true;
	    if(x >= n || y >= m)
	        return false;
	    if(x < 0 || y < 0)
	        return false;
	    if(visited[x][y] == true)
	        return false;
	    if(matrix[x][y] == 0)
	        return false;

	    visited[x][y] = true;
	    for (int i = 0; i < 1; ++i)
	    {
		    switch(1){
		    	case 1:
				    if (DFS(x+1, y, n, m,  dest_x, dest_y) == true){//, visited, matrix
				    	ans[x+1][y]=1;
				        return true;
				    }
				case 2:
				    if (DFS(x-1, y, n, m,  dest_x, dest_y) == true){
				    	ans[x-1][y]=1;
				        return true;
				    }
				case 3:
				    if (DFS(x, y+1, n, m,  dest_x, dest_y) == true){
				    	ans[x][y+1]=1;
				        return true;
				    }
				case 4:
				    if (DFS(x, y-1, n, m,  dest_x, dest_y) == true){
				    	ans[x][y-1]=1;
				        return true;
				    }
				case 5:
				    if (DFS(x+1, y-1, n, m,  dest_x, dest_y) == true){
				    	ans[x+1][y-1]=1;
				        return true;
				    }
				case 6:
				    if (DFS(x-1, y-1, n, m,  dest_x, dest_y) == true){
				    	ans[x-1][y-1]=1;
				        return true;
				    }
				case 7:
				    if (DFS(x+1, y+1, n, m,  dest_x, dest_y) == true){
				    	ans[x+1][y+1]=1;
				        return true;
				    }
				case 8:
				    if (DFS(x-1, y+1, n, m,  dest_x, dest_y) == true){
				    	ans[x-1][y+1]=1;
				        return true;
				    }
			}
		}
	    return false;
	}

int main(int argc, char const *argv[])
{
	int n,m,x,y,xf,yf;
	cout<<"Enter the dimensions of your matrix: (column::row)\n";
	cin>>m>>n;
	cout<<"Enter the matrix elements:\n";
	matrix=(int**)malloc(m*sizeof(int*));
    for(int k=0; k<m; k++){
        matrix[k]=(int*)calloc(n,sizeof(int));
    }
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>matrix[i][j];
		}
	}
	visited=(bool**)malloc(m*sizeof(bool*));
    for(int k=0; k<m; k++){
        visited[k]=(bool*)calloc(n,sizeof(bool));
    }
	cout<<"Enter the source node: \n";
	cin>>x>>y;
	cout<<"Enter the destination node: \n";
	cin>>xf>>yf;

    ans=(bool**)malloc(m*sizeof(bool*));
    for(int k=0; k<m; k++){
        ans[k]=(bool*)calloc(n,sizeof(bool));
    }
	ans[x][y]=1;
	if(DFS(x,y,n,m,xf,yf)){
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<ans[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"Path doesn't exist\n";
	}

	return 0;
}


