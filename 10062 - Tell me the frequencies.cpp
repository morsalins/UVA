#include<stdio.h>
#include<string.h>

int main()
{
    int otpt[128],i,j,k,l,min, index,once=1;
    char line[1001];

    while( gets(line) ){
		if(once!=1)printf("\n");

		for(i=0;i<128;i++) otpt[i]=0;

        for(i=0;i<strlen(line);i++){
            otpt[line[i]]++;
        }
        for(i=32;i<128;i++){
            min = 1001;
			for(j=32;j<128;j++){
                if(otpt[j]!=0){
                    if(min>=otpt[j]) {
						min=otpt[j];
						index=j;
					}
				}

			}
			if(otpt[index]!=0){
				printf("%d %d\n", index, otpt[index]);
				otpt[index]=false;
			}

		}
		once++;
	}
    return 0;
}
