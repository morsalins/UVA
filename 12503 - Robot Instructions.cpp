#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

void currentPosition(string l, int *left, int *right){

    string s = "LEFT";
    if(!l.compare(s)) *left = *left+1;
    else *right = *right+1;
}

int main()
{
	int right, left;
    int tc, n, step, index;
    char line[50], t1[6], t2[4];
    vector <string> lines;

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);
		getchar();

        right=0;
        left=0;
        index=1;
        lines.push_back("\n");

        for(int i=1; i<=n; i++){

			gets(line);
            int len = strlen(line);

            if( len > 5){
                sscanf(line, "%s %s %d", t1, t2, &step);
                lines.push_back(lines[step]);
                currentPosition(lines[step], &left, &right);
            }
            else{
                lines.push_back(line);
                currentPosition(line, &left, &right);
            }
        }

        printf("%d\n", right-left);
		lines.clear();
    }

    return 0;
}
