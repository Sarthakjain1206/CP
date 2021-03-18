#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, h, x;
    cin >> n >> h >> x;

    int arr[n];
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    if(x + maxVal >= h)
        cout << "YES";
    else
        cout << "NO";
        return 0;
}
