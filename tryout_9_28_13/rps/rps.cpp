#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int main()
{
    int beat[2];  //0 R, 1 P, 2 S
    beat[0] = 1;
    beat[1] = 2;
    beat[2] = 0;
    unsigned long long input;
    unsigned long long num;
    cin >> input;
    map<unsigned long long, char> remember;
    char rps[3];
    rps[0]='R';
    rps[1]='P';
    rps[2]='S';
    bool skip_calc = 0;
    while (input!=0)
    {
        if (!(skip_calc))           //skip calculating input if it's a repeat
        {
            num = input/3;
            int game = input%3;
            int num_times = num%3;
            for (int i = 0; i < num_times; i++)
                game = beat[game];
            cout << rps[game] << endl;
            remember[input] = rps[game];
        }
        else
            cout << remember[input] << endl;
        cin >> input;
        skip_calc=0;
        if (remember.count(input) != 0)
            skip_calc = 1;
    }
}
