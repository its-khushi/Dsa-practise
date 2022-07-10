#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+1]={0};
	int sum=0;
	for(int i=1;i<=n;i++){
	cin>>arr[i];
	arr[i]+=sum;
	sum=arr[i];
	cout<<arr[i];	
	}
	
	
	int x;
	cin>>x;
	int tasty[x];
	
	for(int i=0;i<x;i++)
	cin>>tasty[i];
	
	for(int i=0;i<x;i++){
		for(int j=0;j<n;j++){
		if((tasty[i]>=arr[j])&&(tasty[i]<=arr[j+1])){
			cout<<(j+1)<<endl;
			cout<<tasty[i]<<" "<<arr[j]<<" "<<arr[j+1]<<endl;
			break;	
		}
		}
	}
	
	return 0;
	
}
