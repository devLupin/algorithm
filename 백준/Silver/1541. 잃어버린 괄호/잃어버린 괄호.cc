#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;

	string str = "";
	cin >> str;

	string tmp = "";
	bool flag = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
			if (flag) ans -= stoi(tmp);
			else ans += stoi(tmp);

			tmp = "";
			if (str[i] == '-') flag = true;
		}
		else tmp += str[i];
	}

	cout << ans;

	return 0;
}