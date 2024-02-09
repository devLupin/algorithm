#include <bits/stdc++.h>
using namespace std;
using namespace std;
using ll = long long;

ll cal_act(ll a, ll b, char c) {
    if (c == '-') return a - b;
    else if (c == '*') return a * b;
    return a + b;
}
long long solution(string expression) {
    string s = expression;
    long long answer = 0;
    vector<char> p_cal = { '*','+','-' };
    vector<ll> num;
    vector<char> cal;
    
    sort(p_cal.begin(), p_cal.end());
    
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')temp += s[i];
        else {
            num.push_back(stoll(temp));
            cal.push_back(s[i]);
            temp = "";
        }
    }
    
    num.push_back(stoll(temp));
    ll max_num = -1;
    
    do {
        vector<ll> n = num;
        vector<char> c = cal; 
        
        for (int i = 0; i <= 2; i++) {
            int j = 0;
            while (j < c.size()) {
                if (p_cal[i] == c[j]) {              
                    ll result = cal_act(n[j], n[j + 1], c[j]);
                    n.erase(n.begin() + j, n.begin() + j + 2);           
                    c.erase(c.begin() + j);
                    n.insert(n.begin() + j, result);            
                }
                else j++;                 
            }            
        }
        
        max_num = max(max_num, abs(n[0]));
    } while (next_permutation(p_cal.begin(), p_cal.end()));
    
    return max_num;
}