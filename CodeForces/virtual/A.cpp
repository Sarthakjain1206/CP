#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n;i++)
        cin >> arr[i];
    int count = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i+=3) {
        int a = (i < n) ? arr[i] + k: -1;
        int b = (i+1 < n) ? arr[i+1] + k : -1;
        int c = (i+2 < n) ? arr[i+2] + k: -1;
        if(a == -1 || b == -1 || c == -1)
            break;
        if(a < 6 and b < 6 and c < 6)
            count += 1;
        
        // if( arr[i + 1] arr[i + 2])
    }
    cout << count;
    return 0;
}