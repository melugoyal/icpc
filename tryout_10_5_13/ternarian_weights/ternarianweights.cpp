#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

bool power_of_three(int);
int closest_pow_of_three(int);
int vector_sum(vector<int> &);
void vec_reverse(vector<int> &);

void vec_reverse(vector<int> & vec)
{
	for (int i = 0; i < vec.size()/2; i++)
	{
		int temp = vec[i];
		vec[i] = vec[vec.size()-i-1];
		vec[vec.size()-i-1] = temp;
	}
}

bool power_of_three(int a)
{
    for (double i = a; i > 0; i=i/3)
        if (i==1)
            return true;
}

int closest_pow_of_three(int a)
{
    int closest1 = 0, closest2= 0;
    for (int i = a; i > 0; i--)
    {
        if (power_of_three(i))
        {
            closest1 = i;
            break;
        }
    }
    for (int i = a; ; i++)
    {
        if (power_of_three(i))
        {
            closest2=i;
            break;
        }
    }
    return ((closest2-a)<=(a-closest1))?closest2:closest1;
}

int vector_sum(vector<int> & vec)
{
    int sum=0;
    for (int i = 0; i < vec.size(); i++)
        sum+=vec[i];
    return sum;
}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int weight;
        cin >> weight;
        vector<int> left_pan;
        vector<int> right_pan;
        while (1)
        {
            while (vector_sum(right_pan)-vector_sum(left_pan) < weight)
                right_pan.push_back(closest_pow_of_three(weight-(vector_sum(right_pan)-vector_sum(left_pan))));
            while (vector_sum(right_pan)-vector_sum(left_pan) > weight)
                left_pan.push_back(closest_pow_of_three(vector_sum(right_pan)-vector_sum(left_pan)-weight));
            if (vector_sum(right_pan)-vector_sum(left_pan) == weight)
                break;
        }
        cout << "left pan:";
        for (int a = 0; a < left_pan.size(); a++)
            cout << " " << left_pan[a];
        cout << endl;
        cout << "right pan:";
        for (int a = 0; a < right_pan.size(); a++)
            cout << " " << right_pan[a];
        cout << endl;
        if (i<tests-1)
            cout << endl;
    }
}
