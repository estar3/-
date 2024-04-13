#include <stdio.h>

int main(void){
    FILE* fp = NULL;
    //打开文件
    fp = fopen("a.txt", "r");//以只读方式打开当前目录下的a.txt
    if(NULL == fp){
        printf("file open failed\n");
        return -1;
    }
    //定义变量存储从文件中读取的内容
    int i = 0;
    char str[20] = {0};
    double d = 0;
    //按照一定的格式从a.txt文件中读取数据保存到变量i,str,d中
    fscanf(fp, "%d%s%lg", &i, str, &d);
    printf("i = %d, str = %s, d = %lg\n", i, str, d);

    //关闭文件
    fclose(fp);
    fp = NULL;

    FILE* fpw = fopen("b.txt", "w+");//可读可写方式打开b.txt
    //按照指定的格式将变量i,str,d中的数据保存到文件b.txt中
    fprintf(fpw, "%d, %s, %lg\n", i, str, d);
    fclose(fpw);
    
    //从标准输入设备键盘上获取数据保存到i,str,d中
    fscanf(stdin, "%d%s%lg", &i, str, &d);
    //将i,str,d打印输出到标准输出设备显示器上
    fprintf(stdout, "%d,%s,%lg\n", i, str, d);
    //将i,str,d打印输出到标准输出设备显示器上
    fprintf(stderr, "%d,%s,%lg\n", i, str, d);

    return 0;
}

