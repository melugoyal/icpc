#include <iostream>
#include <sstream>
#include <cmath>
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
        string initial, final;
        cin >> initial;
        cin >> final;
        int a_init = 0, a_final = 0, b_init = 0, b_final = 0;
        for (int a = 0; a < initial.length(); a++)
        {
            if (initial[a] == 'A')
                a_init++;
            if (initial[a] == 'B')
                b_init++;
            if (final[a] == 'A')
                a_final++;
            if (final[a] == 'B')
                b_final++;
        }
        string init_copy = initial;
        map<int, char> transitions;
        for (int a = 1; a < initial.length(); a++)
        {
            if (final[a-1]!=final[a])
                transitions.insert(pair<int, char>(a, final[a]));
        }
    }
}
