#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        vector<int> visit;
        ret.push_back(visit);
        Dfs(nums, visit, 0, ret);
        return ret;
    }

    void Dfs(vector<int> &nums, vector<int> &visit, int i, vector<vector<int>> &ret)
    {
        if (i >= nums.size()) {
            return;
        }

        visit.push_back(nums[i]);
        ret.push_back(visit);
        Dfs(nums, visit, i + 1, ret);
        visit.pop_back();
        Dfs(nums, visit, i + 1, ret);
    }
};











