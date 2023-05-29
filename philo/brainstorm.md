# 1. Brainstorm

## 1.1. TOC

- [1. Brainstorm](#1-brainstorm)
	- [1.1. TOC](#11-toc)
	- [1.2. Questionnements](#12-questionnements)
		- [1.2.1. C'est quoi un thread ?](#121-cest-quoi-un-thread-)
		- [1.2.2. C'est quoi un processus ?](#122-cest-quoi-un-processus-)
		- [1.2.3. Différances entre thread et processus](#123-différances-entre-thread-et-processus)
		- [1.2.4. C'est quoi un mutex ?](#124-cest-quoi-un-mutex-)
		- [1.2.5. C'est quoi un data race ?](#125-cest-quoi-un-data-race-)
		- [1.2.6. C'est quoi un deadlock ?](#126-cest-quoi-un-deadlock-)
	- [1.3. Fonctions autorisées](#13-fonctions-autorisées)
		- [1.3.1. memset()](#131-memset)
		- [1.3.2. usleep()](#132-usleep)
		- [1.3.3. gettimeofday()](#133-gettimeofday)
		- [1.3.4. pthread\_create()](#134-pthread_create)
		- [1.3.5. pthread\_detach()](#135-pthread_detach)
		- [1.3.6. pthread\_join()](#136-pthread_join)
		- [1.3.7. pthread\_mutex\_init()](#137-pthread_mutex_init)
		- [1.3.8. pthread\_mutex\_destroy()](#138-pthread_mutex_destroy)
		- [1.3.9. pthread\_mutex\_lock()](#139-pthread_mutex_lock)
		- [1.3.10. pthread\_mutex\_unlock()](#1310-pthread_mutex_unlock)
	- [Déroulement du programme](#déroulement-du-programme)
	- [Structure de données](#structure-de-données)
		- [Context](#context)
		- [Philosophes](#philosophes)
	- [1.4. Ressources](#14-ressources)


## 1.2. Questionnements

### 1.2.1. C'est quoi un thread ?

Une thread (ou fil d'exécution) est une séquence d'instruction qui peut être exécutée simultanément avec d'autres threads dans un programme informatique. Un thread est un sous-processus léger qui partage la même mémoire et les mêmes ressources système que les autres threads d'un même processus.

Les threads sont souvent utilisés pour exécuter des tâches parallèles dans un programme, ce qui peut améliorer les performances et l'efficacité en tirant parti des processeurs multicoeurs ou des processeurs hyperthreading. Par exemple, un programme graphique peut utiliser un thread pour effectuer des calculs intensifs en arrière-plan tout en affichant une interface utilisateur réactive pour l 'utilsiateur.

Les threads peuvent être créés, gérés et synchronisés dans un programme à l'aide de biblothèques de threads telles que pthreads en C. Les threads peuvent être créés pour exécuter des fonctions spécifiques ou pour travailler sur des tâches spécifiques, et pour être gérés pour contrôler leur ordre d'exécution ou leur priorité.

Cependant, l'utilisation de plusieurs threads dans un programme peut également causer des problèmes de synchronisation et de concurrence si les threads accèdent simultanément à des ressources partagées sans les protéger avec des méchanismes de synchronisation tels que les mutex, les sémaphores ou les variables de condition.

### 1.2.2. C'est quoi un processus ?

Un processus est une instance en cours d'exécution d'un programme informatique. Chaque processus dispose de son propre espace mémoire privé et des ses propres ressources système, telles que les fichiers ouverts, les sockets de réseau et les variables d'environnement.

Un processus peut être lancé en exécutant un programme à partir de la ligne de commande ou en utilisant l'interface graphique d'un système d'exploitation. Le système d'exploitation crée alors un nouveau processus en lui allouant des ressources système, en chargeant le code du programme en mémoire et en initalisant les variables d'environnement et les descripteurs de fichiers. Le processus peut alors s'exécuter de manière autonome, en effectuant des opérations sur ses propres ressources et en interagissant avec d'autres processus ou avec le système d'exploitation.

Les processus peuvent être exécutés en mode utilsiateur ou en mode privilégié, selon les droits d'accès accordés par le système d'exploitation. Les processus en mode privilégié ont un accès complet aux ressources systèmes et peuvent effectuer des opérations qui ne sont pas autorisées pour les processus en mode utilsiateur, tels que l'installation de pilotesde périphériques ou la modification de la configuration du système.

Les processus peuvent communiquer entre eux en utilisant des mécanisme de communication interprocessus tels que les pipes, les sockets de réseau, les signaux ou les mémoires partagées. Les processus peuvent également être gérer par le système d'exploitation en utilisant des outls tels que le planificateur de processus, qui contrôle l'ordre d'exécution des processus en fonction de leur priorité et de leur état.

### 1.2.3. Différances entre thread et processus

Les processus sont des entités autonomes et indépendantes qui peuvent communiquer entre elles, tandis que les threads sont des sous-processus légers qui partagent la méme mémoire et les mêmes ressources système dans un même processus. Les threads peuvent être utilisés pour exécuter des tâches parallèles dans un même programme, ce qui peut améliorer les performances et l'efficacité, mais nécessite également une gestion appropriée de la synchronisation de la concurrence.

### 1.2.4. C'est quoi un mutex ?

Un mutex est un objet de synchronisation utilisé pour garantir que deux threads ou processus n'accèdent pas simultanément à une ressources partagée, telle qu'une variable ou une zone mémoire, qui pourrait entrainer des erreurs de cohérence de données ou des conflits de concurrence.

Le terme "mutex" est l'abréviation de "mutual exclusion", ce qui signifie exclusion mutuelle en français. Un mutex est un objet qui permet de réguler l'accès concurrentiel à une ressource partagée, en garantissant que seulement un thread ou processus à la fois peut y accéder.

En pratique, un mutex est utilisé pour bloquer l'accès à une ressource partagée avant que le thread ou le processus ne l'utilise, puis pour le débloquer une fois que l'opération est terminée. Si un autre thread ou processus tente d'accéder à la ressource pendant que le mutex esst verrouillé, il sera mis en attente jusqu'à ce que le mutex soit déverrouillé.

Les mutex sont souvent utilisés en conjonction avec d'autres objets de synchronisation tels que les sémaphores ou les variable conditionnelles pour mettre en place des méchanismes de synchronisation plus complexes et éviter les problèmes de concurrence et de synchonisation entre les threads ou processus.

### 1.2.5. C'est quoi un data race ?

Un data race est un problème de concurrence qui se produit lorsqu'au moins deux threads accèdent simultanément à la même variable ou à la même zone de mémoire partagée, sans synchronisation appropriée entre eux, et qu'au moins l'un de ces accès est une opération d'écriture.

Lorsque'un data race se produit, le résultat du programme devient indéterminé et peut varier en fonction de l'ordre d'exécution des threads, de la plate-forme matérielle, du compilateur ou d'autres facteurs. Cela peut entrainer des erreurs de comportement ou des plantages de l'application, et peut être difficile à diagnostiquer et à corriger.

### 1.2.6. C'est quoi un deadlock ?

Un deadlock, ou blocage mutuel en français, est une situation dans laquelle deux ou plusieurs threads ou processus se bloque les uns les autres en attendant qu'une ressource qu'ils ont tous demandé soit libérée, sans que l'un d'entre eux ne puisse avancer.

Par exemple, supposons que deux threads, A et B, aient besoin de deux ressources R1 et R2 respectivement pour terminer leur tâche. Si le thread A obtient la ressource R1 et le thread B obtient la ressource R2, et que chaqun tente ensuite d'obtenir la ressource qu'il n'a pas encore, ils se bloqueront mutuellement, car la ressource demandée est détenue par l'autre thread. Dans ce cas, les threads A et B sont tous deux bloqués et ne peuvent pas continuer, même s'ils ont encore des ressources disponible.

## 1.3. Fonctions autorisées

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

### 1.3.1. memset()

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

### 1.3.2. usleep()

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

### 1.3.3. gettimeofday()

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

### 1.3.4. pthread_create()

La fonction `pthread_create()` est une fonction de la bibliothèque pthread. Elle permet de créer un nouveau thread dans un programme C/C++. Elle prend en paramètre un pointeur vers unevariable de type `pthread_t` qui représente le thread créé, ainsi qu un pointeur vers une fonction qui sera exécutée par le thread.

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```

- `thread` est un pointeur vers unevariable de type `thread_t` qui sera utilisée pour identifier le thread créé.
- `attr` est un pointeur vers une structure `pthread_attr_t` contenant des attributs spécifiques au thread (par exemple, la taille de la pile, la planification, etc). Si `attr` est NULL,les attributes par défaut sont utilisés.
- `start_routine` est un pointeur vers une fonctionque sera exécutée par le thread. Cette fonction doit prendre un paramètre de type `void*` et retourner un pointeurde type `void*`.
- `arg` est un pointeur générique qui est passé en tantqu argument à la fonction `start_routine`. Il peut être utilisépour transmettre des données au thread.

Lorsque la fonction `pthread_create()` est appelée, un mnouveau thread est créé et commence à exécuter la fonction spécifiée par `start_routine` en parallèle avec le thread appelant.Le nouveau thread partage le même espace d adressage que le thread appelant, ce qui signifie qu-il peut accéder aux variables globales et partager des données avec d autres threads.

La fonction `pthread_create` renvoie 0 si le thread a pu demarrer avec succè et un code d erreur si un problème c est produit.

Il est important de noter que la fonction `pthread_create()` ne garantit pas l ordre d exécution des threads.L ordonnancement des threads est déterminé par le systeme d exploitation et peut varier à chaque exécutiondu programme. Pour synchoniser les threads et gérer l accès concurrentiel aux ressources partagées,d autres méchanisme de synchronisation, tels que les mutex ou les sémaphores,doivent être utilisés.

```c
#include <stdio.h>
#include <pthread.h>

void *routine(void *message)
{
	char *msg = (char *)message;
	printf("%s\n", msg);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	char *message = "Hello la team !";

	int result = pthread_create(&thread, NULL, routine, (void *)message);
	if (result == 0)
	{
		printf("Erreur lors de la création du thread.");
		return (-1);
	}
	pthread_join(thread, NULL);
	printf("Fin de l exectution du thread.");
	return (0);
}
```

### 1.3.5. pthread_detach()

La fonction `pthread_detach()` est utilisée pour détacher un thread. Lorsqu un thread est détaché, il peut se terminer de manière autonome sans nécessiterqu un autre thread appelle la fonction `pthread_join()` pour récupérer ses ressources.

```c
int pthread_detach(pthread_t thread);
```

- `thread` est le thread qu lon souhaite détacher.

Lorsque la fonction `pthread_detach()` est appelée avec un thread en tant que paramètre, elle marque le thread spécifié comme détacher. Cela signifie que le thread peut se terminer de manièreautonome et libérer ses ressources lorsqu ila terminé sonexécution, sans qu un autre thread ne doive appeler explicitement `pthread_join()`.

Une fois qu un thread est détaché, il ne peut plus être rejoint (`pthread_join()`) ou détaché à nouveau. La fonction `pthread_detach()` doit être appelée avant que le thread n achève son exécution.

Il est recommandé de détacher les threads qui sont créés uniquement pour effectuer des tâches autonome et qui n ont pas besoin d être attendus ou dans les résultat ne sont pas nécessaires pour le thread principal. Cela permet d évité le besoin de garder une référence active au thread et simplifie la gestion des ressources.

```c
#include <stdio.h>
#include <pthread.h>

void *routine(void *arg)
{
	printf("Thread en cours d execution.\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	int result = pthread_create(&thread, NULL, routine, NULL);

	if (result != 0)
	{
		printf("Erreur lors de la création du thread.\n");
		return (-1);
	}
	result = pthread_detach(thread);
	if (result != 0)
	{
		printf("Erreur lors du detachement du thread.\n");
		return (-1);
	}
	printf("Thread principal continue son execution\n");
	return (0);
}
```

### 1.3.6. pthread_join()

La focntion `pthread_join()` est utilisée pour attendre la fin d un thread. Elle permet à un thread appelant de bloquer son exécution jusqu à ce que le thread spécifié se termine.

```c
int pthread_join(pthread_t thread, void **retval);
```

- `thread` est le thread que l on souhaite rejoindre.
- `retval` est un poinbteur vers un pointeur générique dans lequel la valeur de retour du thread sera stockée. Si cette valeur de retourn n est pas nécessaire, on peut passer `NULL` à `retval`.

Lorsque la fonction `pthread_join()` est appelée avec un thread en tant que paramètre, le thread appelant se bloque jusqu à ce que le thread spécifié se termine. Une fois que le thread civle a terminé son exécutiuo, le thread appelant reprend son exécution.

De plus, si `retval` n est pas `NULL`, la valeur de retour du thread cible est stockée à l adresse spéciifié par `retval`. Cette valeur de retour peut être utilisée pour récupérer dfes informations du thread ciblem telles qu un code de sortie ou un résultat de calcule.

Il est important de noter que `pthread_join()` be libère pars automatiquement les ressources associées au thread cible. Elle attend simplement que le thread se termine et permet au thread appelant de récupérer la valeur de retour et de contonuer son exécution. Après l appel à `pthread_join()`, le thread cible est considéré comme"joignable", ce que signifie qu il peut être rejoint ultérieurement avec `pthread_join()` ou détacher avec `pthread_detach`.

Il est nessécaire de rejoindre tous les threads "joignable" créér avec `pthread_create()` afin d éviter des fuites de ressources et d assurer la terminaison appropriée de tous les threads.

```c
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread %d en cours d'exécution.\n", thread_id);

    // Effectuer des calculs ou d'autres tâches
    // ...

    int *result = malloc(sizeof(int));
    *result = thread_id * 2;
    pthread_exit(result);
}

int main() {
    pthread_t thread1, thread2;
    int thread_id1 = 1;
    int thread_id2 = 2;

    // Création du premier thread
    int result1 = pthread_create(&thread1, NULL, thread_function, (void *)&thread_id1);
    if (result1 != 0) {
        printf("Erreur lors de la création du thread 1.\n");
        return -1;
    }

    // Création du deuxième thread
    int result2 = pthread_create(&thread2, NULL, thread_function, (void *)&thread_id2);
    if (result2 != 0) {
        printf("Erreur lors de la création du thread 2.\n");
        return -1;
    }

    // Attente de la fin du premier thread
    int *thread1_result;
    pthread_join(thread1, (void **)&thread1_result);
    printf("Thread 1 terminé. Résultat : %d\n", *thread1_result);
    free(thread1_result);

    // Attente de la fin du deuxième thread
    int *thread2_result;
    pthread_join(thread2, (void **)&thread2_result);
    printf("Thread 2 terminé. Résultat : %d\n", *thread2_result);
    free(thread2_result);

    printf("Threads terminés. Fin du programme.\n");

    return 0;
}

```

### 1.3.7. pthread_mutex_init()

La fonction `pthread_mutex_init()` est utilisée pour initaliser un mutex (verrou) avant son utilisation dans un programmemulti-threadé. Un mutex est un méchanisme de synchronisationqui permet de contrôler l accès concurrent à une ressource partagée par plussieurs threads. Le mutex garantit qu un seul thread à la fois peut accéder à cette ressource, assurant ainsi la cohérence des données et évitant les conditions de concurrence.

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_r *attr);
```

- `mutex` est un pointeur vers la structure du mutex à initialiser.
- `attr` est un pointeur facultatif vers un objet `pthread_mutexattr_t` contenant des attributs de configuration supplémentaires pour le mutex.Si vous ne souhaitez pas spécifier d attributs supplémentaire, vous pouvez passer `NULL` à cet argument.

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex; // Déclaration du mutex

int main() {
    // Initialisation du mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Erreur lors de l'initialisation du mutex.\n");
        return -1;
    }

    // Utilisation du mutex pour synchroniser l'accès à une ressource partagée

    // ...

    // Destruction du mutex lorsque vous avez terminé son utilisation
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

### 1.3.8. pthread_mutex_destroy()

La fonction `pthread_mutex_destroy()` est utilisé pour détruire un mutex (verrou). Il est important de détruire chaque mutex avant la fin de l exécution du programme afin d éviter les fuites de mémoire.

```c
int pthread_mhutex_destroy(pthread_mutex_t *mutex);
```

- `mutex`, un pointeur vers la structure du mutex à détruire.

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex; // Déclaration du mutex

int main() {
    // Initialisation du mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Erreur lors de l'initialisation du mutex.\n");
        return -1;
    }

    // Utilisation du mutex pour synchroniser l'accès à une ressource partagée

    // ...

    // Destruction du mutex lorsque vous avez terminé son utilisation
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

### 1.3.9. pthread_mutex_lock()

La fonction `pthread_mutex_lock` est utilisée pour acquérir un mutex das un programme. Lorsqu un thread appelle cette fonction, il tente de verouillier le mutex. Si le mutex est déjà verrouillié  par un autre thread, le thread en cours d exécution sera mis en pause jusqu a ce que le mutedx soit dispoknible.

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

- `mutex` est un pointeur vers la structure du mutex.

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex; // Déclaration du mutex

void* threadFunction(void* arg) {
    // Tentative d'acquérir le verrou du mutex
    pthread_mutex_lock(&mutex);

    // Section critique du code protégée par le mutex

    // ...

    // Libération du verrou du mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialisation du mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Erreur lors de l'initialisation du mutex.\n");
        return -1;
    }

    // Création du thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0) {
        printf("Erreur lors de la création du thread.\n");
        return -1;
    }

    // Attente de la fin du thread
    if (pthread_join(thread, NULL) != 0) {
        printf("Erreur lors de l'attente du thread.\n");
        return -1;
    }

    // Destruction du mutex lorsque vous avez terminé son utilisation
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

### 1.3.10. pthread_mutex_unlock()

La fonction `pthread_mutex_unlock()` est utilisée pour libérer un mutex précédament acquis. Elle premet de signalé la fin d une section critique du code et de permettre à d autres threads d acquérir le mutex pour accéder à la meme ressource partagée.

```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

Il est important de noté qu il faut que se soit le thread qui a acquis le mutex qui doit le libérer.

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex; // Déclaration du mutex

void* threadFunction(void* arg) {
    // Acquérir le verrou du mutex
    pthread_mutex_lock(&mutex);

    // Section critique du code protégée par le mutex

    // ...

    // Libérer le verrou du mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialisation du mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Erreur lors de l'initialisation du mutex.\n");
        return -1;
    }

    // Création du thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0) {
        printf("Erreur lors de la création du thread.\n");
        return -1;
    }

    // Attente de la fin du thread
    if (pthread_join(thread, NULL) != 0) {
        printf("Erreur lors de l'attente du thread.\n");
        return -1;
    }

    // Destruction du mutex lorsque vous avez terminé son utilisation
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

## Déroulement du programme

1. Parser les argument.
2. Construire le contexte.
   1. Construir les philos et leur fourchette.
3. Lancer le thread pour le superviseur et lui donner le contexte.
4. Le superviseurs lance la simulation (run tous les threads des philos).
5. Le superviseurs attend qu on philo meur (retourne).
   1. Le superviseurs annonce la mort du philo au autres philos.
6. Attendre la fin de tous les philos et clean la mémoire.

## Structure de données

### Context

Ce que je veux stocker dans le contexte ?

- Le timestampe du début de la simulation
- Le nombre de philos
- Si un philo est mort
- Le mutex pour l affichage
- La liste des philos


```c
typedef struct s_context
{
	t_time			start;
	int				nbrs_philos;
	int				is_a_philo_dead;
	pthread_mutex_t	mutex_print;
	t_philos		*philos;
}	t_context;
```

```c
typedef struct s_timing
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_timing;
```

### Philosophes

```c
typedef struct s_philo
{
	int				id;
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;
	int				nbrs_time_eat;
	timing_t		timing;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}	t_philo;
```

## 1.4. Ressources

- [GH de widium - Très bonne explication](https://github.com/widium/Philosopher)
- [Playlist YT de CodeVault sur les threads](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
