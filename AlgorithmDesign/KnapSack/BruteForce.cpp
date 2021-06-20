/*
 * @Author      : PureWhite
 * @Date        : 2021-05-30 17:02:35
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-19 22:28:58
 * @Description : 
 */
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
struct Item
{
    int profit;
    int weight;
};
vector<int> t;
vector<int> Result;
int MaxProfit;
int TotalProfit;
int TotalWeight;

//int Capacity = 11;
//vector<Item> ItemSet = {{6, 2}, {10, 4}, {12, 6}, {3, 7}};

// int Capacity = 300;
// vector<Item> ItemSet = {
//     {44, 92},
//     {46, 4},
//     {90, 43},
//     {72, 83},
//     {91, 84},
//     {40, 68},
//     {75, 92},
//     {35, 82},
//     {8, 6},
//     {54, 44},
//     {78, 32}
// };

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

// int Capacity = 60;
// vector<Item> ItemSet = {
//     {20, 30},
//     {18, 25},
//     {17, 20},
//     {15, 18},
//     {15, 17},
//     {10, 11},
//     {5, 5},
//     {3, 2},
//     {1, 1},
//     {1, 1}};

//int Capacity = 1000;
//vector<Item> ItemSet = {{100, 995}, {94, 485}, {506, 326}, {416, 248}, {992, 421}, {649, 322}, {237, 795}, {457, 43}, {815, 845}, {446, 955}, {422, 252}, {791, 9}, {359, 901}, {667, 122}, {598, 94}, {7, 738}, {544, 574}, {334, 715}, {766, 882}, {994, 367}, {893, 984}, {633, 299}, {131, 433}, {428, 682}, {700, 72}, {617, 874}, {874, 138}, {720, 856}, {419, 145}, {794, 995}, {196, 529}, {997, 199}, {116, 277}, {908, 97}, {539, 719}, {707, 242}, {569, 107}, {537, 122}, {931, 70}, {726, 98}, {487, 600}, {772, 645}, {513, 267}, {81, 972}, {943, 895}, {58, 213}, {303, 748}, {764, 487}, {536, 923}, {724, 29}, {789, 674}, {479, 540}, {142, 554}, {339, 467}, {641, 46}, {196, 710}, {494, 553}, {66, 191}, {824, 724}, {208, 730}, {711, 988}, {800, 90}, {314, 340}, {289, 549}, {401, 196}, {466, 865}, {689, 678}, {833, 570}, {225, 936}, {244, 722}, {849, 651}, {113, 123}, {379, 431}, {361, 508}, {65, 585}, {486, 853}, {686, 642}, {286, 992}, {889, 725}, {24, 286}, {491, 812}, {891, 859}, {90, 663}, {181, 88}, {214, 179}, {17, 187}, {472, 619}, {418, 261}, {419, 846}, {356, 192}, {682, 261}, {306, 514}, {201, 886}, {385, 530}, {952, 849}, {500, 294}, {194, 799}, {737, 391}, {324, 330}, {992, 298}, {224, 790}};

void dfs(int cur, vector<Item> &ItemSet)
{
    if (cur == (int)ItemSet.size())
    {
        TotalWeight = 0;
        for (auto item : t)
        {
            TotalWeight += ItemSet[item].weight;
        }
        if (TotalWeight > Capacity)
            return;
        TotalProfit = 0;
        for (auto item : t)
        {
            TotalProfit += ItemSet[item].profit;
        }

        // cout << "一组可行解：" << endl;
        // for (auto item : t)
        //     cout << item << " ";
        // cout << endl
        //      << "TotalProfit:" << TotalProfit << endl;

        if (TotalProfit > MaxProfit)
        {
            MaxProfit = TotalProfit;
            Result = t;
        }
        return;
    }
    t.push_back(cur);
    dfs(cur + 1, ItemSet);
    t.pop_back();
    dfs(cur + 1, ItemSet);
}

int main()
{
    clock_t startTime, endTime;
    startTime = clock();

    dfs(0, ItemSet);

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    //cout << endTime - startTime << endl;

    for (auto item : Result)
        cout << item << " ";
    cout << "MaxProfit：" << MaxProfit << endl;
    return 0;
}