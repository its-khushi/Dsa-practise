#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
	cout<<"enter no:"<<endl;
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cout<<nums[i]<<endl;
	}
	
	priority_queue<int,vector<int>, greater<int> > pq;
	
	for(int i=n-1;i>=0;i++){
		
		if(pq.empty() || pq.top()<nums.back()){
			pq.push(nums.back());
			nums.pop_back();
		}
		else{
			int temp = nums.back();
			nums.pop_back();
			cout<<pq.top()<<" ";
			nums.push_back(pq.top());
			pq.pop();
			cout<<temp<<" "<<nums[i]<<" ";
			nums.push_back(temp);
			while(!pq.empty())
			{
				cout<<pq.top()<<" ";
				nums.push_back(pq.top());
				pq.pop();
			}
			break;	
		}
		
		
	}
	
//	while(!pq.empty()){
//		if(nums.back()<pq.top()){
//			pq.push(nums.back());
//			nums.pop_back();
//			cout<<pq.top();
//		}else{
//			int temp = nums.back();
//			nums.pop_back();
//			nums.push_back(pq.top());
//			pq.pop();
//			pq.push(temp);
//			while(!pq.empty()){
//				nums.push_back(pq.top());
//				pq.pop();	
//			}
//		}
//	}
//	
	for(int i=0;i<n;i++){
		cout<<nums[i]<<endl;
	}
	
}
