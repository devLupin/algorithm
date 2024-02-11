#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int ans, len;
    ans = len = s.size();

    for (int i = 1; i <= len / 2; i++) {
        int cnt = 1;
        string now = "";
        string cmp = s.substr(0, i);

        for (int j = i; j <= len; j += i) {
            string nxt = s.substr(j, i);

            if (nxt == cmp) cnt++;
            else {
                if (cnt > 1) now += to_string(cnt);
                now += cmp;
                cmp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) now += to_string(cnt);
        now += cmp;

        ans = min((int)now.size(), ans);
    }

    return ans;
}