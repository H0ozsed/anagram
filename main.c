#include <stdio.h>
#include <unistd.h>

int option_error(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Error: not enough arguments.", 28);
        return 84;
    }
    return 0;
}

int my_strlen(char *sent)
{
  int count = 0;

    for (int i = 0; sent[i] != '\0'; i++)
        count++;
    return count;
}

char *dowm_case(char sent[])
{
    for (int i = 0; sent[i] != '\0'; i++) {
        if (sent[i] >= 65 && sent[i] <= 90) {
            sent[i] += 32;
        }
    }
  return sent;
}

int count_char(char *av1, char *av2)
{
    int char1 = 0;
    int char2 = 0;

    for (int i = 0; av1[i] != '\0'; i++) {
        char1 += av1[i];
        char2 += av2[i];
    }
    if (char1 == char2) {
        write(1, "anagrams!\n", 10);
    } else { 
      write(1, "no anagrams.\n", 13);
    }
}

int check_anagram(char **av)
{
    int len_1 = my_strlen(av[1]);
    int len_2 = my_strlen(av[2]);

    if (len_1 != len_2) {
        write(1, "no anagrams.\n", 13);
        return 0;
    }
    count_char(dowm_case(av[1]), dowm_case(av[2]));
}

int main(int ac, char **av)
{
    if (option_error(ac, av) == 84)
        return 84;
    check_anagram(av);
    return 0;
}
