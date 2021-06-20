/*
 * @Author      : PureWhite
 * @Date        : 2021-06-20 14:58:29
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-20 15:42:36
 * @Description : 
 */
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int Capacity = 879;                                                                             //背包容量
const int N = 20;                                                                               //物品数目
int Weight[] = {84, 83, 43, 4, 44, 6, 82, 92, 25, 83, 56, 18, 58, 14, 48, 70, 96, 32, 68, 92};  //对象重量数组
int Profit[] = {91, 72, 90, 46, 55, 8, 35, 75, 61, 15, 77, 40, 63, 75, 29, 75, 17, 78, 40, 44}; //对象收益数组

//int Capacity = 13; //背包容量
//const int N = 4;   //物品数目
//int Weight[] = {8, 6, 4, 3};   //对象重量数组
//int Profit[] = {12, 11, 9, 8}; //对象收益数组
int tempWeight;            //当前背包重量
int tempProfit;            //当前背包价值
int MaxProfit;             //迄今最大的收益
vector<int> tempChoice(N); //记录在树中的移动路径,为1的时候表示选择该组数据，为0的表示不选择该组数据
vector<int> bestChoice;
void BackTrack(int i)
{
    if (i >= N) //递归结束的判定条件
    {
        if (tempProfit > MaxProfit)
        {
            MaxProfit = tempProfit;
            bestChoice = tempChoice;
        }
        return;
    }
    if (tempWeight + Weight[i] <= Capacity) //进入该节点的右孩子（值为1的孩子）
    {
        tempChoice[i] = 1;
        tempWeight += Weight[i];
        tempProfit += Profit[i];
        BackTrack(i + 1);
        tempWeight -= Weight[i]; //此处回溯
        tempProfit -= Profit[i];
    }

    tempChoice[i] = 0; //进入该节点的右孩子（值为0的孩子）
    BackTrack(i + 1);
}

int main()
{
    clock_t startTime, endTime;
    startTime = clock();

    BackTrack(0);
    
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    for (int i = 0; i < N; i++)
    {
        if (bestChoice[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    printf("%d", MaxProfit);

    return 0;
}

