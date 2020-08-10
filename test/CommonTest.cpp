#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {

    }

    void Bfs(map<string, vector<string>> &strMap, vector<string> &visit, const string &beginWord, const string &endWord) {

        queue<string> scQueue;
        scQueue.push(beginWord);
        visit.push_back(beginWord);

        while (!scQueue.empty()) {
            string word = scQueue.front();
            scQueue.pop();

            for (string w : strMap[word]) {
                scQueue.push(w);
                visit.insert(w);
            }
        }

    }
};