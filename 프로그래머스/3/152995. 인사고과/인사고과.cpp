#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int score = scores[0][0] + scores[0][1];
    
    auto comp = [](vector<int> v1, vector<int> v2) {
        return (v1[0]+v1[1]) > (v2[0]+v2[1]);
    };
    
    sort(scores.begin()+1, scores.end(), comp);
    
    for(int i = 1; i < scores.size(); i++) {
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
            return -1;
        
        int sum = scores[i][0] + scores[i][1];
        if(score < sum)
            answer++;
        else break;
    }
    
    int wanho = answer;
    for(int c = 2; c < wanho; c++) {
        for(int p = 1; p < c; p++) {        
            if(scores[c][0] < scores[p][0] && scores[c][1] < scores[p][1])
            {
                --answer;
                break;
            }
        }
    }
    
    return answer;
}