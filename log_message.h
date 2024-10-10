#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <sqlite3.h>

class log_message{

	private:
        	std::string message_Text; // variable to hold message
        	std::string time_Stamp;  // variable to hold timestamp
        	
        public:
        	 log_message(std::string time_Stamp, std::string message_Text); // constructor for log message class
        	 std::string get_message(); // returns message
        	 std::string get_timestamp(); // returns timestamp
        	 
        	 
        ~log_message();



};
