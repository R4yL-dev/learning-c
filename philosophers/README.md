# Philosophers

## TODO

- Ajouter la gestion du nombre de repas
- Refaire l affichage pour que se soit joli
- Verifier les leaks
- Verifier les datas races
- Verifier la norme

## Structure

```bash
philo/
├── docs/
│   ├── brainstorm.md
│   ├── fr.subject.pdf
├── headers/
│   ├── philo.h
│   ├── phiengine.h
│   ├── structures.h
│   ├── simulation.h
├── phiengin/
│   ├── args_parser.c
│   ├── context.c
│   ├── philos_list.c
│   ├── philo.c
│   ├── threads.c
│   ├── time_utils.c
│   ├── timing.c
│   ├── utils.c
├── simulation/
│   ├── simulation.c
│   ├── routine.c
│   ├── rtn_utils.c
│   ├── rtn_eat.c
│   ├── rtn_eat_utils.c
│   ├── rtn_sleep.c
│   ├── rtn_think.c
│   ├── supervisor.c
├── main.h
├── Makefile
├── README.md
```
