#include <iostream>
using namespace std;

int* stockSpan(int *price, int size)  {
	// Write your code here
    int * output= new int [size];
    
    for( int i=0;i<size;i++){
    	int s=1;
		int j=i-1;
    	while((j>=0)){
    		if(price[j]>=price[i])
    		break;
    		s++;
    		j--;
		}
		
		output[i]=s;
	}
    
    return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
