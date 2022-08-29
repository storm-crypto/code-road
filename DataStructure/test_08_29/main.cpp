#include <iostream>

using namespace std;

class Date
{
public:
    // 编译时会增加一个隐含的参数
    // void Init(Date* this, int year, int month, int day)
    void Init(int year, int month, int day)
    {
        // 这里可以对日期的合法性进行检查

        _year = year;
        _month = month;
        _day = day;
        cout << "this:" << this << endl;
    }
private:
    // 凡是成员变量，建议命名风格区分一下
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1;
    // d1.year = 2021;
    cout << "d1:" << &d1 << endl;
    d1.Init(2021, 8, 29);
    Date d2;
    cout << "d2:" << &d2 << endl;
    d2.Init(2021, 8, 30);
}
