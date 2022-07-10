#include<iostream>
#include<vector>
#include<list>
using namespace std;

class node {
	
	public:
	int data;
	node* next; 
	node (int data){
		this->data=data;
		this->next=NULL;
	}
};

void printGraph(int v,node ** graph){
	
	for(int i=0;i<v;i++){
		
		node * temp;
		if(graph[i]==NULL){
			cout<<"null found at "<<i+1<<endl;
			continue;	
		}
		
		
		temp = graph[i];
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		
		cout<<endl;
	}
	
} 

node ** makeGraph(int v, int e){
	
	node ** graph= new node*[v];
	for(int i=0;i<v;i++){
		graph[i]=NULL;
	} 
	
	for (int i=0;i<v;i++){
		int a,b;
		cin>>a>>b;
		
		node* newNode = new node(b); 
		if(graph[a]==NULL){	
			graph[a]=newNode;
		}else {
			node * temp = graph[a];
			while(temp->next !=NULL){
				temp = temp->next;
			}
			temp->next= newNode;
		}
		
	}
	
//	printGraph(v,graph);
	return graph;
}


/*Love Babbar
Nishant Chahar
Striver
Siddharth Singh
Mohammad Fraz*/
void dfs(node ** g, int sv ,bool * visited, vector <int> &v ){
	
	if(visited[sv]==true){
		return ;
	}
	visited[sv]=true;
	if(g[sv]==NULL){
		v.push_back(sv);
		return;
	}
	
	node * temp ;
	temp = g[sv];
		while(temp != NULL){
			dfs(g,temp->data,visited,v);
			temp = temp->next;
		}
	
		v.push_back(sv);
	
}


void topologicalOrder(int v, node** g){
	bool * visited= new bool[v];
	vector <int> vec;
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	
	
	for(int i=0;i<v;i++){
	
		if(visited[i]==true){
			continue;	
		}
		
		
		visited[i]=true;
		
		if(g[i]==NULL ){
			vec.push_back(i);
			continue;
		}

		node * temp ;
		temp = g[i];
		while(temp != NULL){
			dfs(g,temp->data,visited,vec);
			temp = temp->next;
		}
		vec.push_back(i);	
	}
	
	cout<<"order: ";
	for(int i=vec.size()-1; i>=0;i--){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	delete [] visited;
}


int main(){
	
	int v,e;
	cin>>v>>e;
	
	node ** graph= makeGraph(v,e);
	topologicalOrder(v,graph);
	return 0;
}
