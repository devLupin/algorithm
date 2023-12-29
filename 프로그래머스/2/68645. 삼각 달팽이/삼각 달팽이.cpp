#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
const int dx[] = { 1,0,-1};
const int dy[] = { 0,1,-1};

vector<int> solution(int n) {
    vector<int> ans;

    int i, j, num, cnt, len, dir = 0;
    i = j = num = 1;
    cnt = 0, len = n;

    while (len > 0) {
        arr[i][j] = num++;
        cnt++;

        if (cnt == len) {
            dir = (dir + 1) % 3;
            cnt = 0;
            len--;
        }

        i += dx[dir];
        j += dy[dir];
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (arr[i][j] != 0) ans.push_back(arr[i][j]);
            
    return ans;
}