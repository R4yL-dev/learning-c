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
- [ ] Initialize items and player structure.
  - [ ] Get player position.
  - [ ] Get collectibles position.
  - [ ] Get exit position.
  - [ ] Remplace player, exit and collectible position in map by empty.
- [ ] Initialize game.
  - [ ] Initialize window.
  - [ ] Create background with map in memory.
  - [ ] Place collectible and exit with items structure.
  - [ ] Place player at initial position with player structure.
- [ ] Run game.
  - [ ] Is the player on a collectible ?
  - [ ] Want the player move into a wall ?
