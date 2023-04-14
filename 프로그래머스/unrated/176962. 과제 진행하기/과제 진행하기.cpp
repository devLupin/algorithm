#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;
using pii = pair<int, int>;

struct Plan{
    string name;
    int start;
    int playtime;
    
    Plan(string a, string b, string c) {
        name = a;
        int time = (ctoi(b[0]) * 10 + ctoi(b[1])) * 60;
        start = time + (ctoi(b[3]) * 10 + ctoi(b[4]));
        playtime = stoi(c);
    }
    
    Plan(string a, int b, int c) {
        name = a;
        start = b;
        playtime = c;
    }
    
    int ctoi(char c) {
        return c - '0';
    }
    
    bool operator< (const Plan &other) const {
        return start > other.start;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Plan> pq;
    stack<Plan> s;
    
    for(auto p : plans)
        pq.push(Plan(p[0], p[1], p[2]));    
    
    int cur_time = 0;
    while(!pq.empty()) {
        Plan now = pq.top();
        
        if(!s.empty()) {
            Plan node = s.top();
            s.pop();
            
            if(now.start > cur_time) {
                pq.push(Plan(node.name, cur_time, node.playtime));
                continue;
            }
            else {
                s.push(node);
            }
        }
        
        pq.pop();
        Plan next = pq.top();
        cur_time = now.start + now.playtime;
        
        if (cur_time <= next.start) {
            answer.push_back(now.name);
        }
        else {
            s.push(Plan(now.name, now.start, now.playtime - (next.start - now.start)));
        }
    }
    
    while(!s.empty()) {
        Plan cur = s.top();
        s.pop();
        
        answer.push_back(cur.name);
    }
    
    return answer;
}