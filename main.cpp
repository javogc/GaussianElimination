#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void intercambioRenglon(vector<vector<double>> &dMatriz, int iRen1, int iRen2)
{
    for(int i = 0; i < dMatriz[iRen1].size(); i++)
    {
        double dNumTemp = dMatriz[iRen1][i];
        dMatriz[iRen1][i] = dMatriz[iRen2][i];
        dMatriz[iRen2][i] = dNumTemp;
    }
}

int main()
{
    int iEcuaciones;
    int iVariables;
		bool bNumeroCorrecto = false;

		// Pide el numero de ecuaciones y de incognitas, valida que sean iguales.
		while(!bNumeroCorrecto)
		{
			cout << "Cuantas ecuaciones tiene el sistema? ";
	    cin >> iEcuaciones;
	    cout << "Cuantas incognitas tiene el sistema? ";
	    cin >> iVariables;

			if(iEcuaciones == iVariables)
				bNumeroCorrecto = true;
			else
			{
				cout << "Por favor ingrese otra vez, numero de ecuaciones tiene que " << endl;
				cout << "ser igual al numero de incógnitas" << endl;
			}
		}

    // vector de vectores de enteros para guardar los datos
    vector<vector<double>> dMatriz(iEcuaciones, vector<double>(iVariables + 1));

    for(int i = 0; i < iEcuaciones; i++)
    {
        for(int j = 0; j <= iVariables; j++)
        {
            double dNumero;

            if(j < iVariables)
                cout << "Cual es el coeficiente de X" << j + 1 << "? ";
            else
                cout << "Cual es el resultado de la ecuacion " << i + 1 << "? ";

            cin >> dNumero;

            dMatriz[i][j] = dNumero;
        }
    }

    intercambioRenglon(dMatriz, 0, 1);

    for(int i = 0; i < iEcuaciones; i++)
    {
        for(int j = 0; j <= iVariables; j++)
        {
            cout << setw(3) << dMatriz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
