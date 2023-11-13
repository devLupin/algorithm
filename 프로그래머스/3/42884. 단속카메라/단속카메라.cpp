#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), compare);

    int cur = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        auto nxt = routes[i];
        if(nxt[0] > cur || nxt[1] < cur) {
            cur = nxt[1];
            answer++;
        }
    }

    return answer;
}