#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

long dp_fact(long);
long rec_fact(long);

int main()
{
    int tests = 0;
    cin >> tests;
    for (int a = 0; a < tests; a++)
    {
        long n = 0;
        long k = 0;
        cin >> n;
        cin >> k;
        long fact_n = rec_fact(n);
        long max_i = 0;
        for (long i = 1; i < 10; i++)
        {
            if (fmod(fact_n, pow((double)k, (double)i)) == 0 && (i > max_i))
                max_i = i;
        }
        cout << max_i << endl;
    }
}

long dp_fact(long a)
{
    long result[a];
    result[0]=1;
    for (int i = 1; i <= a; i++)
    {
        result[i] = i*result[i-1];
    }
    return result[a];
}

long rec_fact(long a)
{
    if (a==0)
        return 1;
    return a*rec_fact(a-1);
}
