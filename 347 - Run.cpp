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
#define MAX 2000
#define EPS 1e-9
#define PI 2*acos(0.0)

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

int value[] = {13, 15, 17, 19, 31, 35, 37, 39, 51, 53, 57, 59, 71, 73, 75, 79, 91, 93, 95, 97, 147, 174, 258, 285, 417, 471, 528, 582, 714, 741, 825, 852, 1263, 1267, 1623, 1627, 2316, 2356, 2396, 2631, 2635, 2639, 2671, 2675, 2679, 2716, 2756, 2796, 3126, 3162, 3526, 3562, 3926, 3962, 5263, 5267, 5623, 5627, 6231, 6235, 6239, 6271, 6275, 6279, 6312, 6352, 6392, 6712, 6752, 6792, 7126, 7162, 7526, 7562, 7926, 7962, 9263, 9267, 9623, 9627, 12368, 12746, 12796, 12863, 13628, 13678, 13849, 13894, 16274, 16279, 16724, 16729, 17246, 17296, 17368, 17863, 18349, 18394, 18623, 18673, 23186, 23479, 23681, 23974, 24167, 24617, 24739, 24789, 27416, 27461, 27916, 27961, 28136, 28479, 28631, 28974, 29167, 29617, 29734, 29784, 31286, 31786, 31862, 31867, 34297, 34792, 34918, 34968, 36281, 36781, 36812, 36817, 38491, 38496, 38941, 38946, 39247, 39418, 39468, 39742, 41389, 41627, 41672, 41839, 42397, 42897, 42973, 42978, 46127, 46172, 46389, 46839, 47392, 47892, 47923, 47928, 49138, 49183, 49638, 49683, 61274, 61279, 61724, 61729, 62318, 62741, 62791, 62813, 63128, 63178, 63849, 63894, 67241, 67291, 67318, 67813, 68123, 68173, 68349, 68394, 72416, 72461, 72916, 72961, 73186, 73429, 73681, 73924, 74162, 74239, 74289, 74612, 78136, 78429, 78631, 78924, 79162, 79234, 79284, 79612, 81236, 81362, 81367, 81736, 83491, 83496, 83941, 83946, 84297, 84792, 84913, 84963, 86231, 86312, 86317, 86731, 89247, 89413, 89463, 89742, 91384, 91627, 91672, 91834, 92347, 92473, 92478, 92847, 94138, 94183, 94638, 94683, 96127, 96172, 96384, 96834, 97342, 97423, 97428, 97842, 134259, 134859, 142359, 142953, 148359, 148953, 194253, 194853, 235914, 235974, 253194, 253794, 259134, 259734, 295314, 295374, 314295, 314895, 319425, 319485, 342591, 342597, 348591, 348597, 359142, 359148, 359742, 359748, 374295, 374895, 379425, 379485, 423591, 423597, 425319, 425379, 425913, 425973, 429531, 429537, 483591, 483597, 485319, 485379, 485913, 485973, 489531, 489537, 531429, 531489, 531942, 531948, 537429, 537489, 537942, 537948, 591342, 591348, 591423, 591483, 597342, 597348, 597423, 597483, 734259, 734859, 742359, 742953, 748359, 748953, 794253, 794853, 835914, 835974, 853194, 853794, 859134, 859734, 895314, 895374, 913425, 913485, 914235, 914835, 942531, 942537, 948531, 948537, 953142, 953148, 953742, 953748, 973425, 973485, 974235, 974835, 1246895, 1248596, 1249568, 1258946, 1426958, 1496258, 1526894, 1596824, 1824956, 1842695, 1849625, 1894256, 1942568, 1946825, 1948526, 1958246, 2415968, 2461958, 2468951, 2485961, 2495618, 2495681, 2518496, 2519468, 2561894, 2568194, 2581496, 2589461, 2619485, 2689415, 2695184, 2695814, 4152689, 4159682, 4256189, 4256819, 4269518, 4269581, 4612589, 4619582, 4682519, 4689512, 4852619, 4859612, 4956182, 4956812, 4962518, 4962581, 5124689, 5184269, 5184962, 5194682, 5261948, 5268941, 5618249, 5618942, 5681249, 5681942, 5814269, 5814962, 5824619, 5894612, 5961248, 5968241, 6124859, 6125894, 6182495, 6189425, 6194852, 6195824, 6251849, 6258149, 6812495, 6819425, 6824159, 6825194, 6894152, 6895124, 6951842, 6958142, 8124956, 8142695, 8149625, 8194256, 8241596, 8246195, 8249561, 8251946, 8426951, 8496251, 8526194, 8596124, 8941526, 8942561, 8946125, 8951246, 9415268, 9425618, 9425681, 9461258, 9468251, 9485261, 9512468, 9518426, 9561824, 9568124, 9581426, 9582461, 9612485, 9625184, 9625814, 9682415};
//Call the Run function to Pre Calculate all the possible value between 2 ans 7 digits.
// store it in an output file and then copy all the value to array declaration ;) .

//vector <int> v;
//int divbyTen[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

//bool isRunaround(int num)
//{
//    int revnum = 0;
//    int n = num;
//    int occur = 0;
//    int counter = 0;
//
//    while (n > 0) {
//        if (occur & (1 << (n % 10))) return false;
//        occur |= 1 << (n % 10);
//        revnum = (revnum * 10) + (n % 10);
//        n /= 10;
//        counter++;
//    }
//
//    int idx = 0;
//    int mask = 0;
//
//    while (mask != (1 << counter) - 1) {
//        int nxt = (revnum / divbyTen[idx]) % 10;
//        idx = (idx + nxt) % counter;
//        if (mask & (1 << idx)) {
//            break;
//        }
//        else {
//            mask |= (1 << idx);
//        }
//    }
//    return mask == ((1 << counter) - 1);
//}
//
//void Run (void)
//{
//    int num = 10;
//
//    while (num < 10000000) {
//        if (isRunaround(num)) {
//            v.push_back(num);
//        }
//        num++;
//    }
//    return;
//}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, m, k;
    char dump[2];

//    Run(); // Call the Run function to Pre Calculate all the possible value between 2 ans 7 digits.
//    for (int i = 0; i < v.size(); i++) {
//        printf("%d, ", v[i]); // store it in an output file and then copy all the value to array declaration ;) .
//    }

    while (scanf("%d", &n) == 1 && n != 0) {
        printf("Case %d: %d\n", Case++, *lower_bound(value, value + 448, n));
    }
    return 0;
}

