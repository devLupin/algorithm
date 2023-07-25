#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    string tmp = "";
    for(int i=0; i<str.size(); i++) {
        tmp += str[i];
    
        if(tmp.size() >= bomb.size()) {
            bool flag = true;

            for(int j=0; j<bomb.size(); j++) {
                if(tmp[tmp.size() - bomb.size() + j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) tmp.erase(tmp.size() - bomb.length(), tmp.size());
        }
    }

    cout << (tmp.empty() ? "FRULA" : tmp);

    return 0;
}