#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main()
{
    string s;
    while (1)
    {
        cin >> s;
        if (s=="0")
            break;
        long[s.length+1] dp;
        dp[0]=1;
        for (int i = 1; i < dp.length(); i++)
        {
            for (int j = 1; j<=3; j++)
            {
                if (i>=j)
                {
                    if (s[i-j] != '0' && 
                }
            }
        }
    }

}
