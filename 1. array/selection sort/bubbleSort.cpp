#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &a)
{

    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
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

    bubbleSort(v);

    for (int i = 0; i < 5; i++)
        cout << v[i] << endl;

    return 0;
}