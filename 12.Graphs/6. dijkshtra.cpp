#include<iostream>
#include<limits.h>
#include<vector>
#include<set>
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
	
	for(int i=0;i<v;i++){
		
			cout<<i<<" "<<weight[i]<<endl;	
	}
	
}


void prims(set<pair<int,int>,int> g , int v){
	
	int * weight = new int [v];
	bool*visited = new bool [v];

	for (int i =0;i<v;i++){
		weight[i]=INT_MAX;
		visited[i]= false;
	}
	
	int ver ;
	
	for(int i =0;i<v-1;i++){
		
        ver=nextW(visited,weight,v);
        if(weight[ver]==INT_MAX)
        weight[ver]=0;
        visited[ver]=true;
        
		for(int j =0;j<v;j++){
			if(g[ver][j]!=0 && !visited[j]){
				int temp = weight[ver]+ g[ver][j];
				if(weight[j]>temp){
					weight[j]=temp;        
				}
            }
        }
	}
	
	print(weight,v);

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
    
     prims(set,v);
    
    for(int i=0;i<v;i++)
    	delete [] arr[i];
    	
    delete []arr;
    
    return 0;
    
    return 0;
}

