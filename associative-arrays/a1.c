#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "Peter" "Bent" "Inge" "Anders" */
/* A variant where h is calculated from som text string */
/* Two names may eaily collide, and we loose data about a person */

#define MAX_PERSON 4
#define NAME_LENGTH_MAX 20
#define NON_EXISTING -1

int h(char *name);
int are_strings_equal(char *str1, char *str2);

int main(void) {
  int age_of_person[MAX_PERSON];
  char name[NAME_LENGTH_MAX];
  int age, index, done = 0, i;

  /* age_of_person initialization */
  for(i = 0; i < MAX_PERSON; ++i){
    age_of_person[i] = NON_EXISTING;
  }

  /* prompt for names and ages, and insert age of person */  
  while(!done){
    printf("Enter a name and age: ");
    scanf(" %s %d", name, &age);
    done = are_strings_equal(name, "exit") || age < 0;
    if (!done){
      index = h(name);
      printf("Index: %d\n", index);
      if (index >= 0)
        age_of_person[index] = age;
    }
  }
 
  /* Print array */ 
  for(i = 0; i < MAX_PERSON; ++i)
    printf("%d: %d\n", i, age_of_person[i]);
  
  return EXIT_SUCCESS;
}

int h(char *name){
  int name_len = strlen(name);
  int sum = name[0] + name[name_len/2] + name[name_len-1];
  return sum % MAX_PERSON;
}

int are_strings_equal(char *str1, char *str2){
  return strcmp(str1, str2) == 0;
}
