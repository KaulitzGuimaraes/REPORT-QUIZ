/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   k_means.h
 * Author: v188530
 *
 * Created on 23 de Maio de 2018, 13:36
 */

#ifndef K_MEANS_H
#define K_MEANS_H
#include "read_dataset.h"
typedef struct cluster {
    sample* value_cluster;
}cluster;
typedef struct group{
    int num_group;
    cluster group_cluster;
    sample** samples;
}group;
typedef struct group{
    int num_cluster;
    group** groups;
}group;
double distance(sample* cluster, sample* sample_calc);
void add_sample_to_group(sample* sample_add, group* gp );
void re_calculate_cluster_value(group* gp);

#endif /* K_MEANS_H */

