#include <stdio.h>

int main()
{
    int arr[20], n, i, j, temp,testcase, caseno,swap;

    scanf("%d", &testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        swap=0;
        for(i=0; i<n-1; i++){

            for(j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swap++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps", swap);
        if(caseno<testcase)printf("\n");
    }
    return 0;
}
