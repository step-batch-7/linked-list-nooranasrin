#include<stdio.h>
#include<stdlib.h>
#include "list.h"

List_ptr create_list() {
  List_ptr list =  malloc(sizeof(List));

  if(list == NULL) {
    return list;
  }

  list->head = NULL;
  list->last = list->head;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value) {
  Node_ptr new_node = malloc(sizeof(Node));

  if(new_node == NULL) {
    return new_node;
  }

  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}


Status add_to_end(List_ptr list, int value) {
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  if(list->head == NULL) {
    list->head = new_node;
  } else {
    list->last->next = new_node;
  }
  
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value) {
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  if(list->head == NULL) {
    list->head = new_node;
    list->last = list->head;
  } else {
     new_node->next = list->head ;
    list->head = new_node;
  }

  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position) {
  if(position == 0) {
    return add_to_start(list, value);
  }

  if (position == list->count - 1) {
    return add_to_end(list, value);
  }

  int index = 0;
  Node_ptr pWalk = list->head;
  Node_ptr previous = pWalk;
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return Failure;
  }

  while (index != position)
  {
    previous = pWalk;
    pWalk = pWalk->next;
    index++;
  }

  new_node->next = previous->next;
  previous->next = new_node;
  list->count++;
  return Success;
}

void display(List_ptr list) {
  Node_ptr pWalk = list->head;

  while (pWalk != NULL) {
    printf("%d\n", pWalk->value);
    pWalk = pWalk->next;
  }
}