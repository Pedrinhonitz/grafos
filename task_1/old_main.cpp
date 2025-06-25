// #include <iostream>
// #include <vector>
// #include "Grafo.h"
// #include "Arrests.h"

// using namespace std;

// int main() {
//     std::vector<int> c;
    
//     c.push_back(2);
//     c.push_back(1);
//     c.push_back(2);
//     c.push_back(1);

//     try {
//         Grafo g1(4);
//         g1.push_arrests(Arrests (0, 1));
//         g1.push_arrests(Arrests (1, 0));
//         g1.push_arrests(Arrests (1, 2));
//         g1.show_grafo();
//         cout << "Walk: " << g1.is_walk(c) << endl;
//         cout << "Path: " << g1.is_path(c) << endl;
//     }catch (const exception &error) {
//         cerr << "exception: " << error.what() << endl;
//     }

//     return 0;
// } 