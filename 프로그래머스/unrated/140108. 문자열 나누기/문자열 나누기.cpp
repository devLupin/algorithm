#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int ans = 0;

    for(int j, i=0; i<s.size(); i++) {
        int cnt = 0, cmp = 0;
        int tmp = s[i];

        for(j=i; j<s.size(); j++) {
            if(s[j] == tmp) cnt++;
            else cmp++;
            if(cnt == cmp) break;
        }

        i = j;
        ans++;
    }

    return ans;
}