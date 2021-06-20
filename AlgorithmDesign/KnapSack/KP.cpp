#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct Item
{
    int v;
    int w;
} Item;

//string path[10] = {"f1_l-d_kp_10_269", "f2_l-d_kp_20_878", "f3_l-d_kp_4_20",
//                    "f4_l-d_kp_4_11", "f6_l-d_kp_10_60",
//                    "f7_l-d_kp_7_50", "f8_l-d_kp_23_10000", "f9_l- d_kp_5_80", "f10_l-d_kp_20_879"};

const int N = 20;
int Capacity = 879;
int MaxProfit;                //设置全局变量，用于存储物品个数，最大重量，最大价值
int X[N];                 //用于存储物品是否放入背包的信号，x[i]=1 为放入，x[i]=0 为不放入
Item ItemSet[N];

int bruteforce(int N, Item ItemSet[], int Capacity, int *X);
void dfsbf(int i, int tempWeight, int tempProfit, int op[]);
int traceback(int N, Item ItemSet[], int Capacity, int *X);
void dfstb(int i, int tempWeight, int tempProfit, int ResProfit, int op[]);
int dynamicpro(int N, Item ItemSet[], int Capacity, int *X);
void dispsolution(int N, int X[], int MaxProfit);
int main()
{
    clock_t startTime, endTime;
    startTime = clock();

    // for (int i = 0; i < 9; i++)
    // {
    //     N = 0;
    //     Capacity = 0;
    //     MaxProfit = 0;
    //     fstream infile;
    //     infile.open(path[i], ios::in);
    //     infile >> N;
    //     infile >> Capacity;
    //     int j = 1;
    //     while (!infile.eof())
    //     {
    //         infile >> ItemSet[j].v;
    //         infile >> ItemSet[j].w;
    //         j++;
    //     }
    //     infile.close();

    //  cout << "bagnumber" << i + 1 << "最优解" << endl;
    //MaxProfit = bruteforce(N, ItemSet, Capacity, X);
    // MaxProfit= traceback(N,ItemSet, Capacity,X);
    MaxProfit = dynamicpro(N, ItemSet, Capacity, X);
    dispsolution(N, X, MaxProfit);
    // }

    endTime = clock(); //计时结束
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
//展示最优解
void dispsolution(int N, int X[], int MaxProfit)
{
    cout << " 选取第";
    for (int i = 1; i <= N; i++)
        if (X[i] == 1)
            cout << i << "、";
    cout << "个物品，总价值=" << MaxProfit << endl;
    cout << endl;
}

//蛮力法
int bruteforce(int N, Item ItemSet[], int Capacity, int *X)
{
    int op[N];          //用于记录每条路径经过的结点的状态，即物品的选择是放入书包还是不放
    dfsbf(1, 0, 0, op); //调用状态函数
    return MaxProfit;
}
void dfsbf(int i, int tempWeight, int tempProfit, int op[])
{
    //初始调用时 i 为 1，第一层。cw 为 0，cv 为 0。
    if (i > N) //如果找到一个叶子结点
    {
        if (tempWeight <= Capacity && tempProfit > MaxProfit) //如果该叶子结点的结果优于上一条路径的结果，就更新最大价值
        {
            MaxProfit = tempProfit;
            for (int j = 1; j <= N; j++) //复制最优解到全局变量x[]中
                X[j] = op[j];
        }
    }

    else //如果还未找完所有物品，在一个结点处可以做有两种选择
    {
        op[i] = 1;                                                              //选取第i 个物品
        dfsbf(i + 1, tempWeight + ItemSet[i].w, tempProfit + ItemSet[i].v, op); //然后递归到下一个结点，即往左孩子处走
        op[i] = 0;                                                              //在前面那条路走完后， 代码回溯到此处，开始执行另一个选择：不选取物品 i
        dfsbf(i + 1, tempWeight, tempProfit, op);                               //然后递归到下一个结点，即往右孩子处走
    }
}
//回溯法
int traceback(int N, Item ItemSet[], int Capacity, int *X)
{
    int ResProfit = 0;
    int op[N];
    for (int i = 1; i <= N; i++) //首先要获取所有物品的价值
        ResProfit += ItemSet[i].v;
    dfstb(1, 0, 0, ResProfit, op); //调用状态函数
    return MaxProfit;
}
void dfstb(int i, int tempWeight, int tempProfit, int ResProfit, int op[])
{
    //初始调用时 i 为 1，第一层。cw 为 0，cv 为 0，rv 为所有物品的重量和。
    if (i > N) //如果找到一个叶子结点
    {

        if (tempWeight <= Capacity && tempProfit > MaxProfit) //如果该叶子结点的结果优于上一条路径的结果，就更新最大价值
        {
            MaxProfit = tempProfit;
            for (int j = 1; j <= N; j++) //复制最优解到全局变量 X[]中
                X[j] = op[j];
        }
    }

    else //如果还未找完所有物品，在每个结点处都要进行判断，再做选择
    {
        if (tempWeight + ItemSet[i].w <= Capacity) //只有当第 i 个物品放入后不会使得总重量大于最大承重，才会做下面的选择
        {
            op[i] = 1;                                                                                        //选取第 i 个物品
            dfstb(i + 1, tempWeight + ItemSet[i].w, tempProfit + ItemSet[i].v, ResProfit - ItemSet[i].v, op); //同时往左孩子处递归
        }
        op[i] = 0;                                             //代码回溯到此处后，进行另一个选择：不选取该物品
        if (tempProfit + ResProfit - ItemSet[i].v > MaxProfit) //但要判断是否满足往右递归的条件，只有当不选该物品后剩余的价值加上已有的价值之和会大于当前最大价值，才会往右递归
            dfstb(i + 1, tempWeight, tempProfit, ResProfit - ItemSet[i].v, op);
    }
}
//动态规划法
int dynamicpro(int N, Item ItemSet[], int Capacity, int *X)
//传入参数为物品数量 N,每个物品重量 w[],每个物品价值 v[],包的最大承重 Capacity
{

    int V[N + 1][Capacity + 1];
    //定义二维表，V[i][j]表示的含义是当第 i 个物品放入最大承重为 j 的包时，包能容纳的最大的价值
    int i, j;
    for (i = 0; i <= N; i++) //将二维表处理一下，0 行和 0 列都为 0
        V[i][0] = 0;
    for (i = 0; i <= Capacity; i++)
        V[0][i] = 0;
    //填表
    for (i = 1; i <= N; i++)            //从第一个物品开始装
        for (j = 1; j <= Capacity; j++) //包的最大承重逐一增加
        {

            if (j - ItemSet[i].w < 0)  // ItemSet[i].w 是第 i 个物品的重量，如果当前物品加进来会超过包此时的最大承重
                V[i][j] = V[i - 1][j]; // 那就不把该物品加入，则此处的价值应该与前一个物品在这个承重下的价值一样
            else
                // 如果该物品可以被加入 ，需要判断：
                // 该物品的价值加上包最大承重减去该物品重量下包的最大价值  是否会大于  不加入该物品包的最大价值
                V[i][j] = (V[i - 1][j] > (V[i - 1][j - ItemSet[i].w] + ItemSet[i].v))
                              ? V[i - 1][j]
                              : V[i - 1][j - ItemSet[i].w] + ItemSet[i].v;
        }
    for (j = Capacity, i = N; i > 0; i--) //从最后一个物品往前逆推每个物品是否被放入包中
    {
        if (V[i][j] > V[i - 1][j]) //由前面可知，这种情况下物品 i 是被放入的
        {
            X[i] = 1;
            j = j - ItemSet[i].w; //更新当前包的最大容量
        }
    }
    return V[N][Capacity];
}
