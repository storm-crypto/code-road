#pragma once

#include <iostream>
#include <pthread.h>

namespace ns_task
{
    class Task
    {
    private:
        int _x;
        int _y;
        char _op;

    public:
        Task() {}
        Task(int x, int y, char op)
            : _x(x), _y(y), _op(op)
        {
        }
        ~Task() {}

        int Run()
        {
            int res = 0;
            switch (_op)
            {
            case '+':
                res = _x + _y;
                break;
            case '-':
                res = _x - _y;
                break;
            case '*':
                res = _x * _y;
                break;
            case '/':
                res = _x / _y;
                break;
            case '%':
                res = _x % _y;
                break;
            default:
                std::cout << "bug??" << std::endl;
                break;
            }
            std::cout << "当前任务正在被：" << pthread_self() << " 处理："
                      << _x << _op << _y << "=" << res << std::endl;

            return res;
        }
    };
}