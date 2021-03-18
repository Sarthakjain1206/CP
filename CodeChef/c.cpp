#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, unsolved = 0;
        bool bot = true, slow = false;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] == -1)
                unsolved += 1;
            if(arr[i] > 1)
                bot = false;
            if(arr[i] > k)
                slow = true;
        }
        // cout << "HEYYY: " <<unsolved << endl;
        if(unsolved > 0) {
            int solved = n - unsolved;
            if(solved < ceil(n/2.0))
                cout << "Rejected\n";
            else if(slow)
                cout << "Too Slow\n";
            else
                cout << "Accepted\n";
        }
        else if (bot)
            cout << "Bot" << endl;
        else if(slow)
            cout << "Too Slow\n";
        else
            cout << "Accepted\n";
    }
    return 0;
}
