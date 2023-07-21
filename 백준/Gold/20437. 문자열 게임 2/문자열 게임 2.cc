#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while(T--) {
		string w;
		int k, ans1 = 0x3f3f3f, ans2 = 0;
		int chk[26] = {0, };

		cin >> w >> k;
		int sz = w.size();

		for(int i=0; i<sz; i++)
			chk[w[i]-'a']++;

		for(int i=0; i<sz; i++) {
			if(chk[w[i]-'a'] < k) continue;

			int cnt = 0;
			for(int j=i; j<sz; j++) {
				if(w[i] == w[j]) cnt++;

				if(cnt == k) {
					ans1 = min(ans1, j-i+1);
					ans2 = max(ans2, j-i+1);
					break;
				}
			}
		}

		if(ans1 == 0x3f3f3f || ans2 == 0) cout << "-1\n";
		else cout << ans1 << ' ' << ans2 << '\n';

	}

	return 0;
}