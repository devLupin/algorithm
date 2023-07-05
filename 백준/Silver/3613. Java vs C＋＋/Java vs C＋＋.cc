#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    bool is_upper = false;
    bool is_bar = false;
    bool is_err = false;
    
    string str;
    cin >> str;

    for(char c : str) {
        if(c == '_') is_bar = true;
        if(c >= 'A' && c <= 'Z') is_upper = true;

        if(is_upper && is_bar) {
            is_err = true;
            break;
        }
    }

    if(str[0] >= 'A' && str[0] <= 'Z') is_err = true;
    if(str[0] == '_') is_err = true;
    if(str[str.size() - 1] == '_') is_err = true;

    for(int i=0; i<str.size() - 1; i++) {
        if(str[i] == '_' && str[i+1] == '_') {
            is_err = true;
            break;
        }
    }

    if(is_err) {
        cout << "Error!";
        return 0;
    }

    string ans = "";
    if(is_upper) {
        for(char c : str) {
            if(c >= 'A' && c <= 'Z') {
                ans += '_';
                ans += (c - 'A' + 'a');
            }
            else ans += c;
        }
    }

    else {
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '_') {
                ans += (str[i+1] - 'a' + 'A');
                i++;
            }
            else ans += str[i];
        }
    }

    cout << ans;
    return 0;
}