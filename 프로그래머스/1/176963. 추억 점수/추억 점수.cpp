#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size(), 0);
    unordered_map<string, int> myMap;
    
    for(int i=0; i<name.size(); i++)
        myMap[name[i]] = yearning[i];
    
    for(int i=0; i<photo.size(); i++)
        for(auto& k : photo[i])
            answer[i] += myMap[k];
    
    return answer;
}