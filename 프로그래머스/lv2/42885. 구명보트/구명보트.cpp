#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.rbegin(), people.rend());
	
	int ans = 0;
	int l = 0, r = people.size()-1;

	for(int a : people) cout << a << ' ';
	cout << '\n';

	while(l <= r) {
		if(people[l] + people[r] > limit) l++;
		else if(people[l] + people[r] <= limit) l++, r--;
		ans++;
	}
	
	return ans;
}