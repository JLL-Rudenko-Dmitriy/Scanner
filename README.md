# Простой сканер портов на c++
## || Утилита для сканирования открытых портов. 
### Запуск программы может осуществляться в двух режимах:
>1. Scanner \<ip> \<port1>, \<port2>, ... , \<port_n>       //Переадать список портов для сканирования
>2. Scanner \<ip> -r <start_port>, <end_port>               //Передать диапазон для сканирования

### Как собрать проект:
> cmake .. -G Ninja\
> cmake --build . 

### Скриншот запуска утилиты
> ![example](https://github.com/JLL-Rudenko-Dmitriy/Scanner/blob/main/launch.jpg)
