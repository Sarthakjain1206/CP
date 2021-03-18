#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while (t--)
    {
        int n, tot_even = 0, tot_odd = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0)
                tot_even += 1;
            else
                tot_odd += 1;
        }
        cout << min(tot_even, tot_odd) << endl;
    }
    return 0;
}
