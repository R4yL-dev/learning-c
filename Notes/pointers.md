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

### L'arithmétique
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

### Void pointer
Nous avons la possibilité de créer des pointers de type *void* (aucun type). Vu que nous ne donnons pas de type au pointer, nous ne pouvons le déréférencer. Nous ne pouvons pas non plus faire d’arithmétique dessus car cela demande de pouvoir déréférencer le pointer. Nous en verrons plus sur les *void pointer* plus loin dans ce document.

## Pointer to pointer
Un pointer est comme une variable classique, ce qui veut dire qu'il possède une adresse mémoire. Nous pouvons stocker son adresse dans un autre pointer, un pointer de pointer. Nous avons vu qu'un pointer devait avoir un type cohérent avec le type de la variable pour la quel nous voulons stocké l'adresse mémoire. Pour un pointer de pointer c'est le même chose. 

```c
#include <stdio.h>

int main(void)
{
	int a = 42;
	int *p1 = &a;
	// Déclaration d'un pointer de pointer sur int
	int **p2 = &p1;

	printf("Value of pointer to pointer on int : %d\n", *(*(p2)));
	return (0);
}
```
```bash
Value of pointer to pointer on int : 42
```

Ici, nous voyons bien que nous déclarons *p2* avec le pointer sur pointer sur int (*int \*\**). Nous affichons aussi la valeur de *a* au travers de celui-ci.

## Pointer comme arguments de fonction
Nous pouvons passer des pointer comme argument de fonction, nous appelons cela *call by reference*. Si nous faisons cela, nous ne créons pas dans la fonc
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjM5MDYwMDQxLC0xNTc1Njg0NjM0LC0xMz
YxNzY4Nzc3LDU0NTc2MTI2OSw1MjE1NTI4OV19
-->