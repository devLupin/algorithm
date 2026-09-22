#include <bits/stdc++.h>
using namespace std;

bool check(deque<char> dq)
{
	stack<char> st;
	for (char c : dq)
	{
		if (c == '(' || c == '[' || c == '{')
			st.push(c);
		else
		{
			if (st.empty())
				return false;
			else if (c == ')' && st.top() == '(')
				st.pop();
			else if (c == ']' && st.top() == '[')
				st.pop();
			else if (c == '}' && st.top() == '{')
				st.pop();
			else
				return false;
		}
	}
	return st.empty();
}

int solution(string s)
{
	int cnt = 0, answer = 0;
	deque<char> dq;
	for (const char& c : s)
		dq.push_back(c);

	while (cnt++ < s.size())
	{
		if (check(dq))
			answer++;

		dq.push_back(dq.front());
		dq.pop_front();
	}

	return answer;
}