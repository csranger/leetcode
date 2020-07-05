//
// Created by zhaohailong on 2020/6/23.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Trie 树的数据结构
static const int TRIE_MAX_CHAR_NUM = 26;            // 小写字母数量，如果 ASCII 码则128

struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool isEnd;

    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = nullptr;
        }
    }
};

// Trie 树的前序遍历
void Preorder(TrieNode *node, int layer)
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i] != nullptr) {
            for (int j = 0; j < layer; j++) {
                printf("---");
            }
            printf("%c", i + 'a');
            if (node->child[i]->isEnd) {
                printf("(end)");
            }
            printf("\n");
            Preorder(node->child[i], layer + 1);
        }
    }
}

// Trie 树获取全部单词
// dfs + 回溯：找出全部路径
void GetAllWordFromTrie(TrieNode *node, string &word, vector<string> &wordList)
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i] != nullptr) {
            word.push_back(i + 'a');
            if (node->child[i]->isEnd) {
                wordList.push_back(word);
            }
            GetAllWordFromTrie(node->child[i], word, wordList);
            word.erase(word.length() - 1, 1);       // 栈顶弹出字符
        }
    }
}

/*
如下 trie 树存储列如下字符串：abc、abcd、abd、b、bcd、efg

                                root
                             /   |    \
                           a/   b|    e\
                          /      |      \
                         n1   n2(end)   n3
                       /        |        \
                     b/        c|        f\
                     /          |          \
                   n4          n5          n6
                 /    \         |           \
               c/     d\       d|           g\
              /         \       |             \
          n7(end)    n8(end)  n9(end)       n10(end)
             |
            d|
             |
         n11(end)

 */
int main()
{
    // Trie 树的构造
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['c' - 'a'] = &n3;
    n2.isEnd = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.isEnd = true;
    n8.isEnd = true;
    n9.isEnd = true;
    n10.isEnd = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.isEnd = true;

    // 前序遍历
    printf("前序遍历: \n");
    Preorder(&root, 0);
    // 获取全部单词
    printf("获取全部单词: \n");
    string word;
    vector<string> wordList;
    GetAllWordFromTrie(&root, word, wordList);
    for (int i = 0; i < wordList.size(); i++ ){
        cout << wordList[i] << endl;
    }

    return 0;
}