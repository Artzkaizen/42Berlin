#!/bin/sh

norminette -R CheckForbiddenSourceHeader *.c
cc -Wall -Werror -Wextra -o ./output/rush00 rush00.c main.c ft_putchar.c && echo " " && echo "======= Rush 00 =======" && ./output/rush00
cc -Wall -Werror -Wextra -o ./output/rush01 rush01.c main.c ft_putchar.c && echo " " && echo "======= Rush 01 =======" && ./output/rush00
cc -Wall -Werror -Wextra -o ./output/rush02 rush02.c main.c ft_putchar.c && echo " " && echo "======= Rush 02 =======" && ./output/rush02
cc -Wall -Werror -Wextra -o ./output/rush03 rush03.c main.c ft_putchar.c && echo " " && echo "======= Rush 03 =======" && ./output/rush03
cc -Wall -Werror -Wextra -o ./output/rush04 rush04.c main.c ft_putchar.c && echo " " && echo "======= Rush 04 =======" && ./output/rush04