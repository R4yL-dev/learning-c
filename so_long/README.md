# So_long

## TODO

- [X] Parse argument.
  - [X] As exacly one argument ?
  - [X] Is the file extention .ber ?
  - [X] Is the path valide and the file readable ?
- [X] Load map into memory.
  - [X] Get the file content in one string.
  - [X] Get the number of rows.
  - [X] Get the number of colonnes.
- [X] Check if map is valide.
  - [X] Is map a rectangle ?
  - [X] Is map surronded by wall ?
  - [X] As map one play and exit and at least one collectible ?
  - [X] Can the player access all collectibles and the exit ?
- [X] Initialize items and player structure.
  - [X] Get player position.
  - [X] Get collectibles position.
  - [X] Get exit position.
  - [X] Remplace player, exit and collectible position in map by empty.
- [X] Initialize game.
  - [X] Initialize window.
  - [X] Create background with map in memory.
  - [X] Place collectible and exit with items structure.
  - [X] Place player at initial position with player structure.
- [x] Run game.
  - [X] Is the player on a collectible ?
  - [X] Want the player move into a wall ?
- [ ] Check leaks
