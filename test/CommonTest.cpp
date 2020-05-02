#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <set>

using namespace std;
#pragma pack(1)
typedef struct {
    uint16_t tag;
    uint32_t valueLen;
    uint8_t value[];
} TLV;

int main()
{
    int a[];
    int b[5] = { 12, 23, 22, 34, 45 };
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(TLV) << endl;
    TLV *tlv;
    cout << sizeof(tlv) << endl;
}











