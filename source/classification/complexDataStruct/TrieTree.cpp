//
// Created by zhaohailong on 2020/6/28.
//

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
static void Preorder(TrieNode *node, int layer)
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

class TrieTree {
public:
    TrieTree()
    {}

    ~TrieTree()
    {
        for (int i = 0; i < nodeVec.size(); i++) {
            delete nodeVec[i];
            nodeVec[i] = nullptr;
        }
    }

    // 1. 插入 word
    void Insert(const string &word)
    {
        TrieNode *ptr = &root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (ptr->child[pos] == nullptr) {
                ptr->child[pos] = NewNode();
            }
            ptr = ptr->child[pos];
        }
        ptr->isEnd = true;
    }

    // 2. 搜索 word
    bool Search(const string &word)
    {
        TrieNode *ptr = &root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (ptr->child[pos] == nullptr) {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return ptr->isEnd;
    }

    // 3. trie 树中是否含有前缀为 prefix 的单词
    bool StartWith(const string &prefix)
    {
        TrieNode *ptr = &root;
        for (int i = 0; i, prefix.length(); i++) {
            int pos = prefix[i] - 'a';
            if (ptr->child[pos] == nullptr) {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return true;
    }

    // 跟结点
    TrieNode *Root()
    {
        return &root;
    }

private:
    vector<TrieNode *> nodeVec;     // 用于析构
    TrieNode root;                  // TrieTree 数据结构

    TrieNode *NewNode() {
        TrieNode *newNode = new TrieNode();
        nodeVec.push_back(newNode);
        return newNode;
    }
};

int main()
{
    TrieTree trie;
    trie.Insert("abc");
    trie.Insert("abcd");
    trie.Insert("abd");
    trie.Insert("b");
    trie.Insert("bcd");
    trie.Insert("efg");
    Preorder(trie.Root(), 0);

    return 0;
}