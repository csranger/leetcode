//
// Created by zhaohailong on 2020/8/11.
//

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string decodeString(string s)
    {
        return decode(s);
    }

    string decode(string s)
    {
        if (s.find_first_of(']') == string::npos) {
            return s;
        }

        int r = s.find_first_of(']');
        int l = s.rfind('[', r);
        int ll = 0;
        int num = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (s[i] - '0' > 9 || s[i] - '0' < 0) {
                ll = i;
                break;
            }
            num = num + (s[i] - '0') * pow(10, l - i - 1);
        }
        string temp = "";
        for (int i = 0; i < num; i++) {
            temp += s.substr(l + 1, r - l - 1);
        }
        string w;
        if (ll != 0) w = s.substr(0, ll + 1);

        string sw = w + temp + s.substr(r + 1);

        return decode(sw);
    }
};