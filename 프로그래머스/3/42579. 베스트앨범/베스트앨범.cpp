#include <bits/stdc++.h>
using namespace std;

typedef struct info {
    vector<pair<int, int>> idx;
    int sum;

    info() {
        idx = {};
        sum = 0;
    }
};

bool compare(pair<string, info> a, pair<string, info> b) {
    return a.second.sum > b.second.sum;
}
bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, info> mp;
    for (int i = 0; i < genres.size(); i++) {
        mp[genres[i]].idx.push_back({ plays[i], i });
        mp[genres[i]].sum += plays[i];
    }

    vector<pair<string, info>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        string key = v[i].first;
        vector<pair<int, int>> val = v[i].second.idx;

        sort(val.begin(), val.end(), compare2);
        v[i].second.idx = val;
    }

    vector<int> ans;
    for (int i = 0; i < v.size(); i++) {
        int sz = min((int)v[i].second.idx.size(), 2);
        for (int j = 0; j < sz; j++) ans.push_back(v[i].second.idx[j].second);
    }

    return ans;
}