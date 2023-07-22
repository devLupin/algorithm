#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;

#define MAX 50001
#define INF 987654321

vector<pii> vec[MAX];
vector<int> dist(MAX, INF);

void dijkstra(int s){
    priority_queue<pii> pq; pq.push({0, s});
    dist[s]=0;
    
    while(!pq.empty()){
        pii t=pq.top(); pq.pop();
        int cur=t.second; int d=t.first*-1;
        
        if(dist[cur]<d) continue;
        for(pii v : vec[cur]){
            int nxt = v.first;
            int nxt_d = v.second+d;
            
            if(nxt_d < dist[nxt]){
                dist[nxt] = nxt_d;
                pq.push({nxt_d*-1, nxt});
            }
        }
    }
}
int main(){
    int N, M; cin>>N>>M;
    
    while(M--){
        int s,e,w; cin>>s>>e>>w;
        vec[s].push_back({e, w});
        vec[e].push_back({s, w});
    }
    
    dijkstra(1);
    
    cout << dist[N];
    
    return 0;
}