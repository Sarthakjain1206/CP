#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int w[n];
        Node *head, ptr;
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            if(i == 0){
                head = Node(data);
                ptr = head;
            }
            else{
                Node *node = Node(data);
                ptr->next = node;
            }
            w[i] = data;
        }
        // int l[n];
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            int dist;
            cin >> dist;
            map[w[i]] = dist;
        }
        Node *ptr = head;
        while(!ptr->next) {
            if(ptr->data > ptr->next->data){
                if(ptr == head) {
                    head = ptr->next;
                    Node *temp = ptr;
                    ptr = head;
                    temp->next = NULL;
                }
                else {
                    
                }
            }
        } 

        for (size_t i = 0; i < count; i++)
        {
            /* code */

        }
        
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