#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[100];
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 0; i < N - 2; i++) {
        if (A[i] == A[i + 1] && A[i] == A[i + 2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
