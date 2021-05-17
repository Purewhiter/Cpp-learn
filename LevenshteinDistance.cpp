/*
 * @Author      : PureWhite
 * @Date        : 2021-05-08 23:40:00
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-05-09 00:04:28
 * @Description : 
 */
#include <algorithm>
#include <iostream>
using namespace std;

// class EditDistance
// {
// public:
//     int minDistance(string P, string T)
//     {
//         int m = P.length();
//         int n = T.length();
//         if (m * n == 0)
//             return m + n;
//         int D[m + 1][n + 1];
//         for (int i = 0; i <= m; i++)
//             D[i][0] = i;
//         for (int j = 0; j <= n; j++)
//             D[0][j] = j;
//         for (int j = 1; j <= n; j++)
//         {
//             for (int i = 1; i <= m; i++)
//             {
//                 if (P[i-1]==T[i-1])
//                     D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j] + 1, D[i][j - 1] + 1));
//                 else
//                     D[i][j] = min(D[i - 1][j - 1]+1, min(D[i - 1][j] + 1, D[i][j - 1] + 1));
//             }
//         }
//         return D[m][n];
//     }
// };

class EditDistance {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};


int main()
{
    EditDistance solution = EditDistance();
    cout<<solution.minDistance("happy", "hsppay");
    return 0;
}