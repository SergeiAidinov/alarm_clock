![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Debian](https://img.shields.io/badge/Debian-D70A53?style=for-the-badge&logo=debian&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-black?style=for-the-badge&logo=clion&logoColor=white)

Учебный проект на языке программирования "Си", иммитирующий работу будильника.

Для запуска проекта необходимо установить доплонительные библиотеки следуюзей командой:

    sudo apt-get install libncurses5-dev libncursesw5-dev

Компиляция осуществляется командой:

    gcc -o alarm alarm_clock.c -lncurses

Запуск проекта:

    ./alarm HOUR MINUTES \n
    , где HOUR и MINUTES - часы и минуты срабатывания будильника. 
