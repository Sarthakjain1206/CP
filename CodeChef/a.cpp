#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y == z or x + z == y or z + y == x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
