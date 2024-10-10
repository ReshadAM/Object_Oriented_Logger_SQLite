
#include "logger.h"


using namespace std;





    /**
        The logger constroctor takes in the name of the app as an argument

        This constructor will open a database
        - Get a database handle suitable for queries
        Create a table for APP in the database
    */
        logger::logger (string table_name) {
            //char* err;
            this->table_name = table_name; // taking in the table_name and assigning it to the private variable
            string table_name_start = table_name; // assigning table name to local variable so i can use it anywhere in the file

            char dataBase_name[table_name_start.length() + 1]; // turning the table name into a char
            strcpy(dataBase_name,table_name_start.c_str());
            char databBase_EXT [50] = ".db";



	    int rc = sqlite3_open("database", &db); // opening the database
	    // checking if the databsse was made
            if (rc == SQLITE_OK) {
               // cout<< "success" << endl;
            } else {
                cout <<"faill" <<endl;
            }

            

            string sql_tr = "create table if not exists " +table_name+" (timestamp varchar(255), message varchar(255));"; // using the provided code to create the database with the timestamp and mesg
            // after table name portion


	    char *err = 0; // will be used to print error message
            int ec =  sqlite3_exec(db,sql_tr.c_str(), 0, 0, &err); // sql_tr = create table if not exists APPLEJUICE(TimeStamp varchar(255), Messages varchar(255));

           // Here were gonna check the error by using the SQLITE_OK which just checks if there is a problem or not
            if (ec != SQLITE_OK) {
             cout << "error: " << err << endl;
           }


        } // end of constroctor

	/*
		// The writer class will take in a message and sore it into the database with the timestamp
	
	*/
         void logger::write(string log_message) {
                // Getting the time
                time_t dt = time(0); // using the ctime library to get the current time and date and the moment of the method being called

                string current_time = asctime(localtime(&dt)); // converting the time into string form
		current_time = current_time.substr(0, current_time.length() -1); // getting the current time


          	string str1 = "insert into " + table_name + " values (\"" + current_time + "\", \"" + log_message + "\");"; // this variable will be inserted into the sqlite3_exec
                char *err = 0;
                int rc = sqlite3_exec(db,str1.c_str(),0,0,&err);

                if (rc != SQLITE_OK) {
                    cout << "insert error: " << err << endl;
                }

        } // end of write



	/*
	
		This method wil take in no values and return a list of all the messages in a vector
		The vector will be of type log_message
	
	
	*/
        vector<log_message> logger::read_all(){
            vector<log_message> log_vector; // making a placeholder log_message to return after putting all data in 

            string str1 = "select * from "+table_name+";"; // will be inserted into the sqlite3_step
	    sqlite3_stmt* stmt;
	    const char *tail;
            sqlite3_prepare(db, str1.c_str(), str1.size(), &stmt,&tail); // the stmt represents the front of the database
            string  timestamp; // represents the time 
            string  message;	// represents the message
            // this sqlite function will return the first row in the databse each iteration, it will iterate until SQLITE_DONE which will make sure we dont have a index out of bounds. //
		int rc = sqlite3_step(stmt);
		if (rc != SQLITE_ROW) {

		cout << "Error something went wrong " << rc << endl;

		}
	    // This while loop will iterate and store the data from the database into the vector
            while(rc != SQLITE_DONE) {
                timestamp = (reinterpret_cast<const char*>(sqlite3_column_text(stmt,0))); // get data from colmn 1 aka the timestamp
                message =   (reinterpret_cast<const char*>(sqlite3_column_text(stmt,1))); // get data from column 2 aka the message
               // cout << "timestamp: " << timestamp << "message: " <<  message << endl;
                log_message log_M = log_message(timestamp, message); // making the object of time log_message to put into the vector
                log_vector.push_back(log_M);
                rc = sqlite3_step(stmt);
               }

	   sqlite3_finalize(stmt);

            return log_vector;

        }


	// deconstructor will make sure the database is closed after the class is off the heap
        logger::~logger () {

        	sqlite3_close(db);

        }








