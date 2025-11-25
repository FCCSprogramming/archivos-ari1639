#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream laguna("laguna.txt");
    if (laguna.is_open())
    {
        int nt = 0;
        int nv = 0;
        laguna >> nt;
        laguna >> nv;
        // matriz para los vertices
        int **vtriangulos = new int *[nt];
        for (int i = 0; i < nt; i++)
        {
            vtriangulos[i] = new int[2];
        }
        // matriz para las coordenadas
        double **coordtriangulos = new double *[nv];
        for (int i = 0; i < nv; i++)
        {
            coordtriangulos[i] = new double[nv];
        }
        // leemos cada "matriz" en el archivo
        // coordenadas
        int j = 0;
        while (j < nv)
        {
            laguna >> coordtriangulos[j][0] >> coordtriangulos[j][1];
            j++;
        }
        // vertices
        j = 0;
        while (j < nt)
        {
            laguna >> vtriangulos[j][0] >> vtriangulos[j][1] >> vtriangulos[j][2];
            j++;
        }
        // calculo del area
        double area = 0;
        for (int i = 0; i < nt; i++)
        {
            double x1 = coordtriangulos[vtriangulos[i][0] - 1][0];
            double y1 = coordtriangulos[vtriangulos[i][0] - 1][1];

            double x2 = coordtriangulos[vtriangulos[i][1] - 1][0];
            double y2 = coordtriangulos[vtriangulos[i][1] - 1][1];

            double x3 = coordtriangulos[vtriangulos[i][2] - 1][0];
            double y3 = coordtriangulos[vtriangulos[i][2] - 1][1];

            area += abs((x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1)) / 2);
            cout << "area " << area << endl;
        }

        ofstream file("area.txt");
        if (file.is_open())
        {
            file << area;
        }
        else
        {
            cout << "Error";
        }
        // liberamos memoria
        for (int i = 0; i < nt; i++)
        {
            delete[] vtriangulos[i];
        }
        delete[] vtriangulos;
        vtriangulos = nullptr;
        for (int i = 0; i < nv; i++)
        {
            delete[] coordtriangulos[i];
        }
        delete[] coordtriangulos;
        coordtriangulos = nullptr;
    }
    else
    {
        cout << "Err";
    }
    return 0;
}