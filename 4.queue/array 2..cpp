#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	int team[n];
	
	for(int i=0;i<n;i++){
		cin>>team[i];
	}
	
	sort(team,team+n);
	int end=0,start=0,len=0;
	while(end<n){
		if(team[end]-team[start]<=5)
		end++;
		else 
		start++;
		
		if(end-start>len)
		len=end-start;
	}
	cout<<len<<endl;
	return 0;
}
