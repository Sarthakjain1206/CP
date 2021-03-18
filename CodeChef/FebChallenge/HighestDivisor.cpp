#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 10; i > 0; i--) {
        if(n % i == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}
