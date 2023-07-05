#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a, int &b) {
    string s1 = to_string(a);
    string s2 = to_string(b);

	return s1+s2 > s2+s1;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);

	if(numbers[0] == 0) return "0";

    string ret = "";
	for(int x : numbers)
		ret += to_string(x);

    return ret;
}