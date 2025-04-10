#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;

    bool all_same = (n[0] == n[1] && n[1] == n[2] && n[2] == n[3]);

    bool step = true;
    for (int i = 0; i < 3; ++i)
    {
        // stringを数値に
        int curr = n[i] - '0';
        int next = n[i + 1] - '0'; 

        // 隣接チェック 9→0もこれでいける
        if ((curr + 1) % 10 != next)
        {
            step = false;
            break;
        }
    }

    if (all_same || step)
    {
        cout << "Weak" << endl;
    }
    else
    {
        cout << "Strong" << endl;
    }

    return 0;
}
