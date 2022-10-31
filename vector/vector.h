
namespace kf {
    class vector{
        public:
            vector();
            vector(int);
            ~vector();
            int size();
            int capacity();
            bool empty();
            void push_back(int);
            int at(int);
            void resize();
        private:
            int capacity_;
            int size_;
            int *data;
            void malloc_data(int);
    };
}
