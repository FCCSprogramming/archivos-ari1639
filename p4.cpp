#include <iostream>
#include <cstring>
using namespace std;
struct Polinomio1
{
    string poli1;
};
int coeficiente(string monomio)
{
    int tamaño = monomio.size();
    string numstr = "";
    for (int i = 0; i < tamaño; i++)
    {
        numstr = numstr + monomio[i];
        if (monomio[i + 1] == 'x')
        {
            break;
        }
    }
    return stoi(numstr);
}
string producto(Polinomio1 p1)
{
    // buscamos identificar los coeficientes y las potencias de x
    // suponemos que se escriben de forma decreciente y ordenado
    int ct = 1;
    int t = p1.poli1.size();
    for (int i = 0; i < t; i++)
    {
        // buscamos cuandos terminos existen
        if (p1.poli1[i] == '+')
        {
            ct++;
        }
    }
    // creamos un arreglo dinamico
    int *coeficientes = new int[ct];
    // llenamos el arreglo con los coeficientes asignadoles la posicion de las potencias de x....
    // 0     1       2       3       4       5       6       potencias
    // 0     3       0       1       3       10      23      coeifcientes
    int j = 0;
    int k = 0;
    for (int i = 0; i < ct; i++)
    {
        string monomio = "";
        // identificar terminos
        while (p1.poli1[j] != '+' && j != t)
        {
            monomio = monomio + p1.poli1[j];
            j++;
        }
        j++;
        // llenamos el arreglo dinamico con el valor
        if (monomio != "")
        {
            coeficientes[ct - k - 1] = coeficiente(monomio);
            k++;
        }
    }
    for (int i = 0; i < ct; i++)
    {
        cout << coeficientes[i] << " ";
    }
    delete[] coeficientes;
    coeficientes = nullptr;
    return "hola";
}
int main()
{
    Polinomio1 p;
    cout << "Ingrese el polinomio de manera completa y decreciente (1x^2+0x+3): " << endl;
    cin >> p.poli1;
    producto(p);
    return 0;
}