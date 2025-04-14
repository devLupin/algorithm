#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) 
{
    vector<int> arr(26, -1);
    vector<int> answer;
    
    for(int i=0; i<s.size(); i++)
    {
        if(arr[s[i] - 'a'] == -1) answer.push_back(-1);
        else answer.push_back(i - arr[s[i] - 'a']);
        arr[(s[i] - 'a')] = i;
    }
    
    return answer;
}