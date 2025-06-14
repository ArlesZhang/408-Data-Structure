#include <stdio.h>
#include <string.h>

#define MAXLEN 255

// 构造模式串 T 的 next 数组
void GetNext(const char *T, int next[]) {
    int j = 0, k = -1;
    int len = strlen(T);
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || T[j] == T[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

// 打印 next 数组
void PrintNext(const char *T, int next[]) {
    int len = strlen(T);
    printf("Pattern: %s\n", T);
    printf("Next:    ");
    for (int i = 0; i < len; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");
}

// 测试主函数
int main() {
    const char *pattern = "abcac";
    int next[MAXLEN];

    GetNext(pattern, next);
    PrintNext(pattern, next);

    return 0;
}