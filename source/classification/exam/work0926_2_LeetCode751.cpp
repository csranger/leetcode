//
// Created by zhaohailong on 2020/5/22.
//

/*
给定一个起始 IP 地址 ip 和一个我们需要包含的 IP 的数量 n，返回用列表（最小可能的长度）表示的 CIDR块的范围。 

CIDR 块是包含 IP 的字符串，后接斜杠和固定长度。例如：“123.45.67.89/20”。固定长度 “20” 表示在特定的范围中公共前缀位的长度。

示例 1：

输入：ip = "255.0.0.7", n = 10
输出：["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
解释：
转换为二进制时，初始IP地址如下所示（为清晰起见添加了空格）：
255.0.0.7 -> 11111111 00000000 00000000 00000111
地址 "255.0.0.7/32" 表示与给定地址有相同的 32 位前缀的所有地址，
在这里只有这一个地址。

地址 "255.0.0.8/29" 表示与给定地址有相同的 29 位前缀的所有地址：
255.0.0.8 -> 11111111 00000000 00000000 00001000
有相同的 29 位前缀的地址如下：
11111111 00000000 00000000 00001000
11111111 00000000 00000000 00001001
11111111 00000000 00000000 00001010
11111111 00000000 00000000 00001011
11111111 00000000 00000000 00001100
11111111 00000000 00000000 00001101
11111111 00000000 00000000 00001110
11111111 00000000 00000000 00001111

地址 "255.0.0.16/32" 表示与给定地址有相同的 32 位前缀的所有地址，
这里只有 11111111 00000000 00000000 00010000。

总之，答案指定了从 255.0.0.7 开始的 10 个 IP 的范围。

有一些其他的表示方法，例如：
["255.0.0.7/32","255.0.0.8/30", "255.0.0.12/30", "255.0.0.16/32"],
但是我们的答案是最短可能的答案。

另外请注意以 "255.0.0.7/30" 开始的表示不正确，
因为其包括了 255.0.0.4 = 11111111 00000000 00000000 00000100 这样的地址，
超出了需要表示的范围。
 

注：

ip 是有效的 IPv4 地址。
每一个隐含地址 ip + x (其中 x < n) 都是有效的 IPv4 地址。
n 为整数，范围为 [1, 1000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ip-to-cidr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n)
    {
        vector<string> ret;
        unsigned long ipNum = Ip2Long(ip);
        while (n > 0) {
            // 取一个数x的最后为1的一位，可以使用x & ((-1) * x)
            // 例如8 = 00001000, -8 = 11111000(补码)，那么两个位与就是1，也就是最后为1的比特位在第4位。位与以后的数值正好为8，也代表了能后面的0能承载的IP个数。
            // lowestOneBitNum 也代表了能涵盖的IP值
            unsigned int lowestOneBitNum = ipNum & (-ipNum);
            while (lowestOneBitNum > n) lowestOneBitNum = lowestOneBitNum >> 1;
            // 计算前缀=32-prefix
            int prefix = 0;
            int tmp = lowestOneBitNum;
            while (tmp > 1) {
                tmp = tmp >> 1;
                prefix++;
            }
            ret.push_back(Long2Ip(ipNum, 32 - prefix));
            ipNum += lowestOneBitNum;
            n -= lowestOneBitNum;
        }
        return ret;

    }

    unsigned long Ip2Long(const string &ip)
    {
        unsigned long a, b, c, d;
        sscanf(ip.c_str(), "%lu.%lu.%lu.%lu", &a, &b, &c, &d);
        return ((a << 24) | (b << 16) | (c << 8) | (d));
    }

    string Long2Ip(unsigned long ipNum, int post)
    {
        string ret;
        for (int i = 0; i < 4; i++) {
            ret = to_string(ipNum & 0xff) + '.' + ret;
            ipNum = ipNum >> 8;
        }
        return ret + "/" + to_string(post);
    }
};