#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


class Deque {
    // Complete this class
    Node * head;
    Node* tail;
    int size;
    
    
    public:
    	Deque(int data){
    		size=0;
    		head=NULL;
    		tail=NULL;
		}
    void insertFront(int data){
    	if(size>10){
    		cout<<"-1"<<endl;
    		return ;
		}
    		size++;
    	Node * newNode = new Node(data);
    	if(head==NULL){
    		head=newNode;
    		tail=head;
		}
		newNode->next= head;
		head=newNode; 
	
	}
	
	void insertRear(int data){
		if(size>10){
			cout<<"-1"<<endl;
    		return ;
		}
		
		size++;
		
		Node * newNode = new Node(data);
		
		if(tail==NULL){
			tail=newNode;
			head=tail;
			return;
		}
		tail->next=newNode;
		tail=tail->next; 
	
		
	}
	
	void deleteFront(){
		if(size==0){
			cout<<-1<<endl;
			return ;
		}
		size--;
		Node * temp= head;
		head=head->next;
		if(tail==temp){
			tail=NULL;
		}
		delete temp;
		
	}
	
	void deleteRear(){
		if(size==0){
			cout<<-1<<endl;
			return ;
		}
		size--;
		
		Node * temp= head;
		if(temp->next==NULL)
		{
			tail=NULL;
			delete head;
			head=NULL;
			return;	
		}
		
		while((temp->next->next!=NULL))
		temp=temp->next;
		tail= temp;
		temp=temp->next;
		tail->next=NULL;
		delete temp;
	}
	int getFront(){
		if(size==0)
		return -1;
		else return head->data;	
	}
	
	int getRear(){
		if(size==0)
		return -1;
		else return tail->data;	
	}
    
};


// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}

