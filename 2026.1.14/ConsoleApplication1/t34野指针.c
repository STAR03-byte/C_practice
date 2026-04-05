#include <stdio.h>

int* ptr_to_floor = NULL;

void recursive_overwrite(int depth) {
    if (depth == 0) {
        // 递归到最底层，定义一个变量覆盖旧内存
        int overwrite_me = 999;
        printf("递归层 overwrite_me = %d, 地址 = %p\n", overwrite_me, (void*)&overwrite_me);
        return;
    }
    recursive_overwrite(depth - 1);
}

int main() {
    {
        int temp_floor = 104;
        ptr_to_floor = &temp_floor;
        printf("块内：temp_floor = %d, 地址 = %p\n", *ptr_to_floor, (void*)ptr_to_floor);
    }

    // 递归调用，强制覆盖栈空间
    recursive_overwrite(100);

    // 再次访问野指针
    printf("块外：现在的楼层是: %d, 地址是: %p\n", *ptr_to_floor, (void*)ptr_to_floor);

    return 0;
}