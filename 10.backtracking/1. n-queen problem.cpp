/*
N-Queen Problem
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such 
configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and 
are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. 
Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell.
Please note that in both the configurations, no pair of queens can kill each other. */

#include<bits/stdc++.h>
using namespace std;

void print(  int n , int ** arr){
    for (int i =0;i<n;i++){
        for(int j=0;j<n;j++){
         cout<<arr[i][j]<<" ";   
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void queen(int row, int ** board, int n ){
    int col =0;
    bool brek=false;
    while((col)<n){
    	
        // checking in rows
        brek=false;
    	
		for(int i=0;i<row;i++){
     	   if(board[i][col]==1){
     	   		brek=true;
     	   		break;
			}      
    	}
    	if(brek==true){
    		col++;
    		continue;	
		}
    	
    	
   		int i = row-1;
   		int j = col-1;
        //checking i -1 and j -1 diagonal(diagonal to the left)
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]==1){
            	brek=true;
				break;	
			}
             i--;
             j--;
        }
        
        if(brek==true){
    		col++;
    		continue;	
		}
		
        i = row-1;
        j = col+1;
        //checking i -1 and j +1 diagonal(diagonal to the right)
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i][j]==1){
            	brek=true;
				break;	
			}
			i--;
			j++;
        }
        
        if(brek==true){
    		col++;
    		continue;	
		}
        
        
        board[row][col]=1;
            
        if(row+1 < n)
        queen(row +1, board, n);
        else if(row == n-1){
        	print(n , board); 
		}
        board[row][col]=0;
        col++;
    }
    
    if(col==n)
    return ;
    
}

int main(){
    
    // write your code here
	int n;
    cin>>n;
    int ** board= new int*[n];
    for (int i =0;i<n;i++){
        *(board+i)=  new int[n]{0}; 
    }
       
    queen(0,board,n);
    
    for (int i =0;i<n;i++){
        delete []board[i]; 
        
    }
    delete [] board;
    return 0;
}
