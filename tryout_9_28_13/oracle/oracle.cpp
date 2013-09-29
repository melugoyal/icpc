#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main()
{
    char inputline[1000];
    cin.getline(inputline, 1000);
    string input(inputline);
    vector<int> question_marks;
    vector<int> periods;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i]=='?')
            question_marks.push_back(i);
        if (input[i]=='.')
            periods.push_back(i);
    }
    for (int i = 0; i < question_marks.size(); i++)
    {
        int prev_index = -1;
        string question;
        for (int j = 0; j < question_marks.size(); j++)
            if (question_marks[j] < question_marks[i])
                prev_index = question_marks[j];
         for (int j = 0; j < periods.size(); j++)
            if (periods[j] < question_marks[i] && periods[j] > prev_index)
                prev_index = periods[j];
         question = input.substr(prev_index+7, question_marks[i]-prev_index-7);
         cout << "Forty-two " << question << "." << endl;
   }

}
