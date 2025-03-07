#include <iostream>

using namespace std;

int main()
{
    long long a,b;

    cin >> a >> b;

    long long attackcount = (a + b - 1) / b;

    cout << attackcount << endl;

    return 0;
}