#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> a(h), b(h);

    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < h; ++i) {
        cin >> b[i];
    }

    for (int s = 0; s < h; ++s) {
        for (int t = 0; t < w; ++t) {
            bool match = true;

            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (a[(i + s) % h][(j + t) % w] != b[i][j]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }

            if (match) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
