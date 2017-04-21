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
#define MP make_pair

#define IT iterator
#define ff first
#define ss second

#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define IAMHERE cout << "YES\n";
#define DEBUG(a, b) cout << a << ": " << b << "\n";

int arr[MAX+7];
int seg[ 3*(MAX+7) ];

void build (int root, int st, int ed) {
    if( st == ed ) {
        seg[root] = arr[st];
        return;
    }

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    build (left, st, mid);
    build (right, mid+1, ed);
    seg[root] = seg[left] * seg[right];
    return;
}

void update(int root, int st, int ed, int idx, int val)
{
	if (idx < st || idx > ed) return;
	if (idx == st && idx == ed) {
		seg[root] = val;
		return;
	}

	int left = root << 1;
	int right = left + 1;
	int mid = (st + ed) >> 1;

	update(left, st, mid, idx, val);
	update(right, mid+1, ed, idx, val);

	seg[root] = seg[left] * seg[right];
}


int querry (int root, int st, int ed, int l, int r) {

    if (l>ed || r<st) return 1;
    if (l<=st && ed<=r) return seg[root];

    int left = root << 1;
    int right = left + 1;
    int mid = (st+ed) >> 1;

    int leftChild = querry (left, st, mid, l, r);
    int rightChild = querry (right, mid+1, ed, l, r);

    return leftChild * rightChild;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n, q, m, k;

    while (scanf("%d %d", &n, &q) == 2) {
    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &k);
    		if (k != 0) k /= abs(k);
    		arr[i] = k;
    	}

    	build(1, 1, n);
    	char type;
    	int idx, val, l, r;
    	string ans;

    	for (int i = 1; i <= q; i++) {
    		cin >> type;

    		if (type == 'C') {
    			cin >> idx >> val;
    			if (val != 0) val /= abs(val);
    			update(1, 1, n, idx, val);
    		}
    		else {
    			cin >> l >> r;
    			int val = querry(1, 1, n, l, r);
    			if (val > 0) ans += '+';
    			else if (val < 0) ans += '-';
    			else ans += '0';
    		}
    	}

    	printf("%s\n", ans.c_str());
    }
    return 0;
}
