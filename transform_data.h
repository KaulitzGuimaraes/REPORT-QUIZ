//
//  transform_data.h
//  km
//
//  Created by Kaulitz Guimarães on 17/07/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#ifndef transform_data_h
#define transform_data_h
#include "read_dataset.h"
#include <stdio.h>
#include <string.h>

static const char* gender_type[] = {"female","male", "other"};

static const char* age_ranges[]  = {"young", "adult","elder"};


static const char* musical_taste [] = {"rock","pop","gospel"};


static const char* favorite_food[] = {"junk","south", "comfort"};

void count_data(sample* s[],long amount_data,int **count_gender, int** count_age, int** count_musical, int** count_fav_food );
void mean_weight(sample *s[],long amount_data, double* mean);
void write_data_file(dataset ds);

void write_file(dataset ds);

#endif /* transform_data_h */
