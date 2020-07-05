//
// Created by zhaohailong on 2020/7/5.
//

/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]

输出:
2

解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0) {
            return 0;
        }

        sort(points.begin(), points.end(), Compare);    // 按照左端点从小到大排序
        int shootNum = 1;                               // 初始化弓箭手数量
        int shootLeft = points[0][0];                   // 初始化射击区间
        int shootRight = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (shootRight < points[i][0]) {
                shootNum++;
                shootLeft = points[i][0];
                shootRight = points[i][1];
                continue;
            }
            shootLeft = points[i][0];
            shootRight = shootRight > points[i][1] ? points[i][1] : shootRight;
        }
        return shootNum;
    }

    static bool Compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};