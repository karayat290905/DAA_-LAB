#include <iostream>
#include <unordered_set>
using namespace std;

void countPairs(int arr[], int n, int k)
{
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - k) != s.end())
        {
            count++;
        }
    }

    cout << "Number of pairs = " << count;
}

int main()
{
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    countPairs(arr, n, k);

    return 0;
}
