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

	// Nous changeons la valeur de la variable via le pointer
	printf("a = %d\n", a);
	return (0);
}
```
```bash
a = 42
```

Nous venons de changer la valeur de *a* via son pointer. Cette opération s'appel le **déréférencement**.

## Types de pointer, void pointer et arithmétique des pointers
Comme nous l'avons vu, un pointer a un type. Si nous voulons pointer un *int* nous devons créer un pointer qui a le type *\* int*. *C* demande que nous déclarions un type pour un pointer car ils ne permette pas seulement de stocké l'adresse d'une variable mais aussi d'accéder à sa valeur (déréférencer). Lorsque nous allons chercher la valeur qui correspond à une adresse, le compilateur doit savoir comment interpréter la donnée. En effet, un *int* ne prend pas la même place qu'un *char* et n'est pas stocké pareil qu'un *float*.

Nous avons vu que les pointer avaient des types. Et comme nous le savons, les types ne prennent pas le même nombre de bytes pour stocker l'information. Un *int* prend 4 bytes (sur une architecture 64 bites) alors qu'un *char* ne prend que 1 bytes. Pour connaitre la taille d'un type, nous pouvons utiliser l'opérateur *sizeof()*.

```c
#include <stdio.h>

int main(void)
{
	printf("size of int : %ld bytes.\n", sizeof(int));  
	printf("size of char : %ld bytes.\n", sizeof(char));  
	printf("size of float : %ld bytes.\n", sizeof(float));  
	printf("size of double : %ld bytes.\n", sizeof(double));  
	return  0;
}
```
```bash
size of int : 4 bytes.  
size of char : 1 bytes.  
size of float : 4 bytes.  
size of double : 8 bytes.
```

# L'arithmétique
Nous pouvons faire des opérations sur les pointer, nous pouvons les additionner ou lui soustraire un entier. Comme nous venons de le voir que les types prennent différents espaces dans la mémoire, nous avons les outils pour comprendre l'arithmétique des pointers.

Si nous avons un pointer sur *int* et que nous lui ajoutons 1, le résultat va être le prochain *int* disponible dans la mémoire. Nous savons qu'un *int* prend 4 bytes de mémoire, si nous lui ajoutons 1, il pointera sur l'adresse de l'*int* suivant (qui se trouve 4 bytes plus loin).

```c
#include <stdio.h>

int main(void)
{
	int a = 42;
	int *p = &a;

	printf("Address = %p, value = %d\n", (p), *(p));
	printf("Address = %p, value = %d\n", (p + 1), *(p + 1));
	return (0);
}
```
```bash
Address = 0x7ffe85ee457c, value = 42  
Address = 0x7ffe85ee4580, value = -2047982212
```

Ici, nous pouvons constater que nous affichons l'adresse et la valeur de la variable *a* au travers d'un pointer. Et lorsque nous ajoutons 1 au pointer, l'adresse change et elle change de exactement 4 bytes (en hexadécimal). La valeur aussi change, ici, elle prend la valeur du prochain *int* dans la mémoire et vu que ce *int* n'est pas réservé par une variable, nous récupérons une données aléatoire stockée en mémoire. 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE1MDgxODk3MzQsLTE1NzU2ODQ2MzQsLT
EzNjE3Njg3NzcsNTQ1NzYxMjY5LDUyMTU1Mjg5XX0=
-->