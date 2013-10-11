#include <iostream>
#include <iomanip>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int r, n, d, m, s;
        cin >> r >> n >> d >> m >> s;
        double angle = d + m/60. + s/3600.;
        double each_slice = M_PI * (double)r * (double)r * angle / 360.;
        if ((double)r*(double)r*M_PI - each_slice*(double)n > each_slice)
            cout << setprecision(20) << (double)r*(double)r*M_PI << endl;
        else
            cout << setprecision(20) << each_slice << endl;
    }
}
