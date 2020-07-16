#include <iostream>
#include "bin.h"
#include "next_fit.h"
#include "first_fit.h"
#include "first_fit_decreasing.h"
#include "best_fit.h"
#include "best_fit_decreasing.h"
#include "supervisor.h"
#include <algorithm>

int main(){
    vector<string> distributions = {"uniform", "uniform_complementary", "gaussian", "exponential_decreasing", "exponential_decreasing_complementary", "exponential_increasing"};
    vector<string> algorithms = {"next_fit", "first_fit_decreasing", "best_fit_decreasing"};
    vector<int> numbers = {2000, 4000, 8000, 16000, 32000, 64000};//, 128000, 256000, 512000, 1024000};
    long double meanTime, meanBin;
    vector<long double> meanTimes;
    vector<long double> meanBins;
    supervisor sup = supervisor();


    /*      Known cases
    vector<string> knownDistributions = {"uniform_complementary","exponential_decreasing_complementary"};
    for(string name : knownDistributions) {  // I make the mean among all distributions
        cout<<endl<<"--- "<<name<<" ---"<<endl;
        for(int num : numbers){
            for(string algo : algorithms){
                sup.runTrials(name, algo, num, meanTime, meanBin);  // The runTrials give me the mean Time and Bins of all 3 trials
                cout<<algo<<"\t"<<to_string(num)<<" meanTime - "<<int(meanTime)<<"| \tbins - "<< int(meanBin)<<" / "<<to_string(num/2)<<endl;
            }
        }
    }*/





    /*      Eliminate the different distributions, making a mean of all of them*/
    for(int num : numbers){
        for(string algo : algorithms){
            meanTimes.clear();
            meanBins.clear();
            for(string name : distributions) {  // I make the mean among all distributions
                sup.runTrials(name, algo, num, meanTime, meanBin);  // The runTrials give me the mean Time and Bins of all 3 trials
                meanTimes.push_back(meanTime);
                meanBins.push_back(meanBin);
            }
            meanTime=0;
            for(auto time:meanTimes){   // Here I have the mean Times of all of the distributions, for the same num
                meanTime = meanTime + time;
            }
            meanBin = 0;
            for(auto bin:meanBins){     // Here I have the mean Bins of all of the distributions, for the same num
                meanBin = meanBin + bin;
            }
            meanTime = meanTime / meanTimes.size();
            meanBin = meanBin / meanBins.size();
            cout<<algo<<"\t"<<to_string(num)<<" meanTime - "<<int(meanTime)<<"\tbins - "<< int(meanBin)<<endl;
        }
    }




    /*      CHECK THE DIFFERENCE BETEWEN DIFFERENT DISTRIBUTIONS TIMES OF THE SAME ALGORITHM WITH THE SAME INPUT
    for(int num : numbers){
        cout<<"------"<<to_string(num)<<"------"<<endl;
        for(string algo : algorithms){
            cout<<"------"<<algo<<"------"<<endl;
            for(string name : distributions) {
                sup.runTrials(name, algo, num);
            }
            cout<<endl<<endl<<endl;
        }
    }*/




    return 0;
}
