#include <iostream>
#include <vector>

using namespace std;

enum State {
    BEGIN = 0,
    UP = 1,
    DOWN = 2
};

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        State state = BEGIN;
        int ret = 1;
        switch (state) {
            case BEGIN:
                if (nums)
        }
    }
};

int main()
{
    vector<int> g = { 1, 2, 3 };
    vector<int> s = { 1, 1 };
    Solution solution;
    cout << solution.findContentChildren(g, s) << endl;

    return 0;
}