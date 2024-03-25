#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};

int solution(vector<int> arrows) {
    int answer = 0;
    map<pii, bool> node;
    map<pair<pii, pii>, bool> edge;
    
    int x = 0, y = 0;
    node[{x, y}] = true;
    
    for(int dir : arrows) {
        int cnt = 2;
        
        while(cnt--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(node[{nx, ny}] && !edge[{{x, y}, {nx, ny}}]) answer++;
            else node[{nx, ny}] = true;
            
            edge[{{x, y}, {nx, ny}}] = true;
            edge[{{nx, ny}, {x, y}}] = true;
            
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}