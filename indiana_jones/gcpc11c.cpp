#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Triple
{
    public:
        int num;
        int previous;
        int next;
        
        Triple()
        {
            num = 0;
            previous = 0;
            next = 0;
        }
};

int main()
{
    int tests;
    cin >> tests;
    for (int  i = 0; i < tests; i++)
    {
        int switches;
        cin >> switches;
        int hints;
        cin >> hints;
        if (switches==1 && hints ==0)
        {
            cout << "1" << endl;
            continue;
        }
        if (hints+1<switches)
        {
            for (int j = 0; j < hints; j++)
            {
                int junk1, junk2;
                cin >> junk1;
                cin >> junk2;
            }
            cout << "missing hints" << endl;
            continue;
        }
        vector<Triple> array;
        bool out_of_range=0;
        for (int j = 0; j < hints; j++)
        {
            bool change_next = 1;
            bool change_prev = 1;
            int _num;
            cin >> _num;
            int _num2;
            cin >> _num2;
            if (_num > switches || _num2 > switches)
                out_of_range=1;
            for (int a = 0; a < array.size(); a++)
            {
                if (array[a].num==_num)
                {
                    if (array[a].next==0)
                        array[a].next=_num2;
                    change_next=0;
                }
                if (array[a].num==_num2)
                {
                    if (array[a].previous==0)
                        array[a].previous =_num;
                    change_prev=0;
                }
            }
            if (change_next)
            {
                Triple my_triple1;
                my_triple1.num = _num;
                my_triple1.next = _num2;
                array.push_back(my_triple1);
            }
            if (change_prev)
            {
                Triple my_triple2;
                my_triple2.num = _num2;
                my_triple2.previous = _num;
                array.push_back(my_triple2);
            }
        }
        vector<int> solutions;
        int prev = 0;
        for (int j = 0; j<hints*10000; j++)
        {
            if (array[j%(hints+1)].previous==prev)
            {
                solutions.push_back(array[j%(hints+1)].num);
                prev = array[j%(hints+1)].num;
            }
            if (solutions.size() == switches)
                break;
        }
        if (solutions.size() != switches || out_of_range)
            cout << "recheck hints" << endl;
        else
        {
            for (int j = 0; j < solutions.size()-1; j++)
                cout << solutions[j] << " ";
            cout << solutions[solutions.size()-1] << endl;
        }
    }
}
