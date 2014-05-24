## Usage ##
```
#!bash
./42sh [--verbose]
```

--verbose: affiche les lexems parsés avant l'éxécution d'une commande.

## Makefile ##

```
#!bash

make [rule] [MODE=debug|release]
```


exemples:

```
#!bash

make re MODE=debug # recompile tout en mode debug (gcc -g)
make re            # recompile tout en mode release (gcc -O3)
```


## Notes ##
[zoli dessin](https://docs.google.com/drawings/d/1onj-TkuuqKqZyILVbRrlkrvAVMpRFn9NRbZADQ7mwg4/edit?usp=sharing)