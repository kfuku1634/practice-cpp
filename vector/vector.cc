#include <iostream>
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

    vector::vector(std::initializer_list<int> init){
        size_ = init.size();
        capacity_ = size_;
        malloc_data(size_);
        int n=0; for( auto a: init ){
            data[n] = a;
            n++;
        }
    }

    vector::~vector(){
        free(data);
    }

    int vector::size() const{
        return size_;
    }

    void vector::malloc_data(int size){
        data = (int*)malloc(sizeof(int)*size);
        std::cout << data << std::endl;
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

    int &vector::back(){
        return data[(size_-1)];
    }

    void vector::pop_back(){
        size_--;
        data[size_] = 0;
    }

    int *vector::begin(){
        return data;
    }

    int *vector::end(){
        return &data[(size_-1)];
    }

    bool vector::operator == ( const vector &vec_oth ) const {
        if ( this->size() != vec_oth.size() ) { return false; }
        return true;
    }
}
