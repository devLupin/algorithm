#include <bits/stdc++.h>
using namespace std;

int N, U[1005];
vector<int> add;

bool binary_search(int target) {
    int mid, st = 0, en = add.size() - 1;

    while (st <= en) {
        mid = (st + en) / 2;

        if (add[mid] == target) return true;
        else if (add[mid] < target) st = mid + 1;
        else en = mid - 1;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> U[i];

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            add.push_back(U[i] + U[j]);

    sort(U, U + N);
    sort(add.begin(), add.end());

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(U[i] - U[j])) {
                cout << U[i];
                return 0;
            }
        }
    }
}