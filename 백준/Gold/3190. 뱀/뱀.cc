#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pic = pair<int,char>;
using pii = pair<int,int>;

int n, k, l;
const int SZ = 100;
const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
int dir = 0;
vector<string> board;
queue<pic> direction;

void print() {
	cout << '\n';

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

int solve() {
	int ret = 0;
	int y = 0, x = 0;

	deque<pii> dq;
	dq.push_back({y,x});
	board[y][x] = 'x';

	while(!dq.empty()) {
		ret++;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if(ny < 0 || nx < 0 || ny >= n || nx >= n) break;
		if(board[ny][nx] == 'x') break;

		if(board[ny][nx] == '.') {
			board[dq.back().Y][dq.back().X] = '.';
			dq.pop_back();
			board[ny][nx] = 'x';
			dq.push_front({ny, nx});
		}
		else {
			board[ny][nx] = 'x';
			dq.push_front({ny, nx});
		}

		if(ret == direction.front().first) {
			if(direction.front().second == 'L') {
				dir += 3;
				dir %= 4;
			}
			else {
				dir += 1;
				dir %= 4;
			}
			direction.pop();
		}

		tie(y, x) = {ny, nx};
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	string s = "";
	for(int i=0; i<n; i++) s += '.';
	for(int i=0; i<n; i++) board.push_back(s);

	for(int r, c, i=0; i<k; i++) {
		cin >> r >> c;
		board[r-1][c-1] = '*';
	}

	cin >> l;
	for(int i=0; i<l; i++) {
		int x; char c;
		cin >> x >> c;
		direction.push({x, c});
	}

	cout << solve();
	return 0;
}