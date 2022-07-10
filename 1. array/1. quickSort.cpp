#include<iostream>
using namespace std;

int partition(int * arr, int lb, int ub){
	
	int p=ub;
	int s=lb;
	int end=ub;
	
	while(s<end){
		
			while(s<=ub && arr[s]<arr[p]){
				s++;

			}
			while(end>=lb && arr[end]>=arr[p]){
				end--;
			}
			
			if(s<end){
				int temp=arr[end];
				arr[end]=arr[s];
				arr[s]=temp;
			}
	}
	
	
	int temp=arr[s];
	arr[s]=arr[p];
	arr[p]=temp;

	return s;
}

void quickSort(int * arr, int lb, int ub){
	
	if(lb<ub){
	
		int part= partition(arr,lb,ub);
		quickSort(arr,lb,part-1);
		quickSort(arr,part+1,ub);
		
	}

}

int main(){
	int arr[]={3, 2 ,1,4,6,5,10,7,9,5};
	quickSort(arr,0,9);
	for(int i =0;i<10;i++){
		cout<<arr[i]<<" "<<endl;
	}
}
