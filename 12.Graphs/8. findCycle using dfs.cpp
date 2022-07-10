#include<iostream>
using namespace std;
class listNode{
	int data ;
	listNode * next;
	
	listNode(){
		
	}
};

bool dfs(int ** g,int v, int sv, bool* visited,int * parent){
	
	if(visited[sv]==true)
	return false;
	
	visited[sv]=true;
	
	for(int i=0;i<v;i++){
		
		if(g[sv][i]==-1){
			continue;
		}
		
		if(visited[i]==true){
			if(parent[i]==parent[sv]){
				return true;
			}else{
				return false;
			}
		}
		
		parent[i]=parent[sv];	
		if(dfs(g,v,i,visited,parent)==true)
		return true;	
		
	}
	
	return false;
	
}


bool findCycle(int ** g, int v){
	
	int * parent = new int[v];
	bool * visited = new bool[v];
	
	for (int i=0;i<v;i++){
		parent[i]=i;
		visited[i]=false;
	} 
	
	
	for(int i=0;i<v;i++){
		
		if(visited[i]==true ){
			continue;
		}
		
		if(dfs(g,v,i,visited,parent)==true)
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
    }
    
    cout<<findCycle(input,n);
	return 0;
	
}
