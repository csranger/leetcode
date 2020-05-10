//
// Created by zhaohailong on 2020/5/11.
//

#include <vector>

using namespace std;

//循环方式的二分查找
bool BinartSearch(vector<int> &sortedArray, int target)
{
    int begin = 0;
    int end = sortedArray.size() - 1;

    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (sortedArray[mid] < target) {
            begin = mid + 1;
        } else if (sortedArray[mid] > target) {
            end = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

// 递归形式的二分查找
bool BinarySearch(vector<int> &sortedArray, int begin, int end, int target)
{
    if (begin >= end) {
        return false;
    }

    int mid = (end + begin) / 2;
    if (sortedArray[mid] < target) BinarySearch(sortedArray, mid + 1, end, target);
    else if (sortedArray[mid] > target) BinarySearch(sortedArray, begin, mid - 1, target);
    else return true;
}