#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> f;
    Fenwick(int n) : n(n), f(n + 1, 0) {}
    
    void update(int i, long long v) {
        for (; i <= n; i += (i & -i)) f[i] += v;
    }
    
    long long sum(int i) {
        long long s = 0;
        for (; i > 0; i -= (i & -i)) s += f[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<long long> freq(M, 0), sumIdx(M, 0);
    for (int i = 0; i < N; i++) {
        freq[A[i]]++;
        sumIdx[A[i]] += (i + 1);
    }
    
    Fenwick fw(M);
    long long inv0 = 0;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        long long c = fw.sum(M) - fw.sum(x + 1);
        inv0 += c;
        fw.update(x + 1, 1);
    }
    
    cout << inv0 << "\n";
    long long cur = inv0;
    for (int k = 0; k < M - 1; k++) {
        int x = (M - 1 - k + M) % M;
        long long r = freq[x], s = sumIdx[x];
        long long d = 2LL * s - r * (long long)(N + 1);
        long long nxt = cur + d;
        cout << nxt << "\n";
        cur = nxt;
    }
    
    return 0;
}
