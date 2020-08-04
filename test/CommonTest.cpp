#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int index[26] = {0};
        for (int i = 0; i < S.length(); i++) {
            index[S[i] - 'a'] = i;
        }

        int startJumpPos = 0;
        vector<int> ret;
        while (startJumpPos < S.length()) {
            // 从 startJumpPos 出开始跳跃
            int maxPos = index[S[startJumpPos] - 'a'];
            int i = startJumpPos + 1;
            while (i < S.length() && i <= maxPos) {
                maxPos = max(maxPos, index[S[i] - 'a']);
                i++;
            }
            ret.push_back(maxPos - startJumpPos + 1);
            startJumpPos = maxPos + 1;
        }
        return ret;
    }
};

int main() {
    string str = "ababcbacadefegdehijhklij";
    Solution s;
    s.partitionLabels(str);

    return 0;
}