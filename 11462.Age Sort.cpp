#include<stdio.h>

void quicksort(unsigned long int, unsigned long int);
unsigned long int partition(unsigned long int m, unsigned long int p);

long int arr[2000001],temp,v;
unsigned long int n,i,j,k;

int main()
{
   while( scanf("%lu",&n)==1 ){
       if(n==0)break;

       for(i=0;i<n;i++)
            scanf("%ld",&arr[i]);
       quicksort(0, n-1);


       for(k=0; k<n; k++){
           printf("%ld", arr[k]);
           if(k<n-1)printf(" ");
       }
       printf("\n");
   }
    return 0;
}

void quicksort(unsigned long int p, unsigned long int q){
    if(p<q){
        j = partition(p,q);
        quicksort(p,j-1);
        quicksort(j+1,q);
    }
}

unsigned long int partition(unsigned long int m, unsigned long int p){

    v = arr[m];
    i=m+1;
    j=p;

    while(arr[i]<v && i<=p)
        i++;

    while(arr[j]>v && j>=m)
        j--;

    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;j--;

        while(arr[i]<v)
            i++;
        while(arr[j]>v)
            j--;
    }

    arr[m]=arr[j];
    arr[j]=v;

    return j;
}
