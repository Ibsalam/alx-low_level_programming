#ifndef _DOG_H
#define _DOG_H

/**
 * struct dog - A structure to represent a dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: struct  project
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner)
#endif
