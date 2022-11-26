
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
class cpp_{
public:
    int *a;
    int n;

cpp_(py::array_t<int> & arr){
    auto buf = arr.request();
    a = (int *)buf.ptr;
    n = buf.shape[0];
}
int heapify(int *a,int i,int n){
    int left_child= 2*i+1;
    int right_child= left_child+1;
    int max=i;
    int t;
    if  (left_child < n) {if (a[left_child]>a[i]){max=left_child;}}
    else{return 0;}
   
    if (right_child < n && a[right_child]>a[max]){max=right_child;}
    if (max!=i){t=a[i]; a[i]=a[max];a[max]=t; heapify(a,max,n);}

    return 0;
}


int heapsort(){

    int i,t;    
    for ( i=int(n/2)-1;i>=0;i--){
        heapify(a,i,n);    
    }

    for ( i=n-1;i>=0;i--){
        t=a[0];
        a[0]=a[i];
        a[i]=t;
 
        heapify(a,0,i);
    }   
    return 0;

}
};
PYBIND11_MODULE(cpp_sort,m ) {
    // optional module docstring
    m.doc() = "pybind11 sort";
    py::class_<cpp_>(m, "cpp_")
        .def(py::init<py::array_t<int> &>())
        .def("heapsort", &cpp_::heapsort)
        .def_readwrite("array_size", &cpp_::n);


    


}