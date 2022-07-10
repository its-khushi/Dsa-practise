#include<iostream>
#include<math.h>
using namespace std;



int main(){
	int t;
	cin>>t;
	while(t--){
		long long int  num;
		long long int mod = 10e8+7;
		cin>>num;
		
		if(num==2){
		cout<<num<<endl;
		continue;	
		}
		
		if((num&(num-1))==0){
			cout<<(2*num-1)%(mod)<<endl;
		}else {
			long long  bit = log2(num);
			long long int ans = pow(2,bit+1);
			cout<<ans%(mod)<<endl;
		}
	}
}
