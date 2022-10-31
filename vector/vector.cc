#include <malloc/_malloc.h>
#include <memory>
#include <cstdlib>
#include "vector.h"

namespace kf
{
    vector::vector(){
        size_ = 0;
        capacity_ = 1;
        malloc_data(1);
    }

    vector::vector(int size){
        size_ = size;
        capacity_ = size;
        malloc_data(capacity_);
    }

    vector::~vector(){
        free(data);
    }

    int vector::size(){
        return size_;
    }

    void vector::malloc_data(int size){
        data = (int*)malloc(sizeof(int)*size);
    }

    int vector::capacity(){
        return capacity_;
    }

    bool vector::empty(){
        return size_ == 0 ? true : false;
    }

    void vector::resize(){
        data = (int*)realloc(data, capacity_ * 2 );
    }

    void vector::push_back(int x){
        if( size_ == capacity_ ){
            resize();
        }
        data[size_] = x;
        size_++;
    }

    int vector::at(int i){
        return data[i];
    }

}
