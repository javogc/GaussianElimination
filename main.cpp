#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int iEcuaciones;
    int iVariables;

    cout << "Cuantas ecuaciones tiene el sistema? ";
    cin >> iEcuaciones;
    cout << "Cuantas incognitas tiene el sistema? ";
    cin >> iVariables;

    // vector de vectores de enteros para guardar los datos
    vector<vector<int>> iMatriz(iEcuaciones, vector<int>(iVariables + 1));

    for(int i = 0; i < iEcuaciones; i++)
    {
        for(int j = 0; j <= iVariables; j++)
        {
            int iNumero;

            if(j < iVariables)
                cout << "Cual es el coeficiente de X" << j + 1 << "? ";
            else
                cout << "Cual es el resultado de la ecuacion " << i + 1 << "? ";

            cin >> iNumero;

            iMatriz[i][j] = iNumero;
        }
    }

    for(int i = 0; i < iEcuaciones; i++)
    {
        for(int j = 0; j <= iVariables; j++)
        {
            cout << setw(3) << iMatriz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
