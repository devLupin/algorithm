#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(ll num) {
    if(num < 2) return false;
        
    for(int i=2; i<=sqrt(num); ++i) {
        if(num % i == 0) return false;
    }
    return true;

}

int solution(int n, int k) {
    int answer = 0;
    vector<int> v;
    
    while(n >0){
        ll bit = n % k;
        n = n / k;
        v.push_back(bit);
    }
    reverse(v.begin(), v.end());
    
    string s = "";
    for(int x : v) {
        if(x != 0) s += to_string(x);
        else {
            if(s == "") continue;
            if(is_prime(stoll(s))) answer++;
            s = "";
        }
    }
    if(s != "" && is_prime(stoll(s))) answer++;
    
    return answer;
}