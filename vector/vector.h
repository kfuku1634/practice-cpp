#include <cstring>
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
                int n=0;
                for( auto a: init ){
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
                capacity_ *= 2;
                data = (T*)realloc(data, (sizeof(T) * capacity_ ));
            }

            void push_back(T x){
                if( is_full() == true ){ resize(); }
                // data[size_] = x;
                memcpy( &data[size_], &x, sizeof(T));
                size_++;
            }

            T at(int i){
                return data[i];
            }

            T &back(){
                return data[(size_-1)];
            }

            void pop_back(){
                size_--;
            }

            T *begin(){
                return data;
            }

            T *end(){
                return &data[(size_)];
            }

            bool operator == ( const vector &vec_oth ) const {
                if ( this->size() != vec_oth.size() ) { return false; }
                for(int i=0; i < this->size(); i++ ){
                    if ( this->data[i] != vec_oth.data[i] ) { return false;}
                }
                return true;
            }

            void insert(int index, T x){
                if ( is_full() == true ){ resize(); }
                for(int i=size(); i != index; i-- ){
                    data[i] = data[i-1];
                }
                //(data+index) = p_tmp;
                memcpy( &data[index], &x, sizeof(T));
                size_++;
            }

            void debug_print(){
                for (auto it = begin(); it != end(); it++) {
                    std::cout << *it << std::endl;
                }
                std::cout << std::endl;
            }

        private:
            int capacity_;
            int size_;
            T *data;
            void malloc_data(int size){
                data = (T*)malloc(sizeof(T)*size);
                if ( data == NULL ){ exit( EXIT_FAILURE ); }
            }
            bool is_full(){
                if(size_ == capacity_){
                    return true;
                }
                return false;
            }
    };
}
