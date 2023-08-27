#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string tmp = "", ans;

	for(int i=1; i<food.size(); i++) {
		int div = food[i] / 2;
		for(int j=0; j<div; j++) tmp += i+'0';
	}

	ans = tmp + '0';
	for(int i=tmp.size()-1; i>=0; i--) ans += tmp[i];

    return ans;
}