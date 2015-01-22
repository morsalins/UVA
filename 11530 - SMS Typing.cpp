#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main()
{
    string text;
    int tc;

    scanf("%d", &tc);
	getchar();

    for(int kase=1; kase<=tc; kase++){

        getline( cin, text);

        int cnt = 0;
        int len = text.size();

        for(int index=0; index<len; index++){

            if( text[index]== 32){
                cnt++;
            }
            else if( text[index]>=97 && text[index]<=99){
                cnt += text[index]%96;
            }
            else if( text[index]>=100 && text[index]<=102){
                cnt += text[index]%99;
            }
            else if( text[index]>=103 && text[index]<=105){
                cnt += text[index]%102;
            }
            else if( text[index]>=106 && text[index]<=108){
                cnt += text[index]%105;
            }
            else if( text[index]>=109 && text[index]<=111){
                cnt += text[index]%108;
            }
            else if( text[index]>=112 && text[index]<=115){
                cnt += text[index]%111;
            }
            else if( text[index]>=116 && text[index]<=118){
                cnt += text[index]%115;
            }
            else if( text[index]>=119 && text[index]<=122){
                cnt += text[index]%118;
            }
        }

        printf("Case #%d: %d\n", kase, cnt);
    }

    return 0;
}
