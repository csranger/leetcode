//
// Created by zhaohailong on 2020/6/28.
//

#include <vector>

using namespace std;

class UF {
public:
    UF(int n)
    {
        m_count = n;
        m_parent.resize(n);
        for (int i = 0; i < n; i++) {
            m_parent[i] = i;    // 每个节点的父节点初始化为自身
        }
    }

    // 将 p 和 q 连接
    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ) {
            return;
        }

        m_parent[rootP] = rootQ;
        m_count--;
    }

    // 节点的跟节点
    int Find(int p)
    {
        while (m_parent[p] != p) {
            // 优化2：路径压缩:以 O(1) 的时间找到某一节点的根节点
            // 调用find函数每次向树根遍历的同时，顺手将树高缩短了，最终所有树高都不会超过 3
            m_parent[p] = m_parent[m_parent[p]];
            p = m_parent[p];
        }
        return p;
    }

    // 返回图中有多少个连通分量
    int Count()
    {
        return m_count;
    }

private:
    // 记录连通分量
    int m_count;
    // 节点的父节点
    vector<int> m_parent;

};