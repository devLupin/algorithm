#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct {
	int year, month, day;
}date;

vector<string> split(string str, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	ret.push_back(str);
	return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	
	auto today_split = split(today, ".");
	date start = { stoi(today_split[0]), stoi(today_split[1]), stoi(today_split[2]) };

	vector<pair<string,int>> type(terms.size());
	for (int i = 0; i < terms.size(); i++) {
		auto cur = split(terms[i], " ");
		type[i] = { cur[0], stoi(cur[1]) };
	}

	for (int i = 0; i < privacies.size(); i++) {
		auto cur = split(privacies[i], " ");
		auto comp_date = split(cur[0], ".");
		auto comp_term = cur[1];

		date comp = { stoi(comp_date[0]), stoi(comp_date[1]), stoi(comp_date[2]) };

		for (int j = 0; j < type.size(); j++) {
			auto cur_term = type[j].first;
			if (cur_term == comp_term) {
				int cur_w = type[j].second;
				cur_w *= 28;

				int add_year = cur_w / (28 * 12);
				int add_month = cur_w % (28 * 12) / 28;
				int add_day = cur_w % (28 * 12) % 28;

				comp.year += add_year;
				comp.month += add_month;
				comp.day += add_day - 1;

				if (comp.day > 28) {
					comp.month++;
					comp.day %= 28;
				}
				else if (comp.day == 0) {
					comp.month--;
					comp.day = 28;
				}

				if (comp.month > 12) {
					comp.year++;
					comp.month -= 12;
				}
				else if (comp.month == 0) {
					comp.year--;
					comp.month = 12;
				}

				if (comp.year > start.year)
					continue;
				else if (comp.year == start.year) {
					if (comp.month > start.month)
						continue;
					else if (comp.month == start.month) {
						if (comp.day >= start.day)
							continue;
					}
				}

				answer.push_back(i + 1);
				break;
			}
		}
	}
	
	return answer;
}