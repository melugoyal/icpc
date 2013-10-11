#include <iostream>
#include <vector>
using namespace std;
bool prime[32000];

bool is_prime(int);
int next_prime(int);

bool is_prime(int a)
{
    if (!(prime[a]))
        return false;
    for (int i = 3; i < a; i++)
        if (a%i==0)
        {
            prime[a] = false;
            return false;
        }
    return true;
}

int next_prime(int a)
{
    if (prime[a])
        return a;
    int retval=0;
    for (int i = a; i < a*2; i++ )
    {
        bool found = 1;
        if (prime[a])
            return a;
        for (int b = 2; b < i; b++)
        {
            if (i%b==0)
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            prime[i]=1;
            retval=i;
        }
    }
    return retval;
}

int main()
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;
    prime[3] = true;
    for (int i = 4; i < 400000; i++)
        prime[i] = false;
    int tests, num, count, b;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> num;
        count = 0;
        vector<int> first_add;
        for (int a = 2; a < num/2+1; a++)
        {
            a = next_prime(a);
//            if (!(is_prime(a)))
//                continue;
            b = num-a;
            if (next_prime(b)!=b)
                continue;
//            if (!(is_prime(b)))
//                continue;
            count++;
            first_add.push_back(a);
            first_add.push_back(b);
        }
        cout << num << " has " << count << " representation(s)" << endl;
        for (int a = 0; a < first_add.size(); a+=2)
            cout << first_add[a] << "+" << first_add[a+1] << endl;
        if (i < tests-1)
            cout << endl;
    }
}
