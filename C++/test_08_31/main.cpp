#include <iostream>
using namespace std;

//class Date
//{
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator==(const Date& d) const
//    {
//        return _year == d._year
//        && _month == d._month
//        && _day == d._day;
//    }
//
//    void Print() const
//    {
//        cout << _year << "��" << _month << "��" << _day << "��" << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main()
//{
//    Date d1(2021, 5, 27);
//    Date d2(2021, 5, 27);
//
//
//    return 0;
//}


class Date
{
public:
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // �˽�һ��
    // ���ǻ���û�б��Լ�ʵ�ֵļ�ֵ
    // ���Բ��Լ�д��������Ĭ�����ɵľ͹�����
    Date* operator&()
    {
        return this;
    }

    const Date* operator&() const
    {
        return this;
    }


private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    Date d1(2021, 5, 27);
    Date d2(2021, 5, 27);


    return 0;
}