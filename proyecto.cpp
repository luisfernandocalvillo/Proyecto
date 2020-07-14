#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

const int longCad = 20;
struct CostoPorArticulo
{
  char nombreArticul[longCad + 1];
  int cantidad;
  float precio;
  float costoPorArticulo;
};

void leerDatos(int cantidad, string articulos[][4])
{
    string nombre,cant, precio;
    for(int i =0;i<cantidad;i++)
    {
        cout << endl << "Articulo #"<<i+1 << endl;
        for(int e =0;e<3;e++)
        {
            if(e==0)
            {
                cout << "Nombre: ";
                cin >> nombre;
                articulos[i][e] = nombre;
            }
            if(e==1)
            {
                cout << "Cantidad: ";
                cin >> cant;
                articulos[i][e] = cant;
            }
            if(e==2)
            {
                cout << "Precio: $";
                cin >> precio;
                articulos[i][e] = precio;
            }
        }
    }
}

void TotalCompra(int cantidad,string articulos[][4])
{
    
    for(int i =0;i<cantidad;i++)
    {
        articulos[i][3] = to_string(stof(articulos[i][2])*stof(articulos[i][1]));
    }
}


void desplegarCompra(int cantidad,string articulos[][4])
{
    for(int i =0;i<cantidad;i++)
    {
        cout << "Articulo #"<<i+1 <<endl;
        cout << "Nombre: " << articulos[i][0] <<endl;
        cout << "Cantidad: " << articulos[i][1] <<endl;
        cout << "Precio Unitario: " << articulos[i][2] <<endl;
        cout << "Precio total: " <<articulos[i][3]<<endl;
        
    }
}

void mostrarCompra(int cantidad,string articulos[][4])
{
    cout<<"Nombre   |   Cantidad   |   Precio Unitario   |   Total"<<endl;
    for(int i =0;i<cantidad;i++)
    {
        for(int e =0;e<4;e++)
        {
            cout << articulos[i][e]<<"   | ";
        }cout << endl <<endl;
        
    }
}

float costoTotalCompra(int cantidad,string articulos[][4] )
{
    float tot = 0.0;
    for(int i =0;i<cantidad;i++)
    {
        tot+=stof(articulos[i][3]);
    }
    
    return tot;
}

int main()
{
    int cantidad;
    float costo_total;
    cout << endl << "Ingrese cantidad de articulos que va llevar: ";
    cin >> cantidad;
    
    string articulos [cantidad][4];
    
    leerDatos(cantidad, articulos);
    TotalCompra(cantidad,articulos);
    mostrarCompra(cantidad,articulos);
    
    costo_total = costoTotalCompra(cantidad,articulos);
    
    cout << "Total de la compra fue de: $"<< costo_total << endl << endl;
}