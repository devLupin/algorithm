#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int SZ = 100;
int r, c, k, t = -1;
vector<int> A[SZ], C[SZ];

bool compare(pii &a, pii &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

vector<int> get_cnt(vector<int> &v) {
    map<int, int> mp;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) continue;
        mp[v[i]]++;
    }

    vector<pii> tmp(mp.begin(), mp.end());
    sort(tmp.begin(), tmp.end(), compare);

    vector<int> ret;
    for (pii nxt : tmp) {
        ret.push_back(nxt.first);
        ret.push_back(nxt.second);
    }

    return ret;
}

void solve(int cnt, int ymax, int xmax) {
    if (t != -1) return;
    if (A[r][c] == k) {
        t = cnt;
        return;
    }
    if (cnt > 100) {
        t = -1;
        return;
    }

    for (int i = 0; i < SZ; i++) {
        C[i].clear();
        C[i].assign(100, 0);
    }

    if (ymax >= xmax) {
        for (int i = 0; i < SZ; i++) {
            vector<int> ret = get_cnt(A[i]);
            for (int j = 0; j < ret.size(); j++) C[i][j] = ret[j];

            xmax = max(xmax, (int)ret.size());
        }
    }
    else {
        for (int i = 0; i < SZ; i++) {
            vector<int> tmp;
            for (int j = 0; j < SZ; j++) tmp.push_back(A[j][i]);
            
            vector<int> ret = get_cnt(tmp);
            for (int j = 0; j < ret.size(); j++) C[j][i] = ret[j];

            ymax = max(ymax, (int)ret.size());
        }
    }

    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            A[i][j] = C[i][j];

    solve(cnt + 1, ymax, xmax);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<SZ; i++)
        A[i].assign(100, 0);

    cin >> r >> c >> k;
    for (int a, b, c, i = 0; i < 3; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    r--, c--;

    solve(0, 3, 3);

    cout << t;
    return 0;
}