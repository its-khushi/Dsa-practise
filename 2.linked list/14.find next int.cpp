#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int next (Node* head){
	int r;
	if(head->next==NULL){
		head->data+=1;
		return head->data/10;
	}
	
	int n = next(head->next);
	
	head->data= head->data+n;
	return head->data/10;
	
}

Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
     int n = next(head);
     if(head->data>=10){
     	Node* newNode = new  Node(head->data/10);
     	newNode->next= head;
     	head=newNode;
	 }
	 
	 Node * temp = head->next;
	 while(temp!=NULL){
	 	temp->data%=10;
	 	temp=temp->next;
	 }
     
    return head;
    
}


int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}


