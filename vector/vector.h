
namespace kf {
    class vector{
        public:
            vector();
            int size();
            int capacity();
            bool empty();
            void push_back(int);
            int at(int);
        private:
            int capacity_;
            int size_;
            int *data;
    };
}
