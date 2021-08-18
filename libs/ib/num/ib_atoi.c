/*
** EPITECH PROJECT, 2020
** ib_atoi
** File description:
** returns a number, sent to the function as a string
*/

int ib_atoi(char const *s)
{
    int number = 0;
    int negative = 1;
    int i = 0;

    for (; s[i] == '-'; i++, negative *= -1);
    for (; s[i] != '\0'; i++) {
        number *= 10;
        number += s[i] - '0';
    }
    return (number * negative);
}