#include <stdio.h>

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
void print(int *arr, int length)
{
    for(int i=0; i<length; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    // int arr[]={1,2,3,4,5,6};
    int length=(int)sizeof(arr)/sizeof(*arr);
    print(arr, length);
    // 冒泡排序
    // bubble_sort(arr, length);
    //  选择排序
    select_sort(arr, length);

    
    print(arr, length);
}