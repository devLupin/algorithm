#include <bits/stdc++.h>
using namespace std;

int N, A[1'000'000];
vector<int> uni;

int lower_bound(int x) {
    int st = 0, en = uni.size();
    while (st < en) {
        int mid = (st + en) / 2;

        if (uni[mid] >= x) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        uni.push_back(A[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i = 0; i < N; i++)
        cout << lower_bound(A[i]) << ' ';

    return 0;
}