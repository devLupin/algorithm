#include <iostream>
#include <deque>
using namespace std;
 
#define SZ 100000+1
 
int N, K;
int visited[SZ];
 
int bfs() {
    deque<int> dq;
    dq.push_front(N);
    visited[N] = 1;

    while (!dq.empty()) {
        int x = dq.front();
        dq.pop_front();

        if (x == K) return visited[K] - 1;

        int nx = x * 2;
        if (nx < SZ && !visited[nx]) {
            dq.push_front(nx);
            visited[nx] = visited[x];
        }

        nx = x + 1;
        if (nx < SZ && !visited[nx]) {
            dq.push_back(nx);
            visited[nx] = visited[x] + 1;
        }

        nx = x - 1;
        if (nx >= 0 && !visited[nx]) {
            dq.push_back(nx);
            visited[nx] = visited[x] + 1;
        }
    }
}
 
int main() {
    cin >> N >> K;
    cout << bfs();
    return 0;
}