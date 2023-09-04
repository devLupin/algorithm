#include <bits/stdc++.h>
using namespace std;

int mon_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
struct user {
	string name;
	int rental_t;
};

int mon2day(int month) {
	if (month == 1) return 0;

	int ret = 0;
	for (int i = 0; i < month - 1; i++) ret += mon_days[i];

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int len;
	int fine;
	string s_dur;
	int duration = 0;
	map<string, map<string, user>> rentals;
	map<string, long long> ans;

	cin >> len >> s_dur >> fine;

	duration += stoi(s_dur.substr(0, 3)) * 1440;
	duration += stoi(s_dur.substr(4, 2)) * 60;
	duration += stoi(s_dur.substr(7, 2));

	for (int i = 0; i < len; i++) {
		string ymd, time, part, name;
		int cur_t = 0;
		cin >> ymd >> time >> part >> name;

		cur_t += mon2day(stoi(ymd.substr(5, 2))) * 1440;
		cur_t += stoi(ymd.substr(8, 2)) * 1440;
		cur_t += stoi(time.substr(0, 2)) * 60;
		cur_t += stoi(time.substr(3, 2));

		if (rentals.find(part) != rentals.end() && rentals[part].find(name) != rentals[part].end()) {
			int rented = cur_t - rentals[part][name].rental_t;

			if (rented > duration) 
            	ans[name] += (long long)((rented - duration) * fine);
		
			rentals[part].erase(name);
			if (rentals[part].empty()) rentals.erase(part);
		}
		else rentals[part][name] = { name, cur_t };
	}

	if (ans.empty()) cout << -1;
	else
		for (auto user : ans) cout << user.first << " " << user.second << '\n';
    
    return 0;
}