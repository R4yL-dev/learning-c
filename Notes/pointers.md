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
Quand nous exécutons ce programme, le terminal nous affiche l'adresse mémoire o
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTM2NDc5ODM3LDU0NTc2MTI2OSw1MjE1NT
I4OV19
-->