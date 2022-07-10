#include<iostream>
#include<limits.h>
using namespace std;

class graph{
	public:
  	int v1;
	int v2;
    int w;
};

int nextW(bool * visited, int * weight , int v){
	
	int next=-1;
	for(int i =0;i<v;i++){
		// if u wont have any vertex with visited == false and weight != int_max 
		if(visited[i]==false &&(next==-1 || weight[i]<weight[next])){
			next = i;
		}
	}
    
	return next;
}

void print(int* parent, int* weight, int v){
	
	for(int i=1;i<v;i++){
		if(i<parent[i]){
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;	
		}	
	}
	
}

void prims(int ** g , int v){
	
	int * weight = new int [v];
	bool*visited = new bool [v];
	int * parent = new int [v]; 


	for (int i =0;i<v;i++){
		weight[i]=INT_MAX;
		visited[i]= false;
		parent[i]=i;
	}
	
	int ver=0;
    weight[ver]=0;
	for(int i =0;i<v-1;i++){
		
        ver=nextW(visited,weight,v);
        visited[ver]=true;
        
		for(int j =0;j<v;j++){
			if(g[ver][j]!=0 && !visited[j]){
				if(weight[j]>g[ver][j]){
					weight[j]=g[ver][j];
					parent[j]=ver;           
				}
            }
        }
		
	}
	
	print(parent,weight,v);
	delete [] parent;
    delete [] visited;
    delete [] weight;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int ** arr= new int*[v];
    
    for(int i=0;i<v;i++){
        arr[i]= new int[v];
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int a,b,c;
    	cin>>a>>b>>c;
        
        arr[a][b]=c;
        arr[b][a]=c;
    }
    
     prims(arr,v);
    
    for(int i=0;i<v;i++)
        delete [] arr[i];
    delete []arr;
    return 0;
}


