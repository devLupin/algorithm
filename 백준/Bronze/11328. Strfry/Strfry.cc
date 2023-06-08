#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int arr[26] = { 0, };
		string a, b; 
		cin >> a >> b;
		
		for (char c : a) arr[c - 'a']++;
		for (char c : b) arr[c - 'a']--;
		
		bool chk = true;
		for (int i : arr)
			if (i != 0)
				chk = false;

		if (chk) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}