/*Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
*/

#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }
		
	void swap (int *a, int *b){
		int temp =*a;
        *a=*b;
        *b=temp;
	}
    int removeMin() {
        // Write your code here
        if(pq.size()==0)
        return 0;
        else if(pq.size()==1){
        	pq.pop_back();
        	return pq[0];	
		}
        
        int n =pq.size()-1;
        int ret = pq[0];
        swap(&pq[0],&pq[n]);
        pq.pop_back();
        n--;
        int parent = 0;
        
        while(parent<=n){
        	
        	int lchild = parent*2+1;
			int rchild=parent*2+2;
			if(lchild<=n && pq[parent]>pq[lchild] &&  rchild<=n && pq[parent]>pq[rchild]){
				int m = pq[lchild]>pq[rchild]?rchild:lchild;
				swap(&pq[parent],&pq[m]);
				parent = m;
				continue;
			}
			else if( lchild<=n && pq[parent]>pq[lchild] ){
					swap(&pq[parent],&pq[lchild]);
					parent = lchild;
					continue;
			} else if( rchild<=n && pq[parent]>pq[rchild]){
					swap(&pq[parent],&pq[rchild]);
					parent = rchild;
					continue;
			}else{
				break;
			}
		}
		
        return ret;
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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
