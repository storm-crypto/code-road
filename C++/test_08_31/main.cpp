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
//    // �˽�һ��
//    // ���ǻ���û�б��Լ�ʵ�ֵļ�ֵ
//    // ���Բ��Լ�д��������Ĭ�����ɵľ͹�����
//    Date* operator&()
//    {
//        return this;
//    }
//
//    const Date* operator&() const
//    {
//        return this;
//    }
//
//
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

//class Date
//{
//    // ��Ԫ����������
//    friend ostream& operator<<(ostream& out, const Date& d);
//    friend istream& operator>>(istream& in, Date& d);
//
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// cout << d1;
//ostream& operator<<(ostream& out, const Date& d)
//{
//    out << d._year << "-" << d._month << "-" << d._day << endl;
//    return out;
//}
//
//// cin >> d1
//istream& operator>>(istream& in,  Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//
//int main()
//{
//    Date d1;
//    //cin >> d1;
//    cout << d1;
//
//    return 0;
//}

//class A
//{
//public:
//    A(int a)
//        :_a(a)
//    {}
//
//private:
//    int _a;
//};
//
//int main()
//{
//    A aa1(1); // ��������
//    // �������Ĺ��캯����֧����������ʽ����ת��
//    A aa2 = 2;
//    // ����explicit�Ͳ���������������ʽ����ת����
//
//
//    return 0;
//}
//
//int main()
//{
//    A aa1(1);  // ��׼�Ĺ��캯�����ã�������������
//    A aa2 = 2; // ��ʽ����ת�����������Ż���Ҳ��ֱ�ӵ��Ĺ���
//    A(3);      // ������������,�������û�����֣� ��������ֻ����һ�У����к��Ҫ������������
//}

// ��̬��Ա

// �����⣺����һ�������ж����˶��ٸ��������
class A
{
public:
    A()
    {
        ++_n;
    }

    // ��������
    A(const A& a)
    {
        ++_n;
    }

    int GetN()
    {
        return _n;
    }

private:
    // �����������������ڹ��캯����ʼ��,Ҫ��������ȫ��λ�ó�ʼ��
    static int _n;  // n���ھ�̬�������������࣬Ҳ����������ж���
};

// ��̬��Ա�����ĳ�ʼ�����涨����������������ʼ����
int A::_n = 0;

int main()
{
    A a1;
    A a2(a1);
    //cout << sizeof(A) << endl;

    cout << a1.GetN() << endl;

    return 0;
}