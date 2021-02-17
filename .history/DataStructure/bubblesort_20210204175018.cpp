/*
 * @Author      : PureWhite
 * @Date        : 2021-02-04 17:39:46
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-04 17:50:18
 * @Description : 
 */
#include<iostream>
using namespace std;
void BubbleSort(int A[],int n)
{
    for (bool sorted = false;sorted=!sorted;n--)
        for(int i=1;i<n;i++)
        {
            if(A[i-1]>A[i])
            {
                swap(A[i-1],A[i]);
                sorted=false;
            }
        }
}
int main()
{
    int a[] = {8, 5, 2, 9, 6, 5, 3};
    BubbleSort(a, mblen(a));
    for(auto i:a)
        cout << i << " ";
    return 0;
}