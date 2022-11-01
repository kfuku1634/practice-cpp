#include <initializer_list>
#include <iostream>
#include <malloc/_malloc.h>
#include <memory>
#include <cstdlib>

namespace kf {
    template <typename T>
    class vector{
        public:
            vector(){
                size_ = 0;
                capacity_ = 1;
                malloc_data(1);
            }

            vector(int size){
                size_ = size;
                capacity_ = size;
                malloc_data(capacity_);
            }

            vector(std::initializer_list<T> init){
                size_ = init.size();
                capacity_ = size_;
                malloc_data(size_);
                int n=0; for( auto a: init ){
                    data[n] = a;
                    n++;
                }
            }

            ~vector(){
                free(data);
            }

            int size() const{
                return size_;
            }


            int capacity(){
                return capacity_;
            }

            bool empty(){
                return size_ == 0 ? true : false;
            }

            void resize(){
                data = (int*)realloc(data, capacity_ * 2 );
            }

            void push_back(int x){
                if( size_ == capacity_ ){
                    resize();
                }
                data[size_] = x;
                size_++;
            }

            int at(int i){
                return data[i];
            }

            int &back(){
                return data[(size_-1)];
            }

            void pop_back(){
                size_--;
                data[size_] = 0;
            }

            int *begin(){
                return data;
            }

            int *end(){
                return &data[(size_-1)];
            }

            bool operator == ( const vector &vec_oth ) const {
                if ( this->size() != vec_oth.size() ) { return false; }
                return true;
            }
        private:
            int capacity_;
            int size_;
            T *data;
            void malloc_data(int size){
                data = (T*)malloc(sizeof(T)*size);
            }
    };
}
