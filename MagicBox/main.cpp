#include <iostream>

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
