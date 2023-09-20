#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int solution(int n) {
    bitset<20> bit(n);
	int cmp = bit.count();

	for(int a = n+1;;a++) {
		bitset<20> tmp(a);
		if(cmp == tmp.count()) return a;
	}
}