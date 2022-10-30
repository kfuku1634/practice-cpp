#include "priority_queue.h"

namespace kf 
{
    priority_queue::priority_queue(){
        size_ = 0;
    };

    int priority_queue::size(){
        return size_;
    }

    bool priority_queue::empty(){
        return (size_==0) ? true : false;
    }
}
