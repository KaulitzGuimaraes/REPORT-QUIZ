/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   read_dataset.h
 * Author: v188530
 *
 * Created on 23 de Maio de 2018, 12:07
 */


#ifndef read_dataset_h
#define read_dataset_h
#include <stdio.h>
#include <stdlib.h>
     
   typedef struct sample{
        int gender; // 0 = female; 1 = male; 2 = other
        int age_range; // 0 = young; 1 = adult; 2 = elder
        double weight;
        int musical_taste; // 0 = rock; 1 = pop; 2 = gospel, 3 = country, 4 =  electro_house
        int favorite_food; // 0 = junk; 1 = south; 2 = confort, 3 = spice
        
    }sample;
   typedef struct dataset{
        long amount_samples;
        long current_pos_amount;
        sample **samples;
    }dataset;
    
    FILE* read_file(char* file_name);
    void read_sample(  dataset *ds, FILE *dataset_file);
    sample* create_sample(int gender, int age_range, double weight, int musical_taste,int favorite_food);
    void add_sample_to_dataset(sample* sample_add, dataset* dataset_add );
    void print_sample(sample s);
    void print_data_set(dataset ds);


#endif /* READ_DATASET_H */

