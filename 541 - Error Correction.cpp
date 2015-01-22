#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    map <int, int> r, c;
    //vector <int> v;
    int n, bit;
    
    while(cin >> n){
         
         if(n==0)return 0;
         
         for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> bit;
                if(bit){
                   r[i]++;
                   c[j]++;
                }    
            }
         }
         
         int row = 0, oddRow = 0;
         int col = 0, oddCol = 0;
         for(map<int, int>::iterator it=r.begin(); it!=r.end(); it++){
            if(it->second & 1){
               oddRow++;
               row = it->first;
            }
         }
         
         for(map<int, int>::iterator it=c.begin(); it!=c.end(); it++){
            if(it->second & 1){
               oddCol++;
               col = it->first;
            }
         }
         
         if(oddRow==0 && oddCol==0)printf("OK\n");
         else if(oddRow==1 && oddCol==1)printf("Change bit (%d,%d)\n", row, col);
         else printf("Corrupt\n");
         
         r.clear();
         c.clear();
    }
         
    return 0;  
}
