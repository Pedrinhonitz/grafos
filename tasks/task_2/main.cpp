#include <iostream>
#include "Grafo.h"
#include "Arrests.h"

using namespace std;

int main() {
    int num_vertices, num_relacoes;
    cin >> num_vertices >> num_relacoes;

    Grafo g(num_vertices);

    for(int i = 0; i < num_relacoes; ++i) {
        int x, y;
        char z;
        cin >> x >> y >> z;

        if(z == 'A') {
            g.push_arrests(Arrests(x, y));
        }
    }

    if(g.is_bipartido()) {
        cout << "SIM" << endl;
    }else {
        cout << "NAO" << endl;
    }

    if(g.is_bipartido_2()) {
        cout << "SIM" << endl;
    }else {
        cout << "NAO" << endl;
    }
}

