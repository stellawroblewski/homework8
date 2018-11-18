#include "cities.hh"
#include <string>
#include <iostream>
#include <fstream>

//Stella Wroblewski and Ariel Flaster


//arg v should be a cities file

//Write a new file called tsp.cc with a main() function that will 
//perform the actual search. The main() function reads in a cities 
//file (the filename should be given as the first argument of the 
//program). It then iterates over a fixed number of iterations 
//(say, one million), In each iteration, it generates a new random
//permutation; evaluates the distance to travel the cities along 
//this ordering; compares it to the best (shortest) distance found 
//so far, and if it's shorter, replaces the cities object with the 
//newly-reordered cities and prints out to the screen the iteration 
//number, followed by a space (or tab) and the total distance of 
//the new path. At the end of the loop, save your cities ordering to 
//a file called "shortest.tsv".

int main(int argc, char* argv[]) {
	//get argv[] to input all its cities into a new cities
	const int NUMBER_OF_TESTS = 10000;
	bool first_time = true;
	Cities cities;
	double lowest_curr_distance;

	// should get file name and turn it into stream
	std::string filename = argv[1];
	auto fin = std::ifstream(filename);
	fin>>cities;

	//should create iterations and calculate distance
	for(int i = 0; i < NUMBER_OF_TESTS; i ++) {
		//create iteration
		Cities::permutation_t random_permutation = cities.random_permutation(cities.cities_.size());
		double distance = cities.Cities::total_path_distance(random_permutation);
		if (first_time == true){
			lowest_curr_distance = distance;
			first_time = false;
			std::cout << i + 1 << "    " << lowest_curr_distance << "\n";
		}
		else if (distance < lowest_curr_distance){
			lowest_curr_distance = distance;
			cities.order_of_cities = random_permutation; //this is wrong, should replace the cities object with the newly-reordered cities, not sure how to do that
			std::cout << i + 1 << "    " << lowest_curr_distance << "\n";
		}

		//record shortest distance and save shorter cities, compare to next cities in loop
	}
	std::ofstream outfile ("shortest.tsv");
	outfile << cities << std::endl;
	outfile.close();
return 0;
}