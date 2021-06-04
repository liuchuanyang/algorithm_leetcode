#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int> > &result)
{
    if(i>=nums.size()){
        return;
    }
    item.push_back(nums[i]);
   
    result.push_back(item);
    generate(i+1, nums, item, result);
}

int main(){
    vector<int> nums;
    for(int i=1; i<4; ++i)
    {
        nums.push_back(i);
    }
    vector<int> item;
    vector<vector<int> > result;
    generate(0, nums, item, result);
    for(int i=0; i< result.size(); ++i)
    {
        for(int j=0; j<result[i].size();++j)
        {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}