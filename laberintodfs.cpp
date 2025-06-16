#include <iostream>
#include <string> 
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector> 

using namespace std;

/// Para tamaño fijo 11x11
int filas = 11;
int columnas = 11;

// Vector de vectores (Mz)
vector<vector<char>> tablero;
vector<vector<bool>> visitados; 
vector<vector<bool>> visitadosResolver;


// Maneras en las que se va a mover (direcciones)

int dirFila[] = {-2,2,0,0};     // Arriba y Abajo
int dirColumna[] = {0,0,-2,2};  // Izquierda y Derecha


void inicializarTableroLleno(){
    // Funcion para iniciar el tablero con el espacio lleno de muros y las celdas no visitadas

    // vector.assign(cantidad, valor)
    // Asignar nuevos valores al vector, reemplazando lo anterior
    tablero.assign(filas, vector<char>(columnas, '#'));         // filas x vector con columnas elementos, todos con el carácter '#'
    visitados.assign(filas, vector<bool>(columnas, false));     // ninguna casilla ha sido visitada aún

}

void posicionarCaracter( int fila, int columna, char caracter){
    tablero[fila][columna] = caracter;
}

void abrirCaminoDFS(int x, int y){
    visitados[x][y] = true;     // Se marca la celda como visitada
    tablero[x][y] = '-';        // Se abre camino, ya no hay muro

    vector<int> direcciones = {0,1,2,3};        // vector con indices para las 2 direcciones posibles
    random_shuffle(direcciones.begin(), direcciones.end());     // mezcla aleatoria
    
    // Según las direcciones mezcladas
    for (int i = 0; i < 4; i++) {
        // Se calcula la proxima celda vecina
        int nx = x + dirFila[direcciones[i]];
        int ny = y + dirColumna[direcciones[i]];

        // Verificamos que esté 1. dentro del tablero. 2. no salga de los bordes. 3. diferente a visitado
        if (nx >= 0 && nx < filas && ny >= 0 && ny < columnas && !visitados[nx][ny]) {
            // Rompemos la pared intermedia (Entre x,y (la celda actual) y nx,ny (la nueva celda), hay un muro de por medio.)
            // Se calcula la coordenada del muro que está entre la celda actual y la nueva.
            int muroX = x + dirFila[direcciones[i]] / 2;
            int muroY = y + dirColumna[direcciones[i]] / 2;
            tablero[muroX][muroY] = '-';

            abrirCaminoDFS(nx, ny);     // Llama a sí misma recursivamente, y sigue explorando desde la nueva celda.
        }
    }
}

bool resolverDFS(int x, int y) {
    // Se crea un nuevo set de direcciones (Paso por paso)
    int dxf[] = {-1, 1, 0, 0}; // arriba, abajo, izquierda, derecha
    int dyf[] = {0, 0, -1, 1};

    if (tablero[x][y] == 'S') return true;      // Se encontró el camino

    visitadosResolver[x][y] = true;

    if (tablero[x][y] != 'E') {
        tablero[x][y] = 'o'; // Marca camino
    }

    // Por cada direccion posible
    for (int i = 0; i < 4; i++) {
        // Se calcula la siguiente celda
        int nx = x + dxf[i];
        int ny = y + dyf[i];

        // Condición para avanzar: está dentro del tablero, no ha sido visitado, y es camino válido
        if (nx >= 0 && nx < filas && ny >= 0 && ny < columnas && !visitadosResolver[nx][ny] && (tablero[nx][ny] == '-' || tablero[nx][ny] == 'S')) {
            
            // Se llama recursivamente para seguir explorando
            if (resolverDFS(nx, ny)) return true;
        }
    }

    // Si no lleva a la salida, desmarcar
    if (tablero[x][y] != 'E') {
        tablero[x][y] = '-';
    }

    return false;       // No se encontró la salida por este camino
}

/// Se define como se va a ver el tablero
void imprimirTablero(){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout << "  " << tablero[i][j];
        }
        cout << endl;
    }
}

// Se llama al main para llamar a las funciones necesarias
int main(){
    srand(time(0));

    inicializarTableroLleno();  // Iniciar el tablero con el espacio lleno de muros y las celdas no visitadas
    abrirCaminoDFS(0,0);    // El algortimo parte desde la entrada y marca esa celda como camino
    
    // Se posicionan entrada y salida
    posicionarCaracter(0, 0, 'E');
    posicionarCaracter(filas-1, columnas-1, 'S');
    
    imprimirTablero();
    cout << "\nCamino resuelto: " << endl;
    visitadosResolver.assign(filas, vector<bool>(columnas, false));
    resolverDFS(0, 0);

    // Se muestra el tablero(laberinto) ordenado
    imprimirTablero();   
    return 0;
}