#include<iostream>

class listADT{
private :
int count=0;// initialised the count of elements as 0
int max_size=5; //maximum size of the array is 5
int arr[5];

public:
void display();// To print the array

int insertbeginning(int num);//To insert in the begining

int insertend(int num);//To insert in the end

int insertposition(int num,int position);//To insert in the index

int deletebeginning();//To delete the first number

int deleteend();//To delete the last number

int deleteposition(int position);//To delete the number form the given position

int search(int num);//To search the number and return the position

int rotate(int k);//To rotate the array towards right

};

int main(){
listADT list;
int choice,result,num,position,k;
do{
printf("\nMENU : \n 1)Insert Beginning \n 2)Insert End \n 3)Insert position \n 4)Delete Begining \n 5)Delete End \n 6)Delete Position \n 7)Search \n 8)Display \n 9)Rotate \n 10)Exit \n");
printf("Enter the choice : ");
scanf("%d",&choice);
switch (choice){
case 1:
printf("Enter the number to be inserted : ");
scanf("%d",&num);
result=list.insertbeginning(num);
if(result == 0)
{
printf("List is full.Cannot insert");
}
break;

case 2:
printf("Enter the number to be inserted : ");
scanf("%d",&num);
result=list.insertend(num);
if(result == 0)
{
printf("List is full.Cannot insert");
}
break;
case 3:
printf("Enter the number to be inserted : ");
scanf("%d",&num);
printf("Enter the position to be inserted : ");
scanf("%d",&position);
result=list.insertposition(num,position);
if(result == 0)
{
printf("List is full.Cannot insert");
}
if(result == -1)
{
printf("invalid position");
}
break;

case 4:
result=list.deletebeginning();
if(result == 0)
{
printf("List is empty.Cannot delete");
}else{
printf("Deleted element is %d",result);
}
break;

case 5:
result=list.deleteend();
if(result == 0)
{
printf("List is empty.Cannot delete");
}
break;

case 6:
printf("Enter the position to be inserted : ");
scanf("%d",&position);
result=list.deleteposition(position);
if(result == 0)
{
printf("List is empty.Cannot delete");
}
if(result == -1)
{
printf("invalid position");
}
break;

case 7:
printf("Enter the number to be searched : ");
scanf("%d",&num);
result=list.search(num);
if(result == -1){
printf("Invalid number");
}else{
printf("Your number's position is %d",result);
}
break;

case 8:
list.display();
break;

case 9:
printf("Enter the number of times to be rotated : ");
scanf("%d",&k);
result=list.rotate(k);
if(result == 1)
{
printf("rotated %d times",k);
}
break;

case 10:
printf("Exiting the loop !!\n");
break;

default:
printf("You have entered a wrong value !!\n");
}
}while(choice != 10);
return 0;
}

void listADT::display(){
for(int i=0;i<count;i++)
{
printf("%d\n",arr[i]);
}
}

int listADT::insertbeginning(int num){
if(count >= 5)
{
return 0;
}
for(int i = count;i>=0;i--)
{
arr[i] = arr[i-1];
}
arr[0] = num;
count++;
return 1;
}

int listADT::insertend(int num){
if(count >= 5)
{
return 0;
}
arr[count]= num;
count++;
return 1;

}

int listADT::insertposition(int num,int position){
if(count >= 5)
{
return 0;
}
if(position < 0 || position > max_size)
{
return -1;
}
for(int i = count;i > position;i--)
{
arr[i]=arr[i-1];
}
arr[position]=num;
count++;
return 1;

}

int listADT::deletebeginning(){
if(count < 0)
{
return 0;
}
for(int i=0;i<(count-1);i++)
{
arr[i]=arr[i+1];
}
count--;
return 1;
}

int listADT::deleteend(){
if(count < 0)
{
return 0;
}
count--;
return 1;

}


int listADT::deleteposition(int position){
if(count <= 0)
{
return 0;
}
if(position < 0 || position > max_size)
{
return -1;
}
for(int i=position;i<(count-1);i++)
{
arr[i]=arr[i+1];
}
count--;
return 1;
}

int listADT::search(int num){
for(int i=0;i<count;i++)
{
if(arr[i]==num)
{
return i;
}
}
return -1;
}

int listADT::rotate(int k){
int temp = 0;
for(int i=0;i<k;i++)
{
temp = arr[0];
for(int j=0;j<(count-1);j++)
{
arr[j]=arr[j+1];
}
arr[count-1]=temp;
}
return 1;
}

