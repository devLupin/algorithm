#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int SZ = 10;
const int dx[] = { -1,1,0,0,-1,-1,1,1 };
const int dy[] = { 0,0,-1,1,-1,1,1,-1 };

int N, M, K, ans;
int A[SZ][SZ], board[SZ][SZ];
vector<int> tree[SZ][SZ];
vector<tiii> die;

bool oom(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }

void spring() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (tree[i][j].size() > 0) {
				vector<int> tmp;
				sort(tree[i][j].begin(), tree[i][j].end());

				for (int nxt : tree[i][j]) {
					if (board[i][j] >= nxt) {
						board[i][j] -= nxt;
						tmp.push_back(nxt + 1);
					}
					else
						die.push_back({ i, j, nxt });
				}

				tree[i][j] = tmp;
			}
}

void summer() {
	for (auto [x, y, z] : die)
		board[x][y] += z / 2;

	die.clear();
}

void fall() {
	vector<pii> tmp;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int nxt : tree[i][j])
				if(nxt % 5 == 0)
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (!oom(nx, ny))
							tmp.push_back({ nx, ny });
					}

	for (auto nxt : tmp)
		tree[nxt.X][nxt.Y].push_back(1);
}

void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] += A[i][j];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			board[i][j] = 5;
		}
	for (int x, y, z, i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += (int)tree[i][j].size();

	cout << ans;
	return 0;
}