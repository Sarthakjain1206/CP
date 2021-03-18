#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        int s;
        cin >> s;
        int intro[s];
        for (int i = 0; i < s; i++)
            cin >> intro[i];
        long totalTime = 0;

        for (int i = 0; i < s; i++) {
            int e;
            cin >> e;
            long sum = 0;
            for (int j = 0; j < e; j++)
            {
                int temp;
                cin >> temp;
                if(j != 0){
                    temp - intro[i] > 0 ? sum += temp - intro[i] : sum += 0;
                }
                else
                    sum += temp;
            }
            totalTime += sum;
        }
        cout << totalTime << endl;
    }
    return 0;
}
