
#include <stdio.h>
#include <stdlib.h> //提供exit()的原型
#include <string>
#pragma warning(disable:4996)；
int main(int argc, char* argv[])
{
    FILE* fp;//文件指针
    int charnum = 0, wordnum = 0;//设置字符数和单词书都为0
    char input[5];//定义一个char类型的变量，表示用户的选择
    char filename[20];//需要读入的文件名
    char ch;//用ch控制文件的遍历
    scanf("%s%s", input, filename);
    if ((input[1] == 'c') || (input[1] == 'w'))
    {
        if (input[1] == 'c')
        {
            if ((fp = fopen(filename, "r")) == 0)    //当文件读取失败，退出
            {
                printf("文件读取失败");
                exit(0);
            }

            while ((ch = fgetc(fp)) != EOF)   //当文件还没读完
            {
                charnum++;    //计算文件中字符的个数
            }
            printf("文件中的字符数是：%d", charnum);
        }
        if (input[1] == 'w')
        {
            if ((fp = fopen(filename, "r")) == 0)
            {
                printf("文件读取失败");
                exit(0);
            }
            while ((ch = fgetc(fp)) != EOF)   //当文件还没读完
            {
                if (ch == ' ' || ch == ',')
                {
                    wordnum++;   //当遇到空格或者逗号时，单词数+1
                   
                }
            }
            wordnum++;//单词数等于空格数+1
            printf("文件中的单词数是：%d", wordnum);
        }
    }
}
