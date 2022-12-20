#include <iostream>
#include <chrono>


class Time {
private:
	std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
public:
	Time() {};

	void start() {
		start_time = std::chrono::steady_clock::now();
	}

	void end() {
		end_time = std::chrono::steady_clock::now();
	}

	void log() {
		std::cerr « std::chrono::duration<double>(end_time - start_time).count() « std::endl;
	}
	void reset() {
		start_time = std::chrono::steady_clock::now();
		end_time = std::chrono::steady_clock::now();

	}

	double current_mesure() {

		return std::chrono::duration<double>(end_time - start_time).count();
	}
};