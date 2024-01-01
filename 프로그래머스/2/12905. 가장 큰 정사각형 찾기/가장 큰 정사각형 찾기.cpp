#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int ans = board[0][0];
    int R = board.size();
    int C = board[0].size();
    
    for(int i=1; i<R; i++) {
        for(int j=1; j<C; j++) {
            if(board[i][j] == 1) {
                board[i][j] = 1 + min({board[i-1][j-1], board[i-1][j], board[i][j-1]});
                ans = max(ans, board[i][j]);
            }
        }
    }

    return ans*ans;
}