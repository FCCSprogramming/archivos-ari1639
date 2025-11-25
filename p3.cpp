#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file("serie.txt", ios::app);
    if (file.is_open())
    {
        int a = 0;
        int b = 1;
        int t = 0;
        for (int i = 0; i < 20; i++)
        {
            t = a + b;
            a = b;
            b = t;
            file << "termino :" << a << endl;
        }
        file.close();
    }
    else
    {
        cout << "Err";
    }
    return 0;
}