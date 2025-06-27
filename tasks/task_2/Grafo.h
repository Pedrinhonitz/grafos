#ifndef GRAFO_H
#define GRAFO_H
#include <vector> 
#include "Arrests.h"


class Grafo {
    public:
        Grafo(int num_vertices);
        int num_vertices();
        int num_arrests();
        bool is_arrests(Arrests e);
        bool push_arrests(Arrests e);
        bool pop_arrests(Arrests e);
        void show_grafo();
        bool is_walk(std::vector<int> v);
        bool is_path(std::vector<int> v);
        bool is_bipartido();
        bool is_bipartido_rec(std::vector<bool>& removido, std::vector<int>& conjunto1, std::vector<int>& conjunto2);
        bool is_bipartido_2();

    private:
        int vertices_number_;
        int arrests_number_;
        std::vector<std::vector<int> > adjacent_matrix_;
};

#endif