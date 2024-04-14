#include <stdio.h>

int main(void){
    FILE* fp = fopen("m.txt", "w+");
    if(fp == NULL){
        printf("failed\n");
        return -1;
    }
    int a[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(a) / sizeof(a[0]);
    int size;
    //向文件m.txt中写入len个数据,每个数据4字节
    size = fwrite(a, sizeof(int), len, fp);
    printf("实际写入了%d个数据\n", size);
    rewind(fp);

    //从文件m.txt中读取数据
    int b[8] = {0};//定义数组存储从文件m.txt中读取到的内容
    size = fread(b, sizeof(int), 9, fp);//想要从文件m.txt中读取9个int类型数据存储到数组b中
    printf("实际读取了%d个数据\n", size);
    for(int i = 0; i < size; i++)
        printf("%d ", b[i]);
    printf("\n");
    //fseek函数演示
    int c[2] = {0};
    fseek(fp, 8, SEEK_SET);//从文件头开始往后数8个字节的位置开始操作文件
    //1    2    3    4    5    6    7    8
    //---- ---- ---- ---- ---- ---- ---- ---- ---- 
    //          ^
    fread(c, sizeof(int), 2, fp);
    printf("%d,%d\n", c[0], c[1]);
    //1    2    3    4    5    6    7    8
    //---- ---- ---- ---- ---- ---- ---- ---- ---- 
    //                    ^     
    //读取完毕后,文件位置调整到了5的位置上
    fseek(fp, 8, SEEK_CUR);//从当前文件位置向后移动8个字节的位置开始操作文件
    //1    2    3    4    5    6    7    8
    //---- ---- ---- ---- ---- ---- ---- ---- ---- 
    //                              ^     
    fread(c, sizeof(int), 2, fp);
    printf("%d,%d\n", c[0], c[1]);
    //1    2    3    4    5    6    7    8
    //---- ---- ---- ---- ---- ---- ---- ---- ---- 
    //                                        ^     
    //读取完毕后, 文件位置调整到了文件末尾
    fseek(fp, -12, SEEK_END);//从文件末尾向前调整12个字节的位置开始操作文件
    //1    2    3    4    5    6    7    8
    //---- ---- ---- ---- ---- ---- ---- ---- ---- 
    //                         ^     
    fread(c, sizeof(int), 2, fp);
    printf("%d,%d\n", c[0], c[1]);

    printf("当前读写位置为:%ld\n", ftell(fp));
    fclose(fp);

    return 0;
}






