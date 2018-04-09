#include <iostream>

using namespace std;

int main()
{
    string passwordAttempt = "";
    
    for(char firstLetter = 'a'; firstLetter <= 'z'; firstLetter++)
    {
        for(char secondLetter = 'a'; secondLetter <='z'; secondLetter++)
        {
            for(char thirdLetter = 'a'; thirdLetter <='z'; thirdLetter++)
            {
                passwordAttempt.push_back(firstLetter);
                passwordAttempt.push_back(secondLetter);
                passwordAttempt.push_back(thirdLetter);
                
                cout << passwordAttempt << endl;
                passwordAttempt.clear();
            }
        }
    }
}