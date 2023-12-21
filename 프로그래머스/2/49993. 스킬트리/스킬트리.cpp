#include <bits/stdc++.h>
using namespace std;

bool check(string cur, string skill) {
    int idx = 0;
    for (int i = 0; i < cur.size(); i++) {
        int cmp = -1;
        for (int j = idx; j < skill.size(); j++) {
            if (cur[i] == skill[j]) {
                cmp = j;
                break;
            }
        }

        if (cmp != -1) {
            if (idx != cmp) return false;
            else idx++;
        }
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int ans = 0;

    for (string cur : skill_trees)
        ans += check(cur, skill);

    return ans;
}