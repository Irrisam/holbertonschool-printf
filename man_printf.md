.TH PRINTF 3 "March 2023" "Version 1.0" "User Commands"

.SH NAME
_printf - prints things thanks to external adapted functions

.SH SYNOPSIS
\fB#include <main.h>\fR
.br
\fBint _printf(const char *format, ...);\fR

.SH DESCRIPTION
The \fB_printf\fR function formats and prints data according to the format
specifier \fIformat\fR. The function writes output to the standard output and
keeps count of the printed bytes. The function returns the number of bytes
written.

The format specifier consists of zero or more directives, which are used to
format the data. Each directive starts with a % character, followed by an
optional flag and optional modifiers, followed by a conversion specifier
character that determines the type of data to be printed.

The supported conversion specifier characters are:

.TP
\fB%c\fR
Prints a character.

.TP
\fB%s\fR
Prints a string.

.TP
\fB%i\fR, \fB%d\fR
Prints an integer.

.TP
\fB%%\fR
Prints a % character.

.SH RETURN VALUE
The \fB_printf\fR function returns the number of bytes written, excluding the
null byte at the end of the output.

On error, the function returns a negative value.

.SH EXAMPLES
The following example demonstrates the usage of the \fB_printf\fR function:

.nf
#include <stdio.h>
#include "main.h"

int main(void)
{
_printf("Hello, %s!\n", "world");
_printf("The answer is %d.\n", 42);
return (0);
}
.fi

The output of this program is:

.nf
Hello, world!
The answer is 42.
.fi

.SH ERRORS
The \fB_printf\fR function fails and returns a negative value in the following
cases:

.TP
format is \fBNULL\fR.

.TP
The conversion specifier is not recognized.

.SH SEE ALSO
printf(3)

.SH AUTHOR
Written by Tristan et Benjamin.
