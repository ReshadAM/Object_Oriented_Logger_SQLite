
#include "log_message.h"
using namespace std;



  

   
	// The constructor for the log message will take in the time and message and assign them to the appropriate variables 
        log_message::log_message(string time_Stamp, string message_Text){

            this->time_Stamp = time_Stamp;
            this->message_Text = message_Text;


        }



	// getter to return the message
        string log_message::get_message() {
            return message_Text;
        }

	// getter to return the time
        string log_message:: get_timestamp(){
            return time_Stamp;
        }

	// empty destructor
	log_message::~log_message(){
	// Was told to leave empty by TA
	}


