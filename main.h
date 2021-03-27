//
// Created by Ferrum on 24.03.2021.
//

#ifndef HOMEWORK2_MAIN_H
#define HOMEWORK2_MAIN_H

#include <iostream>
#include <string>

using namespace std;

struct Dnode{
    string model;
    string country;
    int year=0;
    Dnode *prev, *next;
};

struct Tnode{
    string model;
    Dnode *head;
    Tnode *next;
};

void create_list(Dnode *&L, int n);

void output_from_first_to_last(Dnode *&L);

void output_from_last_to_first(Dnode *&L);

Dnode* find_by_value(Dnode *&L);

void insert_new_node(Dnode *&L);

void new_Dnode_with_model(Dnode *&L, Tnode *&L1);

void del_model(Dnode *&L, Tnode *&q, string value);

void menu();

#endif //HOMEWORK2_MAIN_H
