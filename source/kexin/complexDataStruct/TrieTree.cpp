//
// Created by zhaohailong on 2020/6/23.
//

// Trie 树的构造
#define TRIE_MAX_CHAR_NUM 26            // 小写字母数量

struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool isEnd;

    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = 0;
        }
    }
};

int main()
{


    return 0;
}