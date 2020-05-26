#include<stdio.h>
#include<ctype.h>
main(int argc, char* argv[])
{
    char ch;
    int numberofword=0, wordStart=0;
    FILE *fp1 = fopen(argv[1],"r");
    while( !feof(fp1) )  //若还未到达文件末尾
    {
        ch =fgetc(fp1);     //读取字节存入ch
        if( isalpha(ch) && wordStart==0 )   //字符有效且还没开头
        {
            wordStart = 1;   //有单词了，单词开始开头了
        }
        else if( !isalpha(ch) && wordStart==1 )   //字符无效且有一个字母了
        {
            numberofword++;   //单词数加一
            wordStart = 0;   //没单词了
        }  
    }
    printf("%d",numberofword);
    fclose(fp1);
}