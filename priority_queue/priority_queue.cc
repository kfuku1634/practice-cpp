#include "priority_queue.h"
#include <memory>

namespace kf 
{
    priority_queue::priority_queue(){
        size_ = 0;
        capacity_ = 1;
        data = new int[0];
    };

    int priority_queue::size(){
        return size_;
    }

    bool priority_queue::empty(){
        return (size_==0) ? true : false;
    }

    void priority_queue::push(int push_var){
        data[0] = push_var;
        return;
    }

    int priority_queue::pop(){
        return data[0];
    }

    int priority_queue::capacity(){
        return capacity_;
    }
}
