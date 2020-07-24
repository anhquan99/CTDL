#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    int counter = 60; //amount of seconds
    Sleep(1000);
    while (counter >= 1)
    {
        cout << "\rTime remaining: " << counter << flush;
        Sleep(1000);
        counter--;
    }
}
