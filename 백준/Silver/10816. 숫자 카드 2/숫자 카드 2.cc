#include <bits/stdc++.h>
using namespace std;

int N, M, A[500'005];

// 가장 처음 x보다 작은 수를 만나는 순간 + 1
int lower(int x) {
    int mid, st = 0, en = N;
    
    while (st < en) {
        mid = (st + en) / 2;

        if (A[mid] >= x) en = mid;
        else st = mid + 1;
    }

    return st;
}

// 가장 처음 x보다 큰 수를 만나는 순간
int upper(int x) {
    int mid, st = 0, en = N;

    while (st < en) {
        mid = (st + en) / 2;
        
        if (A[mid] > x) en = mid;
        else st = mid + 1;
    }

    return st;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    cin >> M;
    for (int x, i = 0; i < M; i++) {
        cin >> x;
        cout << upper(x) - lower(x) << ' ';
    }

    return 0;
}