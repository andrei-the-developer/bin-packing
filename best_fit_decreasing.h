//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_BEST_FIT_DECREASING_H
#define UNTITLED_BEST_FIT_DECREASING_H
#include "IBinPack.h"
#include <algorithm>

int binarySearchForClosestMinor(vector<double> arr, int left, int right, double num){    // Gets you the position of the biggest element that is less than num
    // The arr must be ordered in decreasing  order, from highest(left) to lowest(right) 10,9,8,7,..0,1.
    int mid;
    if (left < right){
        mid = (left + right) / 2;
        if (num >= arr[mid]) { //  x < arr[mid]
            return binarySearchForClosestMinor(arr, left, mid, num);
        }
        else{// #arr[mid] < x
            return binarySearchForClosestMinor(arr,mid + 1, right, num);
        }
    }
    else{ //left and right should be equal
        return left;
    }
}
bool existsClosestMinor(vector<double> ordered_numbers, double num){
    if(ordered_numbers.size() > 0){
        if(ordered_numbers[ordered_numbers.size()-1] > num) return false;   //It means that the smallest element in the array is bigger than num(so that the free space we want to occupy)
        else return true;
    }
    else {
        return false;
    }
}

class best_fit_decreasing : public IBinPack{
    /*
     * There are 2 ways of implementing this algorithm
     * (1) This algorithm looks in the input numbers array for the one that best fits the current bin.
     * In a few words, it puts in the last bin the number that fits better.
     *
     * (2) Instead of ordering the numbers and then search the one that fits better, we could let the numbers non ordered,
     * and put the bins in a tree structure, so we can insert the next number in the bin that fits better.
     * In a few words, we put the next number in the bin that fits better.
     *
     * This algorithm uses the method (1)
     *
    */
public:
    best_fit_decreasing(double p_max_bin_size = 1): IBinPack(p_max_bin_size){}

void apply_algorithm(vector<double> numbers, double bin_max_size = 1){
        //Since it is df decreasing, I must sort the array in decreasing order
        sort(numbers.begin(), numbers.end(),greater<double>());
        if (numbers[0]>bin_max_size){
            throw runtime_error("There is an element in your list that is bigger than the bin capacity.");
        }
        int lastIndex;
        double last_bin_free_space;
        add_empty_bin();
        int index_of_closest_minor;
        bool still_free_space = true;
        while (!numbers.empty()){
            lastIndex = int(bins.size()-1);
            last_bin_free_space = bins[lastIndex].get_free_space();
            still_free_space = existsClosestMinor(numbers, last_bin_free_space );
            if(!still_free_space){
                bin newBin = bin();
                newBin.add(numbers[0]);
                numbers.erase(numbers.begin());
                bins.push_back(newBin);
            }
            else {
                while (still_free_space) {
                    index_of_closest_minor = binarySearchForClosestMinor(numbers, 0, numbers.size()-1,
                                                                         bins[bins.size()-1].get_free_space());
                    bins[bins.size()-1].add(numbers[index_of_closest_minor]);
                    numbers.erase(numbers.begin() + index_of_closest_minor);
                    still_free_space = existsClosestMinor(numbers,  bins[bins.size()-1].get_free_space());
                }
            }
        }
}
};


#endif //UNTITLED_BEST_FIT_DECREASING_H
