#include <stdio.h>
#include <string.h>

namespace bit
{
    int scanf = 10;
    int strlen = 20;
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

    return 0;
}
