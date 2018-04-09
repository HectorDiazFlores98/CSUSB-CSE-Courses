#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    for(int x = 0; x <= 100;x++)
    {
        cout << "\r" << x << "% completed.       " << flush;
        this_thread::sleep_for (std::chrono::seconds(1));
    }
}