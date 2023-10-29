#include <bits/stdc++.h>
using namespace std;

int ans = 55;
vector<string> cpy;
string targ;
bool vis[50];

void dfs(string cur, int num) {
    if (cur == targ) {
        ans = min(ans, num);
        return;
    }

    for (int i = 0; i < cpy.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < cur.size(); j++)
            if (cur[j] != cpy[i][j]) cnt++;

        if (cnt == 1 && !vis[i]) {
            vis[i] = true;
            dfs(cpy[i], num + 1);
            vis[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    targ = target;
    cpy.assign(words.begin(), words.end());

    dfs(begin, 0);

    if (ans == 55) return 0;
    return ans;
}