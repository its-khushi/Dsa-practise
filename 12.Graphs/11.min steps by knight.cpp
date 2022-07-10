#include<iostream>
#include<limits.h>
using namespace std;
int solution(int n,int m,int sn,int sm,int en,int em,int ** visited){
		
	if(sn>n||sn<1||sm>m||sm<1 ){
		return -1;
	}
	if(visited[sn][sm]!=-2){
		return visited[sn][sm];
	}
	
	if(sn==en && sm==em){
		cout<<"returned"<<endl;
		return 0;	
	}
	
	
	visited[sn][sm]=-1;
	int x=INT_MAX;
	int a;
	cout<<sn<<" "<<sm<<endl;
	// down right
	a=solution(n,m,sn+1,sm+2,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// down left
	a=solution(n,m,sn-1,sm+2,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// right down
	a=solution(n,m,sn+2,sm-1,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	//right up
	a=solution(n,m,sn+2,sm+1,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// left down
	a=solution(n,m,sn-2,sm+1,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// left up
	a=solution(n,m,sn-2,sm-1,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// up right
	a=solution(n,m,sn+1,sm-2,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	// up left
	a=solution(n,m,sn-1,sm-2,en,em, visited);
	if(a<x && a!=-1)
	x=a;
	
	visited[sn][sm]= (x==INT_MAX?-1:x+1);
	return visited[sn][sm] ;
}



int sol (int n,int m,int sn,int sm,int en,int em){
	int ** visited = new int * [n+1];
	for(int i=0;i<=n;i++){
		visited[i]= new int [m+1];
		for(int j=0;j<=m;j++){
			visited[i][j]=-2;
		}
	}
	int s=solution(n,m,sn,sm,en,em, visited);
		
	for(int i=0;i<n;i++){
		delete [] visited[i];
	}
	delete [] visited;
	
	return s;
}



int main(){
	int n,m;
	cin>>n>>m;
	int sn,sm,en,em;
	cin>>sn>>sm>>en>>em;
	
	cout<<sol(n,m,sn,sm,en,em);	
	
}
