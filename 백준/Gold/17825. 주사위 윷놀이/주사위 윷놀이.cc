#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int SZ = 35;

int ans, board[SZ], route[SZ], turn[SZ], dice[10], piece[4];
bool vis[SZ];

void init() {
	for (int i = 0; i < 21; i++) route[i] = i + 1;

	route[21] = 21;
	for (int i = 22; i < 27; i++) route[i] = i + 1;

	route[27] = 20; 
	route[28] = 29; 
	route[29] = 30;
	route[30] = 25; 
	route[31] = 32; 
	route[32] = 25;

	turn[5] = 22; 
	turn[10] = 31; 
	turn[15] = 28;

	for (int i = 0; i < 21; i++) board[i] = 2 * i;

	board[22] = 13; 
	board[23] = 16; 
	board[24] = 19;
	board[25] = 25; 
	board[26] = 30; 
	board[27] = 35;
	board[28] = 28; 
	board[29] = 27; 
	board[30] = 26;
	board[31] = 22; 
	board[32] = 24;
}

void solution(int depth, int sum) {
	if (depth == 10) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev = piece[i];
		int nxt = prev;
		int move = dice[depth];

		if (turn[nxt] > 0) {
			nxt = turn[nxt];
			move--;
		}

		while (move--) nxt = route[nxt];

		if (nxt != 21 && vis[nxt]) continue;

		vis[prev] = false;
		vis[nxt] = true;
		piece[i] = nxt;

		solution(depth + 1, sum + board[nxt]);

		vis[prev] = true;
		vis[nxt] = false;
		piece[i] = prev;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++) cin >> dice[i];

	init();
	solution(0, 0);

	cout << ans;
	return 0;
}