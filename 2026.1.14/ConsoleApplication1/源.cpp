#include <stdio.h>
#include <limits.h>

// 工具函数：输出int的32位二进制（同时显示十进制和十六进制）
// 注意：为了可靠地显示内存中的位模式，先把值转换为unsigned int再位移。
void print32BitBinary(int num) {
    unsigned int u = (unsigned int)num;
    printf("值: %d    (0x%08X)\n", num, u);

    printf("完整32位二进制：");
    for (int i = 31; i >= 0; i--) {
        unsigned int bit = (u >> i) & 1u;
        putchar(bit ? '1' : '0');
        // 每8位加一个空格，增强可读性
        if (i % 8 == 0 && i != 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

int main() {
    int intMin = INT_MIN;
    int intMax = INT_MAX;

    printf("int 最小值：\n");
    print32BitBinary(intMin);

    printf("\nint 最大值：\n");
    print32BitBinary(intMax);

    return 0;
}