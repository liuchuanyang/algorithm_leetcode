#include <vector>
#include <iostream>
#include<cstdio>

using namespace std;
class Solution {
public:
    void static generator(int i, vector<int>& nums, vector<int>&item, vector<vector<int> > &result)
   {
       if(i>=nums.size()){
           return;
       }
    //    command
    item.push_back(nums[i]);
    result.push_back(item);
    print(item);
    generator(i+1, nums, item, result);
    item.pop_back();
    generator(i+1, nums, item, result);

   }
    vector<vector<int> > subsets(vector<int>& nums) {
        // vector<vector<int> > result;
        vector<int> item;
        this->result.push_back(item);
        
        generator(0, nums, item, this->result);
        return this->result;

    }
    void static print(vector<int> &item)
    {
        for(int i=0; i<item.size();++i)
        {
            printf("[%d]\t", item[i]);
        }
        cout<<endl;
    }
private:
    vector<vector<int> > result;
};
int main(){
    vector<int> nums={1,2,3};
    Solution s;
    s.subsets(nums);
}