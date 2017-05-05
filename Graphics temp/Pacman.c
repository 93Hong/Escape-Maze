// 이전 버전 함수 때문에
#pragma warning(disable:4996)

#include <glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pacman.h"

#define ESCAPE 27
#define PAGE_UP 73
#define PAGE_DOWN 81
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define SPACE 57
#define PI 3.14159265358979323846

typedef struct _object {
	GLfloat*        vertices;    // vertex array
	GLfloat*        colors;      // color array
	GLubyte*        indices;     // index
	int             nums;        // number of vertices
	GLfloat         theta[3];    // rotation parameter (x, y, z)
	GLfloat         trans[3];    // translation parameter
	struct _object* next;
	struct _object* child;

	int            type; // 0 , 1 (원), 2 (원뿔)
	GLfloat         val[4];
	GLfloat         color[3];
} Object;

// ---------------------------------------------------------------------------------------------
// Data
// ---------------------------------------------------------------------------------------------

GLfloat vertices[][3] = { { -0.01,-0.05,-0.01 },{ 0.01,-0.05,-0.01 },{ 0.01,0.05,-0.01 },{ -0.01,0.05,-0.01 },
{ -0.02,-0.05, 0.02 },{ 0.01,-0.05, 0.01 },{ 0.01,0.05, 0.01 },{ -0.01,0.05, 0.01 } };
GLfloat colors[][3] = { { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 1.0,1.0, 0.0 },{ 0.0,1.0, 0.0 },
{ 0.0, 0.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0,1.0, 1.0 },{ 0.0,1.0, 1.0 } };
GLubyte indices[] = { 0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };

// array 1 (top)
GLfloat vertices1[][3] = { { -0.01,-0.3,-0.01 },{ 0.01,-0.3,-0.01 },{ 0.01,0.05,-0.01 },{ -0.01,0.05,-0.01 },
{ -0.01,-0.3, 0.01 },{ 0.01,-0.3, 0.01 },{ 0.01,0.05, 0.01 },{ -0.01,0.05, 0.01 } };
GLfloat colors1[][3] = { { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 1.0,1.0, 0.0 },{ 0.0,1.0, 0.0 },
{ 0.0, 0.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0,1.0, 1.0 },{ 0.0,1.0, 1.0 } };
GLubyte indices1[] = { 0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };

GLfloat vertices2[][3] = { { -0.01,-0.05,-0.01 },{ 0.01,-0.05,-0.01 },{ 0.01,0.05,-0.01 },{ -0.01,0.05,-0.01 },
{ -0.01,-0.05, 0.01 },{ 0.01,-0.05, 0.01 },{ 0.01,0.05, 0.01 },{ -0.01,0.05, 0.01 } };
GLfloat colors2[][3] = { { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 1.0,1.0, 0.0 },{ 0.0,1.0, 0.0 },
{ 0.0, 0.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0,1.0, 1.0 },{ 0.0,1.0, 1.0 } };
GLubyte indices2[] = { 0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };



// ---------------------------------------------------------------------------------------------
// Objects
// ---------------------------------------------------------------------------------------------

Object root, head, nouse, eye1, eye2, eyeblow1, eyeblow2, leftArm, rightArm, leftFinger1, leftFinger2,
rightFinger1, rightFinger2;

int window;
float rotate;

char teksti[100];
char itoa_buffer[100];

int i, r1, r2, kita1, kita2;
float xpos, ypos, zpos;
int angleOfView;
float angle, anim_x, anim_y;

GLfloat z = 0.0f;
GLfloat y_rot;
GLfloat tmp = 0;
GLfloat kita_angle = 0;
GLfloat jump;
GLfloat foodrotate;
GLfloat lookupdown = 0.0;
const float piover180 = 0.00874532925f;
int repeat;
float rotate_view;
float rotation_y;
float win_x, win_z;
signed int level_complete;

GLfloat ambient[] = { 4.0, 1.0, 0.0, 1.0 };
GLfloat diffuse[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat local_view[] = { 0.0 };
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.7, 0.0, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 50.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
GLfloat mat_red_pill[] = { 255.0, 0.0, 0.0, 0.0 };
GLfloat mat_green[] = { 0.0, 255.0, 0.0, 1.0 };
GLfloat mat_red[] = { 255.0, 0.0, 0.0, 1.0 };
GLfloat mat_yellow[] = { 255.0, 255.0, 0.0, 1.0 };
GLfloat mat_blue[] = { 0.0, 0.0, 1.0, 1.0 };


static char *circles[] = {
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xx..............",
	"xxxxxxxxxxxxxxxx",
	"xxxxxxxxxxxxxxxx",
};

void draw(Object* p) {
	glPushMatrix();

	// transformation
	glTranslatef(p->trans[0], p->trans[1], p->trans[2]);
	glRotatef(p->theta[0], 1.0, 0.0, 0.0);
	glRotatef(p->theta[1], 0.0, 1.0, 0.0);
	glRotatef(p->theta[2], 0.0, 0.0, 1.0);

	if (p->type == 0) {
		// draw
		glVertexPointer(3, GL_FLOAT, 0, p->vertices);
		glColorPointer(3, GL_FLOAT, 0, p->colors);
		glDrawElements(GL_QUADS, p->nums, GL_UNSIGNED_BYTE, p->indices);
	}
	else if (p->type == 1) {
		glColor3f(p->color[0], p->color[1], p->color[2]);
		glutSolidSphere(p->val[0], p->val[2], p->val[3]);
	}
	else if (p->type == 2) {
		glColor3f(p->color[0], p->color[1], p->color[2]);
		glutSolidCone(p->val[0], p->val[1], p->val[2], p->val[3]);
	}

	// draw children
	if (p->child) draw(p->child);

	glPopMatrix();

	// draw siblings
	if (p->next) draw(p->next);
}


void maketexture(void) {
	GLubyte texture[16][16][3];
	GLubyte *loc;
	int s, t;

	loc = (GLubyte*)texture;
	for (t = 0; t < 16; t++) {
		for (s = 0; s < 16; s++) {
			if (circles[t][s] == '.') {
				loc[0] = 0x00;
				loc[1] = 0x00;
				loc[2] = 0x00;
			}
			else {
				loc[0] = 0xff;
				loc[1] = 0xff;
				loc[2] = 0xff;
			}
			loc += 3;
		}
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
}

void renderBitmapString(float x, float y, char *string) {
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void processMenuEvents(int option) {
	switch (option) {
	case 2: stop_game(); start_game(); break;
	case 3: stop_game(); break;
	case 4: angleOfView = 0; break;
	case 5: angleOfView = 1; break;
	case 6: angleOfView = 2; weight_x = 1; weight_z = 0; break;
	case 7: angleOfView = 3; break;
	case 100: glutDestroyWindow(window), exit(0);
	}
}

void createMenus() {
	glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("", -1);

	glutAddMenuEntry("Start Game", 2);
	glutAddMenuEntry("Reset Game", 3);
	glutAddMenuEntry("", -1);

	glutAddMenuEntry("Top camera", 4);
	glutAddMenuEntry("Tracking camera", 5);
	glutAddMenuEntry("first person camera", 6);
	glutAddMenuEntry("", -1);
	glutAddMenuEntry("Quit", 100);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

void viewpoint(void) {
	if (angleOfView == 0)	{
		glLoadIdentity();
		gluLookAt(-20, 30, 0, 0, 0, 0, 1.0, 0.0, 0.0);
	}
	if (angleOfView == 1) {
		glLoadIdentity();
		gluLookAt(pacpos_x, 10, pacpos_z, pacpos_x, 0, pacpos_z, 1.0, 0.0, 0.0);
	}
	if (angleOfView == 2)	{
		glLoadIdentity();
		gluLookAt(pacpos_x + weight_x, 1, pacpos_z + weight_z, pacpos_x + 10 * weight_x, 0, pacpos_z + 10 * weight_z, 0.0, 1.0, 0.0);
	}
	if (angleOfView == 3)	{
		glLoadIdentity();
		gluLookAt(-10, 20, pacpos_z, pacpos_x, 0, pacpos_z, 1.0, 0.0, 0.0);
	}
	if (game_routine_running == 0) {
		if (demo_mode == 0)	{
			glLoadIdentity();
			gluLookAt(-30, 110 - rotation_y, -30, 0, 0, 0, 0.0, 1.0, 0.0);

			if (rotation_y < 90) rotation_y += 0.1;
			glRotatef(rotate_view * 10, -0.0f, 10, 0);
			rotate_view += 0.001;
		}
		if (demo_mode == 1)	{
			glLoadIdentity();
			gluLookAt(0, 8, 0, pacpos_x, 0, pacpos_z, 0.0, 1.0, 0.0);
		}
		if (demo_mode == 3)	{
			glLoadIdentity();
			gluLookAt(pacpos_x - 8, 8, pacpos_z - 8, 0, 0, 0, 0.0, 1.0, 0.0);
		}
		if (demo_mode == 2)	{
			glLoadIdentity();
			gluLookAt(-10, 20, pacpos_z, pacpos_x, 0, pacpos_z, 1.0, 0.0, 0.0);
		}
		if (demo_mode == 4) {
			glLoadIdentity();
			gluLookAt(-20, 30, 0, 0, 0, 0, 1.0, 0.0, 0.0);
		}
	}
}

void stop_game() {
	reset_game();
	game_routine_running = 0;
	lives = 10;
	angleOfView = 0;
	rotation_y = 0;
	rotate = 0;
	rotate_view = 0;
	level_complete = 0;
	pac_speed = 1;
	cpu_speed = 1;
	level = 1;
	score = 0;
}

void start_game() {
	reset_game();
	reset_food();
	angleOfView = 0;
	food_remaining = 0;
	game_routine_running = 1;
	level_complete = 0;
}

void resurrect(void) {
	reset_game();
	if (game_routine_running == 1) {
		if (lives == 0) stop_game();
		lives--;
	}
	if (game_routine_running == 0) {
		if (lives == 0) {
			lives = 10;
			if (demo_mode <= 3) demo_mode++;
			else demo_mode = 0;
		}
		lives--;
	}
}

void success() {
	reset_game();
	reset_food();
	angleOfView = 0;
	food_remaining = 0;
	level_complete = 1;
	game_routine_running = 0;
}

void reset_game() {
	pacpos_x = 0, pacpos_z = -9, direction = 3;
	cpu_direction[0] = 0, cpu_direction[1] = 0, cpu_direction[2] = 0, cpu_direction[3] = 0, cpu_direction[4] = 3;
	cpupos_x[0] = 0, cpupos_z[0] = 0, cpu_start[0] = 0;
	cpupos_x[1] = 0, cpupos_z[1] = 0, cpu_start[1] = 0;
	cpupos_x[2] = 0, cpupos_z[2] = 0, cpu_start[2] = 0;
	cpupos_x[3] = 0, cpupos_z[3] = 0, cpu_start[3] = 0;
	cpupos_x[4] = 0, cpupos_z[4] = -9, cpu_start[4] = 0;
}

void reset_food() {
	for (foodloop = 0; foodloop < 320; foodloop++) {
		food_eaten[foodloop] = 0;
	}
}


void InitGL() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);

	glColor4f(0.1f, 0.1f, 0.5f, 0.01f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glEnable(GL_BLEND);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_FOG);
		GLfloat fogColor[4] = { 0.0, 0.0, 1.0, 1.0 };

		fogMode = GL_LINEAR;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.05);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 50.0);
		glFogf(GL_FOG_END, 100.0);

	maketexture();
	///////////////////////////////////////////////////////////////////////////////////////////////

	root.vertices = &vertices[0][0];
	root.colors = &colors[0][0];
	root.indices = &indices[0];
	root.nums = 24;
	root.theta[0] = 0;  root.theta[1] = 0;  root.theta[2] = 0;
	root.trans[0] = 0;  root.trans[1] = 0;  root.trans[2] = 0;
	root.type = 1;
	root.val[0] = 0.5; root.val[2] = 20; root.val[3] = 16;
	root.color[0] = 0.5; root.color[1] = 0.5; root.color[2] = 0.5;
	root.next = 0; root.child = &head; // set child

	head.vertices = &vertices[0][0]; head.colors = &colors[0][0]; head.indices = &indices[0];
	root.nums = 24;
	head.theta[0] = head.theta[1] = head.theta[2] = 0;
	head.trans[0] = 0; head.trans[1] = 0.6;  head.trans[2] = 0;
	head.type = 1;
	head.val[0] = 0.35; head.val[2] = 20; head.val[3] = 16;
	head.color[0] = 0.4; head.color[1] = 0.4; head.color[2] = 0.4;
	head.next = &leftArm; head.child = &nouse; // set child

	nouse.theta[0] = nouse.theta[1] = nouse.theta[2] = 0;
	nouse.trans[0] = 0; nouse.trans[1] = 0;  nouse.trans[2] = 0.35;
	nouse.type = 2;
	nouse.val[0] = 0.025; nouse.val[1] = 0.25; nouse.val[2] = 10; nouse.val[3] = 10;
	nouse.color[0] = 0.4; nouse.color[1] = 0.2; nouse.color[2] = 0.2;
	nouse.next = &eye1; nouse.child = 0; // set child

										 //nouse, eye1, eye2
	eye1.theta[0] = eye1.theta[1] = eye1.theta[2] = 0;
	eye1.trans[0] = -0.1; eye1.trans[1] = 0.1;  eye1.trans[2] = 0.3;
	eye1.type = 1;
	eye1.val[0] = 0.025; eye1.val[2] = 10; eye1.val[3] = 10;
	eye1.color[0] = 0.3; eye1.color[1] = 0.3; eye1.color[2] = 0.4;
	eye1.next = &eye2; eye1.child = &eyeblow1; // set child

	eye2.theta[0] = eye2.theta[1] = eye2.theta[2] = 0;
	eye2.trans[0] = 0.1; eye2.trans[1] = 0.1;  eye2.trans[2] = 0.3;
	eye2.type = 1;
	eye2.val[0] = 0.025; eye2.val[2] = 10; eye2.val[3] = 10;
	eye2.color[0] = 0.3; eye2.color[1] = 0.3; eye2.color[2] = 0.4;
	eye2.next = 0; eye2.child = &eyeblow2; // set child

	eyeblow1.vertices = &vertices[0][0]; eyeblow1.colors = &colors[0][0]; eyeblow1.indices = &indices[0];
	eyeblow1.theta[0] = 0;  eyeblow1.theta[1] = 0; eyeblow1.theta[2] = 85;
	eyeblow1.nums = 24;
	eyeblow1.trans[0] = -0.025; eyeblow1.trans[1] = 0.055;  eyeblow1.trans[2] = 0;
	eyeblow1.type = 0;
	eyeblow1.val[0] = 0.025; eyeblow1.val[2] = 10; eyeblow1.val[3] = 10;
	eyeblow1.color[0] = 0.3; eyeblow1.color[1] = 0.3; eyeblow1.color[2] = 0.4;
	eyeblow1.next = 0; eyeblow1.child = 0; // set child

	eyeblow2.vertices = &vertices[0][0]; eyeblow2.colors = &colors[0][0]; eyeblow2.indices = &indices[0];
	eyeblow2.theta[0] = 0;  eyeblow2.theta[1] = 0; eyeblow2.theta[2] = 95;
	eyeblow2.nums = 24;
	eyeblow2.trans[0] = 0.025; eyeblow2.trans[1] = 0.055;  eyeblow2.trans[2] = 0;
	eyeblow2.type = 0;
	eyeblow2.val[0] = 0.025; eyeblow2.val[2] = 10; eyeblow2.val[3] = 10;
	eyeblow2.color[0] = 0.3; eyeblow2.color[1] = 0.3; eyeblow2.color[2] = 0.4;
	eyeblow2.next = 0; eyeblow2.child = 0; // set child

										   //leftArm, rightArm, leftFinger1, leftFinger2;
	leftArm.vertices = &vertices1[0][0]; leftArm.colors = &colors[0][0]; leftArm.indices = &indices[0];
	leftArm.theta[0] = 0;  leftArm.theta[1] = 0; leftArm.theta[2] = -110;
	leftArm.nums = 24;
	leftArm.trans[0] = -0.45; leftArm.trans[1] = 0.25;  leftArm.trans[2] = 0;
	leftArm.type = 0;
	leftArm.next = &rightArm; leftArm.child = &leftFinger1; // set child

	rightArm.vertices = &vertices1[0][0]; rightArm.colors = &colors[0][0]; rightArm.indices = &indices[0];
	rightArm.theta[0] = 0;  rightArm.theta[1] = 0; rightArm.theta[2] = 110;
	rightArm.nums = 24;
	rightArm.trans[0] = 0.45; rightArm.trans[1] = 0.25;  rightArm.trans[2] = 0;
	rightArm.type = 0;
	rightArm.next = 0; rightArm.child = &rightFinger1; // set child


	leftFinger1.vertices = &vertices2[0][0]; leftFinger1.colors = &colors[0][0]; leftFinger1.indices = &indices[0];
	leftFinger1.theta[0] = 0;  leftFinger1.theta[1] = 0; leftFinger1.theta[2] = -30;
	leftFinger1.nums = 24;
	leftFinger1.trans[0] = -0.025; leftFinger1.trans[1] = -0.35;  leftFinger1.trans[2] = 0;
	leftFinger1.type = 0;
	leftFinger1.next = &leftFinger2; leftFinger1.child = 0; // set child

	leftFinger2.vertices = &vertices2[0][0]; leftFinger2.colors = &colors[0][0]; leftFinger2.indices = &indices[0];
	leftFinger2.theta[0] = 0;  leftFinger2.theta[1] = 0; leftFinger2.theta[2] = 30;
	leftFinger2.nums = 24;
	leftFinger2.trans[0] = 0.025; leftFinger2.trans[1] = -0.35;  leftFinger2.trans[2] = 0;
	leftFinger2.type = 0;
	leftFinger2.next = 0; leftFinger2.child = 0; // set child

	rightFinger1.vertices = &vertices2[0][0]; rightFinger1.colors = &colors[0][0]; rightFinger1.indices = &indices[0];
	rightFinger1.theta[0] = 0;  rightFinger1.theta[1] = 0; rightFinger1.theta[2] = 30;
	rightFinger1.nums = 24;
	rightFinger1.trans[0] = 0.025; rightFinger1.trans[1] = -0.35;  rightFinger1.trans[2] = 0;
	rightFinger1.type = 0;
	rightFinger1.next = &rightFinger2; rightFinger1.child = 0; // set child

	rightFinger2.vertices = &vertices2[0][0]; rightFinger2.colors = &colors[0][0]; rightFinger2.indices = &indices[0];
	rightFinger2.theta[0] = 0;  rightFinger2.theta[1] = 0; rightFinger2.theta[2] = -30;
	rightFinger2.nums = 24;
	rightFinger2.trans[0] = -0.025; rightFinger2.trans[1] = -0.35;  rightFinger2.trans[2] = 0;
	rightFinger2.type = 0;
	rightFinger2.next = 0; rightFinger2.child = 0; // set child
}

void ReSizeGLScene(int Width, int Height) {
	if (Height == 0)   Height = 1;
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	viewpoint();

	glDisable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red_pill);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);


	glEnable(GL_BLEND);

	// 벽 그리기
	while (repeat < 50) {
		glBegin(GL_QUADS);

		/////////////////////////////////////////////////////////////////////////////
		/// 왼쪽 벽
		/////////////////////////////////////////////////////////////////////////////
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], 1.0f, polygony1[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], 1.0f, polygony2[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], -1.0f, polygony2[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], -1.0f, polygony1[repeat]);


		///////////////////////////////////////////오른쪽 벽
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx3[repeat], 1.0f, polygony3[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx4[repeat], 1.0f, polygony4[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx4[repeat], -1.0f, polygony4[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx3[repeat], -1.0f, polygony3[repeat]);


		////////////////////////////////////아래 벽
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], 1.0f, polygony1[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], 1.0f, polygony4[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], -1.0f, polygony4[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx1[repeat], -1.0f, polygony1[repeat]);


		/////////////////////////////위 벽
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], 1.0f, polygony2[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], 1.0f, polygony3[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], -1.0f, polygony3[repeat]);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(polygonx2[repeat], -1.0f, polygony2[repeat]);


		//////////////////////////////////////// 천장
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(polygonx1[repeat], 0.0f + 1, polygony1[repeat]);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(polygonx2[repeat], 0.0f + 1, polygony2[repeat]);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(polygonx3[repeat], 0.0f + 1, polygony3[repeat]);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(polygonx4[repeat], 0.0f + 1, polygony4[repeat]);

		glEnd();
		repeat++;
	}
	repeat = 0;

	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(-14.0f, -1.1f, -17.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-14.0f, -1.1f, 15.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(15.0f, -1.1f, 15.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(15.0f, -1.1f, -17.0f);
	glEnd();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	if (game_routine_running == 1) {
		while (foodloop < 320) {
			if (pacpos_x >= foodx[foodloop] - 0.01 && pacpos_x <= foodx[foodloop] + 0.01 && pacpos_z >= foodz[foodloop] - 0.01 && pacpos_z <= foodz[foodloop] + 0.01 && food_eaten[foodloop] == 0) {
				food_remaining++;
				food_eaten[foodloop] = 1;
				score += level;
			}
			foodloop++;
		}
		foodloop = 0;
		if (food_remaining == 288) success();
	}

	while (foodloop < 311) {
		if (food_eaten[foodloop] == 0) {
			glPushMatrix();

			if (game_routine_running == 1) {
				viewpoint();
				glTranslatef(foodx[foodloop], 0.5f, foodz[foodloop] - 0.25);
			}

			if (game_routine_running == 0) {
				glTranslatef(-25, 0, 25);
				glTranslatef(foodx[foodloop] * 5, 0.5f, foodz[foodloop] * 5);
			}

			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red_pill);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

			glutSolidSphere(0.25, 10, 10);
			glPopMatrix();
		}
		foodloop++;
	}
	foodrotate += 0.1;
	foodloop = 0;

	//
	viewpoint();
	glTranslatef(pacpos_x, tmp*0.01, pacpos_z);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_yellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	draw(&root);

	kita_angle += 14.0f;
	tmp = (float)sin(kita_angle * piover180)*90.0f;

	/*Demo mode*/
	if (game_routine_running == 0) direction = cpu_direction[4];

	if (direction == 1) pacpos_x += 0.1f * pac_speed;
	if (direction == 3) pacpos_x -= 0.1f * pac_speed;
	if (direction == 2) pacpos_z += 0.1f * pac_speed;
	if (direction == 4) pacpos_z -= 0.1f * pac_speed;
	if (game_routine_running == 0) {
		cpupos_x[4] = pacpos_x;
		cpupos_z[4] = pacpos_z;
	}

	for (cpu_loop = 0; cpu_loop < 4; cpu_loop++) {
		if (cpu_loop == 0) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_green);
		if (cpu_loop == 1) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red);
		if (cpu_loop == 2) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_blue);
		if (cpu_loop == 3) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_green);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

		viewpoint();

		glTranslatef(cpupos_x[cpu_loop], cpupos_y*0.01, cpupos_z[cpu_loop]);
		glScalef(1, 1 - cpupos_y * 0.001, 1);
		glutSolidSphere(0.75 + tmp*0.0001, 20, 20);

		jump += 3.0f;
		cpupos_y = (float)sin(jump * piover180)*90.0f;

		if (cpu_direction[cpu_loop] == 1) cpupos_x[cpu_loop] += 0.05f * cpu_speed;
		if (cpu_direction[cpu_loop] == 3) cpupos_x[cpu_loop] -= 0.05f * cpu_speed;
		if (cpu_direction[cpu_loop] == 2) cpupos_z[cpu_loop] += 0.05f * cpu_speed;
		if (cpu_direction[cpu_loop] == 4) cpupos_z[cpu_loop] -= 0.05f * cpu_speed;

		if (pacpos_x > cpupos_x[cpu_loop] - 0.5 && pacpos_x < cpupos_x[cpu_loop] + 0.5 && pacpos_z > cpupos_z[cpu_loop] - 0.5 && pacpos_z < cpupos_z[cpu_loop] + 0.5) resurrect();
	}

	cpu_loop = 0;
	tormaysmallinnus();
	AI(); // enermy 움직이기

	/*Tekstit*/
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glOrtho(0, 0, 1024, 768, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
	glRasterPos2f(-5, 1);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0 + 20, 0.5 + kita2*0.001);
	glColor3f(1.0, 1.0, 0.0);

	for (i = kita1; i <= 360 - kita1; i += 6) {
		angle = i / 180.0 * PI;
		anim_y = sin(angle) + 0.5;
		anim_x = cos(angle);
		glVertex2f(anim_x + 20, anim_y + kita2*0.001);
	}
	glEnd();

	r1++;
	kita1 = (float)sin(r1 * piover180)*90.0f;

	r2 += 3;
	kita2 = (float)sin(r2 * piover180)*90.0f;

	win_x = -0.2, win_z = 0.8;

	strcpy(teksti, "Level: ");
	itoa(level, itoa_buffer, 10);
	strcat(teksti, itoa_buffer);

	strcat(teksti, " Lives: ");
	itoa(lives, itoa_buffer, 10);
	strcat(teksti, itoa_buffer);

	strcat(teksti, " Score: ");
	itoa(score, itoa_buffer, 10);
	strcat(teksti, itoa_buffer);

	if (game_routine_running == 1) renderBitmapString(win_x - 0.1, win_z, teksti);

	if (level_complete == 1) {
		strcpy(teksti, "Level complete! Press [ESC] to proceed.");
		renderBitmapString(win_x - 0.1, win_z, teksti);
	}

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);

	glutSwapBuffers();
}

void keyPressed(unsigned char key) {
	if (key == ESCAPE && level_complete == 1) {
		level++;
		cpu_speed += 0.2;
		start_game();
	}
}

int main(int argc, char **argv) {
	highscore_int = 0; pac_speed = 1; cpu_speed = 1; lives = 10;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Graphics term project");
	glutDisplayFunc(&DrawGLScene);

	glutIdleFunc(&DrawGLScene);

	glutReshapeFunc(&ReSizeGLScene);

	glutKeyboardFunc(&keyPressed);
	glutSpecialFunc(&specialKeyPressed);

	init_3d_objects();

	InitGL(640, 480);

	createMenus();
	glutMainLoop();

	return 1;
}