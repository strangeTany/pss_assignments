#include <iostream>
#include "Users/Director.h"

int main() {
    Director director = *(new Director("Giancarlo", "Succi", "g.succi@innopolis.ru"));
    return 0;
}
