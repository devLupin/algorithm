#include <bits/stdc++.h>
using namespace std;

int arr[55][55];

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    for(int i=1; i<=N; i++) memset(arr[i], 0x3f3f3f, sizeof(arr[i]));
    
    for(auto nxt : road)
        arr[nxt[0]][nxt[1]] = arr[nxt[1]][nxt[0]] = min(arr[nxt[1]][nxt[0]], nxt[2]);

    for(int k=1; k<=N; k++) 
	    for(int i=1; i<=N; i++) 
		    for(int j=1; j<=N; j++) 
			    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]); 
    
    for(int i=1; i<=N; i++) arr[i][i] = 0;
    
    for(int i=1; i<=N; i++)
        if(arr[1][i] <= K) answer++;
    
    return answer;
}