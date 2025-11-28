#include <iostream>
#include <cstring>
using namespace std;
struct Polinomio
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
int *escoef(Polinomio p1, int &grado)
{
    // buscamos identificar los coeficientes y las potencias de x
    // suponemos que se escriben de forma decreciente y completo
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
    grado = ct - 1;
    // creamos un arreglo dinamico
    int *coeficientes = new int[ct];
    // llenamos el arreglo con los coeficientes asignadoles la posicion de las potencias de x....
    // 0     1       2       3       4       5       6       potencias
    // 2     3       0       1       3       10      23      coeifcientes
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
    return coeficientes;
}
void producto(Polinomio p1, Polinomio p2)
{
    // calculamos el arreglo de coeficiente sy potencias de cada polinomio
    int grado1 = 0;
    int grado2 = 0;
    int *px1 = escoef(p1, grado1);
    int *px2 = escoef(p2, grado2);
    // calculamos sus respectivos GRADOS de cada polinomio
    // la cantidad de terminos del numero polinomio es la suma de grados +1
    int ctp3 = grado1 + grado2 + 1;
    int *px3 = new int[ctp3];
    for (int i = 0; i < ctp3; i++)
    {
        px3[i] = 0;
    }
    // fijamos un eleento de p1 y lo mulplicamos por cada elemento de p2
    // obseramos que segun el indice se le asigna la "potencia" de x
    for (int i = 0; i < grado1 + 1; i++)
    {
        for (int j = 0; j < grado2 + 1; j++)
        {
            px3[i + j] = px3[i + j] + (px1[i] * px2[j]);
        }
    }
    cout << "Producto de polinomios: " << endl;
    for (int i = 0; i < ctp3; i++)
    {
        if (i != ctp3 - 1)
        {
            cout << px3[ctp3 - (i + 1)] << "x^" << ctp3 - (i + 1) << "+";
        }
        else
        {
            cout << px3[ctp3 - (i + 1)] << "x^" << ctp3 - (i + 1);
        }
    }
    // liberamos memoria
    delete[] px1;
    delete[] px2;
    delete[] px3;
    px1 = nullptr;
    px2 = nullptr;
    px3 = nullptr;
}
int main()
{
    Polinomio p1, p2;
    cout << "Ingrese el primer polinomio de manera completa y decreciente (1x^2+0x^1+3x^0): " << endl;
    cin >> p1.poli1;
    cout << "Ingrese el segundo polinomio de manera completa y decreciente (1x^2+0x^1+3x^0): " << endl;
    cin >> p2.poli1;
    producto(p1, p2);
    return 0;
}