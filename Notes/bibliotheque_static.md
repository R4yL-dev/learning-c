# 1. Bibliothèque statique

## 1.1. TOC

- [1. Bibliothèque statique](#1-bibliothèque-statique)
	- [1.1. TOC](#11-toc)
	- [1.2. Introduction](#12-introduction)
	- [1.3. Que sont les bibliothèques statique](#13-que-sont-les-bibliothèques-statique)
	- [1.4. Pourquoi utiliser des bibliothèques statique ?](#14-pourquoi-utiliser-des-bibliothèques-statique-)
	- [1.5. Comment cela fonctionne ?](#15-comment-cela-fonctionne-)
	- [1.6. Comment créer une bibliothèque statique ?](#16-comment-créer-une-bibliothèque-statique-)
	- [1.7. Comment utiliser une bibliothèque statique ?](#17-comment-utiliser-une-bibliothèque-statique-)

## 1.2. Introduction

En *C*, c'est une bonne pratique de séparer nos fonctions dans différents fichiers sources et de mettre leur prototype dans des fichier d'entête personalisé. Cela est du au faite, qu'en *C*, nous avons besoin de d'abord déclarer une fonction (ou son prototype) avant de pouvoir l'appeler. Mettre les prototypes dans un fichier header nous permet de respecter cela. Quand nous faisons cela, nous devonc inclure notre fichier d'entête avec l'instruction préprocesseur #include tout en haut de notre fichier source. Ensuite, nous devons compiler tous nos fichiers source ensemble, car *C* est un language compilé et non interpreté.

A un moment, dans un projet qui commence à prendre de l'empleur, nous pouvons nous retrouver avec beaucoup de fonctions (et donc, beaucoup de fichiers). Ajouter tous ces différents fichiers lors de la compilation peu vraiment devenir énérgivore. C'est à ça que servent les bibliothèques. Elle contiennent les fichiers objets, qui sont des fichiers sources compiler est assemblé, mais qui ne sont pas encore passé par le linking. Ces fichiers sont des binaires et ne sont pas lisible par les humains, ils ont l'extention *.o*. Il y a deux sorte de bibliothèque : statique et dynamique. Dans cette note, nous allons voir les bibliothèque statique.

## 1.3. Que sont les bibliothèques statique

Une bibliothèque statique est juste une archive qui contient des fichiers objet qui ne seront utile que durant l'étape du linking et non lors de l'exécution. Cela est du au fait que durant l'exécution, nous avons juste besoin de l'executable que nous compiler et linker avec la bibliothèque.

Par convention, les bibliothèque statique prennent l'extention *.a* sur les systèmes Nix et *.lib* sur Windows.

## 1.4. Pourquoi utiliser des bibliothèques statique ?

Comme nous l'avons vu plus haut, les bibliothèques statique nous permette de gagner du temps et taper moins de texte lors de la compiltion d'un programme. Cela vient du fait que nous n'avons pas besoin de recompiler à chaque fois tous nos fichiers objet. Nous n'avons cas linker une seul fois la bibliothèque lors de l'étape du linkage.

Il y a d'autres raisons qui peuvent nous pousser à faire une bibliothèque statique. Nous pouvons l'utiliser pour cacher le code de notre bibliothèque à ces utilisateurs. Vu que les fichiers objet sont compilé, ils ne sont pas lisible par une humain.

## 1.5. Comment cela fonctionne ?

Quand nous passons notre bibliothèque à notre linker, ils va copier toutes les fonctions qu'ils trouve à l'intérieur de l'exécutable. Avec les grosse bibliothèque cela peut être problèmatique, ce système utilise beaucoup de mémoire. Vu que le linker copie chaque fonctions, même celle qui ne sont pas utilisée par l'exécutable, la phase de linkage peut vite durer longtemps et manger toute la mémoire de l'ordinateur.

## 1.6. Comment créer une bibliothèque statique ?

Pour créer notre bibliothèque. nous allons utiliser la commande `ar`. `ar` est un programme développer par *GNU* qui permet de créer, modifier et extraire une archive. Comme beaucoup d'autres commandes, `ar` a plusieurs options que nous pouvons lui spécifer. Par exemple, l'option *c* permet de créer la bibliothèque si elle n'existe pas déjà et *r* remplace les anciens fichiers objet par les nouveaux quand nous les ajoutons à la bibliothèque et *s* index les fichiers de la bibliothèque une fois que cele-ci est créée ou mise à jour. Du coup, si nous voulons créer une bibliothèque *thelib* qui contiendrait les fichiers *file1.o* et *file2.o*, nous devons entrer cette commande :

```bash
ar rcs thelib.a file1.o file2.o
```

Notez le prfixe *lib* et l'extention *.a*.

## 1.7. Comment utiliser une bibliothèque statique ?

Maintenant que nous avons notre bibliotèque, nous allons pouvoir l'utiliser pour créer un programme. Disons que je veux créer un programme *prog* qui contient le point d'entrée de notre programme (la fonction main()).

La première étape est de tranformer notre fichier source (main.c) en fichier objet (main.o) :

```bash
gcc -c main.c
```

Grace à cette commande, nosu avons générer le fichier main.o.

Nous allons maintenant pouvoir faire le linkage entre notre main et notre bibliothèque. Pour se faire, nous allons utiliser *gcc* avec l'option *-L.*. Les options avec un *.* disent au liker de regarder dans le repertoire courant. Nous allons aussi utiliser l'option *-o* afin de spécifié le nom de notre exécutable :

```bash
gcc main.o -L. thelib.a -o prog
```

Nous avons ici créer un programme exécutable qui utilise notre bibliothèque !
