#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t t = time(0);
    int seconds = localtime(&t) -> tm_sec;
    int minutes = localtime(&t) -> tm_min;
    int hours = localtime(&t) -> tm_hour;
    int day = localtime(&t) -> tm_mday;
    int month = localtime(&t) -> tm_mon + 1;
    int year = localtime(&t) -> tm_year + 1900;
    cout << "seconds: "<< seconds << "\n";
    cout << "minutes: " << minutes << "\n";
    cout << "hours: " << hours << "\n";
    cout << "day: " << day << "\n";
    cout << "month: " << month << "\n";
    cout << "year: " << year << "\n";
}