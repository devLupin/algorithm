#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;
const int SZ = 2000001;
bool arr[SZ];

void eratos() {
	arr[1] = true;

	for (int i = 2; i * i < SZ; i++) {
		if (arr[i]) continue;

		for (int j = i * i; j < SZ; j += i)
			arr[j] = true;
	}

	for (int i = 2; i < SZ; i++)
		if (!arr[i])
			v.push_back((ll)i);
}

bool is_prime(ll num) {
	bool ret = true;
	for (ll cur : v) {
		if (num <= cur) break;
		if (num % cur == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratos();

	int TC; cin >> TC;
	while (TC--) {
		ll a, b, s; cin >> a >> b;
		s = a + b;

		if (s <= 3) cout << "NO";
		else if (s % 2 == 0) cout << "YES";
		else {
			if (is_prime(s - 2)) cout << "YES";
			else cout << "NO";
		}
		cout << '\n';
	}

	return 0;
}