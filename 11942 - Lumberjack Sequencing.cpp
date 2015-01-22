#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> v1, v2;

bool isIncreasedOrder(){

    for(int i=0; i<=9; i++){
        if( v1[i]!=v2[i]) return false;
    }

    return true;
}

bool isDecreasedOrder(){

    for(int i=9, j=0; i>=0; i--, j++){
        if( v1[i]!=v2[j]) return false;
    }

    return true;
}

int main()
{
    int tc, b;

    scanf("%d", &tc);
    printf("Lumberjacks:\n");

    while( tc-- ){

        for(int i=0; i<=9; i++){
            scanf("%d", &b);
            v1.push_back(b);
            v2.push_back(b);
        }

        sort( v2.begin(), v2.end());

        if( isIncreasedOrder() || isDecreasedOrder() ){
            printf("Ordered\n");
        }

        else  printf("Unordered\n");

        v1.clear();
        v2.clear();
    }

    return 0;
}
