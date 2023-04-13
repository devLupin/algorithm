#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> m1;
    map<string, int> m2;
    
    for(int i=0; i<players.size(); i++) {
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++) {
        int cur_idx = m2[callings[i]];
        string change = m1[cur_idx - 1];
        
        m1[cur_idx] = change;
        m1[cur_idx - 1] = callings[i];
        m2[change] = cur_idx;
        m2[callings[i]] = cur_idx - 1;
    }
    
    vector<string> ans;
    
    for(map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
        ans.push_back(it->second);
    return ans;
}