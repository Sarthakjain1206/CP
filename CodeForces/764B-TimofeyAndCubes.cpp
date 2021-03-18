#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = n - 1;
    while (i < j) {
        if (i%2 == 0)
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
