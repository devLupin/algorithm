#include <bits/stdc++.h>
using namespace std;

bool cmp0(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
bool cmp1(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
bool cmp2(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}
bool cmp3(vector<int> &a, vector<int> &b) {
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> ans;
    
    for(auto cur : data) {
        if(ext == "code") {
            if(cur[0] < val_ext) ans.push_back(cur);
        }
        else if(ext == "date") {
            if(cur[1] < val_ext) ans.push_back(cur);
        }
        else if(ext == "maximum") {
            if(cur[2] < val_ext) ans.push_back(cur);
        }
        else if(ext == "remain") {
            if(cur[3] < val_ext) ans.push_back(cur);
        }
    }
    
    if(sort_by == "code") sort(ans.begin(), ans.end(), cmp0);
    else if(sort_by == "date") sort(ans.begin(), ans.end(), cmp1);
    else if(sort_by == "maximum") sort(ans.begin(), ans.end(), cmp2);
    else if(sort_by == "remain") sort(ans.begin(), ans.end(), cmp3);
    
    return ans;
}