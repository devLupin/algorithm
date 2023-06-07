#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r_tmp = 0, r_cnt = 0, b_tmp = 0, b_cnt = 0, ans;
	string str;

	cin >> n >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'R') {
			r_tmp = 1;
			r_cnt += b_tmp;
		}
		else {
			b_tmp = 1;
			b_cnt += r_tmp;
		}
	}

	ans = min(r_cnt, b_cnt);

	r_tmp = 0, r_cnt = 0, b_tmp = 0, b_cnt = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == 'R') {
			r_tmp = 1;
			r_cnt += b_tmp;
		}
		else {
			b_tmp = 1;
			b_cnt += r_tmp;
		}
	}

	ans = min(ans, min(r_cnt, b_cnt));
	cout << ans;

	return 0;
}