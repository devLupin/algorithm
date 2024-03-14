#include <bits/stdc++.h>
using namespace std;

int solve(string s, int st, int en) {
    while(st >= 0 && en < s.size()) {
        if(s[st] != s[en]) break;
        st--, en++;
    }
    return en - st - 1;
}

int solution(string s) {
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        int st = i;
        int en = i + 1;
        int odd = solve(s, st, en);
        int even = solve(s, st, en - 1);
        ans = max({ans, odd, even});
    }
    return ans;
}