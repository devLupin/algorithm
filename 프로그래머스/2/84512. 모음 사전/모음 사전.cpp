#include <bits/stdc++.h>
using namespace std;

string target;
int cnt, n;

void dfs(string s) {
    cnt++;
    
    if(s == target) {
        n = cnt;
        return;
    }
    if(s.size() >= 5) return;
    
    for(char c : {'A', 'E', 'I', 'O', 'U'})
        dfs(s + c);
}

int solution(string word) {
    target = word;
    dfs("");
    return n-1;
}