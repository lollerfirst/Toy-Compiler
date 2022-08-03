#pragma once

#include "RE_parser.h"

#define _ASCII_LEN 128

typedef struct _dfa{
    int* transition_table;
    int* final_states;
} DFA;

DFA DFA_build(const Node* const _node);
