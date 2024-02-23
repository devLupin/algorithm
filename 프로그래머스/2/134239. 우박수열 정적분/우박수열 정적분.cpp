#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<int,int>> v;
    v.push_back({0, k});
    
    for(int i = 1; k != 1; i++) {
        if(k % 2) k = k * 3 + 1;
        else k /= 2;
        v.push_back({i, k});
    }
    
    for(auto nxt : ranges) {
        int s = nxt[0];
        int e = v.size() - 1 + nxt[1];
        
        if(s > e) answer.push_back(-1.0);
        else {
            double res = 0.0;
            for(int i = s; i < e; i++)
                res += (double)(v[i].second + v[i+1].second) / 2;
            answer.push_back(res);
        }
    }
    
    return answer;
}