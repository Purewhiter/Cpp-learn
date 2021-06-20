/*
 * @Author      : PureWhite
 * @Date        : 2021-06-20 16:12:06
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-20 16:16:24
 * @Description : 
 */
#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;
struct Item //物品
{
    int profit;
    int weight;
};
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
bool cmp(Item A, Item B)
{
    return (double)A.profit/A.weight>(double)B.profit/B.weight;
}
int main()
{
    sort(ItemSet.begin(), ItemSet.end(),cmp);
    for(auto &item : ItemSet)
    {
        cout << item.weight << " " << item.profit << endl;
    }
    return 0;
}