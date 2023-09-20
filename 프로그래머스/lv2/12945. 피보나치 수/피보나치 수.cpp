#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int D[100002];

int DP(int n) {
	if(D[n] != -1) return D[n];
	return D[n] = (DP(n-1) + DP(n-2)) % 1234567;
}

int solution(int n) {
    memset(D, -1, sizeof(D));
	D[0] = 0;
	D[1] = 1;
	DP(n);
	return D[n] % 1234567;
}