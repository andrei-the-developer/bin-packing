//
// Created by kortexar on 14/07/20.
//

#ifndef UNTITLED_SUPERVISOR_H
#define UNTITLED_SUPERVISOR_H


#include "first_fit_decreasing.h"
#include "best_fit_decreasing.h"
#include "next_fit.h"

class supervisor{
private:
    IBinPack* currentAlgo;
    next_fit nf;
    first_fit_decreasing ffd;
    best_fit_decreasing bfd;
    vector<string> distributions = {"uniform", "uniform_complementary", "gaussian", "exponential_decreasing", "exponential_decreasing_complementary", "exponential_increasing"};
    vector<string> algorithms = {"next_fit", "first_fit_decreasing", "best_fit_decreasing"};
    vector<int> numbers = {2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000};

    //map<string, map<int, map<string, double>>> results;
    //results.insert(make_pair(name, make_pair(number, make_pair("time", -1.00))));
    //results.insert(<name, <number, <"space", -1.00>>>);
    //vector<string> = {};

    vector<string> searchFilenames(string name, int number){
        string searchPattern =name+"_"+to_string(number/1000)+"k";
        //cout<<"I am looking for "+searchPattern<<"..."<<endl;
        vector<string> allFiles;
        vector<string> filteredFiles;
        allFiles.clear();
        filteredFiles.clear();

        allFiles = read_filenames_from_csv();

        for( string a : allFiles){
            if(a.find(searchPattern) != string::npos){
                filteredFiles.push_back(a);
            }
        }
        return filteredFiles;
    }
public:
    supervisor(){
        nf = next_fit();
        ffd = first_fit_decreasing();
        bfd = best_fit_decreasing();
        /*for(string distrib : distributions){
            for(int numb : numbers){
                results.insert({distrib, {numbers, {"time", -1.0}}});
            }
        }

        double time = -1;
        int space = -1;
        */
    }

    void runTrials(string name, string algorithm, int number, long double& meanTime, long double& meanBinUsed){
        bool nameOK, algorithmOK, numberOK;
        vector<string> filenames;
        string filename;
        vector<double> cvsData;
        vector<long double> times;
        vector<int> bins;

        if (find(distributions.begin(), distributions.end(), name) != distributions.end()) nameOK=true;
        else nameOK=false;
        if (find(algorithms.begin(), algorithms.end(), algorithm) != algorithms.end()) algorithmOK=true;
        else algorithmOK=false;
        if (find(numbers.begin(), numbers.end(), number) != numbers.end()) numberOK=true;
        else numberOK=false;

        if(nameOK && algorithmOK && numberOK){
            if(algorithm == "next_fit"){
                currentAlgo = &nf;
            }
            else if (algorithm == "first_fit_decreasing"){
                currentAlgo = &ffd;
            }
            else if (algorithm == "best_fit_decreasing"){
                currentAlgo = &bfd;
            }
            else{
                cout<<"Non dovrebbe essere possibile arrivare qui";
                return;
            }
            filenames = searchFilenames(name, number);
            if(!(filenames.size()==3)){
                cout<<"Mi aspettavo 3 trial ma ho avuto un numero diverso.";
                return;
            }

            times.clear();
            bins.clear();
            for(string filename : filenames ){
                cvsData = read_csv(filename);
                currentAlgo->run(cvsData);
                times.push_back(currentAlgo->give_time());
                int binsUsed = currentAlgo->give_bins_used();
                bins.push_back(currentAlgo->give_bins_used());
            }
            meanTime = (times[0]+times[1]+times[2])/3;
            meanBinUsed = (bins[0]+bins[1]+bins[2])/3;
            //cout<<algorithm <<" , " <<name <<" , "<<to_string(number) <<"    - mean time(micro): "<<meanTime<<"   ( t1="<<times[0]<<" "<<"t2="<<times[1]<<" "<<"t3="<<times[2]<<" )"<<endl;

        }
        else{
            cout<<"Some if the inserted Data is not valit. Check the corectness of name, algorithm and number inputs.";
        }
    }


};


#endif //UNTITLED_SUPERVISOR_H
