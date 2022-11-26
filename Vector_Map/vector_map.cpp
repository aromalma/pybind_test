#include <iostream>
#include <pybind11/pybind11.h>
#include<pybind11/stl_bind.h>
#include <pybind11/stl.h>

namespace py = pybind11;
PYBIND11_MAKE_OPAQUE(std::vector<int>);
PYBIND11_MAKE_OPAQUE(std::map<int,int>);

void increment_vector(std::vector<int> &v,int c){ // by reference
    for(int i=0;i<int(v.size());i++){v[i]=v[i]+c;}

}
void increment_map_values(std::map<int,int>&v,int c){
    for (auto itr = v.begin(); itr != v.end(); itr++){
        (itr->second)=(itr->second)+c;
        }

}

PYBIND11_MODULE(vector_map,m){
    py::bind_vector<std::vector<int>>(m, "VectorInt");
    py::bind_map<std::map<int, int>>(m, "Map");
    
    m.def("inc",&increment_vector);
    m.def("inc",&increment_map_values);
    m.def("size",[]( std::vector<int> &v){return v.size();});
}
