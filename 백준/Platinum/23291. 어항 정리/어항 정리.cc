#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int SZ = 102;
bool vis[SZ][SZ];
vector<int> v;
vector<deque<int>> dq;

int N, K, ans;
const int dy[] = { 1,0 };
const int dx[] = { 0,1 };

int gap() {
    int mn = 0x3f3f3f;
    int mx = 0;

    for (int nxt : v) {
        mn = min(mn, nxt);
        mx = max(mx, nxt);
    }

    return mx - mn;
}

void adj() {
    vector<int> tmp;    // min elem에 대한 index
    int cmp = 0x3f3f3f;

    for (int nxt : v) cmp = min(cmp, nxt);
    for (int i = 0; i < v.size(); i++)
        if (cmp == v[i]) tmp.push_back(i);

    for (int idx : tmp) v[idx] += 1;
}

void rotate() {
    dq.clear();
    dq.push_back({});

    for (int nxt : v)
        dq[0].push_back(nxt);

    while (true) {

        if (dq.size() == 1) {
            dq.push_back({});
            dq.back().push_back(dq.front().front());
            dq.front().pop_front();
            continue;
        }

        int elem_sz = dq.back().size();
        int lev = dq.size();
        int base_sz = dq.front().size();

        if (base_sz - elem_sz < lev) break;
        

        // 최상단 층에 맞춰 dq size 늘리기
        int increase = elem_sz + 1;
        while (increase != dq.size()) dq.push_back({});

        int dq_sz = dq.size() - 1;
        for (int i = 0; i < elem_sz; i++) {
            for (int j = 0; j < lev; j++) {
                dq[dq_sz - i].push_back(dq[j].front());
                dq[j].pop_front();
            }
        }
    }
}

void adj2() {
    vector<deque<int>> memo;
    for (int i = 0; i < dq.size(); i++) {
        memo.push_back({});
        memo[i].assign(dq[i].size(), 0);
    }

    for (int y = 0; y < dq.size(); y++) {
        for (int x = 0; x < dq[y].size(); x++) {
            for (int dir = 0; dir < 2; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < dq.size() && nx < dq[ny].size()) {
                    int tmp = abs(dq[y][x] - dq[ny][nx]) / 5;

                    if (tmp > 0) {
                        if (dq[y][x] > dq[ny][nx]) {
                            memo[y][x] -= tmp;
                            memo[ny][nx] += tmp;
                        }
                        else {
                            memo[y][x] += tmp;
                            memo[ny][nx] -= tmp;
                        }
                    }
                }
            }
        }
    }

    for (int y = 0; y < dq.size(); y++)
        for (int x = 0; x < dq[y].size(); x++)
            dq[y][x] += memo[y][x];
}

void flatten() {
    v.clear();

    int sz = dq[0].size();
    while(sz--) {
        for (int i = 0; i < dq.size(); i++) {
            if (!dq[i].empty()) {
                v.push_back(dq[i].front());
                dq[i].pop_front();
            }
        }
    }
}

void rotate2() {
    vector<deque<int>> tmp;

    tmp.push_back({});
    tmp.push_back({});

    int sz = v.size() / 2;
    for (int i = 0; i < sz; i++)
        tmp[1].push_front(v[i]);
    for (int i = sz; i < v.size(); i++)
        tmp[0].push_back(v[i]);

    dq.clear();
    for (int i = 0; i < 4; i++) dq.push_back({});

    sz = tmp[0].size() / 2;

    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < sz; j++) {
            dq[3 - i].push_front(tmp[i].front());
            tmp[i].pop_front();
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < sz; j++) {
            dq[i].push_back(tmp[i].front());
            tmp[i].pop_front();
        }
    }
}

int flatten2() {
    v.clear();
    adj2();

    int mx = 0, mn = 0x3f3f3f;
    int sz = dq[0].size();
    while (sz--) {
        for (int i = 0; i < dq.size(); i++) {
            int cur = dq[i].front();
            v.push_back(cur);
            dq[i].pop_front();

            mx = max(mx, cur);
            mn = min(mn, cur);
        }
    }

    return mx - mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int a, i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    while (true) {
        ans++;
        adj();
        rotate();
        adj2();
        flatten();
        rotate2();
        if (flatten2() <= K) break;
    }

    cout << ans;
    return 0;
}