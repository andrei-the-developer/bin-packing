//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_NEXT_FIT_H
#define UNTITLED_NEXT_FIT_H
#include "IBinPack.h"

class next_fit : public IBinPack{
public:
    next_fit(double p_max_bin_size = 1): IBinPack(p_max_bin_size){}

    void apply_algorithm(vector<double> numbers, double bin_max_size = 1){
        int i;
        add_empty_bin();
        for (i=0;i<numbers.size();i++){     // prendi tutti i numeri in ordine
            if(bins[bins.size()-1].get_free_space() > numbers[i]){    //se c'e spazio nel ultimo bin, lo aggiungi
                bins[bins.size()-1].add(numbers[i]);
            }
            else{               // Altrimenti crei un nuovo bin
                bin a = bin(bin_max_size);
                a.add(numbers[i]);
                bins.push_back(a);
            }
        }
    }
};


#endif //UNTITLED_NEXT_FIT_H
