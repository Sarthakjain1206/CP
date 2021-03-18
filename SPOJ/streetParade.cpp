// #include<bits/stdc++.h>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int t;
//     cin >> t;
//     while(t--){ 
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//             cin >> arr[i];
//         stack<int> st;
//         unordered_set<int> set;

//         for (int i = 0; i < n; i++)
//         {
            
//         }
        
//     }
//     int temp;
//     cin >> temp;

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    
    while(cin>>n and n != 0){
        int a[n];
        for(int i = 0; i < n; i++)cin>>a[i];
        int carToSearch = 0;
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() and s.top() == carToSearch+1){
                carToSearch++;
                s.pop();
            }
            if(a[i] != carToSearch+1)
                s.push(a[i]);
            else
                carToSearch++;
        }
        // cout << "CarToSearch: " << carToSearch << endl;
        while(!s.empty() && s.top() == carToSearch + 1){
            carToSearch++;
            s.pop();
        }
        if(carToSearch == n)
            cout << "yes\n";
        else
            cout << "no\n";
        // cout << (carToSearch == n) ? "yes" : "no";
    }
}
