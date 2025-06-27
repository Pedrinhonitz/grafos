#ifndef GRAFO_H
 #define GRAFO_H
 #include <vector> 
 #include "Aresta.h"
 
 
 class Grafo {
     public:
         Grafo(int num_vertices);
         int num_vertices();
         int num_arrests();
         bool is_arrests(Aresta e);
         bool push_arrests(Aresta e);
         bool pop_arrests(Aresta e);
         void show_grafo();
         bool is_walk(std::vector<int> v);
         bool is_path(std::vector<int> v);
         void constroi_coloracao_1();
         void constroi_coloracao_2();
 
     private:
         int vertices_number_;
         int arrests_number_;
         std::vector<std::vector<int> > adjacent_matrix_;
 };
 
 #endif