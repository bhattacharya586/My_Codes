#include <iostream>
using namespace std;
void quicksort(int *x, int left, int right);
int partition(int *x, int left, int right);
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
    int flag = 0;
    quicksort(x, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        if (x[i] == x[j])
        {
            flag = 1;
            cout << "Exist";
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not Exist";
    }
    return 0;
}
void quicksort(int *x, int left, int right)
{
    if (left <= right)
    {
        int p = partition(x, left, right);
        quicksort(x, left, p - 1);
        quicksort(x, p + 1, right);
    }
}
int partition(int *x, int left, int right)
{
    int i = left - 1, j = left, pvt = x[right];
    while (j <= right)
    {
        if (pvt >= x[j])
        {
            i++;
            swap(x[i], x[j]);
        }
        j++;
    }
    return i;
}