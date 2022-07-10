#include <algorithm>
#include<iostream>
using namespace std;
int main() {
        int t;
        cin>>t;
        while(t--){
            int n,p,k;
            cin>>n>>p>>k;
            int s[n] ;
            for (int i = 0; i < n; i++) 
                cin>>s[i];
            sort(s,s+n);
            int l=n/p;
            int r= n%p;
            if(r>k||l==0){
                cout<<"NO\n";
                break;
            }else{
            	int i;
				for(i=p-1;i<n-i-1;i=i+p)
				if(s[i]=s[i+1]){
					cout<<"NO\n";
					break;
				}
				if(i==n-r-1)
				cout<<"YES\n";	
            }
			}
			return 0;
	}
