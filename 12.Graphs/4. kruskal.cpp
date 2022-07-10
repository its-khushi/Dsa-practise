#include <iostream>
#include<algorithm>
using namespace std;


class graph{
	public:
  	int v1;
	int v2;
    int w;
};
int op(graph const & v1,graph const & v2 ){
	return v1.w<v2.w;
}

bool findParent(int *parent, int c, int d){
	
    int a =c, b =d;
	while(c!=parent[c]){
		c= parent[c];
    }
    
    
    while(d!=parent[d]){
		d= parent[d];
    }
    
    if(c==d){
        return false;
    }
    
    parent[c]=parent[d];

    return true;
    
    
}

graph* kruskal(graph* arr,int v){
	
	
	int count =0;
	int mstCount=0;
    int * parent = new int[v];
    for(int i=0;i<v;i++){
    	parent[i]=i;
	}
    
	graph* mst= new graph[v-1];
    
	while(mstCount<v-1){
		
		if(findParent(parent , arr[count].v1 , arr[count].v2)){
            
				mst[mstCount]= arr[count];
				mstCount++;
		}
		count++;
	}
    
	delete [] parent;
	return mst;
	
}

void print(int n, graph* arr){
	
	for(int i=0;i<n;i++){
        
        if(arr[i].v2<arr[i].v1){
            cout<<arr[i].v2<<" "<<arr[i].v1<<" "<<arr[i].w<<endl;
        }else {
            cout<<arr[i].v1<<" "<<arr[i].v2<<" "<<arr[i].w<<endl;
        }
	}
	
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    
    graph arr[e];
    
    for(int i=0;i<e;i++){
    	cin>>arr[i].v1>>arr[i].v2>>arr[i].w;
    }
    
    sort(arr,arr+e,op);
    graph * mst = kruskal(arr,v);
    
    print (v-1,mst);
    delete [] mst;
    
    return 0;
}
