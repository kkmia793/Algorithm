#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    set<char> atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    map<char, int> s_count, t_count;

    for (char c : S) s_count[c]++;
    for (char c : T) t_count[c]++;

    int s_at = s_count['@'];
    int t_at = t_count['@'];

    for (char c = 'a'; c <= 'z'; ++c) {
        if (c == '@') continue;

        if (s_count[c] < t_count[c]) {
            int need = t_count[c] - s_count[c];
            if (atcoder.count(c) && s_at >= need) {
                s_at -= need;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }

        if (t_count[c] < s_count[c]) {
            int need = s_count[c] - t_count[c];
            if (atcoder.count(c) && t_at >= need) {
                t_at -= need;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
