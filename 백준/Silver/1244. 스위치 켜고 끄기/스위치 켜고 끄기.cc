#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int std_num; cin >> std_num;
	for (int i = 0; i < std_num; i++) {
		int sex, switch_num;
		cin >> sex >> switch_num;


		if (sex == 1) {
			for (int i = switch_num; i <= n; i += switch_num)
				v[i] = !v[i];
		}
		else {
			v[switch_num] = !v[switch_num];

			for (int i = 1; v[switch_num - i] == v[switch_num + i]; i++) {
				if (switch_num + i > n || switch_num - i < 1) break;
				v[switch_num - i] = !v[switch_num - i];
				v[switch_num + i] = !v[switch_num + i];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	
	return 0;
}