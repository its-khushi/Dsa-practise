# include<bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n)
{
	int z=0;
    for (int i=0;i<n-1;i++){
    	if(arr[i]!=arr[i+1])
    	{
    		z++;
		}
	}
    	return z;
}
 

int main(){
	int t=0;
	cin>>t;
	while(t--){
		
		int l;
		cin>>l;
		int arr[l];
		for( int i=0;i<l;i++){
			cin>>arr[i];
		}
		
		int * max = max_element(arr, arr + l);
		
		if(countDistinct(arr,l)==0)
		cout<<"0"<<endl;
		else if((*max)==arr[l-1])
		cout<<"1"<<endl;
		else cout<<"2"<<endl;
		
	}
	return 0;
}
