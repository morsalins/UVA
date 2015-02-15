#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define SIZE 1000
#define MAX 200000
#define EPS 1e-9

#define PII pair <int, int>
#define PLL pair <I64, I64>
#define PDD pair <double, double>
#define PSI pair <string, int>
#define PIS pair <int, string>
#define PSS pair <string string>

#define MII map <int, int>
#define MLL map <I64, I64>
#define MDD map <double, double>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string string>

#define VI vector <int>
#define VS vector <string>
#define QI queue <int>
#define QS queue <string>
#define SI stack <int>
#define SS stack <string>

#define pb push_back
#define pob pop_back
#define mp make_pair

#define IT iterator
#define ff first
#define ss second

#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define IAMHERE cout << "YES\n";
#define DEBUG(a, b) cout << a << ": " << b << "\n";

int arr[MAX+7];
I64 segment_tree[ 3*(MAX+7) ];

void build (int root, int st, int ed)
{
    if (st == ed) {
        segment_tree[root] = arr[st];
        return;
    }

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    build (left, st, mid);
    build (right, mid+1, ed);

    segment_tree[root] = segment_tree[left] + segment_tree[right];
    return;
}

void update (int root, int st, int ed, int idx, int val)
{
    if (idx < st || idx > ed) return;
    if (idx == st && idx == ed){
        segment_tree[root] = val;
        return;
    }

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    update (left, st, mid, idx, val);
    update (right, mid+1, ed, idx, val);

    segment_tree[root] = segment_tree[left] + segment_tree[right];
    return;
}

I64 query (int root, int st, int ed, int l, int r)
{
    if (l > ed || r < st) return 0;
    if (l <= st && ed <= r) return segment_tree[root];

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    I64 leftChild = query (left, st, mid, l, r);
    I64 rightChild = query (right, mid+1, ed, l, r);

    return leftChild + rightChild;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];

    while (scanf("%d", &n)==1 && n) {

        for (int i=1; i<=n; i++) {
            scanf("%d", &arr[i]);
        }

        build (1, 1, n);

        char type;
        bool Query = true;

        if (Case > 1) printf("\n");
        printf("Case %d:\n", Case++);

        while (Query) {
            type = getchar();
            if (type == 'S') {
                int idx, value;
                scanf("%d %d", &idx, &value);
                update (1, 1, n, idx, value);
                gets(dump);
            }
            else if (type == 'M') {
                int l, r;
                scanf("%d %d", &l, &r);
                gets(dump);
                printf("%lld\n", query(1, 1, n, l, r) );
            }
            else if (type == 'E') {
                gets(dump);
                Query = false;
            }
        }
    }
    return 0;
}

