//实验步骤:
//touch c.txt 
//echo 1233456789abcdef > c.txt
#include <stdio.h>

int main(void){
    FILE* fpr = fopen("c.txt", "r");
    if(fpr == NULL){
        printf("failed\n");
        return -1;
    }
    FILE* fpw = fopen("d.txt", "w+");
    if(fpw == NULL){
        printf("failed\n");
        return -1;
    }
    int ch;
    while(1){
        ch = fgetc(fpr);//从c.txt中读取一个字符保存到ch变量中 
        if(ch == EOF)//判断遇到了错误,或者到了文件尾
            break;
        fputc(ch, fpw);//向d.txt文件中写入一个字符
    }
    fclose(fpr);
    fpr = NULL;
    fclose(fpw);
    fpw = NULL;

    return 0;
}

