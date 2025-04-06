#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 水色なのであとで
int main() {
    int HA, WA;
    cin >> HA >> WA;
    vector<string> A(HA);
    for (int i = 0; i < HA; i++) {
        cin >> A[i];
    }

    int HB, WB;
    cin >> HB >> WB;
    vector<string> B(HB);
    for (int i = 0; i < HB; i++) {
        cin >> B[i];
    }

    int HX, WX;
    cin >> HX >> WX;
    vector<string> X(HX);
    for (int i = 0; i < HX; i++) {
        cin >> X[i];
    }


}
