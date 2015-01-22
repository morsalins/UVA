#include<cstdio>
#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

#define MCI map<char, int>

int main()
{
    MCI m;
    int tc, cost;
    char ch;
    string s;
    long long int n;
    double sum;

    scanf("%d", &tc);

    while( tc-- ){

        sum=0;
        scanf("%lld", &n);
        for(long long int i=1; i<=n; i++){
            cin >> ch >> cost;
            m[ch] = cost;
        }

        scanf("%lld\n", &n);
        for(long long int i=1; i<=n; i++){
            getline(cin, s);
            //cout << s;
            for(string::iterator it=s.begin(); it!=s.end(); it++){
                sum+=m[*it];
            }
        }

        //double r = (double)(sum/100.00);
        printf("%.2lf$\n", (sum/100.00) );
        m.clear();
    }

    return 0;
}
