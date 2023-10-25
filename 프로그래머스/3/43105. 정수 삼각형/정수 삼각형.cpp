#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> t) {
    int R = t.size();

    for (int i = R - 2; i >= 0; i--) {
        int C = t[i].size();

        for (int j = 0; j < C; j++) {
            t[i][j] += max(t[i + 1][j], t[i + 1][j + 1]);
        }
    }

    return t[0][0];
}