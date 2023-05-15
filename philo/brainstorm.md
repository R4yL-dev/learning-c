# 1. Brainstorm

## 1.1. TOC

- [1. Brainstorm](#1-brainstorm)
	- [1.1. TOC](#11-toc)
	- [Questionnements](#questionnements)
		- [1.2. C'est quoi un thread ?](#12-cest-quoi-un-thread-)
		- [1.3. C'est quoi un processus ?](#13-cest-quoi-un-processus-)
		- [1.4. Différances entre thread et processus](#14-différances-entre-thread-et-processus)
		- [1.5. C'est quoi un mutex ?](#15-cest-quoi-un-mutex-)
		- [1.6. C'est quoi un data race ?](#16-cest-quoi-un-data-race-)
		- [C'est quoi un deadlock ?](#cest-quoi-un-deadlock-)
	- [1.7. Fonctions autorisées](#17-fonctions-autorisées)
		- [1.7.1. memset()](#171-memset)
		- [1.7.2. usleep()](#172-usleep)
		- [1.7.3. gettimeofday()](#173-gettimeofday)
		- [1.7.4. pthread\_create()](#174-pthread_create)
		- [1.7.5. pthread\_detach()](#175-pthread_detach)
		- [1.7.6. pthread\_join()](#176-pthread_join)
		- [1.7.7. pthread\_mutex\_init()](#177-pthread_mutex_init)
		- [1.7.8. pthread\_mutex\_destroy()](#178-pthread_mutex_destroy)
		- [1.7.9. pthread\_mutex\_lock()](#179-pthread_mutex_lock)
		- [1.7.10. pthread\_mutex\_unlock()](#1710-pthread_mutex_unlock)
	- [Ressources](#ressources)


## Questionnements

### 1.2. C'est quoi un thread ?

Une thread (ou fil d'exécution) est une séquence d'instruction qui peut être exécutée simultanément avec d'autres threads dans un programme informatique. Un thread est un sous-processus léger qui partage la même mémoire et les mêmes ressources système que les autres threads d'un même processus.

Les threads sont souvent utilisés pour exécuter des tâches parallèles dans un programme, ce qui peut améliorer les performances et l'efficacité en tirant parti des processeurs multicoeurs ou des processeurs hyperthreading. Par exemple, un programme graphique peut utiliser un thread pour effectuer des calculs intensifs en arrière-plan tout en affichant une interface utilisateur réactive pour l 'utilsiateur.

Les threads peuvent être créés, gérés et synchronisés dans un programme à l'aide de biblothèques de threads telles que pthreads en C. Les threads peuvent être créés pour exécuter des fonctions spécifiques ou pour travailler sur des tâches spécifiques, et pour être gérés pour contrôler leur ordre d'exécution ou leur priorité.

Cependant, l'utilisation de plusieurs threads dans un programme peut également causer des problèmes de synchronisation et de concurrence si les threads accèdent simultanément à des ressources partagées sans les protéger avec des méchanismes de synchronisation tels que les mutex, les sémaphores ou les variables de condition.

### 1.3. C'est quoi un processus ?

Un processus est une instance en cours d'exécution d'un programme informatique. Chaque processus dispose de son propre espace mémoire privé et des ses propres ressources système, telles que les fichiers ouverts, les sockets de réseau et les variables d'environnement.

Un processus peut être lancé en exécutant un programme à partir de la ligne de commande ou en utilisant l'interface graphique d'un système d'exploitation. Le système d'exploitation crée alors un nouveau processus en lui allouant des ressources système, en chargeant le code du programme en mémoire et en initalisant les variables d'environnement et les descripteurs de fichiers. Le processus peut alors s'exécuter de manière autonome, en effectuant des opérations sur ses propres ressources et en interagissant avec d'autres processus ou avec le système d'exploitation.

Les processus peuvent être exécutés en mode utilsiateur ou en mode privilégié, selon les droits d'accès accordés par le système d'exploitation. Les processus en mode privilégié ont un accès complet aux ressources systèmes et peuvent effectuer des opérations qui ne sont pas autorisées pour les processus en mode utilsiateur, tels que l'installation de pilotesde périphériques ou la modification de la configuration du système.

Les processus peuvent communiquer entre eux en utilisant des mécanisme de communication interprocessus tels que les pipes, les sockets de réseau, les signaux ou les mémoires partagées. Les processus peuvent également être gérer par le système d'exploitation en utilisant des outls tels que le planificateur de processus, qui contrôle l'ordre d'exécution des processus en fonction de leur priorité et de leur état.

### 1.4. Différances entre thread et processus

Les processus sont des entités autonomes et indépendantes qui peuvent communiquer entre elles, tandis que les threads sont des sous-processus légers qui partagent la méme mémoire et les mêmes ressources système dans un même processus. Les threads peuvent être utilisés pour exécuter des tâches parallèles dans un même programme, ce qui peut améliorer les performances et l'efficacité, mais nécessite également une gestion appropriée de la synchronisation de la concurrence.

### 1.5. C'est quoi un mutex ?

Un mutex est un objet de synchronisation utilisé pour garantir que deux threads ou processus n'accèdent pas simultanément à une ressources partagée, telle qu'une variable ou une zone mémoire, qui pourrait entrainer des erreurs de cohérence de données ou des conflits de concurrence.

Le terme "mutex" est l'abréviation de "mutual exclusion", ce qui signifie exclusion mutuelle en français. Un mutex est un objet qui permet de réguler l'accès concurrentiel à une ressource partagée, en garantissant que seulement un thread ou processus à la fois peut y accéder.

En pratique, un mutex est utilisé pour bloquer l'accès à une ressource partagée avant que le thread ou le processus ne l'utilise, puis pour le débloquer une fois que l'opération est terminée. Si un autre thread ou processus tente d'accéder à la ressource pendant que le mutex esst verrouillé, il sera mis en attente jusqu'à ce que le mutex soit déverrouillé.

Les mutex sont souvent utilisés en conjonction avec d'autres objets de synchronisation tels que les sémaphores ou les variable conditionnelles pour mettre en place des méchanismes de synchronisation plus complexes et éviter les problèmes de concurrence et de synchonisation entre les threads ou processus.

### 1.6. C'est quoi un data race ?

Un data race est un problème de concurrence qui se produit lorsqu'au moins deux threads accèdent simultanément à la même variable ou à la même zone de mémoire partagée, sans synchronisation appropriée entre eux, et qu'au moins l'un de ces accès est une opération d'écriture.

Lorsque'un data race se produit, le résultat du programme devient indéterminé et peut varier en fonction de l'ordre d'exécution des threads, de la plate-forme matérielle, du compilateur ou d'autres facteurs. Cela peut entrainer des erreurs de comportement ou des plantages de l'application, et peut être difficile à diagnostiquer et à corriger.

### C'est quoi un deadlock ?

Un deadlock, ou blocage mutuel en français, est une situation dans laquelle deux ou plusieurs threads ou processus se bloque les uns les autres en attendant qu'une ressource qu'ils ont tous demandé soit libérée, sans que l'un d'entre eux ne puisse avancer.

Par exemple, supposons que deux threads, A et B, aient besoin de deux ressources R1 et R2 respectivement pour terminer leur tâche. Si le thread A obtient la ressource R1 et le thread B obtient la ressource R2, et que chaqun tente ensuite d'obtenir la ressource qu'il n'a pas encore, ils se bloqueront mutuellement, car la ressource demandée est détenue par l'autre thread. Dans ce cas, les threads A et B sont tous deux bloqués et ne peuvent pas continuer, même s'ils ont encore des ressources disponible.

## 1.7. Fonctions autorisées

- memset()*,
- printf(),
- malloc(),
- free(),
- write(),
- usleep()*,
- gettimeofday()*,
- pthread_create()*,
- pthread_detach()*,
- pthread_join()*,
- pthread_mutex_init()*,
- pthread_mutex_destroy()*,
- pthread_mutex_lock()*,
- pthread_mutex_unlock()*

### 1.7.1. memset()

La fonction `memset()` est une fonction de la bibliothèque standard. Elle est utilisée pour remplir un bloc de mémoire avec une valeur donnée.

```c
void *memset(void *ptr, int value, size_t num);
```

- Le premier paramètre `ptr` est un pointeur ver le bloc de mémoire à remplir.
- Le deuxième paramètre `value` est la valeur qui doit être écrite dans chaque octet de la zone de mémoire. Cette valeur est de type `int`, mais elle est généralement fournie sous la forme d'un `unsigned char` pour éviter les problème de signe.
- le troisème paramètre `num` est le nombre d'octet à remplir avec la valeur donnée.

la fonction `memset()` est souvent utilisée pour initialiser une zone mémoire à une valeur spécifique, comme par exemple initialiser un tableau ou une structure à 0.

Voici un exemple d'utilisation de `memset()` pour initialiser un tableau de 10 entier à 0 :

```c
#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10];

    // Initialiser le tableau à zéro
    memset(arr, 0, sizeof(arr));

    // Afficher le contenu du tableau
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

```bash
0 0 0 0 0 0 0 0 0 0
```

Voici un exemple de l'utilisation de `memset()` pour initialiser une structure à 0 :

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

int main()
{
    Employee emp;

    // Initialiser la structure à zéro
    memset(&emp, 0, sizeof(emp));

    // Afficher le contenu de la structure
    printf("ID: %d\n", emp.id);
    printf("Nom: %s\n", emp.name);
    printf("Salaire: %.2f\n", emp.salary);

    return 0;
}
```

```bash
ID: 0
Nom:
Salaire: 0.00
```

### 1.7.2. usleep()

la fonction `usleep()` est une fonction de la bibliothèque standard. Elle permet de suspendre l'exécution du programme pendant un certain nombre de microsecondes.

```bash
int usleep(useconds_t microseconds);
```

- Le paramètre `micorseconds` spécifie le nombre de microsecondes pendant lesquelles l'éexécution du programme doit être suspendue.

La fonction `usleep()` est souvent utilisée pour introduire des délais dans les programmes, par exemple pour simuler un temps de traitement ou pour synchroniser l'exécution de plusieurs threads.

Voici un exemple de l'utilisation de la fonction `usleep()` pour introduire un délai de 1 seconde dans un programme :

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Début du délai...\n");

    // Attendre 1 seconde
    usleep(1000000);

    printf("Fin du délai.\n");

    return 0;
}
```

### 1.7.3. gettimeofday()

La fonction `gettimeofday()` est une fonction de la bibliothèque standard. Elle permet d'obtenir le temps actuel en microsecondes depuis le 1er janvier 1970 à minuit (temps UNIX).

```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
```

La fonction `gettimeofday()` prend deux paramètre : `tv` et `tz`.

Le paramètre `tv` est un pointeur vers une structure `timeval` qui est remplie avec l'heure actuelle en secondes et microsecondes.

Le paramètre `tz` est un pointeur vers une structure `timezone` qui peut être utilisée pour obtenir le décalage horaire actuel par rapport à UTC.

La fonction `gettimeofday()` renvoie 0 en cas de succès et -1 en cas d'erreur.

Voici un exemple d'utilistion de la fonction `gettimeofday()` pour mesurer le temps d'exécution d'un programme :

```c
#include <stdio.h>
#include <sys/time.h>

int main()
{
    struct timeval start_time, end_time;
    double elapsed_time;

    // Obtenir le temps de début
    gettimeofday(&start_time, NULL);

    // Code à mesurer
    printf("Début de l'exécution...\n");
    for (int i = 0; i < 1000000; i++) {
        // Ne rien faire
    }
    printf("Fin de l'exécution.\n");

    // Obtenir le temps de fin
    gettimeofday(&end_time, NULL);

    // Calculer le temps écoulé en secondes
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    printf("Temps d'exécution : %.6f secondes\n", elapsed_time);

    return 0;
}
```

### 1.7.4. pthread_create()

### 1.7.5. pthread_detach()

### 1.7.6. pthread_join()

### 1.7.7. pthread_mutex_init()

### 1.7.8. pthread_mutex_destroy()

### 1.7.9. pthread_mutex_lock()

### 1.7.10. pthread_mutex_unlock()

## Ressources

- [GH de widium - Très bonne explication](https://github.com/widium/Philosopher)
- [Playlist YT de CodeVault sur les threads](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
