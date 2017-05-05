#include "pacman.h"
#include <time.h>
#include <stdlib.h>

int randomizer(int a, int b, int c, int d, int condition) {
	int direction[4];
	int i;
	int temp;
	temp = 0;
	i = 0;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 4; i++)	{
		direction[i] = rand() % 100;
	}
	i = 0;

	if (condition == 1) direction[2] = -1;
	if (condition == 2) direction[3] = -1;
	if (condition == 3) direction[0] = -1;
	if (condition == 4) direction[1] = -1;

	if (a == 0) direction[0] = -1;
	if (b == 0) direction[1] = -1;
	if (c == 0) direction[2] = -1;
	if (d == 0) direction[3] = -1;

	for (i = 0; i < 4; i++) {
		if (direction[i] > direction[temp]) temp = i;
	}

	return temp + 1;
}

// emermy moving algorithm
// 간단히 레벨에 맞게 속도 변화
void AI(void) {
	cpu_loop = 0;
	/*1*/
	if (cpu_start[0] == 0) {
		if (cpupos_z[0] < 3 - 0.01) {
			cpupos_z[0] += 0.01;
		}
		else {
			cpu_start[0] = 1;
			cpu_direction[0] = 1;
		}
	}
	/*2*/
	if (cpu_start[1] == 0 && cpu_start[0] == 1) {
		if (cpupos_z[1] < 3 - 0.01) {
			cpupos_z[1] += 0.01;
		}
		else {
			cpu_start[1] = 1;
			cpu_direction[1] = 3;
		}
	}
	/*3*/
	if (cpu_start[2] == 0 && cpu_start[1] == 1) {
		if (cpupos_z[2] < 3 - 0.01) {
			cpupos_z[2] += 0.01;
		}
		else {
			cpu_start[2] = 1;
			cpu_direction[2] = 1;
		}
	}
	/*4*/
	if (cpu_start[3] == 0 && cpu_start[2] == 1) {
		if (cpupos_z[3] < 3 - 0.01) {
			cpupos_z[3] += 0.01;
		}
		else {
			cpu_start[3] = 1;
			cpu_direction[3] = 3;
		}
	}

	for (cpu_loop = 0; cpu_loop <= 4; cpu_loop++) {
		/*1*/
		if (cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -15 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*2
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -15 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -15 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*3
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -15 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -15 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*4
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -15 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -15 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*5
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*6
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*7
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*8
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*9
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*10
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*11
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*12
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*13
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*14
		*/ if (cpupos_x[cpu_loop] >= -10 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -10 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*15
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}

		/*16
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*17
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*18
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*19
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*20
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*21
		*/ if (cpupos_x[cpu_loop] >= 11 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 11 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*22
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*23
		*/ if (cpupos_x[cpu_loop] >= -10 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -10 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*24
		*/ if (cpupos_x[cpu_loop] >= 11 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 11 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -12 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*25
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*26
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 0 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 0 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*27
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*28
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*29
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*30
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*31
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 0 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 0 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}

		/*32
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*33
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*34
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*35
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*36
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*37
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*38
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*39
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 0, cpu_direction[cpu_loop]);
		}

		/*40
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*41
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*42
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*43
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}

		/*44
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*45
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}

		/*46
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*47
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*48
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 0, cpu_direction[cpu_loop]);
		}

		/*49
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*50
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*51
		*/ if (cpupos_x[cpu_loop] >= -12 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -12 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*52
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*53
		*/ if (cpupos_x[cpu_loop] >= -1 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -1 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*54
		*/ if (cpupos_x[cpu_loop] >= 2 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 2 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 0, 4, cpu_direction[cpu_loop]);
		}

		/*55
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*56
		*/ if (cpupos_x[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 13 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 13 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 13 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 0, 3, 4, cpu_direction[cpu_loop]);
		}

		/*57
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*58
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -6 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -6 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*59
		*/ if (cpupos_x[cpu_loop] >= -4 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -4 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}


		/*60
		*/ if (cpupos_x[cpu_loop] >= 5 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 5 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= -3 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= -3 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*61
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 0 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 0 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 0, 4, cpu_direction[cpu_loop]);
		}

		/*62
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 0 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 0 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(0, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*63
		*/ if (cpupos_x[cpu_loop] >= -7 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= -7 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 4, cpu_direction[cpu_loop]);
		}

		/*64
		*/ if (cpupos_x[cpu_loop] >= 8 - 0.05 * cpu_speed && cpupos_x[cpu_loop] <= 8 + 0.05 * cpu_speed && cpupos_z[cpu_loop] >= 9 - 0.05 * cpu_speed && cpupos_z[cpu_loop] <= 9 + 0.05 * cpu_speed)
		{
			cpu_direction[cpu_loop] = randomizer(1, 2, 3, 4, cpu_direction[cpu_loop]);
		}
	}
	cpu_loop = 0;
}



