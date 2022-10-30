
namespace kf {
    class priority_queue {
        public:
            priority_queue();
            int size();
            int capacity();
            bool empty();
            void push(int);
            int pop();
        private:
            int *data;
            int capacity_;
            int size_;
    };
}
