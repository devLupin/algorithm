#include <queue>

using namespace std;
using pii = pair<int, int>;

using namespace std;

const int INF = 1000001;
bool visited[INF] = { false, };

int bfs(int x, int y, int n) {
    queue<pii> q;
    q.push({ x, 0 });

    while (!q.empty()) {
        pii cur = q.front();
        int cx = cur.first;
        q.pop();

        if (cx == y)
            return cur.second;

        if (cx * 2 <= y && !visited[cx * 2]) {
            q.push({ cx * 2, cur.second + 1 });
            visited[cx * 2] = true;
        }
        if (cx * 3 <= y && !visited[cx * 3]) {
            q.push({ cx * 3, cur.second + 1 });
            visited[cx * 3] = true;
        }
        if (cx + n <= y && !visited[cx + n]) {
            q.push({ cx + n, cur.second + 1 });
            visited[cx + n] = true;
        }
    }

    return -1;
}

int memo[INF];
int DP(int x, int y, int n) {
    fill_n(memo, INF, INF);
    memo[x] = 0;

    for (int i = x; i <= y; i++) {
        if (i * 2 <= y) memo[i * 2] = min(memo[i * 2], memo[i] + 1);
        if (i * 3 <= y) memo[i * 3] = min(memo[i * 3], memo[i] + 1);
        if (i + n <= y) memo[i + n] = min(memo[i + n], memo[i] + 1);
    }

    return (memo[y] == INF) ? -1 : memo[y];
}

int solution(int x, int y, int n) {
    return DP(x, y, n);
    return bfs(x, y, n);
}
