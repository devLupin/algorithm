#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
	if(s.size() % 2 != 0) return 0;

	stack<char> st;
	for(char c : s) {
		if(st.empty() || st.top() != c) st.push(c);
		else st.pop();
	}

	return st.empty() ? 1 : 0;
}