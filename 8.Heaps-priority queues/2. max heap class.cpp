/*Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/

#include <iostream>
#include<vector>
using namespace std;

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    
    	void swap (int *a, int *b){
		int temp =*a;
        *a=*b;
        *b=temp;
	}
	
    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child = pq.size()-1;
        while (child >=0){
        	int parent = (child-1)/2;
        	if(pq[ parent]<pq[child]){
        		swap (& pq[ parent], &pq[child]);
        		child = parent ;
			}
			else
			break;
		}
        
    }

    int getMax() {
        // Implement the getMax() function here
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size()==0)
        return 0;
        else if(pq.size()==1){
        	int ans = pq[0];
        	pq.pop_back();
        	return ans;
		}
		
		int ans = pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();
		
		int lchild=1,rchild=2,parent=0,max=0;
		while (lchild<pq.size()){
			
			if(pq[lchild]>pq[parent]&& rchild<pq.size() && pq[rchild]>pq[parent] ){
				max = pq[lchild]>pq[rchild]?lchild:rchild;
			}else if(pq[lchild]>pq[parent]){
				max = lchild;
			}else if(rchild<pq.size() && pq[rchild]>pq[parent] ){
				max = rchild;
			}else {
				break;
			}
			
			swap(&pq[max],&pq[parent]);
            parent = max;
            lchild=parent*2+1;
            rchild=parent*2+2;
		}
		
		return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
