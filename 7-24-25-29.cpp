#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<int> cols(N, -1); 

bool es_seguro(int fila, int col) {
    for (int i = 0; i < fila; i++) {
        if (cols[i] == col || cols[i] - i == col - fila || cols[i] + i == col + fila) {
            return false;
        }
    }
    return true;
}

void imprimir_tablero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cols[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void colocar_reinas(int fila) {
    if (fila == N) {
        imprimir_tablero();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (es_seguro(fila, col)) {
            cols[fila] = col;
            colocar_reinas(fila + 1);
            cols[fila] = -1;
        }
    }
}

int main() {
    colocar_reinas(0);
    return 0;
}