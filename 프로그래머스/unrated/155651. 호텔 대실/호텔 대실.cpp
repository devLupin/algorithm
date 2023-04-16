#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Room{
	int start, end;

	Room(string s, string e) {
		start = convert_min(s);
		end = convert_min(e);
	}

	Room(int s, int e) {
		start = s;
		end = e;
	}

	int convert_min(string time) {
		int hour = (time[0] * 10 + time[1]) * 60;
		int min = (time[3] * 10 + time[4]) + hour;

		return min;
	}

	bool operator< (const Room &other) const {
		return start > other.start;
	}
};

int solution(vector<vector<string>> book_time) 
{
	priority_queue<Room> pq;

	for (int i = 0; i < book_time.size(); i++) {
		pq.push(Room(book_time[i][0], book_time[i][1]));
	}

	vector<int> v;

	while (!pq.empty()) {
		Room now = pq.top();
		pq.pop();

		bool chk = false;
		for (int i = 0; i < v.size(); i++) {
			if (now.start >= v[i]) {
				v[i] = now.end + 10;
				chk = true;
				break;
			}
		}
		if(!chk)
			v.push_back(now.end + 10);
	}
	
	return v.size();
}