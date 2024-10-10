#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <ctime>


#include "logger.h"



using namespace std;



int main(int argc, char *argv[])
{

      string argument_one = argv[1]; // take the second arg

      logger dump(argument_one); // create a logger object to call the read_all from
      vector<log_message> vec;   // make a vector of type log_message
      vec = dump.read_all();	// vec will now hold a vertex containing all the messages
      int size = vec.size() + 1; 

      // this will iterate the vertex and print the values in the correct forma
      for (int i = 0; i < size; i++) {

	if (i < size - 1) {
         cout << vec[i].get_timestamp() + ": "; // will call on the ger_timestamp to get timestamo in the logger message class 
         cout << vec[i].get_message() << endl; 
         
         }

      }


    return 0;
}


