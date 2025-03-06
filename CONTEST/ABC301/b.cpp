#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> result;

    for(int i = 0; i < n - 1; ++i){
        result.push_back(a[i]);

        if(abs(a[i] - a[i+1]) != 1){
            if(a[i] < a[i+1]){
                for(int j = a[i] + 1; j < a[i+1]; ++j){
                    result.push_back(j);
                }
            } else {
                for(int j = a[i] - 1; j > a[i+1]; --j){
                    result.push_back(j);
                }
            }
        }
    }

    result.push_back(a[n-1]);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
