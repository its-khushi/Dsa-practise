// array watching 
#include<stdio>
#include<algorithm>

int main(){
	int t;
	int n,l,p;
	scanf("%d",&t);
	while(t--){
		
			scanf("%d%d",&n,&l);
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int m=0;
		for (int i=0;i<n;i++){
			int t=1, x=a[i]+l;
			for(int j=i+1;j<n;j++){
				if(a[j]>x)
				break;
				t++;
			}
			m=max(t,m);
			if(m==t)
			p=i;
		}
		printf("%d %d\n",m,a[p]);	
	}
	return 0;
}
