#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		char str[n];
		for (int i=0;i<n;i++)
		cin>>str[i];
		
		int c=min((n-d),d);
		for(int i=0;i<n-1;i++)
				if(str[i]!=str[i+1])
				
				if(i<c)
				sum+=(i+1);
				else if(n-i-1<c)
				sum+=(n-i-1);
				else
				sum+=c;
			cout<<sum<<endl;
	}
	return 0;
}
