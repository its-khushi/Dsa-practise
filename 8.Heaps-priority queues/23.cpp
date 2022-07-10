#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int>v;
   int k=0;
    
    for(int i =0;i<input.size();i++){
     	 vector<int>*temp =input[i];
        for(int j=0;j<(temp)->size();j++){
            k++;
            v.push_back(temp->at(j));
        }
    }
    
  for(int i =0;i<k;i++)
     cout<<v[i]<<" ";
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
