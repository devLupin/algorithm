#include <string>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

long long solution(vector<int> weights) {
    ll answer = 0;
    vector<ll> cnt(1001, 0);
    
    for(int w : weights)
        cnt[w]++;
    
    for(int w : weights) {
        ll temp;
        
        if(w % 2 == 0) {
            temp = (w/2) * 3;
            if(temp <= 1000) answer += cnt[temp];
        }
        
        if(w % 3 == 0) {
            temp = (w/3) * 4;
            if(temp <= 1000) answer += cnt[temp];
        }
        
        temp = w*2;
        if(temp <= 1000) answer += cnt[temp];
    }
    
    for(int i=100; i<=1000; i++)
        if(cnt[i] >= 2)
            answer += (ll)(cnt[i] * (cnt[i] - 1)) / 2;
    
    return answer;
}