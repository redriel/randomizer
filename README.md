# randomizer
A simple randomizer that chooses one option from the set insered by the user.

## Usage
Simply compile with gcc the source code:

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
I ran this drawing 268435456 times.
Pizza won 71342503 times.
Sushi won 97898064 times.
Fast food won 99194889 times.
```