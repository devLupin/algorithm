#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int,int>;

int solution(string dirs) {
    map<string, int> mp;
    int ans = 0;
    pii cur = {0, 0};
    
    for(char d : dirs) {
        int x, y;
        
        if(d == 'U') {
            x = cur.X;
            y = cur.Y + 1;
        }
        else if(d == 'D') {
            x = cur.X;
            y = cur.Y - 1;
        }
        else if(d == 'L') {
            x = cur.X - 1;
            y = cur.Y;
        }
        else if(d == 'R') {
            x = cur.X + 1;
            y = cur.Y;
        }
        
        if(x >= -5 && y >= -5 && x <= 5 && y <= 5) {
            string str1 = to_string(x) + " " + to_string(y) + " " + to_string(cur.X) + " " + to_string(cur.Y);
            string str2 = to_string(cur.X) + " " + to_string(cur.Y) + " " + to_string(x) + " " + to_string(y);
            cur = {x, y};
            
            if(mp[str1] > 0 || mp[str2] > 0) continue;
            else {
                mp[str1]++;
                mp[str2]++;
                ans++;
            }
        }
    }
    
    
    return ans;
}