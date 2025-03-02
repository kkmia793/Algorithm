#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> loc(N + 1);  

    vector<int> physicalOf(N + 1), inputOf(N + 1);
    for (int i = 1; i <= N; i++) {
        loc[i] = i;
        physicalOf[i] = i;
        inputOf[i] = i;
    }

    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;

            loc[a] = physicalOf[b];
        }
        else if(type == 2){
            int a, b;
            cin >> a >> b;

            int temp = physicalOf[a];
            physicalOf[a] = physicalOf[b];
            physicalOf[b] = temp;

            inputOf[physicalOf[a]] = a;
            inputOf[physicalOf[b]] = b;
        }
        else if(type == 3){
            int a;
            cin >> a;
            cout << inputOf[ loc[a] ] << "\n";
        }
    }
    return 0;
}