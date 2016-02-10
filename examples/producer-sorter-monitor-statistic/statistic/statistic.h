#ifndef STATISTIC_H
#define STATISTIC_H

#include "lib.h"

#define SLEEPING_TIME 5

struct NumberPrototype {
	int number;
	int count;
};

struct NumberRanking {
	struct NumberPrototype place_one;
	struct NumberPrototype place_two;
	struct NumberPrototype place_three;
};

#endif