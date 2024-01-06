#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void DFS(map<string, int>& dic, string& order, string comb, int index, int depth) {
    if (depth == comb.length()) {
        dic[comb]++;
        return;
    }

    for (int i = index; i < order.length(); i++) {
        comb[depth] = order[i];
        DFS(dic, order, comb, i + 1, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> dic;

    for(string& order : orders) {
        sort(order.begin(), order.end());
        
        for(int& sz : course) {
            string cur = "";
            cur.resize(sz);
            DFS(dic, order, cur, 0, 0);
        }
    }
    
    vector<pair<string, int>> tmp;
    for(auto& nxt : dic)
        if(nxt.second > 1) tmp.push_back(nxt);
    sort(tmp.begin(), tmp.end(), cmp);
    
    for(int& sz : course) {
        int mx = 0;
        
        for(auto& nxt : tmp) {
            if(nxt.first.size() != sz) 
                continue;
            else if(mx == 0) {
                answer.push_back(nxt.first);
                mx = nxt.second;
            }
            else if(mx == nxt.second)
                answer.push_back(nxt.first);
            else break;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}