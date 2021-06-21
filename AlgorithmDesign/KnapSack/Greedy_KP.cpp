/*
 * @Author      : PureWhite
 * @Date        : 2021-06-21 15:16:06
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-21 17:07:06
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
int Capacity = 1000;
int MaxProfit;     //当前最大价值
vector<Item> S = {{100, 995}, {94, 485}, {506, 326}, {416, 248}, {992, 421}, {649, 322}, {237, 795}, {457, 43}, {815, 845}, {446, 955}, {422, 252}, {791, 9}, {359, 901}, {667, 122}, {598, 94}, {7, 738}, {544, 574}, {334, 715}, {766, 882}, {994, 367}, {893, 984}, {633, 299}, {131, 433}, {428, 682}, {700, 72}, {617, 874}, {874, 138}, {720, 856}, {419, 145}, {794, 995}, {196, 529}, {997, 199}, {116, 277}, {908, 97}, {539, 719}, {707, 242}, {569, 107}, {537, 122}, {931, 70}, {726, 98}, {487, 600}, {772, 645}, {513, 267}, {81, 972}, {943, 895}, {58, 213}, {303, 748}, {764, 487}, {536, 923}, {724, 29}, {789, 674}, {479, 540}, {142, 554}, {339, 467}, {641, 46}, {196, 710}, {494, 553}, {66, 191}, {824, 724}, {208, 730}, {711, 988}, {800, 90}, {314, 340}, {289, 549}, {401, 196}, {466, 865}, {689, 678}, {833, 570}, {225, 936}, {244, 722}, {849, 651}, {113, 123}, {379, 431}, {361, 508}, {65, 585}, {486, 853}, {686, 642}, {286, 992}, {889, 725}, {24, 286}, {491, 812}, {891, 859}, {90, 663}, {181, 88}, {214, 179}, {17, 187}, {472, 619}, {418, 261}, {419, 846}, {356, 192}, {682, 261}, {306, 514}, {201, 886}, {385, 530}, {952, 849}, {500, 294}, {194, 799}, {737, 391}, {324, 330}, {992, 298}, {224, 790}};

vector<int> Greedy_Knapsack(vector<Item> S, int C)
{
    const int N=S.size();
    int tempWeight; //当前总重量
    vector<int> bestChoice(N); //最优选择

    for (int i = 0; i < N; i++)
    {
        if (tempWeight + S[i].weight <= Capacity)
        {
            bestChoice[i] = 1;
            tempWeight += S[i].weight;
            MaxProfit += S[i].profit;
        }
        else
        {
            bestChoice[i] = 0;
        }
    }
    return bestChoice;
}

int main()
{

    auto start = steady_clock::now();

    sort(S.begin(), S.end(), cmp);
    vector<int> bestChoice = Greedy_Knapsack(S, Capacity);

    auto end = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    double timeElapse = (double)duration.count() / 1000000.0;
    cout
        << "The run time is "
        << timeElapse // * microseconds::period::num / microseconds::period::den
        << "ms" << endl;

    for (int i = 0; i < (int)S.size(); i++)
    {
        if (bestChoice[i] == 1)
            cout << i << " ";
    }
    cout << endl
         << "MaxProfit：" << MaxProfit << endl;
    return 0;
}