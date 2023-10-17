#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for(auto nxt : scoville) pq.push(nxt);
    
    while(pq.top() < K && pq.size() >= 2) {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        
        int neww = f + s * 2;
        pq.push(neww);
        ans ++;
    }
    
    if(pq.top() < K) return -1;
    
    return ans;
}