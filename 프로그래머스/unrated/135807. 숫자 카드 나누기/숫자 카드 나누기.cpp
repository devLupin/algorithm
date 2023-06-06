#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

bool is_div(vector<int> v, int n) {
	for (int a : v)
		if (a % n == 0)
			return true;
	return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int ans = 0;

	int gcd_a = arrayA[0], gcd_b = arrayB[0];
	for (int i = 1; i < arrayA.size(); i++) {
		gcd_a = gcd(arrayA[i], gcd_a);
		gcd_b = gcd(arrayB[i], gcd_b);
	}

	if (!is_div(arrayA, gcd_b)) ans = max(ans, gcd_b);
	if (!is_div(arrayB, gcd_a)) ans = max(ans, gcd_a);
	return ans;
}