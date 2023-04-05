/*
PREPROCESSOR

Examples of using C's macro preprocessor.
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void stringification()
{
    // '#' is the stringification operator
    // It converts macro arguments into quoted strings.
    #define print_with_newline(x) printf(#x "\n")

    print_with_newline(In quotes via the printf function call.);
    print_with_newline("In quotes when printed to the screen.");
}

struct command
{
  char *name;
  void (*function) (void);
};

void (*quit_command) (void);
void (*help_command) (void);

void tokenPasting()
{
    // # = stringification
    // ## = token concatenation (token pasting) operator
    #define COMMAND(NAME)  { #NAME, NAME ## _command }

    // COMMAND(NAME) defines the macro
    // '{' and '} surround the replaced data
    // #NAME converts the NAME arg into a stringified version
    //      ex: converts 'quit' into "quit" and 'help' into "help"
    // NAME is replaced by 'quit' and 'help' (no quotes)
    // ## pastes tokens to create 'quit_command' and 'help_command' (no quotes)

    struct command commands[] =
    {
        COMMAND(quit),
        COMMAND(help)
    };

    // COMMAND(quit) expands into => { "quit", quit_command }
    // COMMAND(help) expands into => { "help", help_command }
    /* Complete expansion creates an array of two structs:

    struct command commands[] =
    {
        { "quit", quit_command },
        { "help", help_command }
    };
    */

    assert(strcmp(commands[0].name, "quit") == 0);
    assert(strcmp(commands[1].name, "help") == 0);
}

int main()
{
    stringification();
    tokenPasting();
    return 0;
}
