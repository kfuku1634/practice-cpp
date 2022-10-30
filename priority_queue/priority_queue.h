
namespace kf {
    class priority_queue {
        public:
            int size_;
            priority_queue();
            int size();
            int capacity();
            bool empty();
            void push(int);
            int pop();
        private:
            int *data;
            int capacity_;

    };
}
