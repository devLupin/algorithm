#include <bits/stdc++.h>
using namespace std;

vector<int> factor(int n) {
	vector<int> ret;
	for(int i=1; i<=n; i++)
		if(n%i == 0) ret.push_back(i);
	return ret;
}

vector<int> solution(int brown, int yellow) {
    auto v = factor(brown+yellow);
	int a = v.size();

	if(a%2 == 0) {
		for(int i=a-1, j=0; j<a; i--,j++) {
			if((v[i]-2)*(v[j]-2) == yellow)
				return {v[i], v[j]};
		}
	}
	else return {v[a/2], v[a/2]};
}