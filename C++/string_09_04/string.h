//
// Created by 旭哥 on 2022-09-04.
//

#ifndef STRING_09_04_STRING_H
#define STRING_09_04_STRING_H

#include <string.h>

namespace ljx
{
    // 管理字符串的数组，可以增删查改
    // 字符串数组的结尾有\0
    class string
    {
    public:
        string(const char* str = "")
            :_str(new char[strlen(str) + 1])
        {
            strcpy(_str, str);
        }

    private:
        char* _str;
    };
}


#endif//STRING_09_04_STRING_H
