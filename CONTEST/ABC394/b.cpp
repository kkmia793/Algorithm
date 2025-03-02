#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> words(N);
    
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    string result;
    for (const string &word : words) {
        result += word;
    }
    
    cout << result << endl;
    
    return 0;
}