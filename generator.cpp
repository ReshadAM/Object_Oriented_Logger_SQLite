#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <ctime>


#include "logger.h"




using namespace std;



int main(int argc, char *argv[])
{
    string argument_one = argv[0]; // takes the first argument which and assigns it to the string
    
    int randomtime; // will hold a random int from 1 - 10
    argument_one.erase(0,2); // erasing the ./ in argument 1

    logger log(argument_one); // ending argument one to the logger.cpp class
    srand(time(0)); // makes it so we dont get the same rand
    int index = 1 + rand() % argc; // make a random number from 1 to argc
    
    // This will loop through and create new random numbers and add a null at the posiion in the argv so that we dont get the same message
    // The loop will then make a new rand number if the same is called
    for (int i = 1; i < argc;){
    	// if we hit a null pointer it means we got the same number, so we will make a new
    	if (argv[index] == nullptr) { 
            index = 1 + rand() % argc;
    	} else {
    	 // else insert the value into the database using the method we made
  
    	 cout << "The program is sleeping......" << endl;
    	 randomtime = 0 + rand() % 10; // generate a random number  from 1 - 10 to represent seconds 
	 sleep(randomtime); // sleep for randdomtime seconds 
	 
    	 log.write(argv[index]);
	 cout << "MESSAGE ADDED" << endl;
	 
    	 argv[index] = nullptr; // after doing so make that index nullpointer so we dont hit it again 
    	 index = 1 + rand() % argc; // generate new number 
    	 i++;
    	}


    }








    return 0;
}


