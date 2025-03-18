#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(7 * N);
    
    for (int i = 0; i < 7 * N; i++) {
        cin >> A[i];
    }

    vector<int> B(N, 0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 7; j++) {
            B[i] += A[i * 7 + j];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << B[i] << (i == N - 1 ? '\n' : ' ');
    }

    return 0;
}
