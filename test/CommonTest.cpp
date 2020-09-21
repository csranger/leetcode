#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    vector<vector<int>> subsets(vector<int> &nums) {
        Backtrack(nums, 0);
        return ans;
    }

    void Backtrack(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(vec);
            return;
        }

        // 选择当前位置
        vec.push_back(nums[start]);
        Backtrack(nums, start + 1);
        // 不选择当前位置
        vec.pop_back();
        Backtrack(nums, start + 1);

    }
};