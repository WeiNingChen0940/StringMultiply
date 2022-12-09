#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int multiplyNum(char *number, int multiplyByNumber);
char *multiply(const char *num_1, const char *num_2);
int multiply10(char *number);
char *revStr(char *s, int lenth);
int main()
{

    return 0;
}

int multiplyNum(char *number, int multiplyByNumber)
{
    int i = 0;
    int jinwei = 0;
    int weishu = 0;
    int temp = 0;
    int lenth = strlen(number);
    for (i = 0; i < lenth; i++)
    {
        if (number[i] == 0)number[i] = '0';
        temp = number[i] - '0';
        number[i] = (temp * multiplyByNumber + jinwei) % 10 + '0';
        jinwei = (temp * multiplyByNumber + jinwei) / 10;
    }
    if (jinwei > 0)
    {
        if (number[i] == 0)number[i] = '0';
        temp = number[i] - '0';
        number[i] = (temp * multiplyByNumber + jinwei) % 10 + '0';
        weishu++;
    }
    return lenth + weishu;
}

int multiply10(char *number)
{
    int len = strlen(number);
    for (int i = len; i >= 1; i--)
    {
        number[i] = number[i - 1];
    }
    number[0] = '0';
    return len + 1;
}
char *revStr(char *s, int lenth)
{
    int start = 0, end = lenth - 1;
    char temp = 0;
    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++, end--;
    }
    return s;
}
int add(char *num1, char *num2)
{
    int jinwei = 0;
    int maxlenth = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    int temp = 0;
    int i = 0;
    for (i = 0; i < maxlenth; i++)
    {
        if (num1[i] == 0 && num2[i] != 0)
        {
            temp = num2[i] - '0';
        }
        else if (num1[i] != 0 && num2[i] == 0)
        {
            temp = num1[i] - '0';
        }
        else if (num1[i] != 0 && num2[i] != 0)
        {
            temp = num1[i] - '0' + num2[i] - '0';
        }
        num1[i] = (temp + jinwei) % 10 + '0';
        jinwei = (temp + jinwei) / 10;
    }
    if (jinwei > 0)
    {
        num1[i] = jinwei + '0';
        return maxlenth + 1;
    }
    else if (jinwei == 0)
    {
        return maxlenth;
    }
}
char *multiply(const char *num_1, const char *num_2)
{
    char *num1 = (char *)num_1, *num2 = (char *)num_2;
    if (strlen(num_1) < strlen(num_2))
    {
        num1 = (char *)num_2;
        num2 = (char *)num_1;
    }
    int lenth1 = strlen(num1);
    int lenth2 = strlen(num2);
    char *num = (char *)calloc((lenth1 + lenth2 + 1) * sizeof(char), 1);
    char *temp = (char *)calloc((lenth1 + lenth2 + 1) * sizeof(char), 1);
    revStr(num1, lenth1);
    revStr(num2, lenth2);
    int ws = lenth1;
    for (int i = 0; i < lenth2; i++)
    {
        memset(temp, 0, lenth1 + lenth2 + 1);
        strcpy(temp, num1);
        multiplyNum(temp, num2[i] - '0');

        for (int o = 0; o < i; o++)
        {
            multiply10(temp);
        }
        ws = add(num, temp);
    }
    free(temp);
    revStr(num, ws);
    return num;
}