/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: v188530
 *
 * Created on 23 de Maio de 2018, 12:06
 */


#include "read_dataset.h"
#include "transform_data.h"

/*
 *
 */
int main(int argc, char** argv) {
    
    dataset ds;
     FILE *dataset_file = read_file("/Users/Kaulitz/Downloads/km/km/dataset.txt");
    read_sample(&ds,dataset_file);
    print_data_set(ds);
     write_file(ds);
  
    return (EXIT_SUCCESS);
}


