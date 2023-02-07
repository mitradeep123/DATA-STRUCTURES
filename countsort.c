#include<stdio.h>
#include<conio.h>
void countsort(int[],int,int);
int main(){
    int a[10],n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
       printf("Enter value for a[%d]:",i);
       scanf("%d",&a[i]);
	}
	printf("Before sorting:\n");
	for(i=0;i<n;i++){
	   printf("%d ",a[i]);
	}
	int p=sizeof(a);
	int max=a[0];
	for(i=1;i<n;i++){
	   if(a[i]>max){
	   	max=a[i];
	   }
	}
	countsort(a,n,max);
	printf("\nAfter sorting:\n");
    for(i=0;i<n;i++){
       printf("%d ",a[i]);
	}
    return 0;
}
void countsort(int a[],int n,int max){
	int i,c[max+1],k=sizeof(a);
	int b[k];
	for(i=0;i<=max;i++){
	   c[i]=0;
	}
	for(i=0;i<=(n-1);i++){
	   c[a[i]]=c[a[i]]+1;
	}
	for(i=1;i<=max;i++){
	   c[i]=c[i-1]+c[i];
	}
	for(i=(n-1);i>=0;i--){
	   b[c[a[i]]-1]=a[i];
	   c[a[i]]=c[a[i]-1];
	}
	for(i=0;i<=(n-1);i++){
	   a[i]=b[i];
	}
}
