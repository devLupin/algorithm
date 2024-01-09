#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int R, C;

int rotate(int x1, int y1, int x2, int y2) {
    int mn = 100 * 100 + 1;

    int helper = arr[x1][y1];

    for (int i = x1; i < x2; i++) {
        arr[i][y1] = arr[i + 1][y1];
        mn = min(mn, arr[i][y1]);
    }
    for (int j = y1; j < y2; j++) {
        arr[x2][j] = arr[x2][j + 1];
        mn = min(mn, arr[x2][j]);
    }
    for (int i = x2; i > x1; i--) {
        arr[i][y2] = arr[i - 1][y2];
        mn = min(mn, arr[i][y2]);
    }

    for (int j = y2; j > y1; j--) {
        arr[x1][j] = arr[x1][j - 1];
        mn = min(mn, arr[x1][j]);
    }

    arr[x1][y1 + 1] = helper;
    mn = min(mn, helper);
    
    return mn;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int n = 1;
    R = rows, C = columns;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            arr[i][j] = n++;

    for (auto nxt : queries) {
        int mn = rotate(nxt[0], nxt[1], nxt[2], nxt[3]);
        answer.push_back(mn);
    }

    return answer;
}