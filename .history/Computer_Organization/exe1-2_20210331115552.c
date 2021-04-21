#include <stdio.h>
void displayShort(int x) //以二进制形式展示短整型数x
{
    for (int i = 15; i >= 0; i--)
    {
        if (i == 15)
            printf("\x1b[31m");
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
        printf("\x1b[0m");
    }
    printf("\n");
}
void displayInt(int x) //以二进制形式展示整型数x
{
    for (int i = 31; i >= 0; i--)
    {
        if (i == 31)
            printf("\x1b[31m");
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
        printf("\x1b[0m");
    }
    printf("\n");
}
typedef struct shorter //定义结构体，保存第2题的结果
{
    short a;  //a保存转换的结果
    int code; //正确转换则code=0，否则code=-1
} shorter;
int short_to_int(short x);        //第1题
shorter int_to_short(int x);      //第2题
int cmp_offsetCode(int x, int y); //第3题
void float_to_binary(float);      //第4题
float binary_to_float();          //第5题
int float_to_int(float x);        //第6题
float int_to_float(int x);        //第7题
double float_to_double(float x);  //第8题
int main()
{
    printf("1. short_to_int\n");
    printf("Please input a short integer(-32768~32767):");
    short x1;
    scanf("%hd", &x1);
    short_to_int(x1);

    printf("\n2. int_to_short\n");
    printf("Please input an integer(-2147483648~2147483647):");
    int x2;
    scanf("%d", &x2);
    int_to_short(x2);

    printf("\n3. cmp_offsetCode\n");
    printf("Please enter x y(offsetCode,like 0x0000ffff 0xffff0000): ");
    int x3, y3;
    scanf("%#x %#x", &x3, &y3);
    printf("%d\n", cmp_offsetCode(x3,y3));

    printf("\n4. float_to_binary\n");
    printf("Please input a float number:");
    float x4;
    scanf("%f", &x4); //20.59375
    float_to_binary(x4);

    printf("\n5. binary_to_float\n");
    binary_to_float();

    printf("\n6. float_to_int\n");
    printf("Please input a float number:");
    float x6;
    scanf("%f", &x6);
    float_to_int(x6);

    printf("\n7. int_to_float\n");
    printf("Please input an integer:");
    int x7;
    scanf("%d", &x7);
    int_to_float(x7);

    printf("\n8. float_to_double\n");
    printf("Please input a float number:");
    float x8;
    scanf("%f", &x8);
    float_to_double(x8);
    return 0;
}

int short_to_int(short x)
{
    int y;
    printf("short: %d\n", x);
    printf("shortBinary:\n");
    displayShort(x);
    if (x & 0x8000) //x是负数
        y = 0xffff0000 | x;
    else
        y = x & 0x00007fff;
    printf("int: %d\n", y);
    printf("intBinary:\n");
    displayInt(y);
    return y;
}
shorter int_to_short(int x)
{
    shorter result;
    if (!(x ^ 0xffff8000)) //特殊情况，x=-32768
    {
        result.code = 0;
        result.a = x & 0x0000ffff;
        printf("Success!\nreturn code=%d\nresult=%d\n", result.code, result.a);
        return result;
    }

    if (x & 0x80000000) //x是负数
    {
        x = (x ^ 0x7fffffff) + 1; //将x转为原码表示
    }
    if (x & 0x7fff8000) //x不在short表数范围内
    {
        result.code = -1;
        if (x & 0x80000000)    //x是负数
            result.a = 0x8000; //返回short的最小值-32768
        else
            result.a = 0x7fff; //x是正数，返回short的最大值32767
    }
    else //x在short表数范围内
    {
        result.code = 0;
        if (x & 0x80000000) //x是负数
            result.a = (x ^ 0x8000ffff) + 1;
        else //x不是负数
            result.a = x & 0x00007fff;
    }

    if (result.code == 0)
        printf("Success!\n");
    else
        printf("Failed!\n");
    printf("return code=%d\nresult=%d\n", result.code, result.a);
    return result;
}

int cmp_offsetCode(int x, int y)
{
    for (int i = 31; i >= 0; i--)
    {
        int x1 = ((x >> i) & 0x00000001); //x1保存x第i位的值
        int y1 = ((y >> i) & 0x00000001); //y1保存y第i位的值
        if (x1 ^ y1)                      //x的第i位与y的第i位不同
        {
            if (x1)
                return 1; //x1=1，则x>y，返回1
            else
                return -1; //x<y，返回-1
        }
    }
    return 0; //x=y，返回0；
}

void float_to_binary(float x)
{
    float *fp = &x;
    int *ip = (int *)fp, tmp = *ip;
    printf("float:%f\n", x);
    printf("binary:\n");
    for (int i = 31; i >= 0; i--)
    {
        if (i == 30)
            printf("\x1b[31m");
        if (i == 22)
            printf("\x1b[32m");
        printf("%d", (tmp >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
        if (i == 0)
            printf("\x1b[0m");
    }
    printf("\n");
}

float binary_to_float()
{
    int b[32], m = 0;
    printf("Please input 32 bits,like 01000001101001001100000000000000:\n");
    for (int i = 31; i >= 0; i--)
    {
        scanf("%1d", &b[i]);
    }
    for (int i = 31; i >= 0; i--)
    {
        m = (m | b[i]);
        if (i != 0)
            m = m << 1;
    }
    float *fp = (float *)&m;
    float f = *fp;
    printf("float:%20f\n", f);
    return f;
}
int float_to_int(float x)
{
    int S, E, M, *ip, tmp, sign, exp, tail, result;
    ip = (int *)&x;
    tmp = *ip;
    S = (tmp >> 31) & 0x00000001;
    E = (tmp >> 23) & 0x000000ff;
    M = tmp & 0x007fffff;
    sign = (S == 0 ? 1 : -1);
    exp = E - 127;
    tail = (M | 0x00800000) >> (23 - exp);
    result = tail * sign;
    printf("float:%f\n", x);
    printf("int:%d\n", result);
    return result;
}
float int_to_float(int x)
{
    int S, E, M, pos = -1, tmp = 0;
    S = (x >> 31) & 0x00000001;
    if (x & 0x80000000)           //x是负数
        x = (x ^ 0x7fffffff) + 1; //变为原码表示0
    for (int i = 30; i >= 0; i--)
    {
        if ((x >> i) & 1)
        {
            pos = i; //找出从左往右除符号位外第一个1的位置
            break;
        }
    }
    if (pos >= 0 && pos <= 23)
    {
        M = (x << (23 - pos)) & 0x007fffff;
        E = pos + 127;
    }
    else if (pos > 23)
    {
        M = (x >> (pos - 23)) & 0x007fffff;
        E = pos + 127;
    }
    else
    {
        M = 0;
        E = 0;
    }
    tmp = tmp | (S << 31);
    tmp = tmp | E << 23;
    tmp = tmp | M;
    float *fp = (float *)&tmp;
    float f = *fp;
    printf("int:%d\n", x);
    printf("float:%f\n", f);
    return f;
}
double float_to_double(float x)
{
    double d, *dp;
    long long int tmp = 0, S, E, M;
    int *ip, i;
    ip = (int *)&x;
    i = *ip;
    S = (i >> 31) & 0x00000001;
    E = ((i >> 23) & 0x000000ff);
    M = i & 0x007fffff;
    tmp = tmp | (S << 63);
    if (E == 255)
    {
        E = 2047;
        tmp = tmp | (E << 52);
        tmp = tmp | (M << 29);
    }
    else if (E != 0)
    {
        tmp = tmp | ((E - 127 + 1023) << 52);
        tmp = tmp | (M << 29);
    }
    else if (E == 0 && M != 0) //此时float为非规格化数，应将其转化为double的规格化数
    {
        int n = 0;
        while ((M & 0x00800000) == 0)
        {
            M = M << 1;
            n++;
        }
        M = M & 0x007fffff;
        E = 1023 - 126 - n;
        tmp = tmp | (E << 52);
        tmp = tmp | (M << 29);
    }
    dp = (double *)&tmp;
    d = *dp;
    printf("float:%.50f\n", x);
    printf("double:%.50lf\n", d);
    return d;
}