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

    void Bfs(map<string, vector<string>> &graph, set<string> &visit, string &beginWord, string &endWord,
             vector<string> &path) {
        queue<string> searchQueue;
        searchQueue.push(beginWord);
        visit.insert(beginWord);

        while (!searchQueue.empty()) {
            string temp = searchQueue.front();
            searchQueue.pop();

            //
            path.push_back(temp);

            for (auto &word : graph[temp]) {
                searchQueue.push(word);
                visit.insert(word);
            }
        }
    }
};