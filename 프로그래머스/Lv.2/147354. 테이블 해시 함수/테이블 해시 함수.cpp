#include <bits/stdc++.h>
using namespace std;

int target;

bool compare(vector<int>& v1, vector<int>& v2) {
    if(v1[target] == v2[target])
        return v1[0] > v2[0];
    return v1[target] < v2[target];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    target = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for(int i=row_begin; i<=row_end; i++) {
        int cur = 0;
        for(int nxt : data[i-1])
            cur += nxt % i;
        answer ^= cur;
    }
    
    return answer;
}