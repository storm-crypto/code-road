#include <iostream>

using namespace std;

class Date
{
public:
    // ����ʱ������һ�������Ĳ���
    // void Init(Date* this, int year, int month, int day)
    void Init(int year, int month, int day)
    {
        // ������Զ����ڵĺϷ��Խ��м��

        _year = year;
        _month = month;
        _day = day;
        cout << "this:" << this << endl;
    }
private:
    // ���ǳ�Ա���������������������һ��
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
