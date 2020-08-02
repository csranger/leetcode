#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static bool less(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), less);
        int left = points[0][0];
        int right = points[0][1];
        int minShots = 1;
        for (int i = 1; i < points.size(); i++) {
            if (right < points[i][0]) {
                minShots++;
                left = points[i][0];
                right = points[i][1];
            } else {
                left = points[i][0];
                right = right > points[i][1] ? points[i][1] : right;
            }
        }
        return minShots;
    }
};

int main() {
    vector<vector<int>> nums = {{3, 9},
                                {7, 12},
                                {3, 8},
                                {6, 8},
                                {9, 10},
                                {2, 9},
                                {0, 9},
                                {3, 9},
                                {0, 6},
                                {2, 8}};
    Solution s;
    cout << s.findMinArrowShots(nums) << endl;

    return 0;
}