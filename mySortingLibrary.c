#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//when size of the list is less than cutoff, insertionSort() is called; or else quickSort() is called
#define CUTOFF 3

typedef int elementType;

int getRandom(elementType a[]); // generates an array of random numbers based on user input.

void insertionSort(elementType a[],int N);
void bubbleSort(elementType a[],int N);
void shellSort(elementType a[], int N);
//void selectionSort(elementType a[],int N);

void mergeSort(elementType a[],int N);
void msort(elementType a[],elementType tmparray[], int left, int right);
void merge(elementType a[],elementType tmparray[], int lpos, int rpos,int rend);

void quickSort(elementType a[],int N);
void qsort_byme(elementType a[], int left, int right);
elementType median3(elementType a[],int left,int right);
void swap(elementType *ptrElement1, elementType *ptrElement2);

int getRandom(elementType a[])
{
  int i,N;
  char yorn[2];
  printf("Please enter the size of the list to sort: ");
  scanf("%d",&N);

  for(i=0;i<N;i++)
    a[i]=random();

  printf("Would you like to see the complete list, (Y or N): ");
  scanf("%s",yorn);

  if(tolower(yorn[0]=='y'))
  {
    for(i=0;i<N;i++)
      printf("\n%d",a[i]);
  }
  return N;
}

//insertion sort is efficient if you want to insert a new element on an already sorted list in the correct position.
//for ith pass, the first (i-1)th elements in the list should be sorted
void insertionSort(elementType a[],int N)
{
  int i,j,tmpcell;
  for(i=0;i<N;i++)
  {
    tmpcell=a[i];
    for(j=i;a[j-1]>tmpcell&&j>=0;j--)
      a[j]=a[j-1];
    a[j]=tmpcell;
  }
}

void bubbleSort(elementType a[],int N)
{
  int i,j,tmp;
  for(i=0;i<N;i++)
  {
    for(j=0;j<(N-i);j++)
    {
      if(a[j]>a[j+1])
      {
        tmp=a[j];
        a[j]=a[j+1];
        a[j+1]=tmp;
      }
    }
  }
}

void shellSort(elementType a[], int N)
{
  int i,j,increment,tmp;
  for(increment=N/2;increment>0;increment/=2)
  {
    for(i=increment;i<N;i++)
    {
      tmp=a[i];
      for(j=i;j>=increment;j-=increment)
      {
        if(tmp<a[j-increment])
          a[j]=a[j-increment];
        else
          break;
      }
      a[j]=tmp;
    }
  }
}


void mergeSort(elementType a[],int N)
{
  elementType *tmparray;
  tmparray=malloc(sizeof(elementType));
  if(tmparray!=NULL)
  {
    msort(a,tmparray,0,N-1);
    free(tmparray);
  }
  else
    printf("Fatal error:out of memory");
}

void msort(elementType a[],elementType tmparray[], int left, int right)
{
  int center;
  if(left<right)
  {
    center=(left+right)/2;
    msort(a,tmparray,left,center);
    msort(a,tmparray,center+1,right);
    merge(a,tmparray,left,center+1,right);
  }
}

void merge(elementType a[],elementType tmparray[], int lpos, int rpos,int rend)
{
  int lend=rpos-1;
  int i;
  int NumElements=rend-lpos+1;
  int tmppos=lpos;

  while(lpos<=lend && rpos <=rend)
  {
    if(a[lpos]<=a[rpos])
      tmparray[tmppos++]=a[lpos++];
    else
      tmparray[tmppos++]=a[rpos++];
  }
  while(lpos<=lend)
    tmparray[tmppos++]=a[lpos++];
  while(rpos<=rend)
    tmparray[tmppos++]=a[rpos++];

  //copying array back to a
  for(i=0;i<NumElements;i++,rend--)
    a[rend]=tmparray[rend];
}


void quickSort(elementType a[],int N)
{
    qsort_byme(a,0,N-1);
}

void qsort_byme(elementType a[],int left,int right)
{
  if((right-left)>=CUTOFF)
  {
    elementType pivot=median3(a,left,right);
    int i=left;
    int j=right-1;

    for(;;)
    {
      while(a[++i]<pivot){}
      while(a[--j]>pivot){}
      if(i<j)
          swap(&a[i],&a[j]);
      else
          break;
    }
    swap(&a[i],&a[right-1]);
    qsort_byme(a,left,i-1);
    qsort_byme(a,i+1,right);
  }
  else
    insertionSort(a+left,right-left+1);
}

elementType median3(elementType a[],int left,int right)
{
  int center=(left+right)/2;
  if(a[left]>a[center])
    swap(&a[left],&a[center]);
  if(a[left]>a[right])
    swap(&a[left],&a[right]);
  if(a[center]>a[right])
    swap(&a[center],&a[right]);

  swap(&a[center],&a[right-1]);
  return a[right-1];
}

void swap(elementType *ptrElement1, elementType *ptrElement2)
{
  elementType *ptrTmp;
  ptrTmp=ptrElement1;
  ptrElement1=ptrElement2;
  ptrElement2=ptrTmp;
}


int main()
{
  int i;
  elementType a[10000];
  int N=getRandom(a);
  quickSort(a,N);
  printf("\nSorted");
  for(i=0;i<N;i++)
    printf("\n%d",a[i]);
  return 0;
}
