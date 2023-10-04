#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> ans;
    
    char prev = words[0][0];
    unordered_map<string, int> um;
    int i;
    for(i=0; i<words.size(); i++) {
        auto cur = words[i];
        if(cur[0] != prev) break;
        prev = cur[cur.size()-1];

        um[cur]++;
        if(um[cur] > 1) break;
    }

    if(i == words.size()) return {0,0};
    else {
        int a = i % n;
        int b = i / n;
        return {a+1, b+1};
    }
}