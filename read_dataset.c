/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "read_dataset.h"

  FILE* read_file(char* file_name){
      FILE* ds = fopen(file_name,"r");
      if(ds == NULL){
          printf("File can't be open\n");
          return NULL;
      }
       printf("File opened with success\n");
      return ds;
  }
  void read_sample( dataset *ds,FILE *dataset_file){
      ds->current_pos_amount= 0;
      fscanf(dataset_file,"%ld",&ds->amount_samples);
        
      char header[100];
       fscanf(dataset_file,"%s",header);
      int gender,age_range,musical_taste,favorite_food;
    
      double weight;
      sample* sp;
     while(!feof(dataset_file)){
         fscanf(dataset_file,"%d,%d,%lf,%d,%d",&gender,&age_range,&weight,&musical_taste,&favorite_food);
         sp = create_sample( gender,  age_range,  weight,  musical_taste, favorite_food);
         add_sample_to_dataset(sp,ds);
           
            
     }
  }
  sample* create_sample(int gender, int age_range, double weight, int musical_taste,int favorite_food){
      sample *sp = malloc(sizeof(sample));
      sp->gender = gender;
      sp->age_range = age_range ;
      sp->weight = weight;
      sp->musical_taste = musical_taste;
      sp->favorite_food = favorite_food;
      
      return sp;
  }
  void add_sample_to_dataset(sample* sample_add, dataset *dataset_add ){
      if(dataset_add->samples == NULL){
          dataset_add->samples = malloc(dataset_add->amount_samples * sizeof(sample*));
      }
      dataset_add->samples[dataset_add->current_pos_amount] = sample_add;
      dataset_add->current_pos_amount++;
  }


void print_sample(sample s){
    /*
     int gender; // 0 = female; 1 = male; 2 = other
     int age_range; // 0 = young; 1 = adult; 2 = elder
     double weight;
     int musical_taste; // 0 = rock; 1 = pop; 2 = gospel, 3 = country, 4 =  electro_house
     int favorite_food;
     */
    printf("%i\t%i\t%f\t%i\t%i\n",s.gender,s.age_range,s.weight,s.musical_taste,s.favorite_food);
}

 void print_data_set(dataset ds){
    int i;
    for (i = 0; i< ds.amount_samples; i++) {
        print_sample(*ds.samples[i]);
    }
    
    
}
