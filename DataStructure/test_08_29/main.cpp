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
//class Date
//{
//public:
//    // �������ǻ����ǵ�����
//    // C++Ϊ�˽��������⣬���빹�캯��,����ʼ��
////    void Init(int year, int month, int day)
////    {
////        _year = year;
////        _month = month;
////        _day = day;
////    }
//
//    // ���캯��->ʵ���������ʱ���Զ�����
//    // ȫȱʡ�����Ĺ��캯��������ʹ��������ô�鷳��
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // ����
////    Date()
////    {
////        _year = 0;
////        _month = 1;
////        _day = 1;
////    }
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    // ����ʵ����ʱ�Զ����ù��캯��������ҲҪһ�µ�Ŷ
//    Date d1(2021, 5, 24);
//    d1.Print();
//
//    Date d2;
//    d2.Print();
//
//}

//class A
//{
//public:
//    A(int a = 0)
//    {
//        cout << "A(int a = 0)���캯��" << endl;
//        _a = a;
//    }
//
//    void Print()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//
//class Date
//{
//public:
//    // ���ǲ�д����������Ĭ�ϻ�����һ�����캯��������д�˱������Ͳ���������
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//        _aa.Print();
//    }
//
//private:
//    // ��������
//    int _year;
//    int _month;
//    int _day;
//
//    // �Զ�������
//    A _aa;
//};

// Ĭ�Ϲ��캯��

//class A
//{
//public:
//    A(int a = 0)
//    {
//        cout << "A(int a = 0)���캯��" << endl;
//        _a = a;
//    }
//
//    void Print()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//
//class Date
//{
//public:
//    // ���ǲ�д����������Ĭ�ϻ�����һ�����캯��������д�˱������Ͳ���������
//
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//        _aa.Print();
//    }
//
//private:
//    // ��������
//    int _year;
//    int _month;
//    int _day;
//
//    // �Զ�������
//    A _aa;
//};

// Ĭ�Ϲ��캯�����������ܶ�ͬѧ��Ϊ���ǲ�д��������Ĭ�����ɵ��Ǹ���Ĭ�Ϲ��캯��

//int main()
//{
//    Date d2;
//    d2.Print();
//
//    return 0;
//}

// ��������

class Date
{
public:
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // d1.Equel(d2)
    bool Equel(Date d)
    {
        return _year == d._year
        && _month == d._month
        && _day == d._day;
    }

    bool operator==(Date x)
    {
        return _year == x._year
               && _month == x._month
               && _day == x._day;
    }

private:
    int _year;
    int _month;
    int _day;
};



int main()
{
    Date d1(2021, 1, 1);
    Date d2(2021, 1, 2);

    // �������ͣ����Բ����֧�������
    // �Զ������ͣ�Ĭ�ϲ�֧�֡�C++������������������������֧����ĳ�������
    d1.operator==(d2);

    cout << d1.Equel(d2) << endl;

    return 0;
}