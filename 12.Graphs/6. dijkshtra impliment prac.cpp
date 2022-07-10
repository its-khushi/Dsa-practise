#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

class vertex{
	public:
	int data;
	int weight;
	vertex * next;
	vertex(int data, int weight){
		next = NULL;
		this->weight= weight;
		this->data = data;
	}
	
	~vertex(){
		if(this->next!=NULL)
		delete (this->next);
	}
	
};

void printDis(int * weight,int n){
	
	for(int i=0;i<n;i++){
		
			cout<<i<<" "<<weight[i]<<endl;	
	}
	
}
	

void bfs(vertex ** g, int n, int sv,int * weight , int * visited){
	
	vertex * temp = g[sv];
	
	while(temp!=NULL){
		if(visited[temp->data]==false){
			int tempDis=weight[sv]+temp->weight;
			if(weight[temp->data]>tempDis)
				weight[temp->data]=tempDis;
		}
		temp = temp->next;
	}
	
}

int minDis(int * dis,int * visited, int n){
	int min =-1;
	
	for(int i=0;i<n;i++){
		if(visited[i]==false &&  (min ==-1 || dis[min]>dis[i]))
		min =i;
	}
	
	return min;
}

// total O(n*n + e)
void dijkstra(vertex ** g, int n, int sv ){
	
	int * weight= new int [n];
	int * visited = new int [n];
	
	
	// log(n)
	for(int i=0;i<n;i++){
		visited[i]=0;
		weight[i]=INT_MAX;
	}

	
	// O(n)
	for(int i=0;i<n;i++){
		
		//O(n)
		sv= minDis(weight,visited,n);
		if(weight[sv]==INT_MAX)
		weight[sv]=0;
		visited[sv]=true;
		// will be called n times but inside the while loop will run for no of egdes times
		bfs(g,n,sv,weight,visited);
	}
	
	printDis(weight, n);
	delete [] weight;
	delete [] visited;
}



vertex ** create_graph(int n, int e){
	
	vertex ** graph = new vertex*[n];
	for(int i=0;i<n;i++){
		graph[i]=NULL;
	}
	for(int i=0;i<e;i++){
		int u,v,wght;
		cin>>u>>v>>wght;
		vertex * newNode1 = new vertex(v,wght);
		vertex * newNode2 = new vertex(u,wght);
		newNode1->next=graph[u];
		newNode2->next=graph[v];
		graph[u]= newNode1;
		graph[v]= newNode2;
	}
	
	return graph;	
}

void print_graph(vertex ** graph, int n){
	
	for (int i=0;i<n;i++){
		vertex * temp = graph[i];
		cout<<i<<":";
		while(temp!=NULL){
			cout<<temp->data<<"-"<<temp->weight;
			if(temp->next!=NULL)
			cout<<",";
			temp = temp->next;
		}
		cout<<endl;
	}
}


int main(){
	int n, e;
	cin>>n>>e;
	
	vertex ** graph=create_graph(n,e);
	print_graph(graph,n);
	
	dijkstra(graph,n,1);
	
	for(int i=0;i<n;i++){
		cout<<i<<endl;
		delete graph[i];		
	}

	delete [] graph;
	return 0;
}
