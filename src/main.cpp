#include <iostream>
#include <chrono>
#include <cmath>

#include "example.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
	//Starting time
	    high_resolution_clock::time_point tStart = high_resolution_clock::now();

	PrintSomething(argv[1]);

	//Ending time and computing time
		high_resolution_clock::time_point tEnd = high_resolution_clock::now();
		double durationTotal =1e-6*duration_cast<microseconds>( tEnd - tStart ).count();
		cout <<"\nProcessing Time:\t"<< durationTotal<<"s ("<< floor(durationTotal/3600.0)<<":"<<floor(fmod(durationTotal/60.0,60.0))<<":"<<floor(fmod(durationTotal,60.0))<<":"<<floor(fmod(1000*durationTotal,1000.0))<<")."<<endl
		<<"##############################"<<endl;
	return 0;
}