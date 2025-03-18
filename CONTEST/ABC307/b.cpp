#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const string& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                string combined = S[i] + S[j];
                if (isPalindrome(combined)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
