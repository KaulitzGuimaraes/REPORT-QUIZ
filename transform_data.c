//
//  transform_data.c
//  km
//
//  Created by Kaulitz Guimarães on 17/07/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "transform_data.h"


void count_data(sample* s[],long amount_data,int **count_gender, int** count_age, int** count_musical, int** count_fav_food ){
    int i;
 
    for (i = 0 ; i< amount_data; i++) {
        *count_age[s[i]->age_range] = ++*count_age[s[i]->age_range];
     
        *count_gender[s[i]->gender] =  ++*count_gender[s[i]->gender];
      
        *count_musical[s[i]->musical_taste] = ++*count_musical[s[i]->musical_taste];
      *count_fav_food[s[i]->favorite_food] = ++*count_fav_food[s[i]->favorite_food];
      
    }
}
void mean_weight(sample *s[],long amount_data, double* mean){
    int i;
    *mean =0;
    for (i = 0 ; i< amount_data; i++) {
        *mean += s[i]->weight;
    }
    *mean = *mean/amount_data;
}
void read_types_count (char* type[], int** count, long amount,FILE* file){
    int i =0;
    for (i = 0 ; i< amount; i++) {
        fprintf(file, "Number of %s : %i\n",type[i],*count[i]);
    }
    
}
void write_data_file(dataset ds){
    FILE *file = fopen("Search report.txt", "w");
    if (file == NULL){
        printf("File can't be open\n");
        
    }
    printf("Writing report\n");
    fputs("----------  Search Report ---------- \n", file);
    fputs("\n\n", file);
    int **gender = malloc(3*sizeof(int*));
    
    int **age =malloc(3*sizeof(int*));
    int **musical= malloc(3*sizeof(int*));
    
    int **fav =malloc(3*sizeof(int*));
    int i;
    for (i =0; i<3;i++){
        gender[i] = malloc(sizeof(int));
        *gender[i]=0;
        age[i] = malloc(sizeof(int));
        *age[i]=0;
        musical[i] = malloc(sizeof(int));
        *musical[i]=0;
        fav[i] = malloc(sizeof(int));
        *fav[i]=0;
        
    }
    double *weight_mean = malloc(sizeof(double));
   
    
    count_data(ds.samples, ds.amount_samples, gender, age, musical, fav);
    mean_weight(ds.samples, ds.amount_samples, weight_mean);
    fputs("=====================================\n", file);
    fprintf(file, "Weight mean : %lf\n",*weight_mean);
    fputs("=====================================\n", file);
    read_types_count(gender_type, gender, 3, file);
     fputs("=====================================\n", file);
     read_types_count(age_ranges, age, 3, file);
    fputs("=====================================\n", file);
    read_types_count(musical_taste, musical, 3, file);
    fputs("=====================================\n", file);
    read_types_count(favorite_food, fav, 3, file);
    fputs("=====================================\n", file);
    fclose(file);
    
}


void write_file(dataset ds){
    
    //printf("File opended with sucdcess\n");
    write_data_file( ds);
  
  
}


