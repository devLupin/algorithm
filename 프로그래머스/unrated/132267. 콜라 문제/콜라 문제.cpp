#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int n) {
    int ans = 0;

	while(n >= a) {
		int get = n/a*b;
		n = get + n%a;
		ans += get;
	}

	return ans;
}