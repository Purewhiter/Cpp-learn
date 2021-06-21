/*
 * @Author      : PureWhite
 * @Date        : 2021-06-20 14:58:29
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-21 15:16:22
 * @Description : 
 */
#include <Algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using namespace chrono;
struct Item //物品
{
    int profit;
    int weight;
};
bool cmp(Item A, Item B)
{
    return (double)A.profit / A.weight > (double)B.profit / B.weight;
}

// int Capacity = 879; //背包容量
// const int N = 20;
// vector<Item> ItemSet = {
//     {91, 84},
//     {72, 83},
//     {90, 43},
//     {46, 4},
//     {55, 44},
//     {8, 6},
//     {35, 82},
//     {75, 92},
//     {61, 25},
//     {15, 83},
//     {77, 56},
//     {40, 18},
//     {63, 58},
//     {75, 14},
//     {29, 48},
//     {75, 70},
//     {17, 96},
//     {78, 32},
//     {40, 68},
//     {44, 92}};
//物品数目
//int Weight[] = {84, 83, 43, 4, 44, 6, 82, 92, 25, 83, 56, 18, 58, 14, 48, 70, 96, 32, 68, 92};
//int Profit[] = {91, 72, 90, 46, 55, 8, 35, 75, 61, 15, 77, 40, 63, 75, 29, 75, 17, 78, 40, 44};

int Capacity = 1000;
const int N = 100; //物品数目
vector<Item> ItemSet = {{100, 995}, {94, 485}, {506, 326}, {416, 248}, {992, 421}, {649, 322}, {237, 795}, {457, 43}, {815, 845}, {446, 955}, {422, 252}, {791, 9}, {359, 901}, {667, 122}, {598, 94}, {7, 738}, {544, 574}, {334, 715}, {766, 882}, {994, 367}, {893, 984}, {633, 299}, {131, 433}, {428, 682}, {700, 72}, {617, 874}, {874, 138}, {720, 856}, {419, 145}, {794, 995}, {196, 529}, {997, 199}, {116, 277}, {908, 97}, {539, 719}, {707, 242}, {569, 107}, {537, 122}, {931, 70}, {726, 98}, {487, 600}, {772, 645}, {513, 267}, {81, 972}, {943, 895}, {58, 213}, {303, 748}, {764, 487}, {536, 923}, {724, 29}, {789, 674}, {479, 540}, {142, 554}, {339, 467}, {641, 46}, {196, 710}, {494, 553}, {66, 191}, {824, 724}, {208, 730}, {711, 988}, {800, 90}, {314, 340}, {289, 549}, {401, 196}, {466, 865}, {689, 678}, {833, 570}, {225, 936}, {244, 722}, {849, 651}, {113, 123}, {379, 431}, {361, 508}, {65, 585}, {486, 853}, {686, 642}, {286, 992}, {889, 725}, {24, 286}, {491, 812}, {891, 859}, {90, 663}, {181, 88}, {214, 179}, {17, 187}, {472, 619}, {418, 261}, {419, 846}, {356, 192}, {682, 261}, {306, 514}, {201, 886}, {385, 530}, {952, 849}, {500, 294}, {194, 799}, {737, 391}, {324, 330}, {992, 298}, {224, 790}};

//int Capacity = 13;
//const int N = 4;
//int Weight[] = {8, 6, 4, 3};
//int Profit[] = {12, 11, 9, 8};
int tempWeight;            //当前总重量
int tempProfit;            //当前总价值
int MaxProfit;             //当前最大价值
vector<int> tempChoice(N); //记录搜索路径，即选择情况
vector<int> bestChoice;    //最优选择

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
    double resSpace = Capacity - tempWeight;
    double loss = tempProfit + resSpace * ((double)ItemSet[i].profit / ItemSet[i].weight);
    // for (int j = i; j < N; j++)
    // {
    //     if (resSpace >= ItemSet[j].weight)
    //     {
    //         loss = tempProfit + (Capacity - tempWeight) * ((double)ItemSet[i].profit / ItemSet[i].weight);
    //         break;
    //     }
    // }
    if (loss > MaxProfit)

        //if (tempProfit + (Capacity - tempWeight) * ((double)ItemSet[i].profit / ItemSet[i].weight) > MaxProfit)
        if (tempWeight + ItemSet[i].weight <= Capacity) //进入该节点的右孩子（值为1的孩子）
        {
            tempChoice[i] = 1;
            tempWeight += ItemSet[i].weight;
            tempProfit += ItemSet[i].profit;
            BackTrack(i + 1);
            tempWeight -= ItemSet[i].weight; //此处回溯
            tempProfit -= ItemSet[i].profit;
        }

    tempChoice[i] = 0; //进入该节点的右孩子（值为0的孩子）
    BackTrack(i + 1);
}

int main()
{

    // clock_t startTime, endTime;
    // startTime = clock();
    auto start = steady_clock::now();
    sort(ItemSet.begin(), ItemSet.end(), cmp);
    BackTrack(0);

    auto end = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    double timeElapse = (double)duration.count() / 1000000.0;
    cout
        << "The run time is "
        << timeElapse // * microseconds::period::num / microseconds::period::den
        << "ms" << endl;

    // endTime = clock();
    // cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    for (int i = 0; i < N; i++)
    {
        if (bestChoice[i] == 1)
            cout << i << " ";
    }
    cout <<endl<< "MaxProfit：" << MaxProfit << endl;
    return 0;
}
