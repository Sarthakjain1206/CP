#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        int s;
        cin >> s;
        vector<long> positiveArr;
        vector<long> negativeArr;
        long maxAns = LONG_MIN;

        // long positiveArr[s];
        // long positiveArr[s];
        int zero = 0;
        for (int i = 0; i < s; i++){
            long temp;
            cin >> temp;
            if(temp < 0)
                negativeArr.push_back(temp);
            else if(temp > 0)
                positiveArr.push_back(temp);
            else
                zero = 1;
        }
        long minNegative = 0;
        long maxPositive = 0;

        for (int i = 0; i < negativeArr.size(); i++) {
            for (int j = i + 1; j < negativeArr.size(); j++){
                int a = negativeArr[i];
                int b = negativeArr[j];

                long ans = max(a * b + (a - b), a * b + (b - a));
                maxAns = max(maxAns, ans);
            }
            minNegative = min(minNegative, negativeArr[i]);
        }
        for (int i = 0; i < positiveArr.size(); i++) {
            for (int j = i + 1; j < positiveArr.size(); j++){
                int a = positiveArr[i];
                int b = positiveArr[j];

                long ans = max(a * b + (a - b), a * b + (b - a));
                maxAns = max(maxAns, ans);
            }
            maxPositive = min(maxPositive, positiveArr[i]);
        }
        if(zero == 1 and negativeArr.size()!=0 and positiveArr.size() != 0) {
            maxAns = max(maxAns, max(abs(minNegative), maxPositive));
        }
        cout << maxAns << endl;
        // sort(negativeArr.begin(), negativeArr.end());
        // sort(positiveArr.begin(), positiveArr.end());

        // if(negativeArr.size() >= 2) {
        //     int a = negativeArr[0];
        //     int b = negativeArr[1];
        //     long ans = max(a * b + (a - b), a * b + (b - a));
        //     maxAns = max(ans, maxAns);
        // }
        // if(positiveArr.size() >= 2) {
        //     int a = positiveArr[positiveArr.size() - 1];
        //     int b = positiveArr[positiveArr.size() - 2];
        //     long ans = max(a * b + (a - b), a * b + (b - a));
        //     maxAns = max(ans, maxAns);
        // }
        // if(zero == 1 and negativeArr.size()!=0 and positiveArr.size() != 0) {
        //     maxAns = max(maxAns, max(abs(negativeArr[0]), positiveArr[positiveArr.size() - 1]));
        // }
        // if(negativeArr.size() == 1 and positiveArr.size() == 1) {
        //     int a = negativeArr[0];
        //     int b = positiveArr[0];
        //     long ans = max(a * b + (a - b), a * b + (b - a));
        //     maxAns = max(ans, maxAns);            
        // }
        cout << maxAns << endl;
        // long maxAns = LONG_MIN;

        // for (int i = 0; i < s-1; i++) {
        //     for (int j = i + 1; j < s;j++){
        //         int a = arr[i];
        //         int b = arr[j];
        //         long ans = max(a * b + (a - b), a * b + (b - 1));
        //         maxAns = max(maxAns, ans);
        //     }
        // }
        // cout << maxAns << endl;
        
        // sort(arr, arr + s);

        // int first = 0;
        // int last = 1;
        // long maxAns = LONG_MIN;

        // while(last < s and first < s) {
            // int a = arr[i];
            // int b = arr[j];
            // long ans = max(a * b + (a - b), a * b + (b - a));
        //     if(ans >= maxAns) {
        //         maxAns = ans;
        //         last++;
        //     }
        //     else {
        //         first++;
        //     }
        // }
        // cout << maxAns << endl;
        // int a = arr[0];
        // int b = arr[1];
        // long ans = max(a * b + (a - b), a * b + (b - a));
        // maxAns = max(ans, maxAns);
        
        // a = arr[s-1];
        // b = arr[s-2];
        // ans = max(a * b + (a - b), a * b + (b - a));
        // maxAns = max(ans, maxAns);

        

        // // if(arr[0] < 0 && arr[1] < 0) {
        // // }
        // // else if(arr[0] >= 0) {
        // // }
        // int index = upper_bound(arr, arr+s, -1) - arr;
        // if(index < s && index > 0) {
        //     a = arr[index];
        //     b = arr[index - 1];
        //     ans = max(a * b + (a - b), a * b + (b - a));
        //     maxAns = max(ans, maxAns);
        // }
        // cout << maxAns << endl;
    }
    return 0;
}
