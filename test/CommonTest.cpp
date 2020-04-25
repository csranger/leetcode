#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;

        int visit[4] = { 0 };

        sort(nums.begin(), nums.end(), greater<int>());

        return Dfs(nums, visit, 0, target);
    }

    bool Dfs(vector<int> &nums, int visit[], int i, int target)
    {
        if (visit[0] == target && visit[1] == target && visit[2] == target && visit[3] == target) {
            return true;
        }

        for (int j = 0; j < 4; j++) {
            if (nums[i] + visit[j] > target) {
                continue;
            }
            visit[j] += nums[i];
            if (Dfs(nums, visit, i + 1, target)) return true;
            visit[j] -= nums[i];
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 2};
    Solution s;
    cout << s.makesquare(nums) << endl;
}











