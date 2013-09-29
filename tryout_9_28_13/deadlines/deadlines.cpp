#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n==0)
            break;
        int x[n];
        int t[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        int max_t = 0;
        int total_x = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i] > max_t)
                max_t = t[i];
            total_x+=x[i];
        }
        int i = max_t-total_x;
        bool bad_time = 1;
        for (; i>=0; i--)
        {
            bad_time=0;
            for (int a = 0; a < n; a++)
            {
                if (i+x[a]>t[a])
                {
                    bad_time = 1;
                    break;
                }
                if (bad_time)
                    break;
            }
            if (bad_time)
                continue;
            int max_t_sub = 0;
            int sum_x_sub = 0;
            for (int k = 1; k < n; k++)
            {
                for (int m = 0; m < k; m++)
                {
                    if (t[m] > max_t_sub)
                        max_t_sub = t[m];
                    sum_x_sub+=x[m];
                }
                if (i+sum_x_sub > max_t_sub)
                {
                    bad_time = 1;
                    break;
                }
                if (bad_time)
                    break;
                max_t_sub=0;
                sum_x_sub=0;
                for (int m = k; m >=0; m--)
                {
                    if (t[m] > max_t_sub)
                        max_t_sub = t[m];
                    sum_x_sub+=x[m];
                }
                if (i+sum_x_sub > max_t_sub)
                {
                    bad_time = 1;
                    break;
                }
                if (bad_time)
                    break;
            }
            if (!(bad_time))
                break;
        }
        if (i<0)
        {
            cout << "impossible" << endl;
            continue;
        }
        else 
            cout << i << endl;
    }
}
