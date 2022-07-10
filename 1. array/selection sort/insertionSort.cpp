#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v)
{

    int n = v.size();

    for (int i = 1; i < n; i++)
    {

        int j = i - 1;
        int temp = v[i];
        while (v[j] > temp && j >= 0)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }
}

int main()
{
    vector<int> v(5);
    v[0] = 5;
    v[1] = 4;
    v[2] = 3;
    v[3] = 2;
    v[4] = 1;

    insertionSort(v);

    for (int i = 0; i < 5; i++)
        cout << v[i] << endl;

    return 0;
}