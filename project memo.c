#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256
#define FILE_NAME "memos.txt"

int main(void) {
    char memo[MAX_LEN];
    FILE* fp;
    time_t t;
    struct tm* tm_info;
    char time_str[64];

    printf("메모를 입력하세요: ");
    fgets(memo, sizeof(memo), stdin);

    // 개행문자 제거
    memo[strcspn(memo, "\n")] = '\0';

    // 현재 시각 구하기
    time(&t);
    tm_info = localtime(&t);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    // 파일 열기 (추가 모드)
    fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        perror("파일을 열 수 없습니다");
        return 1;
    }

    // 날짜와 메모를 파일에 저장
    fprintf(fp, "[%s] %s\n", time_str, memo);
    fclose(fp);

    printf("✅ 메모가 '%s' 파일에 저장되었습니다.\n", FILE_NAME);
    return 0;
}