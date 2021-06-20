#include <iostream>
#include <fstream>
using namespace std; 

int knapSack(int n,int w[],int v[],int MW)  
//传入参数为物品数量n,每个物品重量w[],每个物品价值v[],包的最大承重MW 
{
	int V[n+1][MW+1];  
	//定义二维表，V[i][j]表示的含义是当第i个物品放入最大承重为j的包时，包能容纳的最大的价值
	int i,j;
	for(i=0;i<=n;i++)
		V[i][0]=0;
	for(i=0;i<=MW;i++)
		V[0][i]=0;
	//将二维表处理一下，0行和0列都为0 
	  
	//填表  
	for( i = 1 ; i <= n ; i++ )      //从第一个物品开始装 
		for( j = 1; j <= MW ; j++ )   //包的最大承重逐一增加 
		{
			if (j-w[i-1]<0)    		 // w[i-1]是第i个物品的重量，如果当前物品加进来会超过包此时的最大承重 
				V[i][j] = V[i-1][j];  // 那就不把该物品加入，则此处的值应该与前一个物品在这个承重下的值一样 
			else					
				// 如果该物品可以被加入 ，需要判断：
				// 该物品的价值加上包最大承重减去该物品重量下包的最大价值  是否会大于  不加入该物品包的最大价值 
				V[i][j]= ( V[i-1][j] > ( V[i-1][j-w[i-1]]+v[i-1] ) ) ?   V[i-1][j] : V[i-1][j-w[i-1]]+v[i-1] ;
		}
	
	return V[n][MW];	
}


int main()
{	
    //  "f5_l-d_kp_15_375"
    string path[10] = {"f1_l-d_kp_10_269","f2_l-d_kp_20_878", "f3_l-d_kp_4_20", 
                        "f4_l-d_kp_4_11","f6_l-d_kp_10_60", 
                        "f7_l-d_kp_7_50", "f8_l-d_kp_23_10000", "f9_l-d_kp_5_80" , "f10_l-d_kp_20_879" };
    int n, MW, v[n], w[n],MV;
    int i;
   
    for (i = 0; i < 9 ; i++)
    {
        fstream infile;
        infile.open(path[i], ios::in);
	    infile >> n;
	    infile >> MW;
        int j = 0;
        while(!infile.eof())
	    {
		    infile >> v[j];infile >> w[j];
            j++ ;
	    }
	    infile.close();


        MV= knapSack(n, w, v, MW);
        // cout << MV << endl;
	    cout << "maxvalue of bag" << i+1 << ": " << MV << endl;
    }

    cout << endl;
    return 0;
}
	
