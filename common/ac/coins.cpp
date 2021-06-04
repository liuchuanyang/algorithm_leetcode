#include<cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static int coinChange(vector<int>& coins, int amount) {
        // 初始化数组
        vector<int> dp(amount+1, -1);
        
        dp[0]=0;//金额为0的最优解
        // i是面值，初始化dp[0]=0
        for(int i=1; i<=amount;++i){
            // 遍历钱的面值
            for(int j=0; j<coins.size(); ++j){//递推条件
                // 如果金额i的面值大于第j个金币的面值，并且第i-coins[j]剩余的面值最优解不是-1
                if(i-coins[j]>=0 )
                {
                    if(dp[i]==-1||dp[i]>dp[i-coins[j]]+1){
                        dp[i]=dp[i-coins[j]]+1;
                    }
                }
                
            }
        }
        return dp[amount];
    }
};

int main(){
    vector<int> a={1,2,5,7,10};
    int m=Solution::coinChange(a, 14);
    cout<<m<<endl;
    return 0;
}