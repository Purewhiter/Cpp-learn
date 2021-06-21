/*
 * @Author      : PureWhite
 * @Date        : 2021-06-19 21:49:49
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-20 14:17:48
 * @Description : 
 */
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
struct Item //物品
{
    int profit;
    int weight;
};
int tempProfit, tempWeight;//保存每种情况的价值和重量
int MaxProfit = 0;           //保存最大价值
vector<int> BF_Knapsack(vector<Item> ItemSet, int C)
{
    const int N = ItemSet.size();
    vector<int> BinarySet(N);
    vector<int> bestChoice;
    for (int i = 0; i < (1 << N); i++)
    {
        tempProfit = 0;
        tempWeight = 0;
        // vector<int> tempSet;
        // for (int j = 0; j < N; j++)
        //     if (((i >> j) & 1) == 1)
        //         tempSet.push_back(j);

        // for (auto item : tempSet)
        // {
        //     tempWeight += ItemSet[item].weight;
        // }
        // if (tempWeight > C)
        //     continue;
        // for (auto item : tempSet)
        // {
        //     tempProfit += ItemSet[item].profit;
        // }
        // if (tempProfit > MaxProfit)
        // {
        //     MaxProfit = tempProfit;
        //     bestChoice = tempSet;
        // }
        for (int j = 0; j < N; j++)
        {
            if (BinarySet[j] == 1)
            {
                BinarySet[j] = 0;
                continue;
            }
            if (BinarySet[j] == 0)
            {
                BinarySet[j] = 1;
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (BinarySet[i] == 1)
            {
                tempWeight += ItemSet[i].weight;
            }
        }
        if (tempWeight <= C)
        {
            for (int i = 0; i < N; i++)
                if (BinarySet[i] == 1)
                {
                    tempProfit += ItemSet[i].profit;
                }
            if (tempProfit > MaxProfit)
            {
                MaxProfit = tempProfit;
                bestChoice = BinarySet;
            }
        }
    }
    return bestChoice;
}
int main()
{

    // int Capacity = 11;
    // vector<Item> ItemSet = {{6, 2}, {10, 4}, {12, 6}, {3, 7}};

    int Capacity = 879;
    vector<Item> ItemSet = {
        {91, 84},
        {72, 83},
        {90, 43},
        {46, 4},
        {55, 44},
        {8, 6},
        {35, 82},
        {75, 92},
        {61, 25},
        {15, 83},
        {77, 56},
        {40, 18},
        {63, 58},
        {75, 14},
        {29, 48},
        {75, 70},
        {17, 96},
        {78, 32},
        {40, 68},
        {44, 92}};

    clock_t startTime, endTime;
    startTime = clock();
    vector<int> bestChoice = BF_Knapsack(ItemSet, Capacity);
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    for (int i = 0; i < (int)bestChoice.size(); i++)
    {
        if (bestChoice[i] == 1)
            cout << i << " ";
    }
    cout <<endl<< "MaxProfit：" << MaxProfit << endl;
    return 0;
}