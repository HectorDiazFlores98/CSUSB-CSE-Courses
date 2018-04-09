#include <iostream>
#include <random>
using namespace std;

int main()
{
    default_random_engine prng(random_device{}());
    uniform_int_distribution<char> dist('a','z');
    string password;
    string guess;

    for (int i = 0; i < 3; ++i) password += dist(prng);
    while (true) {
        cout << "Guess 3-letter password: ";
        cin >> guess;
        cout << "You guessed: " << guess << endl;
        if (guess == password) {
            cout << "Access granted." << endl;
            break;
        } else {
            cout << "Access denied." << endl;
        }
    }
    return 0;
}