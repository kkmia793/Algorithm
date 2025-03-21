#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <array>
#include <queue>
#include <climits>

using namespace std;

vector<string> create_solution(long long step, long long q, vector<long long> n, vector<long long> s, vector<long long> a, vector<long long> t, vector<long long> b) {
 const int INF = INT_MAX;

    auto win = [&](long long A, int S, long long B, int T) -> bool {
        long long ueffective = ( ((S % 3) + 1) == T ? A * 2 : A );
        long long reffective = ( ((T % 3) + 1) == S ? B * 2 : B );
        return ueffective > reffective;
    };

    struct BipGraph {
        int L, R;
        vector<vector<int>> adj;
        vector<int> pairL, pairR, dist;

        BipGraph(int L, int R) : L(L), R(R) {
            adj.resize(L);
            pairL.assign(L, -1);
            pairR.assign(R, -1);
            dist.assign(L, 0);
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
        }

        bool bfs() {
            queue<int> q;
            for (int u = 0; u < L; u++) {
                if (pairL[u] == -1) {
                    dist[u] = 0;
                    q.push(u);
                } else {
                    dist[u] = INF;
                }
            }
            int distance = INF;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] < distance) {
                    for (int v : adj[u]) {
                        if (pairR[v] == -1) {
                            distance = dist[u] + 1;
                        } else if (dist[pairR[v]] == INF) {
                            dist[pairR[v]] = dist[u] + 1;
                            q.push(pairR[v]);
                        }
                    }
                }
            }
            return distance != INF;
        }

        bool dfsHK(int u) {
            if (u != -1) {
                for (int v : adj[u]) {
                    int pu = pairR[v];
                    if (pu == -1 || (dist[pu] == dist[u] + 1 && dfsHK(pu))) {
                        pairL[u] = v;
                        pairR[v] = u;
                        return true;
                    }
                }
                dist[u] = INF;
                return false;
            }
            return true;
        }

        int maxMatching() {
            int matching = 0;
            while (bfs()) {
                for (int u = 0; u < L; u++) {
                    if (pairL[u] == -1 && dfsHK(u))
                        matching++;
                }
            }
            return matching;
        }
    };

    vector<string> results;
    results.reserve(q);

    long long offsetS = 0, offsetA = 0, offsetT = 0, offsetB = 0;
    for (int qi = 0; qi < q; qi++) {
        int cnt = n[qi];
        vector<int> userType(cnt), rivalType(cnt);
        vector<long long> userA(cnt), rivalB(cnt);
        for (int i = 0; i < cnt; i++) {
            userType[i] = (int)s[offsetS + i];
            userA[i] = a[offsetA + i];
        }
        for (int i = 0; i < cnt; i++) {
            rivalType[i] = (int)t[offsetT + i];
            rivalB[i] = b[offsetB + i];
        }
        offsetS += cnt;
        offsetA += cnt;
        offsetT += cnt;
        offsetB += cnt;

        bool valid = true;
        if (step == 1 || step == 4) {
            for (int i = 0; i < cnt; i++) {
                if (userType[i] < 1 || userType[i] > 3 || rivalType[i] < 1 || rivalType[i] > 3)
                    valid = false;
            }
        } else if (step == 2) {
            for (int i = 0; i < cnt; i++) {
                if (userType[i] < 1 || userType[i] > 2 || rivalType[i] < 1 || rivalType[i] > 2)
                    valid = false;
            }
        } else if (step == 3) {
            for (int i = 0; i < cnt; i++) {
                if (rivalType[i] < 2 || rivalType[i] > 3)
                    valid = false;
            }
        }

        if (!valid) {
            results.push_back("no");
            continue;
        }

        BipGraph graph(cnt, cnt);
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                if (win(userA[i], userType[i], rivalB[j], rivalType[j]))
                    graph.addEdge(i, j);
            }
        }

        int matching = graph.maxMatching();
        results.push_back(matching == cnt ? "yes" : "no");
    }

    return results;
}