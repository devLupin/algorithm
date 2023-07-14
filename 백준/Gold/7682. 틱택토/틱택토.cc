#include <bits/stdc++.h>
using namespace std;

string s;
char board[3][3];

vector<int> get_winner() {
	vector<int> ret = {0,0};

	for(int i=0; i<3; i++) {
		if(board[i][0] == '.') continue;

		if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
			board[i][0] == 'X' ? ret[0]++ : ret[1]++;
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
			board[i][0] == 'X' ? ret[0]++ : ret[1]++;
	}

	if(board[0][0] != '.' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		board[0][0] == 'X' ? ret[0]++ : ret[1]++;
	if(board[0][2] != '.' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
		board[0][0] == 'X' ? ret[0]++ : ret[1]++;

	return ret;
}

bool check(char c) {
	bool ret = false;
	for(int i=0; i<3; i++) {
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == c) {
			ret = true;
			break;
		}
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == c){
			ret = true;
			break;
		}
	}

	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == c)
		ret = true;
	if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == c)
		ret = true;
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		cin >> s;
		if(s == "end") break;

		int x_cnt = 0;
		int o_cnt = 0;
		int e_cnt = 0;

		for(int i=0; i<s.size(); i++) {
			board[i/3][i%3] = s[i];
			if(board[i/3][i%3] == 'O') o_cnt++;
			else if(board[i/3][i%3] == 'X') x_cnt++;
		}

		bool x = check('X');
		bool o = check('O');

		// 둘다 못 이겼지만, 모든 칸에 착수
		if (!x && !o && x_cnt == 5 && o_cnt == 4) cout << "valid\n";
		// 한쪽이 이겼고, X가 먼저 두는 조건 만족
		else if (x && !o && x_cnt == o_cnt + 1)cout << "valid\n";
		else if (!x && o && x_cnt == o_cnt)cout << "valid\n";
		// 그외
		else cout << "invalid\n";
	}

	return 0;
}