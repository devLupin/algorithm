#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr1[26] = { 0, }, arr2[26] = { 0, }, ans = 0;
	string s1, s2;
	cin >> s1 >> s2;

	for (char c : s1) arr1[c - 'a']++;
	for (char c : s2) arr2[c - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i]) ans += abs(arr1[i] - arr2[i]);
	}

	cout << ans;
	return 0;
}