
# _printf function

This project is a group project to create our own printf function, which is a commonly used function in the C programming language to print output on the console.

## Usage

Our printf function works similarly to the standard printf function, but has some differences in terms of its usage.

```c
#include "main.h"

int _printf(const char *format, ...);
```
The `_printf` function is called with a string `format` containing text and format specifiers. The format specifiers start with the `%` character followed by a conversion specifier. Additional arguments corresponding to the format specifiers can be passed to `_printf` after the format string.

```c
_printf("Hello, %s!\n", "Taieb");
```
This would output `Hello, Taieb!`.

## Return value

The `_printf` function returns the number of characters printed to the standard output.

## Supported Conversion Specifiers

Our printf function also supports many of the format specifiers used in the standard printf function. 
Every format specification starts with a percent sign and ends with a letter. 

Our printf can support :

`%c` - print a single character.

`%s` - print a string of characters.

`%i, %d` - Prints a signed integer in base 10.

`%%` - print a percent sign.

## Examples

Here are some examples of how to use `_printf`:

```c
#include "main.h"

int main(void)
{
    _printf("Hello, i am %s!\n", "Taieb");
    _printf("I am %d years old.\n", 42);
    _printf("My favorite signs are lion and %% sign and the second one is printed literally.\n");
    _printf("%c and %c are the bests.\n", 'T', 'B');
    return (0);
}
```
This would output:

```c
Hello, i am Taieb!
I am 42 years old.
My favorite signs are lion is % sign and the second one is printed literally.
T and B are the bests.
```

## Authors

This project was created by [Tristan](https://github.com/Irrisam) and [Benjamin](https://github.com/yliaze) as part of the Holberton School curriculum.

