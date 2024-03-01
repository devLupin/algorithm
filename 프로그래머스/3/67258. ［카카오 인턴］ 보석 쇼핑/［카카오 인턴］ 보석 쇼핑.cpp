#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> unique(gems.begin(), gems.end());
    unordered_map<string, int> MAP;
    vector<int> ans;

    int s = 0, e = gems.size() - 1;

    for (int i = 0; i < gems.size(); i++) {
        MAP[gems[i]]++;
        if (MAP.size() == unique.size()) {
            e = i;
            break;
        }
    }

    ans = { s + 1, e + 1 };
    int cmp = e - s;

    while (e < gems.size()) {
        string cur = gems[s++];
        MAP[cur]--;

        if (MAP[cur] == 0) {
            e++;
            while (e < gems.size()) {
                MAP[gems[e]]++;
                if (gems[e] == cur) break;
                e++;
            }
        }

        if (e - s < cmp) {
            ans = { s + 1, e + 1 };
            cmp = e - s;
        }
    }

    return ans;
}