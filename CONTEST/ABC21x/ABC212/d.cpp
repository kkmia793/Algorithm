#include <iostream>
#include <queue>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long offset = 0;  // 操作2 の累積加算値
    vector<long long> result;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            long long x;
            cin >> x;
            pq.push(x - offset);  // offsetを引いて格納
        } else if (type == 2) {
            long long x;
            cin >> x;
            offset += x;  // 全体に加算
        } else if (type == 3) {
            long long x = pq.top(); pq.pop();
            result.push_back(x + offset);  // offsetを戻して記録
        }
    }

    for (long long x : result) {
        cout << x << '\n';
    }

    return 0;
}
