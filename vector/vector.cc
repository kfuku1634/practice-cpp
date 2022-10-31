#include "vector.h"
#include <memory>

namespace kf
{
    vector::vector(){
        size_ = 0;
        capacity_ = 1;
        data = new int[0];
    }

    int vector::size(){
        return size_;
    }

    int vector::capacity(){
        return capacity_;
    }

    bool vector::empty(){
        return size_ == 0 ? true : false;
    }

    void vector::push_back(int x){
        data[size_] = x;
    }

    int vector::at(int i){
        return data[i];
    }

}
