#include <iostream>
#include <boost/thread.hpp>

const size_t N = 500;																	// count of records
const size_t threads_count = 2;
int shared_mem = 0;																		// data
boost::barrier bar1(threads_count);
boost::barrier bar2(threads_count);



void write() {
    for (std::size_t i = 0; i < N; ++i) {
        {
            boost::this_thread::sleep(boost::posix_time::milliseconds(rand() % 10));	// time to calculate new data
            bar1.wait();
            std::cout << "Calculated data:\t" << ++shared_mem << "\t";					// write data
            bar2.wait();
        }
    }
    bar1.wait();
}
void read() {
    bar1.wait();
    for (std::size_t i = 0; i < N; ++i) {
        {
            bar2.wait();
            std::cout << "Write to file:\t" << shared_mem << std::endl;					// read  data
            bar1.wait();
        }
    }

}
int main() {
    srand(time(NULL));
    boost::thread t1(&write);
    boost::thread t2(&read);
    t1.join();
    t2.join();
}