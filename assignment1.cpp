#include <iostream>
using namespace std;

int main() {

	int numGames;
	int game[numGames];

    while(true)
    {
        if(!(cin >> numGames))
        {
            cout << "bad input\n";
            continue;
        }
        break;
    }

	for(int i = 0; i < numGames; i++)
	{
	
        while(true)
        {
            if(!(cin >> game[i]))
            {
                cout << "bad input\n";
                continue;
            }
            break;
        }

	}


	return 0;
}
