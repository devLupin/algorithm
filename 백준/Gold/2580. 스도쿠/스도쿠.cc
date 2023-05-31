#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool flag = false;
int sudoku[9][9];
vector<pii> v;

bool check(pair<int, int> p)
{
	int square_x = p.first / 3 * 3;
	int square_y = p.second / 3 * 3;

	for (int i = 0; i < 9; i++)
	{
		if (sudoku[p.first][i] == sudoku[p.first][p.second] && i != p.second)
			return false;
		if (sudoku[i][p.second] == sudoku[p.first][p.second] && i != p.first)
			return false;
	}

	for (int i = square_x; i < square_x + 3; i++)
		for (int j = square_y; j < square_y + 3; j++)
			if (sudoku[i][j] == sudoku[p.first][p.second])
				if (i != p.first && j != p.second)
					return false;

	return true;
}

void dfs(int n) {
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sudoku[i][j] << ' ';
			cout << '\n';
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		sudoku[v[n].first][v[n].second] = i;
		
		if (check(v[n])) dfs(n + 1);
		if (flag) return;
	}

	sudoku[v[n].first][v[n].second] = 0;
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				v.push_back({ i,j });
		}

	dfs(0);
	return 0;
}