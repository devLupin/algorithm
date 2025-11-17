#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
	reverse(cards1.begin(), cards1.end());
	reverse(cards2.begin(), cards2.end());

	for (const auto& str : goal)
	{
		if (!cards1.empty() && str == cards1.back()) cards1.pop_back();
		else if (!cards2.empty() && str == cards2.back()) cards2.pop_back();
		else return "No";
	}

	return "Yes";
}