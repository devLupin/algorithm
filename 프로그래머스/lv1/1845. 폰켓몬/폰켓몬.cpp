#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
	map<int, int> m;
    for(int x : nums) m[x]++;

	return min(m.size(), nums.size() / 2);
}