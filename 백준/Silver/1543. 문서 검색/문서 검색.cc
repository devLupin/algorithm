#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b;
	getline(cin, a);
	getline(cin, b);

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		bool flag = true;
		for (int j = 0; j < b.size(); j++) {
			if (a[i + j] != b[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans++;
			i += b.size() - 1;
		}
	}
	
	cout << ans;
	return 0;
}