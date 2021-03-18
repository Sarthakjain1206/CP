#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool flag = false;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if(s[i] == '1' && !flag) {
                flag = !flag;
                ans++;
            }
            else if(s[i] == '0')
                flag = false;
        }
        cout << ans << endl;
    }
    return 0;
}
