/*
 *  A recursive-descent parser for regular expressions.
 *
 *  Regular Expression grammar ('#' is the empty string):
 *  RE  ::= # | symbol | RE + RE | RE RE | RE * | ( RE ).
 *
 *  Left recursion removal:
 *  RE  ::= # | # RE' | symbol | symbol RE' | ( RE ) | ( RE ) RE',
 *  RE' ::= + RE | + RE RE' | RE | RE RE' | * | * RE'.
 */

#pragma once

#include <stdbool.h>
#include <stdio.h>


#define MAX_CONTENT_LEN 16 // Max characters of the content of a node.
#define MAX_CHILDS 4 // Max number of childs for a variable in the parse tree.
#define INDENTATION 1 // Child indentation when the parse tree is printed.

/**** Parse tree functions and data structures. ****/

typedef struct _node
{
  char content   [MAX_CONTENT_LEN];
  struct _node * childs [MAX_CHILDS];
} Node;

Node * node_new(void);

void node_init(Node * const p_node, const char *s);

void node_add_child(Node * const p_node, Node * const p_child);

void node_free(Node * p_node);

void node_free_last_child(Node * const p_node);

void node_free_childs(Node * const p_node);

void node_print (const Node * const p_node, int indent);

void node_save (Node *p_node, FILE *fp, int indent);

/**** Terminals. ****/

bool epsilon(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool symbol(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool lpar(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool rpar(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool star(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool plus(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

/**** Variables. ****/

bool RE_prime(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool RE(
  const char *rexpr,
  const int *p_idx_int,
  int * const p_idx_out,
  Node * const p_node);

bool parse (
  const char *rexpr,
  Node * const p_node);

/**** PARSER ****/
bool parse (const char *reg_expr, Node *p_node);
