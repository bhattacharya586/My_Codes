#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int *x = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < x[i])
            max = x[i];
    }
    int *fre = new int[max];
    for (int i = 0; i < n; i++)
    {
        fre[x[i]]++;
    }
    int f = 0;
    for (int i = 0; i < max; i++)
    {
        if (fre[i] > 1)
        {
            cout << "Exist";
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Not Exist";
    }
    return 0;
}