#include <stdio.h>
#include"sort.h"

//linear search
int linearsearch(int arr[],int size,int target)
{
for(int i=0;i<size;i++)
{
    if(arr[i]==target)
    {
        return i;
    }
}
return -1;
}

//binary search
int binarysearch(int arr[],int size,int target)
{
int left=0;
int right=size-1;
int  mid;
while(left<=right)
{
    mid=(left+right)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    if(arr[mid]<target)
    {
        left=mid+1;
    }
    if(arr[mid]>target)
    {
        right= mid-1;
    }
}
return -1;
}
 
int main()
{
    int choice;
    int target;
    int size;
    int result_l,result_b;
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&size);

    int arr[size];
     printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
      printf("unsorted array is:\n");
    for(int i=0;i<size;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    printf("ENTER THE ELEMENT YOU WANT TO SEARCH FOR:");
    scanf("%d",&target);

    printf("Your menu for searching are:\n1.Linear search\n2.Binary search\n3.Exit\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&choice);

    switch(choice)   //menu to choose searching options
    {
        case 1:
        printf("Your choice is linear search and your searched\t");
        result_l = linearsearch(arr,size,target);
        if(result_l == -1)
        {
           printf("element is not found");
        }else{
             printf("element is found at:%d",result_l);
        }
        break;

        case 2:
        insertionsort(arr,size);      //sorting before binary search using insertion sort from header file       
        printf("Your choice is binary search and your searched\t");
        result_b = binarysearch(arr,size,target);
         if(result_b == -1)
        {
            printf("element is not found");
        }else{
            printf("element is found at:%d",result_b);
        }
        break;

        case 3:
        printf("Program exited ");
        break;
        
        default:
        printf("your choice is invalid");

    }
    return 0;
}