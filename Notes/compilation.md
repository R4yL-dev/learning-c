# 1. Compilation

## TOC

- [1. Compilation](#1-compilation)
	- [TOC](#toc)
	- [1.1. Introduction](#11-introduction)
	- [1.2. Le préprocessing](#12-le-préprocessing)
	- [1.3. La compilation](#13-la-compilation)
	- [1.4. L'assemblage](#14-lassemblage)
	- [1.5. Linking](#15-linking)
	- [1.6. BONUS](#16-bonus)

## 1.1. Introduction

Pour compiler, nous utilison *GCC* qui veux dire *GNU Compiler Collection*. Comme sont nom l'indique, c'est une *collection* d'outils, développé par *GNU* et il permet de *compiler*. Ce qui veux dire, passer du code source (ici en *C*), à un logiciel qui puisse être exécuté par un ordinateur. *GCC* est vraiment une collection d'outil. En effet, quand nous compilons un code source, il y a en fait 4 étapes qui se succède et qui permette d'arrive à un fichier binaire. Ces 4 étapes peuvent être vues comme 4 logiciel qui vont traiter notre code et se passé le résultat à la suite.

Quand nous utilons *GCC* de la manière suivante, nous cachons en réalité les 4 étapes, mais elle son bien exécuté :

```bash
gcc -o main main.c
```

Nous allons dans ce document, voir ces 4 étapes et donc par quel processus, notre code source se transforme en fichier binaire compréhensible par l'ordinateur.

## 1.2. Le préprocessing

La première étape est le préprocessing, durant cette phase, le compilateur va faire une première lecture du code source.

Afin de pouvoir se rendre compte du traitement effectuer lors du préprocessing, nous pouvons demander à *GCC* de s'aretter une fois qu'il a terminé cette étape :

```bash
gcc -E main.c -o main.i
```

Avec cette commande, nous avons demandé à *GCC*, de faire le préprocessing sur main.c et de mettre le résultat dans un fichier main.i. Le fichier *.i* est aussi appelé *Pure C files*. Il est le résultat du code sources une fois passé par le préprocesseur.

En lisant un fichier *.i*, vous aller vous rendre compte que à ce stade, votre code source est toujours écrit en *C*. Nous reconnaissons toujours les instructions de *C* et nous retrouvons nos fonctions.

Nous pouvons par contre nous rendre compte que nos commentaire ont disparu. En effet, il ne sont utile que pour les humains qui lise le code, il ne servent à rien pour le fichiers binaire final. Il ont donc été simplement supprimer.

Les commentaires ont étés supprimées, mais plein d'autres choses sont apparue. Nous pouvons nous rendre compte que nos fichier d'entête ont été inclus dans notre code avec ces prototypes de fonctions et ces structures. Si nous avions inclus la librairie standarf, tous les prototypes des fonctions qu'elle comporte se serais trouver dans le fichier *.i*.

Les macros et autres instruction préprocesseur (*#*) sont aussi remplacée. C'est à dire que le préprocesseur, va prendre nos *#define* et remplacer partout dans le code ou la valeur est utilisée.

## 1.3. La compilation

La deuxième étape est la compilation. Durant cette phase, le compilateur va transformer notre fichier *.i* en assembleur. L'assembleur est la transcription "humaine" du language machine, c'est à dire, une représentation sous forme de texte des instructions processeur.

Pour constater le travail achevé par le compilateur, nous pouvons utiliser la commande :

```bash
gcc -S main.c
```

Si vous regardez dans votre répértoire courant, vous allez vous rendre compte qu'un fichier main.s a été créer. C'est le résultat de l'étape de compilation. En l'ouvrant, vous allez voir votre programme sous forme d'assembleur. Si vous ne connaissez pas le language assembleur, vous n'allez pas comprendre grande chose. Ce qu'il faut savoir, c'est que l'assembleur est le language le plus bas niveau imaginable. Il est littéralement des instructions pour le processeur sous forme lisible par un être humain.

## 1.4. L'assemblage

La troisième étape est l'assemblage. C'est la derrnière étape obligatoir, la quatrième étant facultative.

Maintenant que nous avons nos fichiers *.s*, cette étape constiste à les assemblé en un fichier binaire (*.o*). Ce fichier est le représentation compilée sous forme binaire de notre fichier (*.s*). Il n'est pas encore un logiciel a proprement parlé (il n'est pas exécutable), mais il est déjà dans une forme comprensive par l'ordianteur.

Pour aretter *GCC* à la fin de cette étape et donc voir son résultat, nous pouvons utiliser la commande :

```bash
gcc -c main.c
```

Une fois cette commande exécutée, vous pourrez vous rendre compte qu'un fichier main.o est présent dans votre répértoire courant. Cela ne sert à rien de lire ce fichier, il n'est pas fait pour être lisible par un humain.

Si nous compilons plusieurs fichier sources en même temps, nous aurons un fichier *.o* par fichier source. Le fichier objet embarque tout ce que le fichier sources à besoin pour être utiliser vu que les header ont été ajouter lors de la première étape.

Cette étape n'est pas exécutée directemetn par *GCC*. C'est l'assembleur de *GNU* qui est utilisé et il 'sappel *gas*.

## 1.5. Linking

Le *linking* ou *édition de lien* et la derrnière étape de compilation. Durant cette étape, *GCC* va prendre tous les fichiers *.o* et les fusionner pour produire le programme finale (généralement un exécutable).

Il peux aussi ajouté d'autre fichier entête à cette étape de la compilation, il peut s'agire des bibliothèque dynamique.

Si nous avons déjà généré nos fichier *.o*, nous pouvons faire le *linking* à la main :

```bash
gcc main.o func.o -o prog
```

Cette étape n'est pas non plus assurée par *GCC*. C'est *ld* qui est appeler pour faire le *linking*.

## 1.6. BONUS

Dans ce chapitre, je liste des arguments pour *GCC* qui pourraient être très utilent.

|Arguments       |Description                                                                                        |
|----------------|---------------------------------------------------------------------------------------------------|
|-Wall           |Active les warnings. Ce sont des problème dans le code mais qui ne font pas échouer la compilation.|
|-Wextra         |Fait des tests supplémenaire sur le code.                                                          |
|-Werror         |Le compilateur traite tous les warnings comme des erreurs.                                         |
|-std=\<norm\>   |Permet de choisir la norme à utiliser par le compilateur.                                          |
|-pedantic       |Force le compilateur à être compatible ISO.                                                        |
|-pedantic-errors|Traite les warnings pedantic comme des erreurs.                                                    |
|-O\<0-3\>       |Optimise la taille du code afin de réduire les temps d'exécution. La compilation est plus longue.  |
|-Os             |Alias pour -O2.                                                                                    |
|-I \<include\>  |Inclus un répértoire pour la compilation. Ex, les fichier d'entête npn standard                    |
|-l \<lib\>      |Permet d'inclure des bibliothèques (.a)                                                            |
|-g              |Active le deubage                                                                                  |
