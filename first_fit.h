//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_FIRST_FIT_H
#define UNTITLED_FIRST_FIT_H
#include "IBinPack.h"

class first_fit : public IBinPack{
public:
    first_fit(double p_max_bin_size = 1): IBinPack(p_max_bin_size){}

    void apply_algorithm(vector<double> numbers, double bin_max_size = 1){
        int i,j;
        add_empty_bin();
        for (i=0;i<numbers.size();i++){     // for each input number
            bool inserted = false;
            for(j=0; j<bins.size(); j++){   //from the first bin to the last
                if(bins[j].get_free_space() > numbers[i]){  //I check if there is space for the unput number. If there is, I insert the element
                    bins[j].add(numbers[i]);
                    inserted=true;
                }
            }
            if(inserted == false){      // Otherwise I create a new bin and insert it there
                add_empty_bin();
                bins[bins.size()-1].add(numbers[i]);
            }
        }
    }

};


#endif //UNTITLED_FIRST_FIT_H
