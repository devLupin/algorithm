#include <bits/stdc++.h>
using namespace std;

bool chk(char c) {
    return c >= 'a' && c <= 'z';
}

int intersection(vector<string> v1, vector<string> v2) {
    int ret = 0;
    
    for(int i=0; i<v2.size(); i++) {
        int flag = -1;
        
        for(int j=0; j<v1.size(); j++)
            if(v1[j] == v2[i]) {
                flag = j;
                break;
            }
        
        if(flag >= 0) {
            ret++;
            v1.erase(v1.begin()+flag);
        }
    }
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    string s;
    
    for(int i=0; i<str1.size(); i++)
            str1[i] = tolower(str1[i]);
    for(int i=0; i<str2.size(); i++)
            str2[i] = tolower(str2[i]);
    
    vector<string> v1, v2;
    for(int i=0; i<str1.size()-1; i++) {
        s = string() + str1[i] + str1[i+1];
        if(chk(str1[i]) && chk(str1[i+1])) v1.push_back(s);
    }
    for(int i=0; i<str2.size()-1; i++) {
        s = string() + str2[i] + str2[i+1];
        if(chk(str2[i]) && chk(str2[i+1])) v2.push_back(s);
    }
    
    int inter, uni = v1.size() + v2.size();
    if(uni == 0) return 65536;
    
    if(v1.size() > v2.size())
        inter = intersection(v1, v2);
    else
        inter = intersection(v2, v1);
    
    uni -= inter;
    if(uni == 0) return 65536;
    
    return (double)inter / uni * 65536;
}  