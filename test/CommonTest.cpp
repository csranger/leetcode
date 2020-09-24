#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    // string s = "3[a2[c]]"，不改变 s
    string decodeString(string s) {
        stack<string> strStk;
        stack<int> numStk;
        string str;
        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                strStk.emplace(str);
                str = strStk.top();
                num = numStk.top();

                string temp;
                while (num-- > 0) temp += str;
                numStk.pop();
                strStk.pop();
                strStk.push(temp);
                // 清零
                str = "";
                num = 0;
            }
            if (s[i] == '[') {
                numStk.push(num);
                num = 0;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                if (str.size() > 0) strStk.push(str);
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] >= 'a' && s[i] <= 'z') {
                str += s[i];
            }
        }
    }
};

int main()
{
    string s = "3[a2[c]]";
    Solution ss;
    cout << ss.decodeString(s) << endl;


    return 0;
}