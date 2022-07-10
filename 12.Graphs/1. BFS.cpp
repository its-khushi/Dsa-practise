#include <iostream>
#include<cstring>
#include<queue>
using namespace std;


void print (int ** node , int n , int sv, bool * visited){
	
	queue<int> q;
    q.push(sv);
    visited [sv]= true;
    
   
    while(!q.empty()){
        
        cout<<q.front()<<endl;
        int sv = q.front();
        q.pop();
        
        for(int i =0;i<n;i++){
            if(node[sv][i]==0){
                continue;
            }
            if(visited[i]==true){
                continue;
            }
            
            q.push(i);
            visited[i]= true;
        }
        
    }
}

void bfs(int ** node , int n){
    
	if(n==0)
        return ;
    
    bool visited[n];
    memset(visited, false , sizeof(visited));
    for(int i =0;i<n;i++){
    	if(visited[i]==true){
    		continue;
		}
		
		print(node,n,i,visited);
	}
    
}

int main() {
    // Write your code here
	int n,e;
    cin>>n>>e;
    
    int ** input = new int *[n];
    
    
    for(int i=0;i<n;i++){
        input[i]= new int [n];
        for(int j =0;j<n;j++){
            input[i][j]=0;
        }
    }

    
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        input[a][b]=1;
        input[b][a]=1;
    }
    
    
    bfs(input,n);
    
    for(int i =0;i<n;i++){
    	delete [] input[i];
	}
    
    delete [] input;
    
    return 0;
}
