//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_BEST_FIT_H
#define UNTITLED_BEST_FIT_H
#include "IBinPack.h"



class best_fit : public IBinPack{
public:
    best_fit(double p_max_bin_size = 1): IBinPack(p_max_bin_size){}

    void apply_algorithm(vector<double> numbers, double bin_max_size = 1){
        int i,j, waste, min_waste, min_pos;
        add_empty_bin();
        for (i=0;i<numbers.size();i++){     // For each input number
            min_pos= -1;
            min_waste = max_bin_size + 1;
            for(j=0; j<bins.size(); j++) {  // Go through every bin
                if (bins[j].get_free_space() > numbers[i]) {    // If there is space in the bin for the current number
                    waste = bins[j].get_free_space() - numbers[i];  // Calculate the waste(aka space remained after I would insert the number)
                    if (waste < min_waste) {    // remember the position of the bin that created the minimum waste
                        min_pos = j;
                        min_waste = waste;
                    }
                }
            }
            if(min_pos != -1){  // If I could find a bin that minimizes the waste with the current number
                bins[min_pos].add(numbers[i]);  //Add the number to that bin
            }
            else{   //Otherwise it means the current number is too big for all the bins
                add_empty_bin();
                bins[bins.size()-1].add(numbers[i]);    //So I create a new bin for it
            }

        }
    }

};


#endif //UNTITLED_BEST_FIT_H
