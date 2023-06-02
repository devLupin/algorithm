#include<bits/stdc++.h>
using namespace std;

const int SZ = 1000;
char body[SZ][SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> body[i][j];

	pair<int, int> heart, leg_center;
	int i, j, left_arm=0, right_arm=0, mid=0, left_leg=0, right_leg=0;
	
	bool flag = true;
	for (i = 0; i < n && flag; i++) {
		for (j = 0; j < n; j++)
			if (body[i][j] == '*') {
				flag = false;
				break;
			}
	}
	heart = { i, j };

	for (i = heart.second - 1; i >= 0; i--) {
		if (body[heart.first][i] != '*') break;
		left_arm++;
	}
	for (i = heart.second + 1; i < n; i++) {
		if (body[heart.first][i] != '*') break;
		right_arm++;
	}

	for (i = heart.first + 1; i < n; i++) {
		if (body[i][heart.second] != '*') break;
		mid++;
	}

	for (j = i; j < n; j++) {
		if (body[j][heart.second - 1] != '*') break;
		left_leg++;
	}

	for (j = i; j < n; j++) {
		if (body[j][heart.second + 1] != '*') break;
		right_leg++;
	}

	cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
	cout << left_arm << ' ' << right_arm << ' ' << mid << ' ' << left_leg << ' ' << right_leg;
	return 0;
}