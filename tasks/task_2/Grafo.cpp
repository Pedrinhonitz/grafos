#include <iostream>
#include <set>
#include <stack>
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

bool Grafo::is_walk(vector<int> v) {
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

bool Grafo::is_path(vector<int> v) {
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

bool Grafo::is_bipartido() {
    vector<bool> deleted(this->vertices_number_, false);
    vector<int> part1, part2;

    return is_bipartido_rec(deleted, part1, part2);
}

bool Grafo::is_bipartido_rec(vector<bool>& deleted, vector<int>& part1, vector<int>& part2) {
    int v = -1;
    for(int i = 0; i < this->vertices_number_; ++i) {
        if(!deleted[i]) {
            v = i;
            break;
        }
    }

    if(v == -1) {
        return true;
    }

    deleted[v] = true;

    if(!is_bipartido_rec(deleted, part1, part2)) {
        return false;
    }

    bool is_part1 = true;
    for(int u : part1) {
        if(this->adjacent_matrix_[v][u]) {
            is_part1 = false;
            break;
        }
    }
    if(is_part1) {
        part1.push_back(v);
        return true;
    }

    bool is_part2 = true;
    for(int u : part2) {
        if(this->adjacent_matrix_[v][u]) {
            is_part2 = false;
            break;
        }
    }
    if(is_part2) {
        part2.push_back(v);
        return true;
    }

    return false;
}

bool Grafo::is_bipartido_2() {
    vector<int> color(this->vertices_number_, -1);

    for(int i = 0; i < this->vertices_number_; ++i) {
        if(color[i] != -1) {
            continue;
        }

        stack<int> _stack;
        _stack.push(i);
        color[i] = 0;

        while(!_stack.empty()) {
            int v = _stack.top();
            _stack.pop();

            for(int u = 0; u < this->vertices_number_; ++u) {
                if(this->adjacent_matrix_[v][u]) {
                    if(color[u] == -1) {
                        color[u] = 1 - color[v];
                        _stack.push(u);
                    }else if(color[u] == color[v]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
