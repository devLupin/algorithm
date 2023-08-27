#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int cnt[MX+1];

void get_count(int n) {
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j=j+i)
			cnt[j]++;
}

int solution(int number, int limit, int power) {
    int ans = 0;

	get_count(number);
	for(int i=1; i<=number; i++) {
		if(cnt[i] > limit) cnt[i] = power;
		ans += cnt[i];
	}
	return ans;
}