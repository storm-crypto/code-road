#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main() {
    int a, b;
    printf("�������������֣�\n");
    scanf("%d%d", &a, &b);
    printf("���������ǣ�%d", max(a, b));
    return 0;
}
