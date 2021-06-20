/*
 * @Author      : PureWhite
 * @Date        : 2021-03-10 18:16:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-06-20 11:46:28
 * @Description : 
 */
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
vector<int> t;
void dfs(int cur, vector<int> &ItemSet)
{
    if (cur == (int)ItemSet.size())
    {
        for (auto item : t)
            cout << item << " ";
        cout << endl;
        return;
    }
    t.push_back(ItemSet[cur]);
    dfs(cur + 1, ItemSet);
    t.pop_back();
    dfs(cur + 1, ItemSet);
}
int main()
{
    // vector<int> nums = {1, 2, 3};
    // dfs(0, nums);
    int N = 20;
    clock_t startTime, endTime;
    startTime = clock();
    for (int i = 0; i < (1 << N); i++)
    {
        vector<int> tempSet;
        for (int j = 0; j < N; j++)
            if (((i >> j) & 1) == 1)
                tempSet.push_back(j);
        // for (auto item : tempSet)
        //     cout << item << " ";
        // cout << endl;
    }
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}