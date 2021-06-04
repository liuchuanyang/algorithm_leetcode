#include<iostream>
#include<vector>
#include <string>
#include <queue>
using namespace std;
// leet_code assign cookes 
int findContentChildren(vector<int>& g, vector<int>& s)
{
    // 对孩子需求因子g与糖果大小s两数组排序
    std::sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child=0;//代表已满足几个孩子，cookie代表尝试了几个糖果
    int cookie=0;
    while(child<g.size()&&cookie<s.size())
    {
        if(g[child]<=s[cookie])
        {
            child++;
            
        }
        cookie++;
        
    }
    return child;
}
// leetcode 376,最大摇摆数列
int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
        {
            return nums.size();//序列个数小于2，直接为摇摆数列
        }
        // 扫描序列时的三种状态
        static const int BEGIN=0;
        static const int UP=1;
        static const int DOWN=2;
        // 摇摆序列最大长度为1
        int max_length=1;
        int STATE=BEGIN;
        for(int i=1; i<nums.size(); ++i)
        {
            switch (STATE)
            {
            case BEGIN:
               if(nums[i-1]>nums[i])
               {
                   STATE=DOWN;
                   max_length++;
               }
               else if(nums[i-1]<nums[i])
               {
                   STATE=UP;
                   max_length++;
               }
                break;
            
            case UP:
                if(nums[i-1]>nums[i])
                {
                    STATE=DOWN;
                    max_length++;
                }
                // else if(nums[i-1]<nums[i])
                // {
                //     STATE=UP;
                // }
                break;
            case DOWN:
                if(nums[i-1]<nums[i])
                {
                    STATE=UP;
                    max_length++;
                }
                // else if(nums[i-1]>nums[i])
                // {
                //     STATE=DOWN;
                // }
                break;
            }
        }
        return max_length;
        
    }
// 汽车加油
int minRefuelStops(int target, int startFuel, vector<vector<int> >& stations) {
        priority_queue<int> Q;
        int result=0;//加油的次数
        vector<int> end={target, 0};
        stations.push_back(end);
        cout<<"size: "<<stations.size()<<endl;
        // 计算各个停靠点间的距离, station[i][0]加油站间的距离，station[i][1]加油站的油量
        for(int i=stations.size()-1; i>0;--i)
        {
            stations[i][0]-=stations[i-1][0];
            cout<<stations[i][0]<<"\t";
        }
        for(int i=0;i<stations.size(); ++i)
        {
            int dis=stations[i][0];
            while(!Q.empty()&&startFuel<dis)
            {
                startFuel+=Q.top();
                Q.pop();
                ++result;
            }
            if(Q.empty()&&startFuel<dis){
                return -1;
            }
            startFuel-=dis;
            Q.push(stations[i][1]);
        }
        
        return result;
    }
int enum_study()
{
    enum state{BEGIN, UP, DOWN};
    state s=DOWN;
    cout<<BEGIN<<endl;
    cout<<UP<<endl;
    cout<<s<<endl;
    std::string sp;
    sp.append(1, 'a');
    sp.append(1,'b');
    cout<<sp<<endl;
    vector<int> vec;
   
    return 0;
}
int main()
{   
    // enum_study();
    vector<vector<int> > vec={{10,60},{20,30},{30,30},{60,40}};
    int result=minRefuelStops(100, 10, vec);
    cout<<result<<endl;
    return 0;
}