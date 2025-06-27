#include <iostream>
#include <set>
#include "Grafo.h"
#include "Arrests.h"

using namespace std;

Grafo::Grafo(int num_vertices) {
    this->vertices_number_ = num_vertices;
    this->arrests_number_ = 0;
    this->adjacent_matrix_.resize(num_vertices);

    for(int i=0; i<num_vertices; i++) {
        this->adjacent_matrix_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return this->vertices_number_;
}

int Grafo::num_arrests() {
    return this->arrests_number_;
}

bool Grafo::is_arrests(Arrests e) {
    if(this->adjacent_matrix_[e.v1_][e.v2_] == 0) {
        return false;
    }else {
        return true;
    }
}

bool Grafo::push_arrests(Arrests e) {
    if(!this->is_arrests(e) && e.v1_ != e.v2_) {
        this->adjacent_matrix_[e.v1_][e.v2_] = 1;
        this->adjacent_matrix_[e.v2_][e.v1_] = 1;
        this->arrests_number_++;

        return true;
    }else {
        return false;
    }
}

bool Grafo::pop_arrests(Arrests e) {
    if(this->is_arrests(e)) {
        this->adjacent_matrix_[e.v1_][e.v2_] = 0;
        this->adjacent_matrix_[e.v2_][e.v1_] = 0;
        this->arrests_number_--;

        return true;
    }else {
        return false;
    }
}

void Grafo::show_grafo() {
    for(auto &i: this->adjacent_matrix_) {
        for(auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool Grafo::is_walk(std::vector<int> v) {
    bool flag = true;
    for(int i=0; i<v.size()-1; i++) {
        if(!this->is_arrests(Arrests(v[i], v[i+1]))) {
            flag = false;
        }
    }
    if(v.empty()) {
        return false;
    }else {
        return flag;    
    }
}

bool Grafo::is_path(std::vector<int> v) {
    bool flag = this->is_walk(v);
    vector<int> marked(this->vertices_number_, 0);
    if(flag) {
        for(int i=0; i<v.size(); i++) {
            if(!marked[v[i]]) {
                marked[v[i]] = 1;
            }else {
                return false;
            }
        }
    }else {
        return false;
    }

    return true;
}

// bool Grafo::is_go(int x, int y) {
//     bool flag = false;

//     if(this->)

//     return flag;
// }