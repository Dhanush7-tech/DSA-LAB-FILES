#include <cstdio>
//selectionsort
void selectionsort(int arr[], int size)
{
 for (int i = 0; i < size - 1; i++)
{
 int min = i;
 for (int j = i + 1; j < size; j++)
 {
  if (arr[j] < arr[min])  
 {
   min = j;
 }
}
        
if (min != i) 
 {
  int temp = arr[i];
  arr[i] = arr[min];
 arr[min] = temp;
 }
 }
}

//bubble sort
void bubblesort(int arr[],int size)
{
for(int i=0;i<size-1;i++)
{
for(int j=0;j<size-i-1;j++)
{
if(arr[j]>arr[j+1])
{
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

}
//insertion sort
void insertionsort(int arr[],int size)
{
for(int i=1;i<size;i++)
{
int temp=arr[i];
int j=i-1;
while(j>=0 && arr[j]>temp)
{
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=temp;
}
}
//to print sorted array
void printarr(int arr[],int size)
{
for(int i =0;i<size;i++)
{
printf("%d",arr[i]);
}
}

int main()
{
printf("The menu:\n1.bubblesort\n2.selectionsort\n3.insertionsort\nexit\n");
int size;
int choice;
printf("enter the size of the array:");
scanf("%d",&size);
int arr[size];
printf("enter the elements of array:");
for(int i=0;i<size;i++){
scanf("%d",&arr[i]);
}

printf("what type of sorting do you need: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
bubblesort(arr,size);
printf("your choice is bubble sort and your sorted array is ");
printarr(arr,size);
break;
case 2:
selectionsort(arr,size);
printf("your choice is selection sort and your sorted array is ");
printarr(arr,size);
break;
case 3:
insertionsort(arr,size);
printf("your choice is insertion sort and your sorted array is ");
printarr(arr,size);
break;
default:
printf("exit");
}
return 0;
}
