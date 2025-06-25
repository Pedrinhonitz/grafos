#include <iostream>
#include <vector>
#include "Grafo.h"
#include "Arrests.h"

using namespace std;

int main() {
    Grafo g1(4);

    g1.push_arrests(Arrests (0, 1));
    g1.push_arrests(Arrests (1, 0));
    g1.push_arrests(Arrests (1, 2));
    g1.show_grafo();

    return 0;
}