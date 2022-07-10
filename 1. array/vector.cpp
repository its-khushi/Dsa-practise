#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	vector <int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	
	vector<int>:: iterator it=v.begin();
	v.erase(it);
	cout<<*it<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}
