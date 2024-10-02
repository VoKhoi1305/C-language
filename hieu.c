#include<stdio.h>
#include<stdlib.h>

typedef struct mail{
    int stt;
    char mail[21];
} mail_t;

void printlist(mail_t a[], int n){
    for(int i=n-1; i>=0 ;i--)
    {
        printf("%d ",a[i].stt);
        printf("%s\n", a[i].mail);
    }
}

void swap(int *a ,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(mail_t A[],int L,int R){
    int i,j;
    int p;
    i=L; j=R+1; p=A[L].stt;
    while(i<j){
        i=i+1;
        while((i<=R) && (A[i].stt<p)) i++;
        j--;
        while((j>=L) && (A[j].stt>p)) j--;
        swap(&A[i] , &A[j]);
    }
    swap(&A[i] , &A[j]);
    swap(&A[j] , &A[L]);
    return j;
}

void QuickSort(mail_t A[],int left, int  right){
    if(left<right)
    {
        int pivot=partition(A,left,right);
        if(left<pivot)
            QuickSort(A,left,pivot-1);
        if(right>pivot)
            QuickSort(A,pivot+1,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    mail_t *arr = malloc(n* sizeof(mail_t));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].stt);
        scanf("%s", arr[i].mail);
    }

    QuickSort(arr,0,n-1);
    printlist(arr,n);

    return 0;
}
