#include <iostream>
#include <cmath>
using namespace std;
// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};


double calcularDistancia(const Point &p1,const Point &p2)
{
    // Completar: Usar la fórmula de distancia euclidiana
    // sugerencia: puede hacer uso de funcionines como sqrt y pow
    double distancia;
    distancia=sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2));
    return distancia;
}


// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int &n) //Puntos es un array
{
    char respuesta;
    cout << "¿Desea ingresar los puntos manualmente? (s/n): "<<endl;
    char *respusuario = new char(n);
    cin>>respusuario;
    // Leer la respuesta del usuario

    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respusuario == "s" || respusuario == "S") // Si no es s o S se toma como que el usuario no quiere ingresar los puntos
    {
        // Completar: Leer las coordenadas de cada punto
        for (int i=0;i<n;i++){
            cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): "<<endl;
            cin >> puntos[i].x>>puntos[i].y;
        }
    }
    else
    {
        // Usar puntos predeterminados
        cout << "Usando puntos predeterminados...\n";
        switch (n){
            case 2:
            puntos[0] = {0, 0};  // Punto 1 (0, 0)
            puntos[1] = {3, 4};
            break;

            case 3:
            puntos[0] = {0, 0};  // Punto 1 (0, 0)
            puntos[1] = {3, 4};  // Punto 2 (3, 4)
            puntos[2] = {6, 8};  // Punto 3 (6, 8)
            break;
            
            case 4:
            puntos[0] = {0, 0};  // Punto 1 (0, 0)
            puntos[1] = {3, 4};  // Punto 2 (3, 4)
            puntos[2] = {6, 8};  // Punto 3 (6, 8)
            puntos[3] = {9, 12}; // Punto 4 (9, 12)
            break;
            
            default:
            puntos[0] = {0, 0};  // Punto 1 (0, 0)
            puntos[1] = {3, 4};  // Punto 2 (3, 4)
            puntos[2] = {6, 8};  // Punto 3 (6, 8)
            puntos[3] = {9, 12}; // Punto 4 (9, 12)
            for(int i=4; i<n; i++){
            puntos[i] = {9, 12};
        }

        }
        
        
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    double distanciaMinima=0;
    for(int i=0; i<n; i++){
        Point p1=puntos[i];
        Point p2=pUsuario;

        double distancia;
        distancia=(calcularDistancia(p1,p2));

        if(distanciaMinima==0){
            distanciaMinima=distancia;
            indiceMasCercano=i;
        }
        else if(distanciaMinima>distancia){
            distanciaMinima=distancia;
            indiceMasCercano=i;
        }
        // do
        // {
        //     distanciaMinima=distancia;
        //     indiceMasCercano=i;
        // } while (distancia>distanciaMinima);
        
    }

    return distanciaMinima;
}


// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    cout << "La distancia al punto más cercano es: " << distancia << endl;
}

int main()
{
    int n;

    while (true){
        cout << "Ingrese el número de puntos (mínimo 2): ";
        // Leer el número de puntos
        cin>> n;
        if (n<2)
        {
            cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        }
        else{
            break;
        }
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos,n);

    // Ingresar el punto del usuario
    Point pUsuario;
    cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    cin >> pUsuario.x>> pUsuario.y;

    int indiceMasCercano;
    double distanciaMinima;
    // Calcular la distancia más cercana
    distanciaMinima=calcularDistanciaMasCercana(puntos,n,pUsuario,indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distanciaMinima);

    return 0;
}

/*BONO:
Escribir una función que reciba un arreglo de puntos y devuelva la distancia total de los puntos que conforman el arreglo si estos fueran recorridos en orden.
*/