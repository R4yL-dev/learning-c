# Philosophers

## TODO

- Il faut que je test sur le hardware de 42 car mon laptop (petit cpu) peux avoir du mal sur le longterme à garder les threads synchro. Je ne sais pas si c est mon CPU ou ma simulation.

## Structure

```bash
├── docs
│   ├── brainstorm.md
│   └── fr.subject.pdf
├── philo
│   ├── headers
│   │   ├── philo.h
│   │   ├── phiengine.h
│   │   ├── structures.h
│   │   └── simulation.h
│   ├── phiengin
│   │   ├── args_parser.c
│   │   ├── context.c
│   │   ├── philos_list.c
│   │   ├── philo.c
│   │   ├── threads.c
│   │   ├── time_utils.c
│   │   ├── timing.c
│   │   └── utils.c
│   ├── simulation
│   │   ├── simulation.c
│   │   ├── routine.c
│   │   ├── routine_solo.c
│   │   ├── rtn_utils.c
│   │   ├── rtn_eat.c
│   │   ├── rtn_eat_utils.c
│   │   ├── rtn_sleep.c
│   │   ├── rtn_think.c
│   │   ├── supervisor.c
│   │   └── sv_utils.c
│   ├── main.c
│   └── Makefile
└── README.md
```
