#include <iostream>
#include <random>
#include <ctime>
using namespace std;
struct tfecha
{
    int dia, mes;
};
struct tcarga
{
    int numpasajeros;
    tfecha fecha;
};
int aleatorio()
{
    return 500 + rand() % 201;
}
void llenar()
{
    int nbus = 0;
    tcarga *bus = new tcarga[360];
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            int num = aleatorio();
            nbus = (i - 1) * 30 + (j - 1);
            bus[nbus].numpasajeros = num;
            bus[nbus].fecha.dia = j;
            bus[nbus].fecha.mes = i;
        }
    }
    // mostrmaos los registros con buses con pasajeros al 95% de capacidad;
    int j = 0;
    for (int i = 0; i < 360; i++)
    {
        if (bus[i].numpasajeros >= 0.95 * 700)
        {
            j++;
            cout << bus[i].fecha.dia << "/" << bus[i].fecha.mes << " :" << bus[i].numpasajeros << " pasajeros" << endl;
        }
    }
    cout << "Numero de dias: " << j;
    delete[] bus;
    bus = nullptr;
}
int main()
{
    srand(time(0));
    llenar();
    return 0;
}