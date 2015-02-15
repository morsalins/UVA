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
#define MAX 100000
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

class info{
public:
    int occurance, lower, upper;
};

int freq[MAX+7], arr[MAX+7];
int segment_tree[ 3*(MAX+7) ];

void build (int root, int st, int ed) {
    if( st == ed ) {
        segment_tree[root] = freq[st];
        return;
    }

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    build (left, st, mid);
    build (right, mid+1, ed);
    segment_tree[root] = max(segment_tree[left], segment_tree[right]);
    return;
}

int getMax (int root, int st, int ed, int l, int r) {

    if (l>ed || r<st) return -1;
    if (l<=st && ed<=r) return segment_tree[root];

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    int leftChild = getMax (left, st, mid, l, r);
    int rightChild = getMax (right, mid+1, ed, l, r);

    return max (leftChild, rightChild);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n, query, num;

    while (scanf("%d", &n) == 1 && n) {

        scanf("%d", &query);
        map <int, info> mp;

        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            arr[i] = num;
            if (mp[num].occurance){
                mp[num].occurance++;
                mp[num].upper = i;
            }
            else{
                mp[num].occurance++;
                mp[num].lower = i;
                mp[num].upper = i;
             }
        }

        int idx = 0;

        for (map<int, info> :: iterator it = mp.begin(); it!=mp.end(); it++){
            int loop = it->ss.occurance;
            for (int j=1; j<=loop; j++){
                freq[++idx] = loop;
            }
        }

        build(1, 1, n);
        int ans = -10;

        for (int q=1; q<=query; q++) {
            int l, r;
            scanf("%d %d", &l, &r);
            int leftPart = mp[ arr[l] ].upper;
            int rightPart = mp[ arr[r] ].lower;

            if (rightPart < leftPart) {
                ans = r - l + 1;
            }
            else {
                ans = max( max(leftPart-l+1, r-rightPart+1), getMax(1, 1, n, leftPart+1, rightPart-1) );
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

