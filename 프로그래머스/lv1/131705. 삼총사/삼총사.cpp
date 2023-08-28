#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> number) {
    int ans = 0;

	int n = number.size();
	int k = 3;

	vector<int> tmp;
	for(int i=0; i<k; i++) tmp.push_back(1);
	for(int i=0; i<n-k; i++) tmp.push_back(0);

	sort(tmp.begin(), tmp.end());

	do {
		int cmp = 0;
        for (int i = 0; i < tmp.size(); i++)
            if (tmp[i] == 1) cmp += number[i];
 
        if(cmp == 0) ans++;
 
    } while (next_permutation(tmp.begin(), tmp.end()));

	return ans;
}