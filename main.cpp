
#include <iostream>
#include <boost/thread.hpp>

const size_t N = 10;				// count of new records
int shared_mem = 0;					// data

boost::mutex mtx_read;
boost::mutex mtx_write;

void write() {
	// Enter
	for (std::size_t i = 0; i < N; ++i) {
		{
			boost::this_thread::sleep(boost::posix_time::milliseconds(100));	// time to calculate new data

			mtx_read.lock();  // block to write data
			{
				std::cout << "Calculated data:\t" << ++shared_mem << "\t";		
			}
			mtx_write.unlock();
		}
	}
	mtx_read.unlock();
}
void read() {
	mtx_write.unlock();
	for (std::size_t i = 0; i < N; ++i) {
		{
			mtx_write.lock();  // block to read data
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(800)); // time to write new data
				std::cout << "Write to file:\t" << shared_mem << std::endl;					
			}
			mtx_read.unlock(); 
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