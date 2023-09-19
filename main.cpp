#include <iostream>
#include <stdlib.h>
using namespace std;

/*int DAC_Max(int arr[], int index, int l)
{
    int max;
    if(l - 1 == 0)
    {
      return arr[index];
    }
    if(index >= l - 2)
    {
        if(arr[index] > arr[index + 1])
          return arr[index];
        else
          return arr[index + 1];
    } 
    max = DAC_Max(arr, index + 1, l);   
    if(arr[index] > max)
       return arr[index];
    else
       return max;
}

int DAC_Min(int arr[], int index, int l)
{
    int min;
      if(l - 1 == 0)
    {
      return arr[index];
    }
    if(index >= l - 2)
    {
        if(arr[index] < arr[index + 1])
          return arr[index];
        else
          return arr[index + 1];
    }
     
    min = DAC_Min(arr, index + 1, l);  
    if(arr[index] < min)
       return arr[index];
    else
       return min;
}

int main(int, char**){
     int arr[7] = { 70, 250, 50, 80, 140, 12, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    max = DAC_Max(arr, 0, n);
    min = DAC_Min(arr, 0, n);
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    return 0;
}*/
struct max{
  int leftmax;
  int rightmax;
  int sum;
};
struct max fmcs(int arr[],int low,int mid,int high)
{
  int leftsum=INT32_MIN;
  int sum=0;
  struct max cross;
  for(int i=mid;i>=low;i--)
  {
    sum=sum+arr[i];
    if(sum>leftsum)
    {
      leftsum=sum;
      cross.leftmax=i;
    }
  }
  int rightsum=INT32_MIN;
  sum=0;
  for(int i=mid+1;i<=high;i++)
  {
    sum=sum+arr[i];
    if(sum>rightsum)
    {
      rightsum=sum;
      cross.rightmax=i;
    }
  }
  cross.sum=leftsum+rightsum;
  return cross;
}
struct max fms(int arr[],int low,int high)
{
  if(high==low)
  {
    struct max max;
    max.leftmax=low;
    max.rightmax=high;
    max.sum=arr[low];
    return max;
  }
    
  else
  {
    int mid=(low+high)/2;
    struct max left=fms(arr,low,mid);
    struct max right=fms(arr,mid+1,high);
    struct max cross=fmcs(arr,low,mid,high);
    if(left.sum>=right.sum&&left.sum>=cross.sum)
      return left;
    else if(right.sum>=left.sum&&right.sum>=cross.sum)
      return right;
    else
    return cross;

  }
}
int main()
{
  FILE *fptr;
  fptr=fopen("1.txt","r");
  if(fptr==NULL)
  {
    cout<<"xxx";
    return 0;
  }
  int arr[100]={0};
  int i=0;
  while (fscanf(fptr, "%d", &arr[i]) != EOF) 
  {
    i++;     
  }
  struct max max=fms(arr,0,i-1);
  cout<<max.leftmax<<"\n"<<max.rightmax<<"\n"<<max.sum;
  return 0;
}
