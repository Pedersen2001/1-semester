#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "Peter" "Bent" "Inge" "Anders" */
/* Fixed placement of the given names. */

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

  /* Print age array */
  printf("\n");
  {
    char *name[] = {"Peter", "Bent", "Inge", "Anders"};
    int i;

    for(i = 0; i < 4; ++i)
      printf("age_of_person[h(\"%s\")] = %d\n", name[i], age_of_person[h(name[i])]);
  }
  
  return EXIT_SUCCESS;
}

int h(char *name){
  if (are_strings_equal(name, "Peter" ))
    return 0;
  else if (are_strings_equal(name, "Bent"  ))
    return 1;
  else if (are_strings_equal(name, "Inge"  ))
    return 2;
  else if (are_strings_equal(name, "Anders"))
    return 3;
  else 
    return -1;
}

int are_strings_equal(char *str1, char *str2){
  return strcmp(str1, str2) == 0;
}


