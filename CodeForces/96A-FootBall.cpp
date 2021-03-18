// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string st;
    cin >> st;
    int zero = 0;
    int one = 0;
    bool dangerous = false;

    for (int i = 0; i < st.length(); i++)
    {
        /* code */
        if (st[i] == '0') {
            zero += 1;
            if(zero > 6) {
                dangerous = true;
                break;
            }
        }
        else if(st[i] != '0' and zero > 0){
            if(zero < 7)
                zero = 0;
            else{
                dangerous = true;
                break;
            }
        }
        
        if(st[i] == '1') {
            one += 1;
            if(one > 6) {
                dangerous = true;
                break;
            }
        }
        else if(st[i] != '1' and one > 0){
            if(one < 7)
                one = 0;
            else
                dangerous = true;
        }
    }
    if (dangerous)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
