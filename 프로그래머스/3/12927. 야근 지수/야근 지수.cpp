#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long ans = 0;
    
    priority_queue<int> pq;
    for(auto i : works) pq.push(i);
    
    while(n-- && !pq.empty()) {
        int num = pq.top();
        pq.pop();
        if(num > 0) pq.push(--num);
    }
    
    while(!pq.empty()) {
        int num = pq.top();
        pq.pop();
        ans += num*num;
    }
    
    return ans;
}