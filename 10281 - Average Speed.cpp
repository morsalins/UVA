#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char line[30];
    int h, m, s, t, et = 0;
    float d, v, ev = 0.0, totaldist = 0.0;

    while( gets(line) ){

		int len = strlen(line);

        if( len > 8 ){
            sscanf(line, "%d:%d:%d %f", &h, &m, &s, &v);
			t = (h*3600) + (m*60) + s;
			d = (float)((t-et) / 3600.00) * ev;
			totaldist += d;
			et = t;
            ev = v;
        }

        else {
            sscanf(line, "%d:%d:%d", &h, &m, &s);
			t = (h*3600) + (m*60) + s;
            d = (float)((t-et) / 3600.00) * ev;
            printf("%s %0.2f km\n", line, totaldist+d);
        }
    }

    return 0;
}
