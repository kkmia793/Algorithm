#include<iostream>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    int t = 0;
    int a = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'T'){
            t++;
        }else{
            a++;
        }

        if (t >= n / 2 || a >= n / 2) break;
    }

    string ans;

    ans = t > a ? "T" : "A";

    cout << ans << endl;
}