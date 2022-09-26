# Pointers

## Introduction
Les pointers sont des variables qui ont la particularité de stocker l'adresse mémoire d'une autre variable. Pour déclarer un pointer, il faut utiliser l'opérateur **\***.

```c
// Déclaration d'une variable
int a;
// Déclaration d'un pointer
int *p;
```
*C* nous impose de donner un type cohérent à nos pointer. Si le pointer doit pointer une variable de type *int*, il doit être de type *\* int*.
Comme nous l'avons vu, un pointer stock l'adresse d'une variable. Pour avoir accès à l'adresse, nous devons utiliser l'opérateur *&*. Voici comment ajouter l'adresse d'une variable à un pointer :
```c
int a;
int *p;
// Nous ajoutons l'adresse de a dans le pointer p
p = &a;
```

Nous pouvons afficher l'adresse d'une variable avec cet opérateur :
```c
#include <stdio.h>

int main(void)
{
	int a;
	
	printf("%p\n", &a);
	return (0);
}
```
```bash
0x7ffee0c47ab4
```
Quand nous exécutons ce programme, le terminal nous affiche l'adresse mémoire où esst stocké la variable *a*.
Si nous affichons la valeur du pointer, le résultat est aussi l'adresse de la variable *a*.
```c
#include <stdio.h>

int main(void)
{
	int a;
	int *p;

	p = &a;
	printf("%p\n", p);
	return (0);
}
```
```bash
0x7ffcdf0c6d0c
```
Nous pouvons constater que l'adresse à changer entre les deux exemples. C'est parce que nous avons exécuté le programme deux fois. C'est le système d'exploitation qui gère l'adressage et peut donc fournir des adresses différentes entre chaque exécution.
Nous savons maintenant comment faire pointer un pointer sur une variable. Maintenant, nous allons voir comment changer la valeur de la variable en passant par le pointer. Pour se faire, nous allons utiliser l'opérateur *\** :
```c
#include <stdio.h>

int main(void)
{
	int a = 20;
	int *p = &a;

	//Nous changeons la valeur de la variable via le pointer
	printf("a = %d\n", a);
	return (0);
}
```
```bash
a = 42
```
Nous venons de changer la valeur de *a* via son pointer. Cette opération s'appel le **déréférencement**.

## Types de pointer, void pointer et arithmétique des pointers
Comme nous l'avons vu, un pointer a un type. Si nous voulons pointer un *int* nous devons créer un pointer qui a le type *\* int*. *C* demande que nous déclarions un type pour un pointer car ils ne permette pas seulement de stocké l'adresse d'une variable mais aussi d'accéder à sa valeur (déréférencer). Lorsque nous allons chercher la valeur qui correspond à une adresse, le compilateur doit savoir comment interpréter la donnée. 


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzODczNDQwNzksNTQ1NzYxMjY5LDUyMT
U1Mjg5XX0=
-->