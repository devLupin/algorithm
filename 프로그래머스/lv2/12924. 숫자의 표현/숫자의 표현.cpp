#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int ans = 0, tmp = 0, sum = 0;

	for(int i=1; i<=n; i++) {
		sum += i;
		if(sum > n) {
			for(int j=tmp+1; j<i && sum > n; j++) {
				sum -= j;
				tmp = j;
			}
		}
		if(sum == n) ans++;
	}

	return ans;
}
