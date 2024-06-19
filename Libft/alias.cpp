#include <iostream>
#include <fstream>
#include <cstdlib>

void ft_putstr_fd(const char* s, std::ostream& os)
{
    os << s;
}

int main() {
    const char* filename = "Makefile";

    std::ofstream file(filename, std::ios::out | std::ios::app);

    if (!file.is_open()) 
    {
        perror("Error opening the file");
        return 1;
    }
    else 
    {
        ft_putstr_fd("\ntest: all \n", file);
        ft_putstr_fd("\t$(CC) main.c libft.a\n", file);
        ft_putstr_fd("\t./a.out\n", file);
        ft_putstr_fd("\t@rm a.out\n", file);
        ft_putstr_fd("\t@make fclean\n", file);
    }

    file.close();
    return 0;
}
