//
// Created by zhaohailong on 2020/4/25.
//

/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 队列中存放此元素
struct Qitem {
    string m_word;
    int m_step;
    int m_parentPos;      // 前驱结点在队列中的位置
    Qitem(string word, int step, int parentPos)
        : m_word(word), m_step(step), m_parentPos(parentPos)
    {}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> graph;

        ConstructGraph(beginWord, wordList, graph);

        map<string, int> visit;         // 存储结点及其对应的步数(起始点到此结点所需步数)
        vector<Qitem> qe;
        vector<int> endWordPos;
        Bfs(graph, visit, beginWord, endWord, qe, endWordPos);

        vector<vector<string>> ret;
        for (int i = 0; i < endWordPos[i]; i++) {
            int parentPos = endWordPos[i];
            vector<string> path;
            while (parentPos != -1) {
                string &word = qe[parentPos].m_word;
                path.push_back(word);
                parentPos = qe[parentPos].m_parentPos;
            }
            ret.push_back(vector<string>());
            for (int j = path.size() -1 ; j >= 0; j--) {
                ret[i].push_back(path[j]);
            }
        }
        return ret;
    }

private:
    void Bfs(map<string, vector<string>> &graph, map<string, int> &visit, const string &beginWord,
             const string &endWord, vector<Qitem> &qe, vector<int> &endWordPos)
    {
        int minStep = 0;

        qe.push_back(Qitem(beginWord, 1, -1));  // (1)起始结点的[前驱结点]在队列的索引设为 -1
        visit[beginWord] = 1;                   // (2)搜索过结点使用map，也保存着步数信息，起始单词步数为 1

        int front = 0;         // (3)队列头指针front，指向 vector 表示的队列头，这样不要pop掉已访问的结点

        // 从 beginWord 开始宽搜
        while (front != qe.size()) {        // 标记队列为空，队列使用 vector<Qitem> 表示，而不是 queue<pair<string, int>>
            string &word = qe[front].m_word;
            int step = qe[front].m_step;
            if (minStep != 0 && step > minStep) {            // 全部路径搜索完成
                break;
            }
            if (word == endWord) {
                minStep = step;
                endWordPos.push_back(front);            // (4)某一路径最后结点放入队列里的索引，所以每个值代表一条最短路径
            }

            const vector<string> &neighbors = graph[word];
            for (int i = 0; i < neighbors.size(); i++) {
                if (visit.find(neighbors[i]) == visit.end() ||  // 没被访问或另一条最短路径
                    visit[neighbors[i]] == step + 1) {
                    qe.push_back(Qitem(neighbors[i], step + 1, front));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
    }

    void ConstructGraph(const string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph)
    {
        // 这里wordList里可能含有beginWord
        bool hasBeginWord = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                hasBeginWord = true;
                break;
            }
        }
        if (!hasBeginWord) {
            wordList.push_back(beginWord);
        }

        // 构造 graph
        for (int i = 0; i < wordList.size(); i++) {
            graph[wordList[i]] = vector<string>();
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (Connnect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    bool Connnect(const string &str1, const string str2)
    {
        int count = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                count++;
            }
        }
        return count == 1;
    }
};


int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dog", "dot", "lot", "log", "cog"};

    Solution s;
    vector<vector<string>> ret = s.findLadders(beginWord, endWord, wordList);
    cout << ret.size() << endl;
    vector<string> path1 = ret[1];
    for (int i = 0; i < path1.size(); i++) {
        cout << path1[i];
        if (i != path1.size() -1) {
            cout << "->";
        }
    }
    cout << "\n" << endl;

    return 0;
}
