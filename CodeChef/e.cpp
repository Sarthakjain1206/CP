#include <bits/stdc++.h>
using namespace std;
int lis(string arr, int n)
{
    int *lis, i, j, max = 0;
    lis = (int *)malloc(sizeof(int) * n);

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++)
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // cout << "LIS: " << lis(s, n) << endl;
        cout << n - lis(s, n) << endl;
    }
    return 0;
}
