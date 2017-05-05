
#ifndef __pacman_h__
#define __pacman_h__
#endif

#include <glut.h>

void start_game();
void stop_game();
void success();
void reset_game();
void reset_food();
void tormaysmallinnus();
void AI();
void init_3d_objects();
void save_highscore(int new_score);

GLfloat foodx[320], foodz[320];
int food_eaten[320];
int foodloop;

float polygonx1[50];
float polygony1[50];

float polygonx2[50];
float polygony2[50];

float polygonx3[50];
float polygony3[50];

float polygonx4[50];
float polygony4[50];


int direction;
int seta;

GLfloat pacpos_x, pacpos_z, pacposy;
float pac_speed;

signed int level;
signed int lives;


signed int cpu_loop;
int cpu_direction[5];
GLfloat cpupos_x[5], cpupos_z[5], cpupos_y;
signed int cpu_start[4];
float cpu_speed;

int demo_mode;

int food_remaining;

void specialKeyPressed(int key);
int score;
float height;
signed int game_routine_running;
int highscore_int;
signed int update_highscore;
static GLint fogMode;
int weight_x, weight_z;