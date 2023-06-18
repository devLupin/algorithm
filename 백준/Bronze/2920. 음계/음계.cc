#include<iostream>
using namespace std;
int main(void) {
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false);
	int arr[8] = { 0, };
	bool asc = true, des = true, mix = true;
	bool a = false, d = false, m = false;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if (i == 0) continue;
		if (arr[i] > arr[i - 1] && !d) {
			d = true; des = false;
		}
		else if (arr[i] < arr[i - 1] && !a) {
			a = true; asc = false;
		}
		else if(!m) {
			m = true; mix = false;
		}
	}
	if (asc)
		cout << "ascending";
	else if (des)
		cout << "descending";
	else
		cout << "mixed";
}