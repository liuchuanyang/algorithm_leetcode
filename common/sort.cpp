#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
void swap(int *p, int *q)
{
    int tmp;
    tmp=*p;
    *p=*q;
    *q=tmp;
    // printf("%d, %d\n", *p, *q);
}
/*
@冒泡排序
比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
https://www.runoob.com/w3cnote/bubble-sort.html
*/
int bubble_sort(int *arr, int length)
{
    int len, j;
    bool flag;
    for(len=length-1; len>=1; len--)
    {
        flag=true;//判断程序是否发生了交换，如果没有交换，数组已经有序
        for(j=0; j<len; ++j)
        {
            if(arr[j]>arr[j+1])
            {
                flag=false;
                swap(arr+j, arr+j+1);
            }
        }
        if(flag)
            break;
    }
    return 0;
}
/*
@选择排序
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕。
@注：比较次数O(n^2),交换次数O(n)
*/
int select_sort(int *arr, int length)
{
    int i, j;
    for(i=0; i<length-1;++i)
    {
        int min=i;
        for(j=i+1;j<length; ++j)
        {
            if(arr[min]>arr[j])
            {
                min=j;
                
            }
        }
         swap(arr+i, arr+min);
    }
    return 0;
}
// 插入排序
void insert_sort(int *arr, int length)
{
    int i,j;
    for(i=1; i<length; ++i)
    {
        int p=arr[i];
        j=i;
        while(j>0&&arr[j-1]>p)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=p;
        // for(j=i; j>0; j--)
        // {
        //     if(arr[j-1]>p)
        //     {
        //         arr[j]=arr[j-1];
        //     }
        //     else
        //     {
        //         break;
        //     }
            
        // }
        // arr[j]=p;
    }
}
int parition(int *arr, int low, int high)
{
    int p= arr[low];
    while(low<high)
    {
        while(low<high && arr[high]>p)
        {
            high--;
        }
        arr[low]=arr[high];
        while(low<high && arr[low]<p)
        {
            low++;
        }
        arr[high]=arr[low];
    }
    arr[high]=p;
    return low;
}
void quick_sort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pivot=parition(arr, low, high);
        quick_sort(arr, low, pivot-1);
        quick_sort(arr, pivot+1, high);
    }
    
}
// i是二叉树倒数第一个非叶子节点
void heapfiy(int *arr, int n, int i)
{
    // 左孩子
    int s1=2*i+1;
    // 右孩子
    int s2=2*i+2;
    // 初始化最大结点
    int largest=i;
    if(arr[s1]>arr[largest] && s1<=n)
    {
        largest=s1;
    }
    if(arr[s2]>arr[largest]&& s2<=n)
    {
        largest=s2;
    }
    if(largest!=i)
    {
        swap(arr+i, arr+largest);
        heapfiy(arr, n, largest);
    }

}
// 大堆排序，为升序
void heapsort(int *arr, int length)
{
    int n=length-1;
    // 建堆
    for(int i = (n-1)/2; i>=0; --i)
    {
        heapfiy(arr, n, i);
    }
    for(int i=n; i>0; --i)
    {
        // 交换
        swap(arr+i, arr);
        // 重建堆，i-1是因为最后一个元素已经被剔除
        heapfiy(arr, i-1, 0);
    }
    
    
}
// void print(int *arr, int length)
// {
//     for(int i=0; i<length; ++i)
//     {
//         printf("%d\t", arr[i]);
//     }
//     printf("\n");
// }
void print(const vector<int> &arr)
{
    for(int i=0; i< arr.size(); ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge_two_vec(vector<int>& sub1, vector<int>& sub2, vector<int> &vec)
{
    int i=0;
    int j=0;
    while(i<sub1.size()&&j<sub2.size())
    {
        if(sub1[i]<=sub2[j])
        {
            vec.push_back(sub1[i]);
            ++i;
        }
        else{
            vec.push_back(sub2[j]);
            ++j;
        }
    }
    for(;i<sub1.size();++i)
    {
        vec.push_back(sub1[i]);
    }
    for(;j<sub2.size(); ++j)
    {
        vec.push_back(sub2[j]);
    }
}
void merge_sort(vector<int> &vec)
{
    int size=vec.size();
    if(size<=1)
    {
        return;
    }
    int mid=size/2;
    vector<int> subset1;
    vector<int> subset2;
    for(int i=0; i<mid; ++i)
    {
        subset1.push_back(vec[i]);
    }
    for(int i=mid; i<size; ++i)
    {
        subset2.push_back(vec[i]);
    }
    merge_sort(subset1);
    merge_sort(subset2);
    vec.clear();
    merge_two_vec(subset1, subset2, vec);
}
int main()
{
    // int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    // int arr[]={1,2,3,4,5,6};
    // int length=(int)sizeof(arr)/sizeof(*arr);
    // print(arr, length);
    // 冒泡排序
    // bubble_sort(arr, length);
    //  选择排序
    // select_sort(arr, length);
    // 插入排序
    // insert_sort(arr, length);
    // 快速排序
    // quick_sort(arr, 0, length-1);
    // 堆排序
    // heapsort(arr, length);
    vector<int> arr={ 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    merge_sort(arr);
    print(arr);
}