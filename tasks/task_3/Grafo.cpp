#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#include "Grafo.h"
#include "Aresta.h"

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

bool Grafo::is_arrests(Aresta e) {
    if(this->adjacent_matrix_[e.v1_][e.v2_] == 0) {
        return false;
    }else {
        return true;
    }
}

bool Grafo::push_arrests(Aresta e) {
    if(!this->is_arrests(e) && e.v1_ != e.v2_) {
        this->adjacent_matrix_[e.v1_][e.v2_] = 1;
        this->adjacent_matrix_[e.v2_][e.v1_] = 1;
        this->arrests_number_++;

        return true;
    }else {
        return false;
    }
}

bool Grafo::pop_arrests(Aresta e) {
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
        if(!this->is_arrests(Aresta(v[i], v[i+1]))) {
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

void Grafo::constroi_coloracao_1() {
    vector<int> color(this->vertices_number_, -1);

    for(int i = 0; i < this->vertices_number_; ++i) {
        // if(color[i] != -1) {
        //     continue;
        // }

        stack<int> _stack;
        _stack.push(i);
        
        color[i] = 1;
        // cout << "VERTICE: " << i << endl;
        int max_cor = 1;
        while(!_stack.empty()) {
            int v = _stack.top();
            _stack.pop();
            int color_max = -1;
            for(int u = 0; u < this->vertices_number_; ++u) {
                if(this->adjacent_matrix_[v][u]) {
                    if(color_max < color[u]) {
                        color_max = color[u];
                    }
                    if(color[i] == color[u]) {
                        color[i]++;
                    }
                }
            }
            if(color[i] == color_max) {
                color[i]++;
            }

            for(int u = 0; u < this->vertices_number_; ++u) {
                if(this->adjacent_matrix_[v][u]) {
                    if(color[i] == color[u]) {
                        color[i] = color_max++;
                    }
                }
            }
        }
    }
    int maior = -1;
    for(int i=0; i<color.size(); i++) {
        if(color[i]>maior) {
            maior = color[i];
        }
    }

    cout << "Numero de cores: " << maior << endl;
    for(int i=1; i<=maior; i++) {
        cout << "Cor " << i << ": ";
        for(int j=0; j<color.size(); j++) {
            if(i == color[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void Grafo::constroi_coloracao_2() {
    vector<int> color(this->vertices_number_, -1);

    vector<int> vetor_grau(this->vertices_number_, -1); 
    vector<int> vetor_index(this->vertices_number_, -1); 
    for(int i = 0; i < this->vertices_number_; ++i){
        int grau = 0;
        for(int j=0; j<this->vertices_number_; j++){
            if(this->adjacent_matrix_[i][j]) {
                grau++;
            }
        }
        vetor_grau.push_back(grau);
        vetor_index.push_back(i);
    }

    for(int i = 0; i < vetor_index.size(); ++i) {
        int grau_posicao = vetor_grau[i];
        for(int j=i; j<vetor_index.size(); j++){
            if(vetor_grau[i]<vetor_grau[j]) {
                int aux = vetor_grau[i];
                vetor_grau[i] = vetor_grau[j];
                vetor_grau[j] = aux;
                int aux2 = vetor_index[i];
                vetor_index[i] = vetor_index[j];
                vetor_index[j] = aux2;
            }
        }
    }

    for(int i = 0; i < this->vertices_number_; ++i) {
        int index_ = vetor_index[i];
        stack<int> _stack;
        _stack.push(index_);
        
        color[index_] = 1;
        int max_cor = 1;
        while(!_stack.empty()) {
            int v = _stack.top();
            _stack.pop();
            int color_max = -1;
            for(int u = 0; u < this->vertices_number_; ++u) {
                if(this->adjacent_matrix_[v][u]) {
                    if(color_max < color[u]) {
                        color_max = color[u];
                    }
                    if(color[index_] == color[u]) {
                        color[index_]++;
                    }
                }
            }
            if(color[index_] == color_max) {
                color[index_]++;
            }

            for(int u = 0; u < this->vertices_number_; ++u) {
                if(this->adjacent_matrix_[v][u]) {
                    if(color[index_] == color[u]) {
                        color[index_] = color_max++;
                    }
                }
            }
        }
    }
    int maior = -1;
    for(int i=0; i<color.size(); i++) {
        if(color[i]>maior) {
            maior = color[i];
        }
    }

    cout << "Numero de cores: " << maior << endl;
    for(int i=1; i<=maior; i++) {
        cout << "Cor " << i << ": ";
        for(int j=0; j<color.size(); j++) {
            if(i == color[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}