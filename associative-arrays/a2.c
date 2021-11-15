#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple table solution with both insertion and retrieval, linear search */
/* Assume that there always is enough room for new elements in the table */

#define MAX_PERSON 8         /* Higher than before */
#define NAME_LENGTH_MAX 20
#define NON_EXISTING -1
#define NOT_FOUND -1

struct person_data{
  char name[NAME_LENGTH_MAX];
  int age;
};
typedef struct person_data person_data;


int insert_person_age(char *name, int age, person_data age_of_person[]);
int index_of_person(char *name, person_data age_of_person[]);
int is_empty(person_data pd);
int next_index(int i);

int main(void) {
  person_data age_of_person[MAX_PERSON];
  char name[NAME_LENGTH_MAX];
  int age, index, done = 0, i;

  /* age_of_person initialization */
  for(i = 0; i < MAX_PERSON; ++i){
    strcpy(age_of_person[i].name, "");
    age_of_person[i].age = NON_EXISTING;
  }

  /* prompt for names and ages, and insert age of person */
  while(!done){
    printf("Enter a name and age (type exit to exit): ");
    scanf(" %s %d", name, &age);
    done = strcmp(name, "exit") == 0;
    if (!done){
      index = insert_person_age(name, age, age_of_person);
      printf("Index: %d\n", index);
    }
  }
 
  /* Print array */
  for(i = 0; i < MAX_PERSON; ++i)
    printf("%d: %s, age: %d\n", i, age_of_person[i].name, age_of_person[i].age);

  /* Find index of name, prompt for names */
  done = 0;
  while(!done){
    printf("Enter a name (type exit to exit): ");   
    scanf(" %s", name);  
    done = strcmp(name, "exit") == 0;
    if (!done){
      index = index_of_person(name, age_of_person);
      printf("Index of %s: %d ", name, index);
      if (index != NOT_FOUND)
        printf("age: %d\n", age_of_person[index].age);
      else
        printf("\n");
    }
  }
  
  return EXIT_SUCCESS;
}


int insert_person_age(char *name, int age, person_data age_of_person[]){
  int index;

  index = 0; 
  while(!is_empty(age_of_person[index]) && strcmp(name, age_of_person[index].name) != 0)
    index = next_index(index);

  if (is_empty(age_of_person[index])){
    /* index has empty space */
    age_of_person[index].age = age;
    strcpy(age_of_person[index].name, name);    
  }
  else if (strcmp(name, age_of_person[index].name) == 0){
    age_of_person[index].age = age;
  }
  else{
    printf("Should not happen");
    exit(EXIT_FAILURE);
  }

  return index;
}

int next_index(int i){
  return (i < MAX_PERSON - 1) ? i + 1 : 0;
}

/* Return index of person with name, or NOT_FOUND */
int index_of_person(char *name, person_data age_of_person[]){
  int i = 0;
  while(!is_empty(age_of_person[i]) && 
        strcmp(name, age_of_person[i].name) != 0) /* No name hit */
    i = next_index(i);

  /* At index i: empty or name match */
  if (is_empty(age_of_person[i]))
    return NOT_FOUND;
  else if (strcmp(name, age_of_person[i].name) == 0)
    return i;
  else 
    return NOT_FOUND; /* Should not happen */
}

int is_empty(person_data pd){
  return (pd.age == NON_EXISTING);
}
