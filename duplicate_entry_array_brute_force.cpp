#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int f = 0;
    int n;
    cin >> n;
    int *x = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] == x[j])
            {
                cout << "Exist";
                f = 1;
                break;
            }
        }
        if (f == 1)
        {
            break;
        }
    }
    if (f == 0)
    {
        cout << "Not Exist";
    }
    return 0;
}