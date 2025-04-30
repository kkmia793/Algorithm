#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin>>N)) return 0;
    const int INF = 1000000000;
    vector<int> l(N+1, INF);
    vector<string> e(N+1);
    vector<char> p(N+1), o(N+1);
    for(int i=1; i<=N; i++){
        string t = to_string(i);
        if(t.find_first_not_of('1') == string::npos){
            l[i] = t.size();
            e[i] = t;
            p[i] = o[i] = 0;
        }
        for(int j=1; j<i; j++){
            int k = i - j;
            if(l[j] == INF || l[k] == INF) continue;
            int w = p[k] ? 2 : 0;
            int c = l[j] + 1 + l[k] + w;
            if(c < l[i]){
                string sk = e[k];
                if(p[k]) sk = "(" + sk + ")";
                e[i] = e[j] + "+" + sk;
                l[i] = c;
                o[i] = p[i] = 1;
            }
        }
        for(int a=2; a*a<=i; a++){
            if(i % a == 0){
                int b = i / a;
                if(l[a] != INF && l[b] != INF){
                    int wa = o[a] ? 2 : 0;
                    int wb = o[b] ? 2 : 0;
                    int c = l[a] + wa + 1 + l[b] + wb;
                    if(c < l[i]){
                        string sa = e[a];
                        if(o[a]) sa = "(" + sa + ")";
                        string sb = e[b];
                        if(o[b]) sb = "(" + sb + ")";
                        e[i] = sa + "*" + sb;
                        l[i] = c;
                        o[i] = 1;
                        p[i] = 0;
                    }
                }
            }
        }
    }
    cout << e[N];
    return 0;
}
