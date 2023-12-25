#include <bits/stdc++.h>
using namespace std;

struct info {
    string head;
    int num;
    int n;
};

bool compare(info& a, info& b) {
    if (a.head == b.head) {
        if (a.num == b.num) return a.n < b.n;
        return a.num < b.num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> origin(files.begin(), files.end());
    
    for (int i = 0; i < files.size(); i++) {
        for (int j = 0; j < files[i].size(); j++) {
            files[i][j] = tolower(files[i][j]);
        }
    }

    vector<info> v;
    for (int j = 0; j < files.size(); j++) {
        string f = files[j];
        int i;
        for (i = 0; i < f.size(); i++)
            if (f[i] >= '0' && f[i] <= '9') break;

        string head = f.substr(0, i);
        string num = "";
        for (; i < f.size(); i++) {
            if (f[i] >= '0' && f[i] <= '9') num += f[i];
            else break;
        }
        cout << head << ' ' << num << '\n';
        v.push_back({ head, stoi(num), j });
    }

    sort(v.begin(), v.end(), compare);

    vector<string> ans;
    for(auto nxt : v) ans.push_back(origin[nxt.n]);
    
    return ans;
}