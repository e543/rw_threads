
#include <iostream>
#include <boost/thread.hpp>

const size_t N = 500;				// count of records
const size_t threads_count = 2;
int shared_mem = 0;					// data

boost::mutex mtx_write;
boost::mutex mtx_read;

void write() {
	// Enter
	for (std::size_t i = 0; i < N; ++i) {
		{
			boost::this_thread::sleep(boost::posix_time::milliseconds(10));	// time to calculate new data

			mtx_write.lock(); // block to write data
			{
				std::cout << "Calculated data:\t" << ++shared_mem << "\t";		
			}
			mtx_read.unlock();
		}
	}
	mtx_write.unlock();
}
void read() {
	mtx_read.unlock();
	for (std::size_t i = 0; i < N; ++i) {
		{
			mtx_read.lock();  // block to read data
			{
				std::cout << "Write to file:\t" << shared_mem << std::endl;					
			}
			mtx_write.unlock();
		}
	}
	// Exit
}
int main() {
	srand(time(NULL));
	boost::thread t1(&write);
	boost::thread t2(&read);
	t1.join();
	t2.join();
}