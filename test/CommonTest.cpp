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
    string str = "hello,world";
    cout << str[0] << endl;


    return 0;
}











