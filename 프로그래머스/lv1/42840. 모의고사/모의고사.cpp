#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int req1[] = {1,2,3,4,5};
int req2[] = {2,1,2,3,2,4,2,5};
int req3[] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    int ans1=0, ans2=0, ans3=0;
    
    for(int i=0; i<answers.size(); i++) {
        if(req1[i%5] == answers[i]) ans1++;
        if(req2[i%8] == answers[i]) ans2++;
        if(req3[i%10] == answers[i]) ans3++;
    }
    
    int max_val = max({ans1, ans2, ans3});
    vector<int> ret;
    if(ans1 == max_val) ret.push_back(1);
    if(ans2 == max_val) ret.push_back(2);
    if(ans3 == max_val) ret.push_back(3);
    
    return ret;
}