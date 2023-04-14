#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

vector<int> solution(vector<int> sequence, int k) {
    int start=0, end=0;
    
    queue<pii> q;
    int len = 1000001;
    int sum = 0;
    for(int i=0; i<sequence.size(); i++) {
        q.push({sequence[i], i});
        sum += sequence[i];
        
        while(sum > k) {
            pii cur = q.front();
            q.pop();
            
            sum -= cur.first;
        }
        
        if(sum == k && q.size() < len) {
            start = q.front().second;
            end = q.back().second;
            len = q.size();
        }
    }
    
    return {start, end};
}