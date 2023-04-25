#include <string>
#include <vector>

using namespace std;

bool check(vector<string> board, char c) 
{
    for(int i=0; i<3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;
    }
    
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int f_cnt=0, s_cnt=0;
    for(string s : board) {
        for(char c : s) {
            if(c == 'O')
                f_cnt++;
            else if(c == 'X')
                s_cnt++;
        }
    }
    
    if(f_cnt < s_cnt || 1 < f_cnt - s_cnt)
        return 0;
    
    bool f_sign = check(board, 'O');
    bool s_sign = check(board, 'X');
    
    if(f_sign && s_sign) return 0;
    if(f_sign && f_cnt-s_cnt != 1) return 0;
    if(s_sign && f_cnt != s_cnt) return 0;
    
    return 1;
}