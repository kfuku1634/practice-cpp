#include "vector/vector.h"

namespace kf {
    template <typename T>
    class priority_queue {
        public:
            priority_queue(){}
            int size(){ return vec.size(); }
            bool empty(){ return vec.empty(); }
            int capacity(){ return vec.capacity(); }
            void push( T element ){ 
                int insert_index=0;
                while( insert_index != vec.size() ){
                    if( vec.at(insert_index) >  element ){
                        break;
                    }
                    insert_index++;
                }
                vec.insert(insert_index, element);
            }
            void pop(){ vec.pop(); }
            T &top(){ return vec.back(); }
        private:
            vector<T> vec;
    };
}
