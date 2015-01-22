#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    string s;
    map <string, int> m;
	map <string, int>::iterator it;
    int cnt=0, tc;

    scanf("%d", &tc);
    getchar();
    scanf("\n");

    while( tc-- ){
        cnt = 0;
		while(1){
            getline(cin, s);
            if( s.empty() ) break;
            m[s]++;
            cnt++;
        }

        while( !m.empty() ){

            it=m.begin();
            string s1 = it->first;
			int n = it->second;
            //cout << n ;
			float result = ((float)n/(float)cnt)*100.00;
            cout << s1 << " ";
            printf("%.4f\n", result);
            m.erase(it);
        }
        if(tc>0)printf("\n");
    }

    return 0;
}
