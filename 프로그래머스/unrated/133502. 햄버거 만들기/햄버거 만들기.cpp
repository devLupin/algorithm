#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string curr = "";
    for (int i = 0; i < ingredient.size(); i++) {
        curr += to_string(ingredient[i]);
        if (curr.length() >= 4 && curr.substr(curr.length() - 4, 4) == "1231") {
            curr = curr.substr(0, curr.length() - 4);
            answer++;
        }
    }
    return answer;
}