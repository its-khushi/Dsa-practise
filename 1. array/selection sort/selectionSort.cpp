#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// if we pass vector only then no change in the original copy hence pass by refrence to change the original vector

vector<int> selectionSort(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }

        swap(a[min], a[i]);
    }

    return a;
}

int main()
{

    vector<int> v(5);
    v[0] = 5;
    v[1] = 4;
    v[2] = 3;
    v[3] = 2;
    v[4] = 1;

    vector<int> a = selectionSort(v);

    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;

    return 0;
}
