#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 1; i <= n; ++i)
    {
        int count = 0;
        for(int j = 1; j <= i; ++j)
        {
            if(n % j == 0)
            {
                count++;
            }
        }

        if(count == 8)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}