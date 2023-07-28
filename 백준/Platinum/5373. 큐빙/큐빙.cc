#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> rotateRight(vector<vector<char>> cube){
    vector<vector<char>> tmp(3, vector<char>(3, ' '));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tmp[j][3 - i - 1] = cube[i][j];
        }
    }
    
    return tmp;
}

vector<vector<char>> rotateLeft(vector<vector<char>> cube){
    vector<vector<char>> tmp(3, vector<char>(3, ' '));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tmp[3 - j - 1][i] = cube[i][j];
        }
    }
    
    return tmp;
}

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        vector<string> v;
        vector<vector<char>> up(3, vector<char>(3, 'w'));
        vector<vector<char>> down(3, vector<char>(3, 'y'));
        vector<vector<char>> front(3, vector<char>(3, 'r'));
        vector<vector<char>> back(3, vector<char>(3, 'o'));
        vector<vector<char>> left(3, vector<char>(3, 'g'));
        vector<vector<char>> right(3, vector<char>(3, 'b'));

        cin >> t;

        for(int j = 0; j < t; j++){
            string s;
            
            cin >> s;
            v.push_back(s);
        }

        for(int j = 0; j < v.size(); j++){
            vector<char> tmp;

            switch(v[j][0]){
                case 'U':
                    if(v[j][1] == '-'){
                        tmp = right[0];
                        right[0] = front[0];
                        front[0] = left[0];
                        left[0] = back[0];
                        back[0] = tmp;
                        up = rotateLeft(up);
                    }
                    else{
                        tmp = left[0];
                        left[0] = front[0];
                        front[0] = right[0];
                        right[0] = back[0];
                        back[0] = tmp;
                        up = rotateRight(up);
                    }
                    break;
                case 'D':
                    if(v[j][1] == '-'){
                        tmp = right[2];
                        right[2] = back[2];
                        back[2] = left[2];
                        left[2] = front[2];
                        front[2] = tmp;
                        down = rotateLeft(down);
                    }
                    else{
                        tmp = left[2];
                        left[2] = back[2];
                        back[2] = right[2];
                        right[2] = front[2];
                        front[2] = tmp;
                        down = rotateRight(down);
                    }
                    break;
                case 'F':
                    if(v[j][1] == '-'){
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(right[k][0]);
                        }

                        for(int k = 0; k < 3; k++){
                            right[k][0] = down[0][2 - k];
                            down[0][2 - k] = left[2 - k][2];
                            left[2 - k][2] = up[2][k];
                            up[2][k] = tmp[k];
                        }
                        front = rotateLeft(front);
                    }
                    else{
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(left[k][2]);
                        }
                        
                        for(int k = 0; k < 3; k++){
                            left[k][2] = down[0][k];
                            down[0][k] = right[2 - k][0];
                            right[2 - k][0] = up[2][2 - k];
                            up[2][2 - k] = tmp[k];
                        }
                        front = rotateRight(front);
                    }
                    break;
                case 'B':
                    if(v[j][1] == '-'){
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(left[k][0]);
                        }

                        for(int k = 0; k < 3; k++){
                            left[k][0] = down[2][k];
                            down[2][k] = right[2 - k][2];
                            right[2 - k][2] = up[0][2 - k];
                            up[0][2 - k] = tmp[k];
                        }
                        back = rotateLeft(back);
                    }
                    else{
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(right[k][2]);
                        }

                        for(int k = 0; k < 3; k++){
                            right[k][2] = down[2][2 - k];
                            down[2][2 - k] = left[2 - k][0];
                            left[2 - k][0] = up[0][k];
                            up[0][k] = tmp[k];
                        }
                        back = rotateRight(back);
                    }
                    break;
                case 'L':
                    if(v[j][1] == '-'){
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(front[k][0]);
                        }

                        for(int k = 0; k < 3; k++){
                            front[k][0] = down[k][0];
                            down[k][0] = back[2 - k][2];
                            back[2 - k][2] = up[k][0];
                            up[k][0] = tmp[k];
                        }
                        left = rotateLeft(left);
                    }
                    else{
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(back[k][2]);
                        }

                        for(int k = 0; k < 3; k++){
                            back[k][2] = down[2 - k][0];
                            down[2 - k][0] = front[2 - k][0];
                            front[2 - k][0] = up[2 - k][0];
                            up[2 - k][0] = tmp[k];
                        }
                        left = rotateRight(left);
                    }
                    break;
                case 'R':
                    if(v[j][1] == '-'){
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(back[k][0]);
                        }

                        for(int k = 0; k < 3; k++){
                            back[k][0] = down[2 - k][2];
                            down[2 - k][2] = front[2 - k][2];
                            front[2 - k][2] = up[2 - k][2];
                            up[2 - k][2] = tmp[k];
                        }
                        right = rotateLeft(right);
                    }
                    else{
                        for(int k = 0; k < 3; k++){
                            tmp.push_back(front[k][2]);
                        }

                        for(int k = 0; k < 3; k++){
                            front[k][2] = down[k][2];
                            down[k][2] = back[2 - k][0];
                            back[2 - k][0] = up[k][2];
                            up[k][2] = tmp[k];
                        }
                        right = rotateRight(right);
                    }
                    break;
            }
        }

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cout << up[j][k];
            }
            cout << endl;
        }
    }
    
    return 0;
}