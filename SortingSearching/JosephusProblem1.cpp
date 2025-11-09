#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
};

Node *insertAtEnd(Node *head, Node *lastNode, Node *newNode) {
    lastNode->next = newNode;
    newNode->next = head;
    return newNode;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if(n==1) {
        cout << 1 << '\n';
        return 0;
    }
    Node *head = new Node(1, nullptr);
    Node *lastNode = head;
    for(int i=2;i<=n;i++) {
        lastNode = insertAtEnd(head, lastNode, new Node(i, nullptr));
    }
    Node *curr = head;
    for(int i=0;i<n;i++) {
        cout << curr->next->value << ' ';
        curr->next = curr->next->next;
        curr = curr->next;
    }
    cout << '\n';
    return 0;
}