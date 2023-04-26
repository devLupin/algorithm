#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) 
{
    map<int, int> m;
    for(int t : tangerine) m[t]++;
    
    vector<int> v;
    for(auto u : m)
        v.push_back(~u.second);
    
    sort(v.begin(), v.end());
    
    int answer=0, cnt=0;
    for(int i : v) {
        if (cnt >= k) break;
        answer++;
        cnt += ~i;
    }
    
    return answer;
}