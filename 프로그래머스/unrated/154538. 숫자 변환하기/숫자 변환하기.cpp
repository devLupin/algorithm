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
        
        if (cx * 2 < INF && !visited[cx * 2]) {
            q.push({ cx * 2, cur.second + 1 });
            visited[cx * 2] = true;
        }
        if (cx * 3 < INF && !visited[cx * 3]) {
            q.push({ cx * 3, cur.second + 1 });
            visited[cx * 3] = true;
        }
        if (cx + n < INF && cx + n > 0 && !visited[cx + n]) {
            q.push({ cx + n, cur.second + 1 });
            visited[cx + n] = true;
        }
    }

    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}