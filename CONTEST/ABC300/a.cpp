#include<iostream>
#include <vector>

using namespace std;

int main()
{
    int n,a,b;

    cin >> n >> a >> b;

    vector<int> c(n+1);

    for(int i = 1; i < n+1; ++i)
    {
        cin >> c[i];
    }

    int ans = 0;

    for(int i = 1; i < n+1; ++i)
    {
        if(c[i] == a + b)
        {
             ans = i;
             break;
        }
    }

    cout << ans << endl;

    return 0;
}