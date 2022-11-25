#pragma once

#include <iostream>

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
    };
}