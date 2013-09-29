#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    while (1)
    {
        int m, n, s;
        cin >> m;
        cin >> n;
        cin >> s;
        if (m==0 && n==0 && s==0)
            break;
        int x[s];
        int y[s];
        for (int i = 0; i < s; i++)
            cin >> x[i] >> y[i];
        int max_x[s];
        int max_y[s];
        int max_d[s];
        for (int i = 0; i < s; i++)
        {
            max_x[i] = max(abs(x[i] - n), abs(x[i]));
            max_y[i] = max(abs(y[i] - m), abs(y[i]));
            max_d[i] = max(max_x, max_y);
        }

    }
}
