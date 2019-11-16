
/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Oct 2019
 */

#include <array>
#include <string>
#include <map>
#include <python3.8/Python.h>

#include "lib/QPULib.h"
#include "pybind11/include/pybind11/pybind11.h"
#include "pybind11/include/pybind11/stl.h"

using namespace std;

const int VECTOR_SIZE = 16;
const int NUM_QPU = 12;

static const map<string, void (*)(Ptr<Int>, Ptr<Int>, Ptr<Int>)> OPERATION = {
        {"ADD", [](Ptr<Int> m1, Ptr<Int> m2, Ptr<Int> result){ *result = *m1 + *m2;}},
        {"MUL", [](Ptr<Int> m1, Ptr<Int> m2, Ptr<Int> result){ *result = *m1 * *m2;}}
};

auto operation(const string operation) -> void (*)(Ptr<Int>, Ptr<Int>, Ptr<Int>) {
    return OPERATION.at(operation);
}

array<int, 16> qpu_execute( array<int, VECTOR_SIZE> matrix1,
                            array<int, VECTOR_SIZE> matrix2,
                            const string operationID = "ADD",
                            const int numOfQpusToUse = 1 ) {

    //create shared array to pass data back and forth between QPU and CPU
    SharedArray<int> a(VECTOR_SIZE), b(VECTOR_SIZE), r(VECTOR_SIZE);
    for(int index =0; index < VECTOR_SIZE; index++){
        a[index] = matrix1[index];
        b[index] = matrix2[index];
    }

    // init and invoke gpu
    auto kernel = compile(operation(operationID));
    if(numOfQpusToUse <= NUM_QPU)
        kernel.setNumQPUs(numOfQpusToUse);
    else
        kernel.setNumQPUs(1);
    kernel(&a, &b, &r);

    //copy the result and return
    array<int, 16> result{};
    for(int index = 0; index < 16; index++) result[index] = r[index];
    return result;
}

PYBIND11_MODULE(qpu, m) {
    m.doc() = "QPU Bindings to Python";
    m.def("execute", &qpu_execute, "EXECUTE QPU OPERATION (ADD, MUL) CURRENTLY SUPPORTED");
}

// test program
int main(){
    array<int, 16> matrix1 = {10,11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    array<int, 16> matrix2 = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
    array<int, 16> result = qpu_execute(matrix1, matrix2); //EXECUTES ADD OPERATION
    return 0;
}