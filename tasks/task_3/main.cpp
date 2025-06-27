 #include <iostream>
 #include "Grafo.h"
 #include "Aresta.h"
 
 using namespace std;
 
 int main() {
    int num_vertices, num_arrestas;
    string _char;
    cin >> num_vertices >> num_arrestas;

    Grafo g(num_vertices);

    for(int i = 0; i < num_arrestas; ++i) {
        int x, y;
        cin >> x >> y;

        g.push_arrests(Aresta(x, y));
    }

    cin >> _char;
    if(_char == "P") {
        g.constroi_coloracao_1();
    }else if(_char == "A") {
        g.constroi_coloracao_1();
        g.constroi_coloracao_2();
    }
}
 
 