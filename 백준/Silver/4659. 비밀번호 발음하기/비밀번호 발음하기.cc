#include<bits/stdc++.h>
using namespace std;

bool check_cons(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str; cin >> str;
		if (str == "end") break;

		bool flag = true;
		bool con = false;

		for (int i = 0; i < str.size(); i++) {
			if (!con && check_cons(str[i])) con = true;

			if (i >= 1 && str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o') {
				flag = false;
				break;
			}

			if (i >= 2) {
				if (check_cons(str[i - 2]) == check_cons(str[i - 1]) && check_cons(str[i - 2]) == check_cons(str[i])) {
					flag = false;
					break;
				}
			}
		}

		string answer;
		if (flag && con) answer = " is acceptable.";
		else answer = " is not acceptable.";

		cout << '<' << str << '>' << answer << '\n';
	}

	return 0;
}