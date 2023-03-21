# 1. Brainstorm

## 1.1. TDM

- [1. Brainstorm](#1-brainstorm)
	- [1.1. TDM](#11-tdm)
	- [1.2. But](#12-but)
	- [1.3. \< file1 cmd1 | cmd2 \> file2](#13--file1-cmd1--cmd2--file2)
	- [1.4. Opérateurs de redirection](#14-opérateurs-de-redirection)
	- [1.5. Fonctions externes autorisées](#15-fonctions-externes-autorisées)
		- [1.5.1. perror()](#151-perror)
		- [1.5.2. strerror()](#152-strerror)
		- [1.5.3. access()](#153-access)
		- [1.5.4. dup()](#154-dup)
		- [1.5.5. dup2()](#155-dup2)
		- [1.5.6. execve()](#156-execve)
		- [1.5.7. fork()](#157-fork)
		- [1.5.8. pipe()](#158-pipe)
		- [1.5.9. unlink()](#159-unlink)
		- [1.5.10. wait()](#1510-wait)
		- [1.5.11. waitpid()](#1511-waitpid)


## 1.2. But

Le but est de faire une application qui simule la commande bash `< file1 cmd1 | cmd2 > file2`. Le programme doit être appeler comme suite : `./pipex file1 cmd1 cmd2 file2`.

## 1.3. < file1 cmd1 | cmd2 > file2

- `< file1` - Il s'agit de la redirection d'entrée, cela signifie que le contenu du fichier `file1` sera utilisé comme entrée pour la commande suivante `cmd1`.
- `cmd1` - Il s'agit de la première commande qui sera exécutée. Elle prendra l'entrée de `file1` et effectuera une opération sur celle-ci.
- `|` - C'est le symbole pipe, cela signifie que la sortie de `cmd1` sera utilisée comme entrée pour la commande suivante `cmd2`.
- `cmd2` - Il s'agit de la deuxième commande qui sera exécutée. Elle prendra la sortie de `cmd1` et effectuera une opération sur celle-ci.
- `> file2` - Il s'agit de la redirection de sortie, cela signifie que la sortie de `cmd2` sera enregistrée dans le fichier `file2`.

En résumé, cette commande prend le contenu de `file1` et le fait passer par deux commandes `cmd1` et `cmd2`, avant de sauvegarder la sortie finale dans `file2`.

## 1.4. Opérateurs de redirection

- `>` : Redirection de sortie standard vers un fichier.
    >Exemple : `ls > fichier.txt` permet de stocker la liste des fichiers du répertoire courant dans un fichier nommé `fichier.txt`.

- `>>` : Ajout de la sortie standard à la fin d'un fichier existant.
    >Exemple : `echo "Hello World" >> fichier.txt` permet d'ajouter la chaîne de caractères "Hello World" à la fin du fichier `fichier.txt`.

- `<` : Redirection d'un fichier vers l'entrée standard d'une commande.
    >Exemple : `sort < fichier.txt` permet de trier le contenu du fichier `fichier.txt`.

- `2>` : Redirection de la sortie d'erreur standard vers un fichier.
    >Exemple : `ls fakefile 2> erreur.txt` permet de stocker l'erreur "No such file or directory" dans un fichier nommé `erreur.txt`.

- `2>>` : Ajout de la sortie d'erreur standard à la fin d'un fichier existant.
    >Exemple : `commande_inconnue 2>> erreurs.txt` permet d'ajouter le message d'erreur "commande_inconnue : command not found" à la fin du fichier `erreurs.txt`.

- `&>` ou `>&` : Redirection de la sortie standard et d'erreur standard vers un fichier.
    >Exemple : `commande &> log.txt` permet de stocker à la fois la sortie standard et d'erreur standard de la commande `commande` dans un fichier nommé `log.txt`.

- `|` : Redirection de la sortie d'une commande vers l'entrée d'une autre commande.
    >Exemple : `ls | grep "fichier"` permet de rechercher tous les fichiers contenant "fichier" dans le répertoire courant.

## 1.5. Fonctions externes autorisées

- open()
- close()
- read()
- write()
- malloc()
- free()
- *perror()
- *strerror()
- *access()
- *dup()
- *dup2()
- *execve()
- exit()
- *fork()
- *pipe()
- *unlink()
- *wait()
- *waitpid()
- ft_printf()

\* = fonctions que je ne connais pas et que je n'ai jamais utiliser

### 1.5.1. perror()

La fonction `perror()` est utilisée pour afficher un message d'erreur en fonction de la valeur de la variable globale `errno`. La variable `errno` contient le code d'erreur associé à la dernière erreur qui s'est produite dans le programme.

La fonction `perror()` prend un argument de type chaîne de caractères, qui est un message d'erreur supplémentaire à afficher avant le message d'erreur système.

La syntaxe de base de la fonction `perror()` est la suivante:

```c
void perror(const char *s);
```

Voici un exemple simple qui illustre l'utilisation de la fonction `perror()`:

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
   FILE *fp;

   fp = fopen("missing_file.txt", "r");
   if (fp == NULL) {
      perror("Erreur");
      printf("Erreur (%d): %s\n", errno, strerror(errno));
   }

   return 0;
}
```

Dans cet exemple, nous essayons d'ouvrir un fichier qui n'existe pas, ce qui entraîne une erreur. La fonction `perror()` est appelée pour afficher un message d'erreur avec la chaîne "Erreur". Le message d'erreur système correspondant est également affiché.

Si vous exécutez ce programme, vous obtiendrez une sortie similaire à celle-ci:

```bash
Erreur: No such file or directory
Erreur (2): No such file or directory
```

Dans cet exemple, le message d'erreur système est "No such file or directory", et le code d'erreur est 2, qui est la valeur de la macro `ENOENT` définie dans la bibliothèque standard.

### 1.5.2. strerror()

La fonction `strerror()` est utilisée pour convertir un code d'erreur en une chaîne de caractères décrivant l'erreur correspondante. Cette fonction prend un argument de type entier, qui est le code d'erreur à convertir, et renvoie un pointeur vers une chaîne de caractères qui décrit l'erreur.

La syntaxe de base de la fonction `strerror()` est la suivante:

```c
char *strerror(int errnum);
```

Voici un exemple simple qui illustre l'utilisation de la fonction strerror():

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
   int err = ENOENT;  // No such file or directory

   printf("Erreur: %s\n", strerror(err));

   return 0;
}
```

Dans cet exemple, la variable err contient le code d'erreur `ENOENT`, qui signifie "No such file or directory". La fonction `strerror()` est appelée pour convertir ce code d'erreur en une chaîne de caractères qui décrit l'erreur correspondante. Cette chaîne est ensuite affichée à l'écran à l'aide de la fonction `printf()`.

Si vous exécutez ce programme, vous obtiendrez une sortie similaire à celle-ci:

```bash
Erreur: No such file or directory
```

Dans cet exemple, la chaîne "No such file or directory" est obtenue en convertissant le code d'erreur `ENOENT` à l'aide de la fonction `strerror()`.

### 1.5.3. access()

La fonction `access()` est utilisée pour vérifier si un fichier ou un répertoire existe et si l'utilisateur a des autorisations pour y accéder. Cette fonction prend deux arguments : le chemin du fichier ou du répertoire à vérifier et un entier représentant le mode d'accès.

La syntaxe de base de la fonction `access()` est la suivante :

```c
int access(const char *path, int mode);
```

Le premier argument, `path`, est une chaîne de caractères représentant le chemin du fichier ou du répertoire à vérifier.

Le deuxième argument, `mode`, est un entier représentant le mode d'accès que nous voulons vérifier. Ce mode d'accès peut être l'une des constantes suivantes :

- `F_OK` : pour vérifier si le fichier ou le répertoire existe.
- `R_OK` : pour vérifier si l'utilisateur a le droit de lecture.
- `W_OK` : pour vérifier si l'utilisateur a le droit d'écriture.
- `X_OK` : pour vérifier si l'utilisateur a le droit d'exécution.

La fonction `access()` renvoie 0 si le fichier ou le répertoire existe et si l'utilisateur a les autorisations appropriées en fonction du mode spécifié. Si le fichier ou le répertoire n'existe pas ou si l'utilisateur n'a pas les autorisations appropriées, la fonction renvoie -1.

Voici un exemple simple qui illustre l'utilisation de la fonction `access()` :

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
   char *file_path = "test.txt";

   if (access(file_path, F_OK) == -1) {
      printf("Le fichier n'existe pas.\n");
   } else {
      printf("Le fichier existe.\n");
   }

   if (access(file_path, R_OK) == -1) {
      printf("Vous n'avez pas le droit de lire le fichier.\n");
   } else {
      printf("Vous avez le droit de lire le fichier.\n");
   }

   if (access(file_path, W_OK) == -1) {
      printf("Vous n'avez pas le droit d'écrire dans le fichier.\n");
   } else {
      printf("Vous avez le droit d'écrire dans le fichier.\n");
   }

   if (access(file_path, X_OK) == -1) {
      printf("Vous n'avez pas le droit d'exécuter le fichier.\n");
   } else {
      printf("Vous avez le droit d'exécuter le fichier.\n");
   }

   return 0;
}
```

Dans cet exemple, nous vérifions si le fichier "test.txt" existe et si l'utilisateur a les autorisations nécessaires pour lire, écrire et exécuter ce fichier. Nous utilisons la fonction `access()` avec différents modes d'accès pour effectuer ces vérifications. En fonction des résultats, nous affichons différents messages à l'utilisateur. Si vous exécutez ce programme, vous obtiendrez une sortie similaire à celle-ci :

```bash
Le fichier existe.
Vous avez le droit de lire le fichier.
Vous avez le droit d'écrire dans le fichier.
Vous n'avez pas le droit d'exécuter le fichier.
```

Dans cet exemple, le fichier "test.txt" existe et l'utilisateur a les autorisations nécessaires pour lire et écrire dans ce fichier, mais n'a pas l'autorisation d'exécuter le fichier

### 1.5.4. dup()

### 1.5.5. dup2()

### 1.5.6. execve()

### 1.5.7. fork()

### 1.5.8. pipe()

### 1.5.9. unlink()

### 1.5.10. wait()

### 1.5.11. waitpid()
