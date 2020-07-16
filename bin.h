//
// Created by kortexar on 07/07/20.
//

#ifndef UNTITLED_BIN_H
#define UNTITLED_BIN_H

#include <vector>

using namespace std;

class bin {
private:
    double occupied_space=0;
    double max_space;
    vector<double> elements;

public:
    bin(double p_max_space){
        max_space = p_max_space;
        occupied_space = 0;
        elements.clear();
    }
    bin(){
        max_space = 1;
        occupied_space = 0;
        elements.clear();
    }

    double get_occupied_space(){return occupied_space;}
    double get_free_space(){
        double freespace =  max_space - occupied_space;
        return freespace;
    }
    int get_number_of_elements(){return elements.size();}

    void add(double new_element){
        if (occupied_space + new_element <= max_space){
            elements.push_back(new_element);
            occupied_space = occupied_space + new_element;
        }
        else{
            throw runtime_error("You are trying to ad inside a bind an element which does not fit inside.");
        }
    }
    void print_elements(){
        for (int i=0; i< elements.size();i++){
            cout<<elements[i]<<"  ";
        }
    }
};


#endif //UNTITLED_BIN_H
