#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int w[n];
        for (int i = 0; i < n; i++)
            cin >> w[i];
        map<int, pair<int, int>> map;
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            map[w[i]] = make_pair(temp, i);
        }
        int res = 0;
        int prevIndex;
        for (auto i = map.begin(); i != map.end(); i++)
        {
            // cout << i->first<< " ";
            // We do not have to move smallest element anywhere.
            if(i == map.begin())
                prevIndex = (i->second).second;
            else {
                int index = (i->second).second;
                while (prevIndex >= index) {
                    res++;
                    index += (i->second).first;
                }
                prevIndex = index;
            }
        }

        cout << res << endl;

    }
    return 0;
}


/*
2 1 4 3

1 4 3 2 (1) 
1 3 4 2 (1)
1 3 2 4 (1)
1 2 4 3 (1)
1 2 3 4 (1)
============

3 2 1

2 3 1 (2)
2 1 3 (2)
1 2 3 (2)
*/


        // while(i < n - 1){
        //     if(w[i] > w[i + 1]) {
        //         int jump = map[w[i]] - 1;
        //         if(jump == 0) {
        //             res += 2;
        //             swap(w[i], w[i + 1]);
        //         }
        //         else {
        //             res += 1;
        //             for (int j = i; j < jump && j < n - 1; j++)
        //                 swap(w[j], w[j + 1]);
        //         }
        //         i = 0;
        //     }
        //     else
        //         i++;
        // }
