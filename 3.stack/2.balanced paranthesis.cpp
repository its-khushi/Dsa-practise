/*
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding 
closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
class Stack {
	Node* head;
	Node* tail;
   public:
    Stack() {
        head=NULL;
        tail=NULL;
    }

    bool isEmpty() {
        return head==NULL;
    }

    void push(int element) {
        Node* newNode = new Node(element);
        if(head==NULL){
        	head=newNode;
        	tail=newNode;
		}
		else
		{
			tail->next= newNode;
			tail=tail->next;
		}
		
	}

    int pop() {
        if(head==NULL)
        return -1;
        
        if(head->next== NULL){
        	int x = head->data;
        	delete head ;
        	head = NULL;
        	tail=NULL;
        	return x;
		}
        
        Node * temp= head;
        while((temp != NULL)&& (temp->next != NULL) && (temp->next->next != NULL)){
        	temp=temp->next;
		}
		
		Node * del= temp->next;
		temp->next= NULL;
		tail=temp;
		int x = del->data;
		delete del;
		return x;
    }

};


bool isBalanced(string expression) 
{
	Stack s;
	int n = expression.length();
	for ( int i=0; i < n ; i++){
		
		if((expression[i]=='{')|| (expression[i]=='[')||(expression[i]=='(')){
		s.push(expression[i]);
		}
		else if((expression[i]=='}')|| (expression[i]==']')||(expression[i]==')')){
			char c = s.pop();
			if(c=='{'&&  expression[i]!='}')
			return false;
			else if(c=='('&&  expression[i]!=')')
			return false;
			else if(c=='['&&  expression[i]!=']')
			return false;
		}
		
	}
	
	if(s.isEmpty())
	return true;
	else return false;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
