//
// Created by zhaohailong on 2020/8/10.
//

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    // 找到了返回 true，找不到换个位置找
                    if (Dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

    // 从起始点 x,y 开始在 board 里搜索 word
    bool Dfs(vector<vector<char>> &board, int x, int y, const string &word, int step)
    {
        if (board[x][y] != word[step] || step >= word.size()) {
            return false;
        }
        if (step == word.size() - 1) {
            return true;
        }

        // 核心，从 x,y 开始深搜时先保存当前结点，如果失败在回退。board[x][y] = 0;
        // 是为了再次搜索这个位置肯定走不通，因为不等于目标word
        char temp = board[x][y];
        board[x][y] = 0;

        static const int dx[] = { -1, 1, 0, 0 };
        static const int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newY < 0 || newX >= board.size() || newY >= board[newX].size()) {   // 剪枝
                continue;
            }
            if (board[newX][newY] != 0) {       // 剪枝
                if (Dfs(board, newX, newY, word, step + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = temp;
        return false;
    }
};




