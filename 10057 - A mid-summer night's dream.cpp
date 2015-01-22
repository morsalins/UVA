#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

#define SIZE 65536
#define I64 long long

int main()
{
    unsigned int num, median, another_median;
    long int n;
    set <unsigned int> numbers;
    unsigned int counters[SIZE+10];

    while( cin >> n ){

        memset(counters, 0, sizeof(counters));
        for(int i=1; i<=n; i++){

            cin >> num;
            counters[num]++;
            numbers.insert(num);
        }

        //int len = numbers.size();

        if( n&1 ){

           int limit = n/2;
           set <unsigned int>::iterator it = numbers.begin();
           int temp = *it;
           int i = counters[ temp ];
           while(1){

               if(i>limit){
                    median = *it;
                    break;
               }
               it++;
               temp = *it;
               i += counters[ temp ];
           }
           cout << median << " " << counters[median] << " " << "1" << "\n";
        }

        else{

           int limit = n/2;
           set <unsigned int>::iterator it = numbers.begin();
           int temp = *it;
           int i = counters[ temp ];
           while(1){

               if(i>=limit){
                    median = *it;
                    break;
               }
               it++;
               temp = *it;
               i += counters[ temp ];
           }

           it++;
           temp =  *it;
           if(counters[median] == counters[ temp ]){
              another_median = temp;
              cout << median << " " << counters[median]+counters[another_median] << " " << another_median-median+1 << "\n";
           }

           else{
              cout << median << " " << counters[median] << " " << "1" << "\n";
           }
        }

        numbers.clear();
    }

    return 0;
}
