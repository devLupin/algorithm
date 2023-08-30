#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, k, cnt = 0;
    char c;
    vector<char> v;
    
    cin >> N >> k;
    for(int i = 0; i < N; i++){
        cin >> c;
        v.push_back(c);
    }

    for(int i = 0; i < N; i++){
        if(v[i] != 'P')continue;
        for(int j = i - k; j <= i + k; j++){
            if(0 <= j && j < N && v[j] == 'H'){
                v[j] = '0';
                cnt++;
                break;
            }
        }

    }
    cout << cnt;

    return 0;
}