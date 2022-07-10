#include<iostream>
using namespace std;

bool dfs(int ** g, int n, int sv, int * visited, int * incycle){
	
	if(visited[sv]== true){
		if(incycle[sv]== true)
		return true;
		else
		return false;
	}
	visited[sv]= true;
	incycle[sv]=true;
	
	for(int i=0;i<n;i++){
		
		if(g[sv][i]==0)
		continue;
		
		if(dfs(g,n,i,visited,incycle)==true)
		return true;
	}
	incycle[sv]=false;
	
	return false;
	
}

bool findCycle(int ** g, int n){
	int * visited= new int [n];
	int * incycle= new int [n];	
	for(int i =0;i<n;i++){
		if(visited[i]==0){
			if(dfs(g,n,i,visited,incycle)==true){
			delete [] visited;
			delete [] incycle;
			return true;	
			}
		}
		
	}
	delete [] visited;
	delete [] incycle;
	return false;
}
int main(){
	int n,e;
    cin>>n>>e;
    
    // making matrix
    int ** input = new int *[n];
    for(int i=0;i<n;i++){
        input[i]= new int [n];
        for(int j =0;j<n;j++){
            input[i][j]=-1;
        }
    }

    // inserting edges
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        input[a][b]=1;
    }
    
    cout<<findCycle(input,n);
    
    for(int i=0;i<n;i++)
    delete [] input[i];
    
    delete [] input;
    
	return 0;
}


