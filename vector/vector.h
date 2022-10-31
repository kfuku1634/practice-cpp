#include <initializer_list>

namespace kf {
    class vector{
        public:
            vector();
            vector(int);
            vector(std::initializer_list<int> init);
            ~vector();
            int size();
            int capacity();
            bool empty();
            void push_back(int);
            int at(int);
            void resize();
            int &back();
            void pop_back();
            int *begin();
            int *end();
        private:
            int capacity_;
            int size_;
            int *data;
            void malloc_data(int);
    };
}
