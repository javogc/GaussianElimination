// Eliminacion Gaussian
//
// Alejandro de la Rosa Cortes A01381412
// Oscar Armando Leal Marcos   A00816227
// Javier Guajardo Canseco
//
// Métodos Numéricos
// 8 de octubre 2015

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void intercambioRenglon(vector<vector<double>> &dMatriz, int iRen1, int iRen2)
{
    // Dato temporal que va a guardar el dato del iRen1 para pasarselo al iRen2
    double dNumTemp;

    // Cambia los datos del renglon iRen1 por los del iRen2 y viceversa
    for(int i = 0; i < dMatriz[iRen1].size(); i++)
    {
        dNumTemp = dMatriz[iRen1][i];
        dMatriz[iRen1][i] = dMatriz[iRen2][i];
        dMatriz[iRen2][i] = dNumTemp;
    }
}

//va haciendo ceros el triangulo inferior, recalculando las ecuaciones
void trianguloInferior(vector<vector<double>> &dMatriz)
{
    for(int i = 0; i < dMatriz.size() - 1; i++)
    {
        for(int j = i + 1; j < dMatriz.size(); j++)
        {
            int iIndex = j;
            //intercambia renglón si es necesario (para no dividir entre 0)
            while(i < dMatriz.size() && dMatriz[i][i] == 0)
            {
                intercambioRenglon(dMatriz, i, iIndex);
                iIndex++;
            }
            if(dMatriz[i][i] != 0)
            {
                double dX = dMatriz[j][i] / dMatriz[i][i];

                if(dX != 0)
                {
                    for(int k = i; k < dMatriz[i].size(); k++)
                    {
                        dMatriz[j][k] -= dMatriz[i][k] * dX;
                    }
                }
            }
        }
    }
}

void solucion(vector<vector<double>> const &dMatriz, int iEcuaciones, int iVariables)
{
    //Checa si se trata de un sistema con soluciones infinitas, o tiene soluciones imaginarias
    if (dMatriz[iEcuaciones - 1][iVariables - 1] == 0)
    {
        if(dMatriz[iEcuaciones - 1][iVariables] == 0)
            cout << "El sistema tiene infinitas soluciones" << endl;
        else
            cout << "El sistema no tiene soluciones reales" << endl;
    }
    else
    {
        //Calcula soluciones del sistema
        double arrDSoluciones[iVariables];

        cout << "Soluciones del sistema: " << endl;

        for(int i = iEcuaciones - 1; i >= 0; i--)
        {
            if(i == iEcuaciones - 1)
            {
                arrDSoluciones[i] = dMatriz[i][iVariables] / dMatriz[i][i];
            }
            else
            {
                double iSuma = 0;
                for(int j = i + 1; j < iVariables; j++)
                {
                    iSuma += dMatriz[i][j] * arrDSoluciones[j];
                }
                arrDSoluciones[i]=(dMatriz[i][iVariables] - iSuma)/dMatriz[i][i];
            }
        }

        for(int i = 0; i < iVariables; i++)
        {
            cout << arrDSoluciones[i] << endl;
        }
    }
}

int main()
{
    int iEcuaciones, iVariables;
    char cRespuesta;

    do
    {
        // Pide el numero de ecuaciones y de incognitas, que es el mismo.
        cout << "Ingresa el numero de ecuaciones e incognitas que tendra el sistema\n(tiene que ser el mismo) ";
        cin >> iEcuaciones;

        iVariables = iEcuaciones;

        // vector de vectores de enteros para guardar los datos
        vector<vector<double>> dMatriz(iEcuaciones, vector<double>(iVariables + 1));


        // Pide los coeficientes de las variables de cada una de las ecuaciones y el resultado
        //      de cada una de ellas mismas.
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

                //Llena la matriz de sistema de ecuaciones
                dMatriz[i][j] = dNumero;
            }
        }

        trianguloInferior(dMatriz);
        solucion(dMatriz, iEcuaciones, iVariables);

        cout << "Quieres resolver otro sistema? y/n ";
        cin >> cRespuesta;
    }
    while (cRespuesta == 'y' || cRespuesta == 'Y');

    return 0;
}
