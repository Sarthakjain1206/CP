#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int d, c;
        cin >> d >> c;

        int day1[3], day2[3];
        cin >> day1[0] >> day1[1] >> day1[2];
        cin >> day2[0] >> day2[1] >> day2[2];

        int day1Cost = day1[0] + day1[1] + day1[2];
        int day2Cost = day2[0] + day2[1] + day2[2];
        int couponCost = day1Cost + day2Cost + c;

        if(day1Cost >= 150 && day2Cost >= 150) {
            if(day1Cost + day2Cost + 2*d > couponCost)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if(day1Cost < 150 && day2Cost < 150) {
            cout << "NO\n";
        }
        else {
            if(day1Cost + day2Cost + c + d < day1Cost + day2Cost + 2*d)
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }

    return 0;
}
