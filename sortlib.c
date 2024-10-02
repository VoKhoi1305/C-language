#include<stdio.h>
#include<stdlib.h>
void printlist(double a[], int n){
    for(int i=n-1; i>=0 ;i--)
    {
        printf("%.2lf\n",a[i]);
    }
    printf("\n");
}
void swap(double *a ,double *b){
double temp;
temp=*a;
*a=*b;
*b=temp;
}
//============================

int partition(double A[],int L,int R){
   int i,j;
  double p;
    i=L; j=R+1; p=A[L];
    while(i<j){
        i=i+1;
        while((i<=R) && (A[i]<p)) i++;
        j--;
        while((j>=L) && (A[j]>p)) j--;
        swap(&A[i] , &A[j]);
    }
    swap(&A[i] , &A[j]);
    swap(&A[j] , &A[L]);
    return j;
}
void QuickSort(double A[],int left, int  right){
    if(left<right)
    {
        int pivot=partition(A,left,right);
        if(left<pivot)
            QuickSort(A,left,pivot-1);
        if(right>pivot)
            QuickSort(A,pivot+1,right);
    }
}
//==========================================================================================================================
int main(){
    double arr[15];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
       scanf("%lf", &arr[i]);
    }
   // Insertionsort(arr,n);
   // Selectionsort(arr,n);
  // Bubblesort(arr,n);
 // MergeSort(arr,0,n-1);
 QuickSort(arr,0,n-1);
    printlist(arr,n);

    return 0;
}
