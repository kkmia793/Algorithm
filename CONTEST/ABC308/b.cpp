#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<string> c(n);
    vector<string> d(m);
    for (int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i){
        cin >> d[i];
    }

    vector<int> p(m+1);
    for (int i = 0; i < m + 1; ++i){
        cin >> p[i];
    }    

    vector<int> price(n);

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(c[i] == d[j]){
                price[i] = p[j+1];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(price[i] == 0){
            price[i] = p[0];
        }
    }

    int sum = reduce(price.begin(), price.end());
    cout << sum << endl;

    return 0;
}