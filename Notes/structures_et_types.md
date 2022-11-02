# 1. Structure et types

## 1.1. TOC

- [1. Structure et types](#1-structure-et-types)
	- [1.1. TOC](#11-toc)
	- [1.2. Introduction](#12-introduction)
	- [1.3. Structures](#13-structures)
		- [1.3.1. Création et utilisation des structures](#131-création-et-utilisation-des-structures)
		- [1.3.2. Structures imbriquées](#132-structures-imbriquées)
	- [1.4. Types](#14-types)
		- [1.4.1. Création et utilisation des types personalisé](#141-création-et-utilisation-des-types-personalisé)
		- [1.4.2. Imbriquer la création d'un type et d'une structure](#142-imbriquer-la-création-dun-type-et-dune-structure)
	- [1.5. Les structures et les pointeur](#15-les-structures-et-les-pointeur)
	- [1.6. Énumération](#16-énumération)
		- [1.6.1. Énumération et typedef](#161-énumération-et-typedef)
		- [1.6.2. Modifier la valeur du champ d'une énumération](#162-modifier-la-valeur-du-champ-dune-énumération)

## 1.2. Introduction

*C* nous ermet de créer nos propres type ainsi que nos propre structures. Nous allons voir dans la suite de ce papier comment cela fonction.

## 1.3. Structures

Une structures permet de rassembler un ensemble de données. Quand nous avons beaucoup de variables, le code peut rapidement devenir confus, les structures permet de palier entre autre à ce problème.

### 1.3.1. Création et utilisation des structures

Voici comment créer une structure :

```c
struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
};
```

Ceci est la déclaration d'une structure qui ce nomme *s_personne*. A l'intérieur du scope de la structure, nous pouvons ajouter des champs composés d'un type et d'un nom.
> **/!\\ Il faut absolument ajouter un ";" à la fin du scope /!\\**

Maintenant que nous avons créer notre structure, nous allons l'utiliser dans un petit exemple :

```c
#include <stdio.h>

struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
};

int main (void)
{
    // Création d'une personne p1 et population de ces champs
    struct s_personne p1 = {"John", "Doe", 42};
    // Afficher les informations de p1.
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42

```

Cet exemple utilise la struture que nous avons créer plus tôt. Nous commençons par créer p1 en lui passant les informations lors de son initialisation.
Ensuite, nous affichons chaqun de ces champs. Pour accéder aux champs, nous utilisons l'opérateur `.`.

Si nous ne voulons pas remplir les champs lors de l'initialisation de la structure, nous avons la possibilité de le faire par la suite :

```c
#include <stdio.h>
#include <string.h>

struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
};

int main (void)
{
    struct s_personne p1;
    strcpy(p1.first_name, "John");
    strcpy(p1.last_name, "Doe");
    p1.age = 42;
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42

```

### 1.3.2. Structures imbriquées

Nous avons la possibilité de mettre des structures dans des structures. Voici une permière manière de faire :

```c
#include <stdio.h>

struct s_pet
{
    signed char type[256];
    signed char name[256];
    int age;
};

struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
    // Ajout du champ pet de type s_pet
    struct s_pet pet;
};

int main (void)
{
    // Nous ajoutons directement les information de Snoopy lors de la création de John
    struct s_personne p1 = {"John", "Doe", 42, {"Snoopy", "dog", 4}};
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    printf("Pet type : %s | Pet name : %s | Pet age : %d\n", p1.pet.type, p1.pet.name, p1.pet.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42
Pet type : Snoopy | Pet name : dog | Pet age : 4

```

Dans cette exemple, nous avons donné un chien à John, pour ce faire, nous avons créer une structure pour contenir Snoopy. Nous pouvons créer Snoppy lors de la création de John.

Une deuxième apprche existe, elle consiste à déclarer la sous structure dans la structure. Il faut faire attetion avec cette notation car elle peut créer des erreur, en effet, nous devons ajouter en plus de la sous structure, un nom de variable suplémentaire à la fin de la déclaration de la sous structure :

```c
#include <string.h>

struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
    struct s_pet
    {
        signed char type[256];
        signed char name[256];
        int age;
    // Nous devons absolument ajouter une variable (ici pet) pour que le progamme compile
    } pet;
};

int main (void)
{
    struct s_personne p1 = {"John", "Doe", 42, {"Snoopy", "dog", 4}};
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    printf("Pet type : %s | Pet name : %s | Pet age : %d\n", p1.pet.type, p1.pet.name, p1.pet.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42
Pet type : Snoopy | Pet name : dog | Pet age : 4

```

Chaque fois que nous déclarons une structure dans une structure, nous sommes obligé de donner un nom de variable à la sous structure. Le compilateur en a besoin dans la structure princiaple lors de la compilation.

## 1.4. Types

*C* nous permet de créer nos propre types de variable, en plus d'être très pratique, nous allons voir que les types personalisé se mélange très bien avec les structures.

### 1.4.1. Création et utilisation des types personalisé

Pour créer un type, nous devons utiliser l'opérateur `typedef` suivit de la chose à remplacer, suivit de par quoi la chose sera remplacé.

Pour remprendre l'exemple de John, nous allons vouloir créer le type *Personne* qui contiendra notre structure *s_personne*.

```c
#include <stdio.h>

struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
};

// création du type Personne
typedef struct s_personne Personne;

int main (void)
{
    // Nous créons John en utilisant notre nouveau type
    Personne p1 = {"John", "Doe", 42};
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42

```

Comme nous pouvons le constater, nous avons put créer John en utilisant le type pérsonalisé que nous avons créer en entête.

### 1.4.2. Imbriquer la création d'un type et d'une structure

```c
#include <stdio.h>

// Création du type Personne qui contient la structure s-personne
typedef struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
} Personne;

int main (void)
{
    // Création de John
    Personne p1 = {"John", "Doe", 42};
    // Afficher les informations de John.
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42

```

Cet exemple fait exactement la même chose que l'exemple précédant. Il et par contre plus concis car il économise une ligne.

## 1.5. Les structures et les pointeur

Nous devons maintenant voir comment travaillier sur une structure (qu'elle soit dans un type personalisé ou non) au travers d'un pointeur. Nous allons créer un exemple dans le quel nous allons créer une fonction qui va modifier les informations de John. Pour se faire, nous allons passer un pointeur sur John à notre fonction.

```c
#include <stdio.h>

typedef struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
} Personne;

void update_age(Personne *ptr)
{
    // Nous modifions l'age de John
    (*ptr).age = 21;
}

int main (void)
{
    Personne p1 = {"John", "Doe", 42};
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    // On passe l'adresse de p1 à notre fonction
    update_age(&p1);
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

```bash
First name : John | Last name : Doe | Age : 42
First name : John | Last name : Doe | Age : 21

```

La fonction que nous avons ajouter est très simple. Elle prend en paramètre un pointeur sur un type *Personne* et change l'age à 21. Pour pouvoir modifier un champ au travers d'un pointeur, nous devons mettre le nom du pointeur entre paranthèse.

Il existe une autre notation qui permet d'accéder aux champs d'une structure au travers d'un pointeur. La notation que nous vennons de voir n'est pas très lisible et peu créer des erreurs. L'exemple du dessous fait exacement la même chose que l'exemple que nous vennons de faire.

```c
#include <stdio.h>

typedef struct s_personne
{
    signed char first_name[256];
    signed char last_name[256];
    int age;
} Personne;

void update_age(Personne *ptr)
{
    // Nous modifions l'age de John avec l'opérateur ->
    ptr->age = 21;
}

int main (void)
{
    Personne p1 = {"John", "Doe", 42};
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    // On passe l'adresse de p1 à notre fonction
    update_age(&p1);
    printf("First name : %s | Last name : %s | Age : %d\n", p1.first_name, p1.last_name, p1.age);
    return (0);
}
```

Ici, nous utilisons l'opérateur `->` afin d'accéder au champ age de notre pointeur sur John. Comme nous pouvons le constater, nous ne devons plus mettre le `*` ainsi que les `()`.

## 1.6. Énumération

Une énumération, permet comme son nom l'indique d'énumérer des valeurs. Nous allons voir un exemple très simple afin d'illustrer.

```c
#include <stdio.h>

// Création de l'énum e_fruit
enum e_fruit
{
    POMME,
    POIRE,
    BANANE
};

int main(void)
{
    // Déclaration de la variable f1 de type enum e_fruit
    enum e_fruit f1 = POIRE;
    return (0);
}
```

Nous vennons de créer une énumration (e_fruit) qui contient 3 valeurs. Ensuite, nous avec déclarer une variable (f1) de type enum e_fruit et nous lui avons donner la valeur de POIRE. Que se passe il si nous affichons la valeur de f1 ?

```c
#include <stdio.h>

enum e_fruit
{
    POMME,
    POIRE,
    BANANE
};

int main(void)
{
    enum e_fruit f1 = POIRE;
    printf("%d\n", f1);
    return (0);
}
```

```bash
1

```

f1 vaut *1* car il est le deuxième terme déclarer dans e_fruit. En effet, dans une énumération, la valeur d'un champ et une valeur numérique qui commence à 0 et qui s'incrémente de 1 pour chaque terme ajouter à l'énumération.

### 1.6.1. Énumération et typedef

Comme pour les structures, nous pouvons mettre une énumération dans un type, voici un exemple :

```c
#include <stdio.h>

typedef enum e_fruit
{
    POMME,
    POIRE,
    BANANE
} FRUIT;

int main(void)
{
    FRUIT f1 = BANANE;
    printf("%d\n", f1);
    return (0);
}
```

```bash
2

```

### 1.6.2. Modifier la valeur du champ d'une énumération

Nous ne pouvons pas modifié la valeur d'un champ d'une énumération en dehors de sa déclaration car c'est une variable. Et comme nous l'avons vu, par défaut, la valeur d'une champ d'une énumération et sa position dans la déclaration de l'énumération.

Nous pouvons par contre changer la valeur d'un champ lors de la création de l'énumération :

```c
#include <stdio.h>

typedef enum e_fruit
{
    POMME = 100,
    POIRE = 200,
    BANANE = 300
} FRUIT;

int main(void)
{
    FRUIT f1 = POIRE;
    printf("%d\n", f1);
    return (0);
}
```

```bash
200

```
