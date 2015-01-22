#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<cctype>
#include <cstring>


using namespace std;

struct information{
    int name;
    int solve;
    int penulty;
};

typedef struct information info;

bool cmp (info x, info y)
{
    if ( x.solve > y.solve ) return true;
    if ( x.solve == y.solve && x.penulty < y.penulty ) return true;
    if ( x.solve == y.solve && x.penulty == y.penulty && x.name < y.name ) return true;
    return false;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    map <int, int> solved, time;
    map <int, bool> submission;
    vector <info> v;
    int stat[101][11];
    bool isSolved[101][11];
    int num, s, t;
    char verdict;
    char line[25];
    info contestants;
    int tc;

    scanf("%d", &tc);
    getchar();
    gets(line);

    while( tc-- ){

        memset(stat, 0, sizeof(stat));
        memset(isSolved, 0, sizeof(isSolved));


        while( gets(line) && strlen(line) ){

            sscanf(line, "%d %d %d %c", &num, &s, &t, &verdict);

            submission[num] = true;

            if(verdict=='R'||verdict=='U'||verdict=='E') continue;

            else if(verdict=='I'){
                stat[num][s]++;
            }

            else if(verdict=='C'){
                if(!isSolved[num][s]){
                    solved[num]++;
                    isSolved[num][s] = true;
                    time[num] += t + (stat[num][s]*20);
                    stat[num][s]++;
                }
            }
        }

        for(int i=1; i<101; i++){

            if(submission[i]){
                contestants.name = i;
                contestants.solve = solved[i];
                contestants.penulty = time[i];
                v.push_back(contestants);
            }
        }

        sort (v.begin(), v.end(), cmp);

        int len = v.size();
        for(int i=0; i<len; i++){
            cout << v[i].name << " " << v[i].solve << " " << v[i].penulty << "\n";
        }

        if(tc>0)cout << "\n";

        v.clear();
        solved.clear();
        time.clear();
        submission.clear();

    }

    return 0;
}
