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

bool bfs(vertex ** g, int n, int sv, int * visited){
	
	queue<pair<int,int> > q;
	pair <int,int> p;
	p.first= sv;
	p.second=-1;
	q.push(p);
	
	while(!q.empty()){
		pair <int, int> t = q.front();
		q.pop();
		visited[t.first]=true;
		vertex * temp= g[t.first];
		while(temp !=NULL){
			if(visited[temp->data]==true && temp->data !=t.second){
				return true;
			}
			p.first=temp->data;
			p.second=t.first;
			q.push(p);
			temp = temp->next;
		}
	}
	return false;
}

bool findCycle(vertex ** g, int n ){
	
	int * visited= new int [n];
	
	for(int i=0;i<n;i++){
		if(visited[i]!=true)
		if(bfs(g,n,i,visited)==true)
		return true;
	}
	
	delete [] visited;
	return false;
	
}

vertex ** create_graph(int n, int e){
	
	vertex ** graph = new vertex*[n];
	for(int i=0;i<n;i++){
		graph[i]=NULL;
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		vertex * newNode1 = new vertex(v);
		vertex * newNode2 = new vertex(u);
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
	
	vertex ** graph=create_graph(n,e);
	print_graph(graph,n);
	cout<<findCycle(graph,n);
	
	for(int i=0;i<n;i++){
		delete graph[i];
	}
	delete [] graph;
	
	return 0;
}
