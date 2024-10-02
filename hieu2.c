#include<stdio.h>

#include<stdlib.h>


int main()
{
	int n =10;
	int A[10];
	int nthval =0;
	int ab;
	for (int i=0; i<n; i++){
		ab=0;
		for (int j = 0; j<i;j++){
			if (nthval-i == A[j]){
				ab=1;
			}
			
		if(nthval-i>0 && ab==0){
			nthval -= i;
		}	
		else nthval += i;
		
		A[i]= nthval;
		printf("%d\n",nthval);
		}
	}
	return 0;
}
