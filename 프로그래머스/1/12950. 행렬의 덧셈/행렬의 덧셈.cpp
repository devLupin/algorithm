#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> ans;
    
    for(int i=0; i<arr1.size(); i++)
    {
        ans.push_back({});
        for(int j=0; j<arr1[0].size(); j++)
        {
            ans[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    
    return ans;
}