#include<iostream>
using namespace std;

bool dfs(int ** g , int v,int prev, int sv, bool* visited){
	
	visited[sv]=true;
	
	for(int i=0;i<v;i++){
		
		if(g[sv][i]==-1){
			continue;
		}
		if(visited[i]==true){
			if(i!=prev){
				return true;
			}
			continue;
		}
		
		if(dfs(g,v,sv,i,visited)==true)
		return true;	
		
	}
	
	return false;
	
}


bool findCycle(int ** g, int v){
	
	bool * visited = new bool[v];
	
	for (int i=0;i<v;i++){
		visited[i]=false;
	} 
	
	
	for(int i=0;i<v;i++){
		
		if(visited[i]==true ){
			continue;
		}
		
		if(dfs(g,v,-1,i,visited)==true)
		return true;
		
	}
	
	return false;
}

int main (){
	
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
        input[b][a]=1;
    }
    
    cout<<findCycle(input,n);
	return 0;
	
}
