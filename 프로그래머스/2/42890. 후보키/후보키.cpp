#include <bits/stdc++.h>
using namespace std;

int ans, row, col;
vector<vector<string>> cpy;
bool vis[10];
vector<int> keys;
vector<vector<int>> candidate;

bool is_uniqueness() {
    unordered_map<string, int> tmp;

    for (int i = 0; i < cpy.size(); i++) {
        string s = "";
        for (int j : keys) s += cpy[i][j];
        tmp[s]++;
        if (tmp[s] > 1) return false;
    }

    return true;
}

bool is_minimality() {
    if (keys.size() == 1) return true;

    unordered_map<int, int> cmp;
    for (int k : keys) cmp[k]++;

    for (auto nxt : candidate) {
        bool flag = false;

        for (int x : nxt) {
            if (cmp[x] == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) return false;
    }

    return true;
}

void DFS(int idx, int cnt, int total) {
    if (cnt == total) {
        if (is_uniqueness() && is_minimality()) {
            candidate.push_back(keys);
            ans++;
        }
        return;
    }

    for (int i = idx; i < col; i++) {
        if (vis[i]) continue;
        
        vis[i] = true;
        keys.push_back(i);
        DFS(i, cnt + 1, total);
        keys.pop_back();
        vis[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    cpy.assign(relation.begin(), relation.end());
    row = relation.size();
    col = relation[0].size();

    for (int i = 1; i <= col; i++)
        DFS(0, 0, i);

    return ans;
}