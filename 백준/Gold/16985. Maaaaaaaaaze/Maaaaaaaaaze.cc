#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

const int MX = 130, SZ = 5;
const int dz[] = {-1,1,0,0,0,0};
const int dy[] = {0,0,-1,1,0,0};
const int dx[] = {0,0,0,0,-1,1};
int ans=MX;
vvvi board(SZ, vvi(5, vector<int>(5))), arr(SZ, vvi(5, vector<int>(5)));
bool visited[SZ][SZ][SZ], maze_vis[SZ];

typedef struct{
	int z, y, x, dist;
}Pos;

void rotate(int idx) {
	vvi tmp(5, vector<int>(5));

	for(int i = 0; i < SZ; i++)
    	for(int j = 0; j < SZ; j++)
    		tmp[i][j] = arr[idx][i][j];

  	for(int i = 0; i < SZ; i++)
    	for(int j = 0; j < SZ; j++)
    		arr[idx][i][j] = tmp[SZ-1-j][i];
}

int bfs() {
	if(arr[0][0][0] != 1 || arr[SZ-1][SZ-1][SZ-1] != 1) return MX;

	fill_n(&visited[0][0][0], SZ*SZ*SZ, false);

	queue<Pos> q;
	q.push({0,0,0,0});
	visited[0][0][0] = true;

	while(!q.empty()) {
		auto cur = q.front();
		q.pop();

		if(cur.z == SZ-1 && cur.y == SZ-1 && cur.x == SZ-1) return cur.dist;

		for(int dir=0; dir<6; dir++) {
			int nz = cur.z + dz[dir];
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if(nz < 0 || ny < 0 || nx < 0 || nz >= SZ || ny >= SZ || nx >= SZ) continue;
			if(!visited[nz][ny][nx] && arr[nz][ny][nx] == 1) {
				q.push({nz, ny, nx, cur.dist + 1});
				visited[nz][ny][nx] = true;
			}
		}
	}

	return MX;
}

void make_maze(int cnt) {
	if(cnt == SZ) {
		ans = min(ans, bfs());
		return;
	}

	for(int i=0; i<SZ; i++) {
		if(!maze_vis[i]) {
			arr[cnt] = board[i];
			maze_vis[i] = true;

			for(int d=0; d<4; d++) {
				rotate(cnt);
				make_maze(cnt+1);
			}
			maze_vis[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++)
			for(int k=0; k<SZ; k++)
				cin >> board[i][j][k];

	make_maze(0);
	cout << (ans == MX ? -1 : ans);
	return 0;
}