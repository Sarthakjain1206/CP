#include <bits/stdc++.h>
using namespace std;

bool comparator(int a, int b) {
    return a > b;
}

int main(int argc, char const *argv[])
{
    int n, count = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the array..
    sort(arr, arr + n, comparator);
    // Make prefix sum array
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    // Validate
    for (int i = 0; i < n; i++) {
        if(arr[i] <= arr[n-1] - arr[i])
            count++;
        else
            break;
    }

    cout << count + 1;
    return 0;
}
