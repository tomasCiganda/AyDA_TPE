#include <iostream>
#include <fstream>

using namespace std;

/**
 * Abre el archivo seg�n el origen, procesa las l�neas del mismo y
 * almacena la informaci�n resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen);//, Contenedor & contenedor);

int main()
{
    procesar_archivo_entrada("ranking_empresas.csv");
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_empresas = atoi(linea.c_str());
        cout << "Se cargar�n " << cantidad_empresas << " empresas." << endl;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posici�n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string razon_social = linea.substr(pos_inicial, pos_final);

            //Segunda posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string pais = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int empleados = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Cuarta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string rubro = linea.substr(pos_inicial, pos_final - pos_inicial);

            cout << razon_social << "-"<<pais<<"-"<<empleados<<"-"<<rubro<<endl;
        }
    }
}
