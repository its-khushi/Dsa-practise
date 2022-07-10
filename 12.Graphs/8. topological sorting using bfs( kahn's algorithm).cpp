#include<iostream>
#include<queue>
using namespace std;

class vertex{
	public:
	int data;
	vertex * next;
	vertex(int data){
		next = NULL;
		this->data = data;
	}
	
	~vertex(){
		
		while(this->next !=NULL){
			vertex * temp1 = this->next;
			this->next= this->next->next;
			delete temp1;
		}
	}
	
};

bool bfs(vertex ** g, int sv, int * indegree,queue <int> & q ){
		
		vertex * temp = g[sv];
	
		while(temp !=NULL){
			if(indegree[temp->data]!=0){
				indegree[temp->data]--;
	
				if(indegree[temp->data]==0){
					q.push(temp->data);		
				}	
				
			}
			temp = temp->next;
		}
}





void topology(vertex ** g, int n, int * indegree ){
	
	queue<int>q;
	
	
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}	
	}
	
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		
		cout<<temp<<" ";
		bfs(g,temp,indegree,q);
	}
	
	
}


vertex ** create_graph(int n, int e, int * indegree){
	vertex ** graph = new vertex*[n];
	for(int i=0;i<n;i++){
		graph[i]=NULL;
		indegree[i]=0;
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		indegree[v]++;
		vertex * newNode1 = new vertex(v);
//		vertex * newNode2 = new vertex(u);
		newNode1->next=graph[u];
//		newNode2->next=graph[v];
		graph[u]= newNode1;
//		graph[v]= newNode2;
	}
	
	return graph;	
}

void print_graph(vertex ** graph, int n){
	
	for (int i=0;i<n;i++){
		vertex * temp = graph[i];
		cout<<i<<":";
		while(temp!=NULL){
			cout<<temp->data;
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
	
	int * indegree = new int [n];
	vertex ** graph=create_graph(n,e, indegree);
	print_graph(graph,n);
	topology(graph,n, indegree);
	
	for(int i=0;i<n;i++){
		delete graph[i];
	}
	delete [] graph;
	delete [] indegree;
	return 0;
}
