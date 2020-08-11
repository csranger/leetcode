//
// Created by zhaohailong on 2020/4/18.
//

/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        wordList.push_back(beginWord);
        map<string, vector<string>> strMap;
        for (int i = 0; i < wordList.size(); i++) {
            strMap[wordList[i]] = vector<string>();
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (Connect(wordList[i], wordList[j])) {
                    strMap[wordList[i]].push_back(wordList[j]);
                    strMap[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        set<string> visit;
        return  Bfs(strMap, visit, beginWord, endWord);
    }

    // set<pair<string ,int>> visit <结点，步数>
    int Bfs(map<string, vector<string>> &strMap, set<string> &visit, string &beginWord, string &endWord) {
        queue<pair<string, int>> searchQueue;
        searchQueue.push(make_pair(beginWord, 1));
        visit.insert(beginWord);

        while (!searchQueue.empty()) {
            string cur = searchQueue.front().first;
            int step = searchQueue.front().second;
            searchQueue.pop();

            if (cur == endWord) {
                return step;
            }

            for (string &word: strMap[cur]) {
                if (visit.find(word) != visit.end()) {
                    continue;
                }

                searchQueue.push(make_pair(word, step + 1));
                visit.insert(word);
            }
        }
        return 0;
    }

    bool Connect(const string &str1, const string &str2) {
        int num = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                num++;
            }
        }
        return num == 1;
    }
};