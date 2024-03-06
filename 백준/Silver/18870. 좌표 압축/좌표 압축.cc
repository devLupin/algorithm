#include <bits/stdc++.h>
using namespace std;

int N, A[1'000'000];
vector<int> tmp, uni;

int binary_search(int x) {
    int st = 0, en = uni.size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;

        if (uni[mid] == x) return mid;
        else if (uni[mid] < x) st = mid + 1;
        else en = mid - 1;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        tmp.push_back(A[i]);
    }
    sort(tmp.begin(), tmp.end());
    
    for (int i = 0; i < N; i++)
        if (i == 0 || tmp[i] != tmp[i - 1]) uni.push_back(tmp[i]);

    for (int i = 0; i < N; i++)
        cout << binary_search(A[i]) << ' ';

    return 0;
}