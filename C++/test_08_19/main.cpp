#include <iostream>

using namespace std;
//class Date
//{
//public:
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//private:
//    // ���ǳ�Ա���������������������һ��
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    d1.Init(2022, 8, 20);
//    Date d2;
//    d2.Init(2021, 8, 20);
//
//    return 0;
//}

// 1.��������ܱ���ͨ����
// 2.����������������������
//class A
//{
//public:
//    void PrintA()
//    {
//        cout<<_a<<endl;
//    }
//    void Show()
//    {
//        cout<<"Show()"<<endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = NULL;
//    p->PrintA();
//    p->Show();
//}

// �������Ա����ʲô����д��ʱ�򣬱�������Ĭ��
//class Date
//{
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};

// ���캯��������
class Date
{
public:
    // 1. �޲ι��캯��
    Date()
    {}

    // 2. ���ι��캯��
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

void TestDate()
{
    Date d1;                // �����޲ι��캯��
    Date d2(2022, 1, 1);    //�����вι��캯��
}