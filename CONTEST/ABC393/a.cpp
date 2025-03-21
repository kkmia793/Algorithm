/*
4種類の牡蠣 1, 2, 3, 4 があります。このうち ちょうど1種類 の牡蠣を食べると お腹を壊す ことが分かっています。他の牡蠣は食べてもお腹を壊しません。

高橋君と青木君が食べた牡蠣と、それによる体調の情報が以下のように与えられます。
	•	高橋君: 牡蠣 1, 2 を食べた
	•	青木君: 牡蠣 1, 3 を食べた

それぞれの体調は以下の文字列で表されます。
	•	S₁ = “sick” のとき、高橋君はお腹を壊した
	•	S₁ = “fine” のとき、高橋君はお腹を壊さなかった
	•	S₂ = “sick” のとき、青木君はお腹を壊した
	•	S₂ = “fine” のとき、青木君はお腹を壊さなかった

この情報をもとに、どの種類の牡蠣を食べると お腹を壊す のかを判定してください。*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S1, S2;
    cin >> S1 >> S2;

    if (S1 == "sick" && S2 == "sick") {
        cout << 1 << endl;
    } else if (S1 == "sick" && S2 == "fine") {
        cout << 2 << endl;
    } else if (S1 == "fine" && S2 == "sick") {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }

    return 0;
}