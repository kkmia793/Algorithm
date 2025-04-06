#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    int prev;
    int next;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = (int)S.size();

    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].c = S[i];
        nodes[i].prev = i - 1;
        nodes[i].next = i + 1;
    }
    nodes[0].prev = -1;
    nodes[n - 1].next = -1;

    int head = 0;

    for (int p = head; p != -1;) {
        int nx = nodes[p].next;

        if (nx != -1 && nodes[p].c == 'W' && nodes[nx].c == 'A') {
            nodes[p].c = 'A';
            nodes[nx].c = 'C';

            int pp = nodes[p].prev;
            p = (pp != -1) ? pp : nx;
        } else {
            p = nx;
        }
    }

    string ans;
    int cur = head;
    while (cur != -1) {
        ans.push_back(nodes[cur].c);
        cur = nodes[cur].next;
    }

    cout << ans << "\n";
    return 0;
}