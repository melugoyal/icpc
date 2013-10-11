#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> cards;
    for (int i = 0; i < num; i++)
    {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    while(1)
    {
        bool can_remove = 0;
        for (int i = 0; i<cards.size()-1; i++)
        {
            for (int a = 0; a < cards.size(); a++)
                cout << cards[a] << " ";
            cout << endl;
            if ((cards[i] + cards[i+1]) % 2 == 0)
            {
                cards.erase(cards.begin()+i);
                cards.erase(cards.begin()+i);
                can_remove=1;
            }
        }
        if ((!(can_remove)) || cards.size() == 0)
            break;
    }
    cout << cards.size() << endl;
}
