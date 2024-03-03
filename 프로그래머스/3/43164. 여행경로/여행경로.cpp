#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool vis[10001];
bool stop = false;

void dfs(string cur, int cnt) {
    answer.push_back(cur);

    if (ticket.size() == cnt) stop = true;

    for (int i = 0; i < ticket.size(); i++) {
        if (vis[i]) continue;
        if (ticket[i][0] == cur) {
            vis[i] = true;
            dfs(ticket[i][1], cnt + 1);

            if (!stop) {
                answer.pop_back();
                vis[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;

    dfs("ICN", 0);
    return answer;
}