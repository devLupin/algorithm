#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		string cmd, num;
		int n;
		cin >> cmd >> n >> num;

		deque<int> dq;
		string tmp = "";
		for (int i = 1; i < num.size() - 1; i++) {
			if (num[i] == ',') {
				dq.push_back(stoi(tmp));
				tmp = "";
			}
			else tmp += num[i];
		}

		if (tmp != "") dq.push_back(stoi(tmp));

		bool chk = false, error = false;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') chk = !chk;
			else if (!dq.empty()) {
				if (chk) dq.pop_back();
				else dq.pop_front();
			}
			else {
				if (!dq.empty()) {
					if (chk) dq.pop_back();
					else dq.pop_front();
				}
				else {
					error = true;
					break;
				}
			}
		}

		if (error) cout << "error\n";
		else {
			cout << '[';
			while (dq.size() > 1) {
				if (chk) {
					cout << dq.back() << ',';
					dq.pop_back();
				}
				else {
					cout << dq.front() << ',';
					dq.pop_front();
				}
			}
			if (!dq.empty()) {
				if (chk) cout << dq.back();
				else cout << dq.front();
			}
			cout << "]\n";
		}
	}

	return 0;
}