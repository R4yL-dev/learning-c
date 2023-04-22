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
	- [Déroulement](#déroulement)
	- [1.6. Liens utiles](#16-liens-utiles)
		- [1.6.1. Vidéos](#161-vidéos)


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

La fonction `dup()` en C est utilisée pour dupliquer un descripteur de fichier. Elle prend en entrée un descripteur de fichier existant et retourne un nouveau descripteur qui pointe vers le même fichier que le descripteur original. En d'autres termes, elle crée une copie du descripteur de fichier.

La syntaxe de la fonction est la suivante :

```c
int dup(int oldfd);
```

où `oldfd` est le descripteur de fichier existant à dupliquer.

La fonction `dup()` retourne un nouveau descripteur de fichier, qui est l'entier le plus bas non utilisé pour représenter un descripteur de fichier. Si la fonction échoue, elle retourne -1 et définit la variable `errno` pour indiquer l'erreur.

La duplication d'un descripteur de fichier peut être utile dans de nombreuses situations, comme par exemple pour rediriger la sortie standard vers un fichier, pour dupliquer la sortie standard dans un tube pour la communication entre processus, ou pour dupliquer un descripteur de fichier pour l'utiliser dans une fonction qui ne devrait pas modifier le descripteur original.

Voici un exemple qui illustre l'utilisation de la fonction `dup()` pour rediriger la sortie standard vers un fichier :

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, newfd;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // duplique le descripteur de fichier
    newfd = dup(STDOUT_FILENO);
    if (newfd == -1) {
        perror("Erreur lors de la duplication du descripteur de fichier");
        return 1;
    }

    // redirige la sortie standard vers le fichier
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Erreur lors de la redirection de la sortie standard");
        return 1;
    }

    // affiche un message dans le fichier
    printf("Ce message sera écrit dans le fichier 'output.txt'\n");

    // restaure la sortie standard
    if (dup2(newfd, STDOUT_FILENO) == -1) {
        perror("Erreur lors de la restauration de la sortie standard");
        return 1;
    }

    // ferme les descripteurs de fichier
    close(fd);
    close(newfd);

    return 0;
}
```

Dans cet exemple, nous ouvrons un fichier "output.txt" en mode écriture. Nous dupliquons ensuite le descripteur de fichier de la sortie standard en utilisant la fonction `dup()`, et redirigeons la sortie standard vers le fichier "output.txt" en utilisant la fonction `dup2()`. Nous affichons un message à l'écran, qui sera redirigé vers le fichier. Enfin, nous restaurons la sortie standard et fermons les descripteurs de fichier. Si vous exécutez ce programme, vous verrez que le message est bien écrit dans le fichier "output.txt".

### 1.5.5. dup2()

La fonction `dup2()` est utilisée pour dupliquer un descripteur de fichier et rediriger la sortie d'un descripteur vers un autre descripteur de fichier. Elle prend en entrée deux descripteurs de fichier, `oldfd` et `newfd`, et retourne un nouveau descripteur de fichier.

La syntaxe de la fonction est la suivante :

```c
int dup2(int oldfd, int newfd);
```

où `oldfd` est le descripteur de fichier existant à dupliquer et `newfd` est le descripteur de fichier vers lequel la sortie de `oldfd` doit être redirigée.

La fonction `dup2()` retourne le nouveau descripteur de fichier si elle réussit, ou -1 si elle échoue. Si elle réussit, le descripteur `newfd` est fermé avant que la sortie de oldfd ne soit redirigée vers `newfd`.

La duplication d'un descripteur de fichier peut être utile dans de nombreuses situations, comme par exemple pour rediriger la sortie standard vers un fichier, pour dupliquer la sortie standard dans un tube pour la communication entre processus, ou pour dupliquer un descripteur de fichier pour l'utiliser dans une fonction qui ne devrait pas modifier le descripteur original.

Voici un exemple qui illustre l'utilisation de la fonction `dup2()` pour rediriger la sortie standard vers un fichier :

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // redirige la sortie standard vers le fichier
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Erreur lors de la redirection de la sortie standard");
        return 1;
    }

    // affiche un message dans le fichier
    printf("Ce message sera écrit dans le fichier 'output.txt'\n");

    // ferme le descripteur de fichier
    close(fd);

    return 0;
}
```

Dans cet exemple, nous ouvrons un fichier "output.txt" en mode écriture. Nous redirigeons ensuite la sortie standard vers le fichier "output.txt" en utilisant la fonction `dup2()`. Nous affichons un message à l'écran, qui sera redirigé vers le fichier. Enfin, nous fermons le descripteur de fichier et terminons le programme. Si vous exécutez ce programme, vous verrez que le message est bien écrit dans le fichier "output.txt".

### 1.5.6. execve()

La fonction `execve()` est utilisée pour exécuter un programme à partir d'un processus en remplaçant l'image de ce processus par celle du programme. Elle prend en entrée le chemin d'accès au programme à exécuter, un tableau d'arguments pour le programme, ainsi qu'un tableau d'environnement pour le programme.

La syntaxe de la fonction est la suivante :

```c
int execve(const char *path, char *const argv[], char *const envp[]);
```

où `path` est le chemin d'accès au programme à exécuter, `argv` est un tableau d'arguments pour le programme et `envp` est un tableau d'environnement pour le programme.

La fonction `execve()` ne retourne pas en cas de succès. En cas d'erreur, elle retourne -1.

Lorsqu'un processus appelle la fonction `execve()`, il est remplacé par le programme spécifié par `path`, qui est exécuté à la place. Les arguments pour le programme sont passés dans `argv` et l'environnement pour le programme est passé dans `envp`. Le premier élément de `argv` doit être le nom du programme, et le dernier élément de argv doit être NULL.

La fonction `execve()` est souvent utilisée en conjonction avec la fonction `fork()`. Le processus parent appelle `fork()` pour créer un nouveau processus, puis le processus enfant appelle `execve()` pour exécuter un nouveau programme.

Voici un exemple qui illustre l'utilisation de la fonction `execve()` pour exécuter le programme "hello" avec des arguments :

```c
#include <unistd.h>

int main() {
    char *args[] = { "hello", "world", NULL };
    char *env[] = { "PATH=/usr/bin", NULL };

    execve("/home/user/hello", args, env);

    return 0;
}
```

Dans cet exemple, nous avons créé un tableau `args` contenant deux arguments pour le programme "hello". Nous avons également créé un tableau `env` contenant une variable d'environnement `PATH`. Nous appelons ensuite la fonction `execve()` pour exécuter le programme "hello" en utilisant les arguments et l'environnement spécifiés.

Notez que si la fonction `execve()` réussit, le programme courant est remplacé par le programme spécifié par `path` et le code qui suit l'appel à `execve()` ne sera jamais exécuté. Si `execve()` échoue, elle retourne -1 et le programme courant continue à s'exécuter.

### 1.5.7. fork()

La fonction `fork()` en C permet de créer un nouveau processus appelé "processus enfant" qui est une copie du "processus parent". Les deux processus, parent et enfant, continuent ensuite leur exécution à partir de l'instruction suivant l'appel à `fork()`.

La syntaxe de la fonction est la suivante :

```c
pid_t fork(void);
```

La fonction `fork()` ne prend pas d'argument et renvoie un `pid_t`, qui est un type de données permettant de stocker l'identifiant du processus. Si la fonction réussit, elle retourne 0 dans le processus enfant et l'identifiant du processus enfant dans le processus parent. Si la fonction échoue, elle renvoie -1 dans le processus parent et aucun processus enfant n'est créé.

Lorsque `fork()` est appelée, le processus parent crée une copie exacte de lui-même appelée "processus enfant". Les deux processus partagent alors la même image mémoire jusqu'à ce que l'un d'eux modifie une partie de cette image. À ce moment-là, le système d'exploitation crée une copie distincte de la zone mémoire modifiée pour le processus qui l'a modifiée.

Le processus parent et le processus enfant disposent chacun de leur propre espace de pile et de registres de processeur, mais partagent les mêmes descripteurs de fichiers. Cela signifie que, si le processus parent a ouvert un fichier, le processus enfant aura également accès à ce fichier.

Voici un exemple simple d'utilisation de `fork()` pour créer un nouveau processus enfant :

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Je suis le processus enfant\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Je suis le processus parent\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
```

Dans cet exemple, nous appelons la fonction `fork()` pour créer un nouveau processus enfant. Si `fork()` retourne -1, cela signifie qu'une erreur s'est produite et nous affichons un message d'erreur en utilisant la fonction `perror()` et sortons du programme avec `EXIT_FAILURE`.

Si `fork()` retourne 0, cela signifie que nous sommes dans le processus enfant. Nous affichons alors un message pour indiquer que nous sommes dans le processus enfant, puis nous sortons du programme avec `EXIT_SUCCESS`.

Si `fork()` retourne un identifiant de processus différent de 0, cela signifie que nous sommes dans le processus parent. Nous affichons alors un message pour indiquer que nous sommes dans le processus parent, puis nous sortons du programme avec `EXIT_SUCCESS`.

Notez que le message "Je suis le processus enfant" est affiché deux fois, une fois dans le processus parent et une fois dans le processus enfant. Cela se produit parce que les deux processus exécutent la même instruction. Cependant, le message "Je suis le processus parent" n'est affiché qu'une seule fois, car seule l'instruction qui suit `if (pid == 0)` est exécutée dans le processus enfant, tandis que l'instruction qui suitelse est exécutée dans le processus parent.

La fonction `fork()` est souvent utilisée en conjonction avec d'autres fonctions système pour créer des programmes plus complexes. Par exemple, un programme peut utiliser `fork()` pour créer plusieurs processus, chacun exécutant une partie différente du programme, puis utiliser la fonction `wait()` pour attendre la fin de chaque processus avant de continuer.

Il est important de noter que chaque processus a son propre espace d'adressage virtuel, ce qui signifie que les modifications apportées à la mémoire dans un processus ne sont pas visibles dans les autres processus. Cela signifie également que chaque processus a sa propre copie des variables et des fichiers ouverts. Si vous voulez que deux processus communiquent entre eux, vous devez utiliser des mécanismes de communication interprocessus tels que les pipes ou les sockets.

En résumé, la fonction `fork()` permet de créer un nouveau processus enfant qui est une copie exacte du processus parent. Les deux processus partagent la même image mémoire jusqu'à ce qu'un processus modifie une partie de cette image. Le processus parent et le processus enfant disposent chacun de leur propre espace de pile et de registres de processeur, mais partagent les mêmes descripteurs de fichiers. La fonction `fork()` est souvent utilisée en conjonction avec d'autres fonctions système pour créer des programmes plus complexes.

### 1.5.8. pipe()

La fonction `pipe()` est une fonction système en C qui permet de créer un canal de communication unidirectionnel entre deux processus. Ce canal, appelé pipe, peut être utilisé pour transmettre des données entre les deux processus. Le pipe est implémenté en utilisant un tampon en mémoire partagé entre les deux processus.

La fonction `pipe()` prend un tableau de deux entiers en paramètre. Ces entiers représentent les descripteurs de fichiers du pipe. Le descripteur de fichier `fd[0]` est utilisé pour la lecture et `fd[1]` est utilisé pour l'écriture. Le processus père utilise généralement `fd[1]` pour écrire des données dans le pipe, tandis que le processus enfant utilise `fd[0]` pour lire ces données.

La création d'un pipe est souvent utilisée en conjonction avec la fonction `fork()`. Après la création d'un pipe, le processus parent utilise `fork()` pour créer un nouveau processus enfant. Le processus parent ferme ensuite son propre descripteur de fichier `fd[0]` et le processus enfant ferme son propre descripteur de fichier `fd[1]`. De cette façon, le processus parent et le processus enfant ont chacun un descripteur de fichier différent pour le pipe et peuvent communiquer entre eux en écrivant et en lisant des données dans le pipe.

Par exemple, le processus parent peut écrire des données dans le pipe en utilisant la fonction `write()` et le processus enfant peut lire ces données en utilisant la fonction `read()`. Il est important de noter que la lecture et l'écriture dans un pipe sont bloquantes par défaut, ce qui signifie que si le tampon est vide, le processus en lecture sera bloqué jusqu'à ce que des données soient écrites dans le pipe, et si le tampon est plein, le processus en écriture sera bloqué jusqu'à ce que les données soient lues par le processus en lecture.

En résumé, la fonction `pipe()` permet de créer un canal de communication unidirectionnel entre deux processus en utilisant un tampon en mémoire partagé. Le processus parent utilise généralement `fd[1]` pour écrire des données dans le pipe, tandis que le processus enfant utilise `fd[0]` pour lire ces données. La création d'un pipe est souvent utilisée en conjonction avec la fonction `fork()` pour créer un nouveau processus enfant et communiquer entre les processus.

La fonction `pipe()` est utilisée pour créer un canal de communication unidirectionnel entre deux processus en utilisant un tampon en mémoire partagé. Voici un exemple de son utilisation :

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int fd[2];
    pid_t pid;
    char buf[20];

    // Créer un pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Créer un nouveau processus enfant
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Processus enfant
        // Fermer le descripteur de fichier d'écriture
        close(fd[1]);

        // Lire les données à partir du pipe
        if (read(fd[0], buf, sizeof(buf)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Afficher les données lues
        printf("Processus enfant : %s\n", buf);

        // Fermer le descripteur de fichier de lecture
        close(fd[0]);
        exit(EXIT_SUCCESS);
    } else { // Processus parent
        // Fermer le descripteur de fichier de lecture
        close(fd[0]);

        // Écrire des données dans le pipe
        if (write(fd[1], "Hello, world!", 14) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Fermer le descripteur de fichier d'écriture
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
}
```

Dans cet exemple, nous créons un pipe en utilisant la fonction `pipe()` et stockons les descripteurs de fichiers retournés dans le tableau fd. Nous créons ensuite un nouveau processus enfant en utilisant la fonction `fork()`. Le processus enfant ferme son propre descripteur de fichier d'écriture `fd[1]`, lit les données à partir du pipe en utilisant la fonction `read()`, puis affiche les données lues à l'écran. Le processus parent ferme son propre descripteur de fichier de lecture `fd[0]`, écrit des données dans le pipe en utilisant la fonction `write()`, puis ferme son propre descripteur de fichier d'écriture `fd[1]`.

L'exécution du programme produit la sortie suivante :

```bash
Processus enfant : Hello, world!
```

Cela montre que le processus parent a écrit des données dans le pipe et que le processus enfant les a lues avec succès.

### 1.5.9. unlink()

La fonction `unlink()` est utilisée pour supprimer un fichier du système de fichiers. Voici sa signature :

```c
int unlink(const char *path);
```

La fonction prend en paramètre le chemin d'accès au fichier à supprimer. Elle retourne 0 en cas de succès et -1 en cas d'erreur.

Voici un exemple d'utilisation de la fonction `unlink()` :

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *filename = "file.txt";

    // Créer un fichier
    if (creat(filename, 0644) == -1) {
        perror("creat");
        exit(EXIT_FAILURE);
    }

    // Vérifier l'existence du fichier
    if (access(filename, F_OK) == -1) {
        perror("access");
        exit(EXIT_FAILURE);
    }

    // Supprimer le fichier
    if (unlink(filename) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    // Vérifier que le fichier n'existe plus
    if (access(filename, F_OK) == 0) {
        printf("Le fichier existe encore\n");
        exit(EXIT_FAILURE);
    }

    printf("Le fichier a été supprimé avec succès\n");
    exit(EXIT_SUCCESS);
}
```

Dans cet exemple, nous créons un fichier en utilisant la fonction `creat()`. Nous vérifions ensuite l'existence du fichier en utilisant la fonction `access()`, puis nous supprimons le fichier en utilisant la fonction `unlink()`. Nous vérifions enfin que le fichier n'existe plus en utilisant à nouveau la fonction access().

L'exécution du programme produit la sortie suivante :

```bash
Le fichier a été supprimé avec succès
```

Cela montre que le fichier a été créé, supprimé avec succès, et n'existe plus sur le système de fichiers.

### 1.5.10. wait()

La fonction `wait()` est utilisée dans les programmes multi-processus pour attendre la fin d'un processus fils. Voici sa signature :

```c
pid_t wait(int *status);
```

La fonction prend en paramètre un pointeur vers un entier `status` qui sera utilisé pour stocker le code de sortie du processus fils. Elle retourne l'identifiant du processus fils qui a terminé son exécution.

Si aucun processus fils n'est en train de s'exécuter au moment de l'appel à `wait()`, la fonction se bloque jusqu'à ce qu'un processus fils termine son exécution. Si plusieurs processus fils sont en train de s'exécuter, la fonction attend la fin de n'importe quel processus fils.

Voici un exemple d'utilisation de la fonction `wait()` :

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Code du processus fils
        printf("Je suis le processus fils (%d)\n", getpid());
        sleep(2);
        exit(EXIT_SUCCESS);
    } else {
        // Code du processus parent
        printf("Je suis le processus parent (%d)\n", getpid());
        printf("Attente de la fin du processus fils...\n");
        pid = wait(&status);
        if (pid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Le processus fils (%d) a terminé avec le code de sortie %d\n", pid, status);
    }

    exit(EXIT_SUCCESS);
}
```

Dans cet exemple, nous créons un processus fils en utilisant la fonction `fork()`. Le processus fils affiche un message, attend deux secondes, puis se termine en appelant `exit()`. Le processus parent attend la fin du processus fils en utilisant la fonction `wait()`, puis affiche le code de sortie du processus fils.

L'exécution du programme produit la sortie suivante :

```bash
Je suis le processus parent (1234)
Attente de la fin du processus fils...
Je suis le processus fils (1235)
Le processus fils (1235) a terminé avec le code de sortie 0
```

Cela montre que le processus parent a attendu la fin du processus fils en utilisant la fonction `wait()`, puis a affiché le code de sortie du processus fils.

### 1.5.11. waitpid()

La fonction `waitpid()` est similaire à la fonction `wait()`, mais elle permet de spécifier le processus fils à attendre et de contrôler son comportement. Voici sa signature :

```c
pid_t waitpid(pid_t pid, int *status, int options);
```

Le premier paramètre `pid` est l'identifiant du processus fils à attendre. Si `pid` vaut `-1`, la fonction attend la fin de n'importe quel processus fils. Si `pid` vaut `0`, la fonction attend la fin de n'importe quel processus fils dont le groupe de processus est identique à celui du processus appelant. Si `pid` est positif, la fonction attend la fin du processus fils dont l'identifiant correspond à `pid`.

Le deuxième paramètre `status` est un pointeur vers un entier qui sera utilisé pour stocker le code de sortie du processus fils.

Le troisième paramètre `options` est un entier qui peut être utilisé pour contrôler le comportement de la fonction. Par exemple, l'option `WNOHANG` permet de retourner immédiatement si aucun processus fils n'a terminé son exécution.

La fonction `waitpid()` retourne l'identifiant du processus fils qui a terminé son exécution, ou `-1` en cas d'erreur.

Voici un exemple d'utilisation de la fonction `waitpid()` :

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1, pid2;
    int status1, status2;

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Code du premier processus fils
        printf("Je suis le premier processus fils (%d)\n", getpid());
        sleep(2);
        exit(42);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Code du deuxième processus fils
        printf("Je suis le deuxième processus fils (%d)\n", getpid());
        sleep(3);
        exit(66);
    }

    printf("Attente de la fin des processus fils...\n");

    // Attente de la fin du premier processus fils
    pid1 = waitpid(pid1, &status1, 0);
    if (pid1 == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
    printf("Le premier processus fils (%d) a terminé avec le code de sortie %d\n", pid1, status1);

    // Attente de la fin du deuxième processus fils
    pid2 = waitpid(pid2, &status2, 0);
    if (pid2 == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
    printf("Le deuxième processus fils (%d) a terminé avec le code de sortie %d\n", pid2, status2);

    exit(EXIT_SUCCESS);
}
```

Dans cet exemple, nous créons deux processus fils en utilisant la fonction `fork()`. Chaque processus fils affiche un message, attend un certain temps, puis se termine en appelant `exit()` avec un code de sortie différent. Le processus parent attend la fin des deux processus fils en appelant deux fois la fonction `waitpid()`. À chaque appel, nous passons l'identifiant du processus fils à attendre ainsi qu'un pointeur vers une variable qui sera utilisée pour stocker le code de sortie. La fonction waitpid() est appelée deux fois avec les options par défaut (0), ce qui signifie qu'elle attend la fin complète de chaque processus fils.

Lorsqu'un processus fils se termine, le processus parent est réveillé et peut récupérer le code de sortie du processus fils en lisant la valeur stockée dans la variable passée en deuxième argument. Le processus parent peut alors afficher un message pour indiquer quelle tâche a été accomplie par chaque processus fils.

Notez que la fonction `waitpid()` est bloquante, c'est-à-dire qu'elle ne retourne que lorsque le processus fils a terminé son exécution. Si vous voulez attendre la fin d'un processus fils sans bloquer le processus parent, vous pouvez utiliser l'option `WNOHANG`, qui permet de retourner immédiatement si aucun processus fils n'a terminé son exécution.

## Déroulement

1. Vérifier que le bon nombre d'argument est reçu
2. Ouvrir le `file_1` avec `open()` et les bons paramètre (Lecture seul, erreur si non existant)
3. Ouvrire le `file_2` avec `open()` et les bons paramètre

## 1.6. Liens utiles

### 1.6.1. Vidéos

- [The fork() function in C](https://www.youtube.com/watch?v=cex9XrZCU14)
- [Waiting for processes to finish (using the wait function) in C](https://www.youtube.com/watch?v=tcYo6hipaSA)
- [Communicating between processes (using pipes) in C](https://www.youtube.com/watch?v=Mqb2dVRe0uo)

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define CMD1_POS 2
#define CMD2_POS 3
#define FILE1_POS 1
#define FILE2_POS 4

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	child_process(char *cmd, char **envp, int in_fd, int out_fd)
{
	char	**cmd_args;
	char	*path;

	if (!(cmd_args = ft_split(cmd, ' ')))
		exit_error("Failed to split command");
	if (!(path = ft_strjoin("/bin/", cmd_args[0])))
		exit_error("Failed to join command path");
	if (dup2(in_fd, STDIN_FILENO) == -1)
		exit_error("Failed to dup2");
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		exit_error("Failed to dup2");
	close(in_fd);
	close(out_fd);
	execve(path, cmd_args, envp);
	exit_error("Failed to execute command");
}

int		main(int argc, char **argv, char **envp)
{
	int		file1;
	int		file2;
	int		pipes[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit_error("Invalid number of arguments");
	if ((file1 = open(argv[FILE1_POS], O_RDONLY)) == -1)
		exit_error("Failed to open file 1");
	if ((file2 = open(argv[FILE2_POS], O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		exit_error("Failed to open file 2");
	if (pipe(pipes) == -1)
		exit_error("Failed to create pipe");

	if ((pid1 = fork()) == -1)
		exit_error("Failed to fork");
	else if (pid1 == 0)
		child_process(argv[CMD1_POS], envp, file1, pipes[1]);
	close(pipes[1]);

	if ((pid2 = fork()) == -1)
		exit_error("Failed to fork");
	else if (pid2 == 0)
		child_process(argv[CMD2_POS], envp, pipes[0], file2);
	close(pipes[0]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(file1);
	close(file2);
	return (0);
}
```
