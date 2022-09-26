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
Nous pouvons passer des pointer comme argument de fonction, nous appelons cela *call by reference*. Si nous faisons cela, nous ne créons pas dans la fonction une copie de la variable que nous devrons retourner par la suite. A la place, nous passons l'adresse de la variable que nous allons pouvoir modifier directement.

```c
#include <stdio.h>

void add_one(int *nb)
{
	(*nb) = (*nb) + 1;
}

int main(void)
{
	int a = 42;
	int *p_a;
	
	p_a = &a;
	printf("a : %d\n", a);
	add_one(p_a);
	printf("a : %d\n", a);
	return (0);
}
```
```bash
a : 42  
a : 43
```

Ici, j'ai créé ne fonction *add_one()* qui prend comme argument un pointer sur int. Elle ajoute 1 à la valeur associée à l'adresse passée en argument.
Nous pouvons constater à l'affichage que la valeur de *a* a bien changé une fois la fonction appelée alors que celle-ci ne retourne rien.

## Pointer et array
En *C*, le concept de pointer et le concept de tableau sont très liés. Nous allons, dans ce chapitre, en voir plus sur ce lien.
Quand nous créons un table de 5 *int*, nous réservons 5 fois 4 bytes consécutif dans la mémoire. Ces 5 *int* sont vraiment stockés à la suite dans la mémoire, ce qui veut dires qu'ils sont exactement espacé de 4 bytes les uns des autres et que nous pouvons facilement passer de l'un à l'autre.

```c
#include <stdio.h>

int  main(void)  
{  
	int arr[5];  
  
	arr[0] = 1;  
	arr[1] = 2;  
	arr[2] = 3;  
	arr[3] = 4;  
	arr[4] = 5;  
	printf("address : %p, value : %d.\n", (arr), *(arr));  
	printf("address : %p, value : %d.\n", (arr + 1), *(arr + 1));  
	printf("address : %p, value : %d.\n", (arr + 2), *(arr + 2));  
	printf("address : %p, value : %d.\n", (arr + 3), *(arr + 3));  
	printf("address : %p, value : %d.\n", (arr + 4), *(arr + 4));  
	return  (0);  
}
```
```bash
address : 0x7ffd2bbb2f60, value : 1.  
address : 0x7ffd2bbb2f64, value : 2.  
address : 0x7ffd2bbb2f68, value : 3.  
address : 0x7ffd2bbb2f6c, value : 4.  
address : 0x7ffd2bbb2f70, value : 5.
```

Ici, nous voyons que nous pouvons accéder aux cellules d'un tableau comme s'il était un pointeur. Cela vient du faut que *arr* est en fait un pointeur sur le premier élément du tableau (arr[0]). C'est pour cela que quand nous affichons le résultat du déréférencement de *arr* nous voyons la valeur de *arr[0]*.

Il y a quand même quelques différences entre un tableau et un pointer. Par exemple, il est impossible d'incrémenter un tableau (arr++) alors que nous pouvons le faire avec un pointer(p++).
Nous pouvons mettre un tableau dans un pointer (p = arr) alors qu'il est impossible de faire l'inverse (arr = p).

## Tableau comme argument de fonction
Nous pouvons passer des tableaux en argument d'une fonction. Et nous avons plusieurs manières de le faire. Cela est dû au fait que les tableaux et les pointers sont très liés. La première chose à bien comprendre est quand nous envoyons un tableau à une fonction, il est automatiquement passé par référence. Ce qui veut dire que dans la fonction qui reçois le tableau, c'est en fait, l’adresse du premier élément qui est reçu.
Cela fait que dans la fonction, il est impossible de savoir la taille du tableau car la fonction n'a pas cette information, juste l'adresse de la première valeur du tableau. Il faut parcourir le tableau et arriver au dernier  élément pour connaitre sa taille réelle Ce mécanisme permet d'optimiser l'utilisation de la mémoire. Un tableau peut être gigantesque, ce qui demanderais énormément de ressources pour le transférer d'une fonction à une autre. Alors qu'avec ce mécanisme le compilateur force le passage par référence, ce qui fait qu'il n'y a qu'une adresse qui se balade de fonction en fonction.

```c
void  ft_size_arr(int arr[])  
{  
	printf("[FUNC] size of arr : %ld.\n", sizeof(arr));  
}  
  
int  main(void)  
{  
	int arr[5];  
  
	ft_size_arr(arr);  
	printf("[MAIN] size of arr : %ld.\n", sizeof(arr));  
	return  (0);  
}
```
```bash
[FUNC] size of arr : 4.  
[MAIN] size of arr : 20.
```

Vu que la fonction ne reçois dans tous les cas qu'une adresse, nous pouvons très bien recevoir le tableau comme ceci :

```c
void  ft_size_arr(int *arr)  
{  
printf("[FUNC] size of arr : %ld.\n", sizeof(*arr));  
}
```

Cela est complètement équivalent à la notation du premier exemple.

## Tableaux de caractères et pointers
En *C*, les chaines de caractères sont forcément des tableaux de caractères. Pour pouvoir faire une string, il faut que le tableau qui la reçoit soit assez grand. La meilleure taille est le nombre de *char* dans la chaine + 1. Nous devons ajouter 1 car par convention, nous devons terminer toutes nos strings par le caractère '\0'. Le tableau peut être plus grand que le nombre de *char* + 1 car les fonctions 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTQ2NDk4Mzc0OCwxNDY3Njg5NzE4LC0xNT
c1Njg0NjM0LC0xMzYxNzY4Nzc3LDU0NTc2MTI2OSw1MjE1NTI4
OV19
-->