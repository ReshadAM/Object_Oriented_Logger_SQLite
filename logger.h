#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <sqlite3.h>
#include "log_message.h"	
// header file for logger class 
class logger{
	
	
	private:
        	sqlite3  *db; // will be used to access the database
        	std::string table_name; // variable for table name

        	
        public:
        	logger (std::string table_name); // logger constructor
        	void write(std::string log_message);  // method for write into the database
        	std::vector<log_message> read_all(); // method to read messages ( returns a vector )
        	
       ~logger();
        	
        	
}; 
        




