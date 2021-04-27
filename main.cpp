
#include <iostream>
#include <boost/thread.hpp>

const size_t N = 10;			// count of new records
int thr_count = 4;				// count of threads
int shared_mem = 0;				// data

boost::barrier bar_read(thr_count);
boost::barrier bar_write(thr_count);

void write() {
	// Enter
	for (std::size_t i = 0; i < N; ++i) {
		{
			boost::this_thread::sleep(boost::posix_time::milliseconds(600));	// time to calculate new data

			bar_read.wait();  // block to write data
			{
				std::cout << std::endl << std::endl << "Calculated data:\t" << ++shared_mem << std::endl;
			}
			bar_write.wait();
		}
	}
	bar_read.wait();
}
void readF() {
	bar_read.wait();
	for (std::size_t i = 0; i < N; ++i) {
		{
			bar_write.wait(); // block to read data
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(600)); // time to write new data
				std::cout << "Write to File:\t" << shared_mem << std::endl;
			}
			bar_read.wait();
		}
	}
	// Exit
}

void readG() {
	bar_read.wait();
	for (std::size_t i = 0; i < N; ++i) {
		{
			bar_write.wait(); // block to read data
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(600)); // time to write new data
				std::cout << "Write to Game:\t" << shared_mem << std::endl;
			}
			bar_read.wait();
		}
	}
	// Exit
}

void readNW() {
	bar_read.wait();
	for (std::size_t i = 0; i < N; ++i) {
		{
			bar_write.wait();  // block to read data
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(600)); // time to write new data
				std::cout << "Write to Network:\t" << shared_mem << std::endl;
			}
			bar_read.wait();
		}
	}
	// Exit
}

int main() {
	srand(time(NULL));

	boost::thread t1(&write);
	boost::thread t2(&readF);
	boost::thread t3(&readG);
	boost::thread t4(&readNW);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

