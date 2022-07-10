/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2*/

#include <iostream>
using namespace std;

void swap (int *a, int *b){
	int temp =*a;
    *a=*b;
	*b=temp;
}

void insert(int arr[], int n){
	
	int child = n,parent;
	while(child>0){
		parent = (child-1)/2;
		if(arr[parent]>arr[child]){
			swap(&arr[child],&arr[parent]);
			child=parent;
		}
		else{
			break;
		}
	}
}
inline int min (int arr[], int a, int b){
	if(arr[a]<arr[b])
	return a;
	else 
	return b;
}

void remove (int arr[], int size ){
	if(size==0)
		return ;
	
	swap(&arr[0],&arr[size]);
	size--;
	
	int lchild=1;
	int rchild=2;
	int parent=0;
	while(lchild<=size){
		if(arr[lchild]<arr[parent] && rchild<=size && arr[rchild]<arr[parent]){
			int index = min(arr,lchild,rchild);
			swap(&arr[index],&arr[parent]);
			parent = index;
		}else if(arr[lchild]<arr[parent]){
			swap(&arr[lchild],&arr[parent]);
			parent = lchild;
		}else if(rchild<=size && arr[rchild]<arr[parent]){
			swap(&arr[rchild],&arr[parent]);
			parent = rchild;	
		}else{
			return;
		}
		
		lchild=parent*2+1;
		rchild=parent*2+2;
	}
	
	return ;
}

void heapSort(int arr[], int n) {
    // Write your code   
    
    for (int i=1;i<n;i++){
    	insert(arr,i);
	}
	
	for(int i =n-1;i>=1;i--){
		remove (arr,i);
	}
    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
