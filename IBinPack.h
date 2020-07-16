//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_IBINPACK_H
#define UNTITLED_IBINPACK_H
#include "bin.h"
#include <iostream>
#include "helper.h"

class IBinPack {
protected:
    vector<bin> bins;
    double max_bin_size;
    long double time_needed_for_algorithm;


public:
    virtual void apply_algorithm(vector<double> numbers, double bin_max_size = 1){cout<<"LOLL";};
    IBinPack(double p_max_bin_size = 1) {
        max_bin_size=p_max_bin_size;
    }

    void run(vector<double> numbers, double bin_max_size = 1){
        bins.clear();
        timer::start();
        apply_algorithm(numbers, bin_max_size);
        time_needed_for_algorithm = timer::stop();
    }


    void add_empty_bin(){
        bin new_bin = bin(max_bin_size);
        bins.push_back(new_bin);
    }

    void tell_elements(){
        cout<<"Here us the list of elents inside the bins:"<<endl;
        for (int i=0;i<bins.size();i++){
            cout <<"BIN "<<i <<": ";
            bins[i].print_elements();
            cout <<endl;
        }
    }

    int give_bins_used(){
        return bins.size();
    }

    long double give_time(){
        return time_needed_for_algorithm*1000000;   //gives the time in microseconds
    }
};


#endif //UNTITLED_IBINPACK_H
