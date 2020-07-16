//
// Created by kortexar on 08/07/20.
//

#ifndef UNTITLED_HELPER_H
#define UNTITLED_HELPER_H
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <ctime>
#include <map>
#include <algorithm>

using namespace std;



vector<double> read_csv(string filename){   // This function can read only csv with no column names, but only doubles
    vector<double> result;

    // Create an input filestream
    ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    string line;
    double val;


    // Read data, line by line
    while(getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);

        // Extract each integer
        while(ss >> val){

            // Add the current integer to the result
            result.push_back(val);

            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();
        }
    }

    // Close file
    myFile.close();

    return result;
}

vector<string> read_filenames_from_csv(){   // This function can read only csv with no column names, but only doubles
    vector<string> result;

    // Create an input filestream
    ifstream myFile("../Filenames.csv");

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    string line;

    // Read data, line by line
    while(getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);
        while( ss.good() )
        {
            string substr;
            getline( ss, substr, ',' );
            result.push_back( substr );
        }
    }

    // Close file
    myFile.close();
    return result;
}

class timer{
public:
    static clock_t startedAt;
    static long double duration;
    static bool started;
    static void start(){
        if (timer::started == true){
            cout<< "You have already started the timer. Stop it before you can start it again";
            throw runtime_error("You have already started the timer. Stop it before you can start it again");
        }
        else{
            timer::started = true;
            timer::startedAt = clock();
        }
    }
    static long double stop(){
        if (timer::started == true){
            timer::duration = ( clock() - timer::startedAt ) / (double) CLOCKS_PER_SEC;
            timer::started = false;
            return duration;
        }
        else{
            throw runtime_error("Timer is not started. You must start it and then you can stop it.");
        }

    }
};



clock_t timer::startedAt;
long double timer::duration;
bool timer::started;

#endif //UNTITLED_HELPER_H
