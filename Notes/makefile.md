# 1. Makefile

## 1.1. TOC

- [1. Makefile](#1-makefile)
	- [1.1. TOC](#11-toc)
	- [1.2. Introduction](#12-introduction)
	- [1.3. Le minimum](#13-le-minimum)
	- [1.4. Enrichir le Makefile](#14-enrichir-le-makefile)
	- [1.5. Utiliser des variables](#15-utiliser-des-variables)
		- [1.5.1. Variables pérsonalisées](#151-variables-pérsonalisées)
		- [1.5.2. Les variables interne](#152-les-variables-interne)
	- [1.6. Règles d'inférence](#16-règles-dinférence)
	- [1.7. .PHONY](#17-phony)
	- [1.8. Générer automatiquement la liste des fichiers objet](#18-générer-automatiquement-la-liste-des-fichiers-objet)
	- [1.9. Générer automatiquement la liste des fichiers sources](#19-générer-automatiquement-la-liste-des-fichiers-sources)

## 1.2. Introduction

*Make* est un outil qui nous permet d'automatiser (entre autre) les étapes de compilation de nos projets.
Pour pouvoir utiliser *Make* nous allons devoir créer un *Makefile*. Le *Makefile* est un fichier qui se constitue de règles qui prennent la forme de :

```Makefile
cible : dependance
    commandes
```

Il est important de précéder chaque *commande* d'une tablulation !
Quand nous lancons *make* avec un fichier *Makefile*, soit la première règle, soit la règle passée a *make* est évaluée. L'évaluation d'une règle se fait en plusieurs étapes :

- D'abord, les dépendances sont évaluée, si la dépendance est la cible d'une autre règle du *Makefile* , cett règle est aussi évaluée.
- Dès que l'ensemble des dépendances sont analysées et si la cible ne correspond à aucun fichier ou si un fichier dépendance est plus récent que la règle, les différentes commandes sont exécutées.

## 1.3. Le minimum

Voici un exemple de fichier *Makefile*  minimaliste :

```Makefile
prog : func.o main.o
    gcc -o prog main.o func.o

func.o : func.c
    gcc -o func.o -c func.c -Wall -Wextra -Werror

main.o : main.c
    gcc -o main.o -c main.c -Wall -Wextra -Werror
```

Dans cette exemple, nous cherchons à créer un exécutable *prog*. La première dépendance (*func.o*) est une règle, elle est donc évaluée. Vu que aucune dépendance de *func.o* n'est une règle, la commande est exécutée (*gcc -o func.o -c func.c -Wall -Wextra -Werror*). Maintenant que nous sommes arrivé à la fin d'une branche (il n'y a pas de dépendance qui soit une règle et la commande de la dernière règle a été exécutée), *make* va évaluée la deuxième dépendance de prog (*main.o*). Il va faire la même chose que pour le *func.o*. Le fichier *main.o* va être créer grace à la règle (*main.o*). Maintenant que toutes les dépendance de *prog* sont satisfaites, la commande de *prog* est lancée (*gcc -o prog main.o func.o*).

Il y a encore une suptilité, avant d'exécuté une commande, *make* va vérifié que la dépendance (par ex : *main.c*) et plus récent (timestamp du fichier) que la règle (par ex : *main.o*). Si la dépendance est plus récente, la commande est exécuté alors que si la dépendance est plus ancienne, la commande ne sera pas exécuté. Cela permet de ne par recompilier les fichiers *.c* en *.o* si il n'ont pas été modifié et donc gagnier énormément de temps de compilation.

La clé pour comprendre le fonction des *Makefile* est de bien comprendre le cheminement qu'il fait pour évalué les règles. Ce que nous vennons de voir en dessus en sommes !

## 1.4. Enrichir le Makefile

Nous vennons de voir comment créer des règles propres à la compilation, comment générer tous les fichiers *.o* et comment les réunir afin de créer un binaire fonctionnel.

Nous allons maintenant voir comment ajouter des règles qui vont nous simplifié la vie lors du développement de nos projets.

Nous allons ajouter des règles afins de pouvoir supprimer les fichier *.o* que nous n'avons plus besoin une fois le binaire constitué. Nous allons aussi voir comment supprimer toutes les fichiers qui ont été créer par *make*, binaire inclu.

Voici le fichier *Makefile* de l'exemple du dessus au quel j'ai ajouter les règles *all*, *clean*, *fclean* et *re* :

```Makefile
all : prog

prog : func.o main.o
    gcc -o prog main.o func.o

func.o : func.c
    gcc -o func.o -c func.c -Wall -Wextra -Werror

main.o : main.c
    gcc -o main.o -c main.c -Wall -Wextra -Werror

clean :
    rm -f main.o func.o

fclean : clean
    rm -f prog

re : fclean all
```

- *all* Cette règle spécifie que si nous lacon la commande *make all*, la dépendance (*prog*) sera analysée. Cella permet d'avoir un point d'entrée unique qui fabriquera tous le binaire d'un coup.
- *clean* Cette règle permet d'effacer tous les fichiers *.o* lorsque la commande *make clean* sera appelée.
- *fclean* Cette règle à pour dépendance *clean*. *clean* sera donc exécuté en tout premier lieu. En suite, la commande de *fclean* est exécuté et elle supprime le binaire.
- *re* Cette règle va d'abord exécuté les règles *clean* et *fclean* (Ce qui supprime tous les fichiers générer par *make*). Une fois que tous les fichiers sont supprimer, elle exécute *all* (et donc la compilation du binaire).

## 1.5. Utiliser des variables

### 1.5.1. Variables pérsonalisées

Afin de rendre le fichier plus facile à adapter entre plusieurs projets et d'évité la répétition. Il est possible d'utiliser des variables dans un *Makefile*. Pour les créer nous utilisons la syntaxe `NOM = VALEUR` et pour les utiliser nous devons faire `$(NOM)`.

Pour notre exemple, nous allons créer 3 variables :

- *NAME* qui va contenir le nom de l'exécutable.
- *CFLAGS* qui va contenir tous les flags utile à la compilation.
- *CC* qui va contenir le nom du compilateur.

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : func.o main.o
    $(CC) -o prog main.o func.o

func.o : func.c
    $(CC) -o func.o -c func.c $(CFLAGS)

main.o : main.c
    $(CC) -o main.o -c main.c $(CFLAGS)

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

Nous pouvons constater que à chaque endroit ou nous avons appeler une variable par son nom, elle a été remplacée par sa valeur.

### 1.5.2. Les variables interne

Quand nous créons un *Makefile*, nous avons a notre disposition plusieurs variables internes qui peuvent être très utile afin d'automatiser encore plus notre *Makefile*.

Voici une petite liste de variables internes :

|Variable|Description                                        |
|--------|---------------------------------------------------|
|$@      |Le nom de la cible                                 |
|$<      |Le nom de la première dépendance                   |
|$^      |La liste des dépendances                           |
|$?      |La liste des dépendances plus récentes que la cible|
|$*      |Le nom du fichier sans suffixe                     |

Nous allons utiliser ces variables afin de simlifé et enlever des répétion dans notre *Makefile* :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : func.o main.o
    $(CC) -o $@ $^

func.o : func.c
    $(CC) -o $@ -c $< $(CFLAGS)

main.o : main.c
    $(CC) -o $@ -c $< $(CFLAGS)

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

## 1.6. Règles d'inférence

Nous avons la possibilité avec les *Makefile* de créer des règles génériques qui seront appelées par défaut. Voici comment une règle générique qui ciblerais tous les *.o* avec comment dépendance tous les *.c* :

```Makefile
%.o : %.c
    commandes
```

Il existe aussi une notation plus ancienne qui permet d'arrivé au même résultat :

```Makefile
.c.o :
    commandes
```

Nous allons pouvoir ajouter a notre *Makefile* une règle générique pour construire tous nos *.o* à partir de nos *.c* :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : func.o main.o
    $(CC) -o $@ $^

%.o : %.c
    $(CC) -o $@ -c $< $(CFLAGS)

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

Nous avons beaucoup simolifé les choses !

Nous avons encore un problème, avec la règle générique que nous avons créer, le fichier *.h* n'est plus pris en compte. Ce qui veux dir que *main.o* ne sera pas reconstruit si *func.h* change. Nous pouvons préciser les dépendances séparément des règles d'inférence et de rétablir le fonctionnement d'origine :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : func.o main.o
    $(CC) -o $@ $^

main.o : func.h

%.o : %.c
    $(CC) -o $@ -c $< $(CFLAGS)

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

## 1.7. .PHONY

Nous avons vu que *make* ne n'exécutais une commande que si la cible était plus récente que la dépendance. Cela est vraiment très pratique en général, sauf quand nous avons un fichier qui à le même nom qu'une règle qui n'a pas de dépendance. Vu que la règle n'a pas de dépendance, la cible est forcément plus récente et ne sera donc jamais reconstruite.

Par résoudre ce problème, nous avons à notre disposition une cible qui s'appel *.PHONY*. *.PHONY* reconstruit forcement ces dépendance à chaque fois que *make* est appeler. Nous pouvons l'utiliser comme suite :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : func.o main.o
    $(CC) -o $@ $^

main.o : func.h

%.o : %.c
    $(CC) -o $@ -c $< $(CFLAGS)

.PHONY : clean fclean re

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

## 1.8. Générer automatiquement la liste des fichiers objet

Un gros projet peut très rapidement contenir énormément de fichier *.c* et donc de fichier *.o*. Au bout d'un moment, il peut devenir très fastidieux de devoir tous les rentrer à la main. Nous allons voir une méthode qui va nous permette de créer la liste de tous les fichier *.o* à traiter en fonction des fichier *.c*.

Pour se faire, nous devons ajouter deux vatiables à notre *Makefile* :

- *SRC* qui est la liste des fichier sources (*.c*).
- *OBJ* qui est la liste des fichier objet (*.o*).

Nous allons remplit la variable *OBJ* à partir de la variable *SRC* :

```Makefile
OBJ = $(SRC:.c=.o)
```

Cette ligne dis "Ajoute dans la varible *OBJ* chaque fichier qui sont dans *SRC* et qui se termine par *.c* mais change le *.c* en *.o*.

Voici ce que sa donne :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = func.c main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
    $(CC) -o $@ $^

main.o : func.h

%.o : %.c
    $(CC) -o $@ -c $< $(CFLAGS)

.PHONY : clean fclean re

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```

## 1.9. Générer automatiquement la liste des fichiers sources

Comme pour les fichiers objets, nous avons la possibilité de lister automatiquement les fichiers sources dans la variable *SRC*.

`Il n'est pas dans la norme de 42 d'utiliser cette méthode. En effet, tous les fichier sources doivent être lister à la main au début du fichier. Cella permet d'un coup d'oeil de savoir quels fichiers sont traiter par notre Makefile.`

Pour remplir la variable *SRC*, nous allons utiliser le wildcard (\*). Nous ne pouvons pas utiliser directement le commande `*.c` car l'opérateur n'est pas reconnu par *make*. Pour quand même l'utiliser, nous avons à notre disposition la commande *wildcard* qui permet de simuler l'opérateur \* :

```Makefile
NAME = prog
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
    $(CC) -o $@ $^

main.o : func.h

%.o : %.c
    $(CC) -o $@ -c $< $(CFLAGS)

.PHONY : clean fclean re

clean :
    rm -f main.o func.o

fclean : clean
    rm -f $(NAME)

re : fclean all
```
