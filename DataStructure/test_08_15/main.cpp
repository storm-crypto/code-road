#include <stdio.h>
#include <string.h>

namespace bit
{
    int scanf = 10;
    int strlen = 20;

    // Ƕ�׶��������ռ�
    namespace N3
    {
        int c;
        int d;
        int Sub(int left, int right)
        {
            return left - right;
        }
    }
}

int main()
{
    // ��ӡ�⺯���е�scanf��strlen�ĵ�ַ
    // û��ָ��Ĭ�Ϸ��ʾֲ�����ȫ�ֵ�
    printf("%x\n", scanf);
    printf("%x\n", strlen);

    // ָ������bit��������ռ������scanf��strlen
    printf("%x\n", bit::scanf);
    printf("%x\n", bit::strlen);

    // Ƕ�׶���������ռ��ʹ��
    bit::N3::Sub(10, 3);

    return 0;
}
