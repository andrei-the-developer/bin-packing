//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_FIRST_FIT_DECREASING_H
#define UNTITLED_FIRST_FIT_DECREASING_H

#include <algorithm>
#include "IBinPack.h"

class first_fit_decreasing : public IBinPack{
public:
    first_fit_decreasing(double p_max_bin_size = 1): IBinPack(p_max_bin_size){}

    void apply_algorithm(vector<double> numbers, double bin_max_size = 1){
        sort(numbers.begin(), numbers.end());
        int i,j;
        for (i=0;i<numbers.size();i++){
            bool inserted = false;
            for(j=0; j<bins.size(); j++){
                if(bins[j].get_free_space() > numbers[i]){
                    bins[j].add(numbers[i]);
                    inserted=true;
                }
            }
            if(inserted == false){
                bin a = bin(bin_max_size);
                a.add(numbers[i]);
                bins.push_back(a);
            }
        }
    }

};
#endif //UNTITLED_FIRST_FIT_DECREASING_H
