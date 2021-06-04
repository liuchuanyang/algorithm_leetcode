#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // 存在多个不同的解法
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> >mark;
        vector<string> location;
        vector<vector<string> > result;
        // vector<int> item;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
               mark[i].push_back(0);
            }
            // mark.push_back(item);
            // item.erase(item.begin(), item.end());
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n,location,result, mark);
        return result;
    }
    void static generate(int k, int n,//k完成了几个皇后的放置(正在放置第k行皇后)
        vector<string> &location, //某次结果存储在location中
        vector<vector<string> >&result,
        vector<vector<int> > &mark//表示棋盘标记数组
        )
    {
        
        if(k==n){//当满足？？时，结束递归，结束前需要？？
            result.push_back(location);
            return;
        }
        for(int i=0; i<n; ++i)
        {
            if(mark[k][i]==0){
                vector<vector<int> > tmp_mark=mark;//记录回溯前的mark镜像
                location[k][i]='Q';
                put_down_the_queen(k,i, mark);//放置皇后
                generate(k+1, n, location, result, mark);//递归下一行皇后放置
                
                mark=tmp_mark;//回溯后要做？？事
                location[k][i]='.';

            }
        }
    }
    void static put_down_the_queen(int x, int y, vector<vector<int> > &mark)
    {
        static const  int dx[]={-1,1,0,0,-1,-1,1,1};
    static const  int dy[]={0, 0,-1, 1, -1, 1, -1,1};
        mark[x][y]=1;
        for(int i=1; i<mark.size(); ++i)
        {
            for(int j=0; j<8; ++j)
            {
                int new_x=x+i*dx[j];
                int new_y=y+i*dy[j];
                if(new_x>=0&&new_x<mark.size()&&new_y>=0&&new_y<mark.size())
                {
                    mark[new_x][new_y]=1;
                }
            }
        }
        
    }
};

int main(){
    Solution s;
    s.generate()
}