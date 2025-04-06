#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> s(1000);
    bool up = true;

    for(int i = 1; i < 9; ++i)
    {
        cin >> s[i];
    }

    s[0] = 0;

    for(int i = 1; i < 9; ++i)
    {
        if((s[i] - s[i-1]) < 0 || s[i] < 100 || s[i] > 675 || s[i] % 5 != 0) 
        {
            up = false;
            break;
        }
    }

    if(up)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}

