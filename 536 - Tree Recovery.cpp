#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<cctype>
#include<cmath>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>


using namespace std;

string otpt;

void postOrder(string::iterator in, string::iterator pre, int n)
{
    int root = find(in, in+n, *pre) - in;

    if (root != 0)
        postOrder(in, pre+1, root);

    if (root != n-1)
        postOrder(in+root+1, pre+root+1, n-root-1);

    otpt += *pre;
}

int main()
{
    string pre, in;

    while(cin >> pre >> in){

        postOrder(in.begin(), pre.begin(), in.size());

        cout << otpt << "\n";

        otpt.clear();
    }

    return 0;
}

