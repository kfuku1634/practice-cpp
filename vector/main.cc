#include <iostream>
#include "vector.h"

int main(){
    kf::vector vec1 = {1,2,3,4,5};
    kf::vector vec2 = {1,2,3,4,5};

    if ( vec1 == vec2 ) {
        std::cout << "eq" << std::endl;
    }

    for (auto a: vec1 ) {
        std::cout << a << std::endl;
    }

}
