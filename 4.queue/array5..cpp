#include<iostream>
# define MAX (int)10e6 
using namespace std;
int arr[MAX];
int main(){
	int l[5];
	for(int i=0;i<5;i++)
	cin>>l[i];
	int *a[5];
	int p=0;
	for (int i=0;i<5;i++){
		a[i]= new int [l[i]];
	
	for(int j=0;j<l[i];j++){
		cin>>a[i][j];
		int x=a[i][j];
		arr[x]++;
		if(arr[x]==3)
			p++;}	
		delete []a[i];
	}
	cout<<p<<endl;
	
}
