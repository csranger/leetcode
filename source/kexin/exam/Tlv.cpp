//
// Created by zhaohailong on 2020/4/30.
//

/*
TLV（Tag-Length-Value），是一种简单实用的数据传输方案。其数据包一般包括三个域，分别为：标签域（Tag），长度域（Length），内容域（Value）。
TLV码流格式: 00 01 00 00 00 01 6f，其中：码流中前 2 字节00 01为 T，紧接着 4 字节00 00 00 01为 L，后续的6f为 V，字节均为十六进制。
字节序为大端（网络序）
现给定一个 TLV 的的数据码流，请按要求进行解码输出。
输入：输入为单行十六进制码流，如00 01 00 00 00 01 6f：
输出：
解码要求：解码后输出成单行字符串，格式为:
{T:<tag>,L:<streamLen>,V:<value>}
其中
<tag> 为解析后的标签或类型 T，十进制；
<streamLen> 为解析后的长度 L，十进制；
<value>为解析后的内容；若内容为英文字母，则：小写变成大写输出，大写变成小写输出；其它字符保持原样输出。
长度 L 可能与实际 V 长度不符，需要校验，长度小于L的，反馈Invalid ；长度大于L的内容做截断处理。
 */

#include <string>
#include <iostream>

using namespace std;

#pragma pack(1) // 1.对齐，结构体对齐：https://www.cnblogs.com/flyinggod/p/8343478.html

typedef struct {
    uint16_t tag;
    uint32_t valueLen;
    char value[];
} TLV;

#pragma pack()

class Solution {
public:
    string ParseTlv(const uint8_t *stream, const uint32_t streamLen)
    {
        string ret;
        // 处理 TL
        TLV *tlv = (TLV *) stream;
        uint16_t tag = Ntohs(tlv->tag);
        uint32_t valueLen = Ntohl(tlv->valueLen);

        // 处理 V：V 实际长度小于 L
        if (streamLen - 6 < valueLen) {
            ret = "{T:" + to_string(tag) + ",L:" + to_string(valueLen) + ",V:Invalid";
            return ret;
        }
        // V 实际长度大于等于 L
        ret = "{T:" + to_string(tag) + ",L" + to_string(valueLen) + ",V:";
        for (int i = 0; i < valueLen; i++) {  // 'A'：65 'a'：97
            if (tlv->value[i] >= 'a' && tlv->value[i] <= 'z') {
                tlv->value[i] = tlv->value[i] - ('a' - 'A');    // 小写转大写
            } else if (tlv->value[i] >= 'A' && tlv->value[i] <= 'Z') {
                tlv->value[i] = tlv->value[i] + ('a' - 'A');    // 大写转小写
            }
            ret += tlv->value[i];
        }
        ret += "}";
        return ret;
    }

    // 2.字节序（大小端）理解:https://blog.csdn.net/sunflower_della/article/details/90439935
    // 将一个 uint16_t 从网络字节序转换为主机字节序
    uint16_t Ntohs(uint16_t v)              // 0x00 01(网络字节序) -> 0x01 00(主机字节序）
    {
        return ((v & 0xff00) >> 8 | (v & 0x00ff) << 8);
    }

    // 将一个 uint32_t 从网络字节序转换为主机字节序
    uint32_t Ntohl(uint32_t v)              // 0x00, 0x00, 0x00, 0x01(网络字节序) -> 0x01 00 00 00(主机字节序）
    {
        return ((v & 0xff000000) >> 24 |    // 第1个字节数据右移3个字节
                (v & 0x00ff0000) >> 8 |     // 第2个字节数据右移1个字节
                (v & 0x0000ff00) << 8 |     // 第3个字节数据左移1个字节
                (v & 0x000000ff) << 24);    // 第4个字节数据左移3个字节
    }
};

int main()
{
    static uint8_t input[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x11, 0x6D, 0x6E, 0x6C, 0x6B, 0x6A, 0x69, 0x68, 0x67,
                               0x66, 0x65, 0x64, 0x63, 0x62, 0x41, 0x41, 0x41, 0x41, 0x6D, 0x6D, 0x6D, 0x6D, 0x6D,
                               0x6D, 0x6D, 0x6D };
    Solution s;
    string ret = s.ParseTlv(input, sizeof(input));
    cout << ret << endl;
    return 0;
}