# randomizer
A simple randomizer that chooses one option from the set insered by the user.

## Usage
Just compile the source code with `gcc` or your favourite C compiler:

```shell
gcc -o randomizer ./randomizer.c
```

Then run the program:
```shell
./randomizer 3
```

The user have to insert the number of options as inline argument.
Then he will be prompted to insert the name of every option:
```shell
Option 1: Pizza
Option 2: Sushi
Option 3: >
```

After few seconds, the program will show the results:
```shell
I ran this drawing 26840 times.
Pizza won 24.61% times.
Sushi won 35.44% times.
Tacos won 39.95% times.
The winner is Tacos.
```
