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
        long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                tot_even += 1;
            else
                tot_odd += 1;
        }
        if(tot_odd % 2 == 0) {
            tot_even += 1;
            tot_odd = 0;
        }
        else{
            tot_even += tot_odd / 2;
            tot_odd = 1;
        }

        if(tot_odd == 1) {
            if(tot_even > 0)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        } 
        else
            cout << 1 << endl;
    }
    return 0;
}
