#include <iostream>

using namespace std;

//class Date
//{
//public:
//    // ����ʱ������һ�������Ĳ���
//    // void Init(Date* this, int year, int month, int day)
//    void Init(int year, int month, int day)
//    {
//        // ������Զ����ڵĺϷ��Խ��м��
//
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "this:" << this << endl;
//    }
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
//    // d1.year = 2021;
//    cout << "d1:" << &d1 << endl;
//    d1.Init(2021, 8, 29);
//    Date d2;
//    cout << "d2:" << &d2 << endl;
//    d2.Init(2021, 8, 30);
//}

// ����thisָ��ķ�����
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
//    A* p = nullptr;
//    p->PrintA(); // ���󣺿�ָ�����
//    //p->Show();   // ��������
//}

// �������Ա����������ʲô����д��ʱ�򣬱��������Զ�����6����������6��������Ĭ�ϳ�Ա����

// 1. ���캯�����Զ���ĳ�ʼ��
class Date
{
public:
    // �������ǻ����ǵ�����
    // C++Ϊ�˽��������⣬���빹�캯��,����ʼ��
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }

    // ���캯��->ʵ���������ʱ���Զ�����
    // ȫȱʡ�����Ĺ��캯��������ʹ��������ô�鷳��
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // ����
//    Date()
//    {
//        _year = 0;
//        _month = 1;
//        _day = 1;
//    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    // ����ʵ����ʱ�Զ����ù��캯��������ҲҪһ�µ�Ŷ
    Date d1(2021, 5, 24);
    d1.Print();

    Date d2;
    d2.Print();

}