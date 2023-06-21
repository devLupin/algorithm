#include <bits/stdc++.h>
using namespace std;

string states[4];
int k, n, d, chk[4];

void shift(int idx, int dir) {
	if(dir == 1) {
		char first = states[idx][7];
		for(int i=6; i>=0; i--) states[idx][i+1] = states[idx][i];
		states[idx][0] = first;
	}

	else {
		char last = states[idx][0];
		for(int i=1; i<8; i++)
			states[idx][i-1] = states[idx][i];
		states[idx][7] = last;
	}
}

void rotate() {
	int left = n-1;
	int right = n+1;
	
	fill_n(&chk[0], 4, 0);
	chk[n] = d;

	// left의 끝까지 체크
	char cmp = states[n][6];
	int dir = d;
	while(left >= 0) {
		char cmp_left = states[left][2];
		if(cmp == cmp_left) break;

		dir *= -1;
		cmp = states[left][6];
		chk[left--] = dir;
	}

	//right의 끝까지 체크
	cmp = states[n][2];
	dir = d;
	while(right < 4) {
		char cmp_right = states[right][6];
		if(cmp == cmp_right) break;

		dir *= -1;
		cmp = states[right][2];
		chk[right++] = dir;
	}

	
	for(int i=0; i<4; i++)
		if(chk[i] != 0)
			shift(i, chk[i]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<4; i++)
		cin >> states[i];

	cin >> k;
	while(k--) {
		cin >> n >> d;
		n--;

		rotate();
	}

	int ans = 0;
	int score[] = {1,2,4,8};
	for(int i=0; i<4; i++)
		if(states[i][0] == '1') ans += score[i];

	cout << ans;
    return 0;
}