//
// Created by zhaohailong on 2020/6/29.
//

#include <vector>

using namespace std;

/*
 * value : 线段树数组
 * nums : 原始数组
 * pos : 当前value索引
 * left : 当前线段左端点
 * right : 当前线段右端点
 */
void BuildSegmentTree(vector<int> &value, vector<int> &nums, int pos, int left, int right)
{
    if (left == right) {
        value[pos] = nums[left];
        return;
    }

    int mid = (left + right) / 2;
    BuildSegmentTree(value, nums, 2 * pos + 1, left, mid);
    BuildSegmentTree(value, nums, 2 * pos + 2, mid + 1, right);

    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}