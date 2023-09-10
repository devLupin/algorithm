#include <bits/stdc++.h>
using namespace std;

int D[1'000'000];
string s, x;

void DP() {
	for(int t=0, i=1; i<100'000; i++) {
		x += to_string(i);
		for(int j=t; j<t+to_string(i).size(); j++) D[j] = i;
		t += to_string(i).size();
	}

}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> s;
	DP();

	for(int t=0, i=0; i<x.size(); i++) {
		if(t == s.size()) {
			cout << D[i-1];
			break;
		}
		if(s[t] == x[i]) t++;
	}

	return 0;
}