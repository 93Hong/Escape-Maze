#include <glut.h>
#include "pacman.h"

void specialKeyPressed(int key) {
	if (game_routine_running == 1) {
		if (direction == 0) {
			if (key == GLUT_KEY_UP) {
				weight_x = 1;
				weight_z = 0;
			}
			else if (key == GLUT_KEY_DOWN) {
				weight_x = -1;
				weight_z = 0;
			}

			else if (key == GLUT_KEY_RIGHT) {
				weight_x = 0;
				weight_z = 1;
			}

			else if (key == GLUT_KEY_LEFT) {
				weight_x = 0;
				weight_z = -1;
			}

			if (seta == 1) {
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 2) {
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 3) {
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 4) {
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 5) {
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 6)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 7)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 8)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 9)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 10)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 11)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 12)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 13)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 14)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 15)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 16)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 17)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 18)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 19)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 20)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 21)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
			}

			if (seta == 22)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 23)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 24)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 25)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;

			}

			if (seta == 26)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 27)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 28)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 29)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
			}
			if (seta == 30)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 31)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;

			}

			if (seta == 32)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 33)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 34)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 35)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 36)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 37)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 38)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 39)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 40)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 41)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;

			}

			if (seta == 42)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 43)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
			}

			if (seta == 44)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 45)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
			}

			if (seta == 46)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 47)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 48)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_DOWN) direction = 3;
				if (key == GLUT_KEY_RIGHT) direction = 2;
			}

			if (seta == 49)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 50)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 51)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;

			}

			if (seta == 52)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 53)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 54)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
			}

			if (seta == 55)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 56)
			{
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 57)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 58)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 59)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
			}

			if (seta == 60)
			{
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 61)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 62)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 63)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}

			if (seta == 64)
			{
				if (key == GLUT_KEY_UP) direction = 1;
				if (key == GLUT_KEY_LEFT) direction = 4;
				if (key == GLUT_KEY_RIGHT) direction = 2;
				if (key == GLUT_KEY_DOWN) direction = 3;
			}
		}
	}
}
