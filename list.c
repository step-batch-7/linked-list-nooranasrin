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

Status add_unique(List_ptr list, int value) {
  Node_ptr pWalk = list->head;

  while (pWalk != NULL) {
    if(pWalk->value == value) {
      return Failure;
    }
    pWalk = pWalk->next;
  }

  return add_to_end(list, value);
}

Status remove_from_start(List_ptr list) {
  Node_ptr head = list->head;
  list->head = list->head->next;
  list->count--;
  free(head);
  return Success;
}

Status remove_from_end(List_ptr list) {
  if(list->head->next == NULL) {
    return remove_from_start(list);
  }

  Node_ptr pWalk = list->head;
  Node_ptr previous = pWalk;

  while (pWalk->next != NULL) {
    previous = pWalk;
    pWalk = pWalk->next;
  }

  previous->next = NULL;
  list->last = previous;
  list->count--;
  free(pWalk);
  return Success;
}

Status remove_at(List_ptr list, int position) {
  if(position == 0) {
    return remove_from_start(list);
  }

  if (position == list->count - 1) {
    return remove_from_end(list);
  }

  Node_ptr pWalk = list->head;
  Node_ptr previous = pWalk;
  int index = 0;

  while (index != position) {
    previous = pWalk;
    pWalk = pWalk->next;
    index++;
  }

  previous->next = pWalk->next;
  list->count--;
  free(pWalk);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value) {
  Node_ptr pWalk = list->head;
  Node_ptr previous = pWalk;

  if(list->head->value == value) {
    return remove_from_start(list);
  }

  while (pWalk->value != value)
  {
    previous = pWalk;
    pWalk = pWalk->next;
  }

  previous->next = pWalk->next;
  list->count--;
  free(pWalk);
  return Success;
}

Status remove_all_occurrences(List_ptr list, int value) {
  Node_ptr pWalk = list->head;
  int status;

  while(pWalk != NULL) {
    if(pWalk->value == value) {
      status =  remove_first_occurrence(list, value);
      pWalk = list->head;
    } else {
      pWalk = pWalk->next;
    }
  }
  return status;
}

Status clear_list(List_ptr list) {
  Node_ptr pWalk = list->head;
  int status;

  while(pWalk != NULL) {
    status =  remove_from_start(list);
    pWalk = list->head;
  }
  return status;
}

Status is_present(List_ptr list, int value) {
  Node_ptr pWalk = list->head;

  while(pWalk != NULL) {
    if(pWalk->value == value) {
      return Success;
    }
    pWalk = pWalk->next;
  }
  return Failure;
}

void display(List_ptr list) {
  Node_ptr pWalk = list->head;

  while (pWalk != NULL) {
    printf("%d\n", pWalk->value);
    pWalk = pWalk->next;
  }
}

void destroy_list(List_ptr list) {
  Status status = clear_list(list);
  free(list);
}