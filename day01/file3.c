//实验步骤:
//touch e.txt 
//echo 1233456789abcdef > e.txt
#include <stdio.h>

int main(void){
    FILE* fpr = fopen("e.txt", "r");
    if(fpr == NULL){
        printf("failed\n");
        return -1;
    }
    FILE* fpw = fopen("f.txt", "w+");
    if(fpw == NULL){
        printf("failed\n");
        return -1;
    }
    char str[4] = {0};//暂存从文件中读取的字符串
    while(fgets(str, 4, fpr) != NULL){//循环从文件e.txt中读取3个字符
        fputs(str, fpw);//将读取到底额数据写入到文件f.txt中
    }

    fclose(fpr);
    fpr = NULL;
    fclose(fpw);
    fpw = NULL;

    return 0;
}

