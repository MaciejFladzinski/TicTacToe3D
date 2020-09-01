// project "TicTacToe3D" created by Maciej Fladziñski and Rafa³ Janas
#include <GL/glut.h>
#include <iostream>

int playingField[3][3];
int playerTurn; // "0" - if player2(O) turn, "1" - if player1(X) turn

int result; // "0" - player2(O) wins, "1" - player1(X) wins, "2" - it's draw
bool gameOver;

void init()
{
	playerTurn = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			playingField[i][j] = 2; // "0" - O, "1" - X, "2" - nothing
		}
	}
}

void keyboardPress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':
		if (gameOver == true)
		{
			gameOver = false;
			init();
		}
		break;

	case 'n':
		if (gameOver == true)
		{
			exit(0);
		}
		break;

	case 27: // "esc" -> quit
		exit(0);
	}
}

void mouseClick(int button, int state, int x, int y)
{
	if (gameOver == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (x > 50 && y > 50 && x < 150 && y < 150)
		{
			if (playerTurn == 1)
			{
				if (playingField[0][0] == 2)
				{
					playingField[0][0] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[0][0] == 2)
				{
					playingField[0][0] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 150 && y > 50 && x < 250 && y < 150)
		{
			if (playerTurn == 1)
			{
				if (playingField[0][1] == 2)
				{
					playingField[0][1] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[0][1] == 2)
				{
					playingField[0][1] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 250 && y > 50 && x < 350 && y < 150)
		{
			if (playerTurn == 1)
			{
				if (playingField[0][2] == 2)
				{
					playingField[0][2] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[0][2] == 2)
				{
					playingField[0][2] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 50 && y > 150 && x < 150 && y < 250)
		{
			if (playerTurn == 1)
			{
				if (playingField[1][0] == 2)
				{
					playingField[1][0] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[1][0] == 2)
				{
					playingField[1][0] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 150 && y > 150 && x < 250 && y < 250)
		{
			if (playerTurn == 1)
			{
				if (playingField[1][1] == 2)
				{
					playingField[1][1] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[1][1] == 2)
				{
					playingField[1][1] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 250 && y > 150 && x < 350 && y < 250)
		{
			if (playerTurn == 1)
			{
				if (playingField[1][2] == 2)
				{
					playingField[1][2] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[1][2] == 2)
				{
					playingField[1][2] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 50 && y > 250 && x < 150 && y < 350)
		{
			if (playerTurn == 1)
			{
				if (playingField[2][0] == 2)
				{
					playingField[2][0] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[2][0] == 2)
				{
					playingField[2][0] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 150 && y > 250 && x < 250 && y < 350)
		{
			if (playerTurn == 1)
			{
				if (playingField[2][1] == 2)
				{
					playingField[2][1] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[2][1] == 2)
				{
					playingField[2][1] = 0;
					playerTurn = 1;
				}
			}
		}
		else if (x > 250 && y > 250 && x < 350 && y < 350)
		{
			if (playerTurn == 1)
			{
				if (playingField[2][2] == 2)
				{
					playingField[2][2] = 1;
					playerTurn = 0;
				}
			}
			else if (playerTurn == 0)
			{
				if (playingField[2][2] == 2)
				{
					playingField[2][2] = 0;
					playerTurn = 1;
				}
			}
		}
	}
}

void drawString(void* font, const char s[], float x, float y)
{
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}

void drawLines()
{
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);

	glVertex3f(50, 50, 0);
	glVertex3f(350, 50, 0);

	glVertex3f(50, 50, 0);
	glVertex3f(50, 350, 0);

	glVertex3f(50, 350, 0);
	glVertex3f(350, 350, 0);

	glVertex3f(350, 350, 0);
	glVertex3f(350, 50, 0);

	glVertex3f(150, 50, 0);
	glVertex3f(150, 350, 0);

	glVertex3f(250, 50, 0);
	glVertex3f(250, 350, 0);

	glVertex3f(50, 150, 0);
	glVertex3f(350, 150, 0);

	glVertex3f(50, 250, 0);
	glVertex3f(350, 250, 0);

	glColor3f(0.85, 0.85, 0.85);

	glVertex3f(50, 50, 0);
	glVertex3f(100, 100, -1);

	glVertex3f(350, 50, 0);
	glVertex3f(400, 100, -1);

	glVertex3f(50, 350, 0);
	glVertex3f(100, 400, -1);

	glVertex3f(350, 350, 0);
	glVertex3f(400, 400, -1);


	glVertex3f(100, 100, -1);
	glVertex3f(400, 100, -1);

	glVertex3f(100, 100, -1);
	glVertex3f(100, 400, -1);

	glVertex3f(100, 400, -1);
	glVertex3f(400, 400, -1);

	glVertex3f(400, 400, -1);
	glVertex3f(400, 100, -1);


	glVertex3f(100, 200, -1);
	glVertex3f(400, 200, -1);

	glVertex3f(100, 300, -1);
	glVertex3f(400, 300, -1);

	glVertex3f(200, 100, -1);
	glVertex3f(200, 400, -1);

	glVertex3f(300, 100, -1);
	glVertex3f(300, 400, -1);


	glVertex3f(150, 50, 0);
	glVertex3f(200, 100, -1);

	glVertex3f(250, 50, 0);
	glVertex3f(300, 100, -1);

	glVertex3f(50, 150, 0);
	glVertex3f(100, 200, -1);

	glVertex3f(50, 250, 0);
	glVertex3f(100, 300, -1);
	
	glVertex3f(250, 150, 0);
	glVertex3f(300, 200, -1);

	glVertex3f(350, 150, 0);
	glVertex3f(400, 200, -1);
	
	glVertex3f(150, 150, 0);
	glVertex3f(200, 200, -1);

	glVertex3f(150, 250, 0);
	glVertex3f(200, 300, -1);

	glVertex3f(250, 250, 0);
	glVertex3f(300, 300, -1);

	glVertex3f(350, 250, 0);
	glVertex3f(400, 300, -1);

	glVertex3f(150, 350, 0);
	glVertex3f(200, 400, -1);

	glVertex3f(250, 350, 0);
	glVertex3f(300, 400, -1);

	glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get current angle
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}

	glEnd();
}

void drawXO()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (playingField[i][j] == 1)
			{
				glBegin(GL_LINES);

				glColor3f(1, 0, 0);

				glVertex2f(100 + j * 100 - 40, 100 + i * 100 - 40);
				glVertex2f(100 + j * 100 + 40, 100 + i * 100 + 40);
				glVertex2f(100 + j * 100 - 40, 100 + i * 100 + 40);
				glVertex2f(100 + j * 100 + 40, 100 + i * 100 - 40);

				glEnd();
			}
			else if (playingField[i][j] == 0)
			{
				glColor3f(0, 1, 0);

				drawCircle(100 + j * 100, 100 + i * 100, 40, 15);
			}
		}
	}
}

bool checkWinner()
{
	int i;
	int j;

	// horizontal check
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j < 3; j++)
		{
			if (playingField[i][0] != 2 && playingField[i][0] == playingField[i][j])
			{
				if (j == 2)
				{
					return true;
				}
			}
			else
			{
				break;
			}
		}
	}

	// vertical check
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j < 3; j++)
		{
			if (playingField[0][i] != 2 && playingField[0][i] == playingField[j][i])
			{
				if (j == 2)
					return true;
			}
			else
			{
				break;
			}
		}
	}

	// diagonal check
	if ((playingField[0][0] != 2 && playingField[0][0] == playingField[1][1] && playingField[0][0] == playingField[2][2]) || (playingField[2][0] != 2 && playingField[2][0] == playingField[1][1] && playingField[2][0] == playingField[0][2]))
	{
		return true;
	}

	return false;
}

bool checkDraw()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (playingField[i][j] == 2)
			{
				return false;
			}
		}
	}
	return true;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);

	if (playerTurn == 1)
	{
		drawString(GLUT_BITMAP_HELVETICA_18, "Player1(X) turn", 150, 30);
	}
	else
	{
		drawString(GLUT_BITMAP_HELVETICA_18, "Player2(O) turn", 150, 30);
	}

	drawLines();

	drawXO();

	if (checkWinner() == true)
	{
		if (playerTurn == 1)
		{
			gameOver = true;
			result = 0;
		}
		else
		{
			gameOver = true;
			result = 1;
		}
	}
	else if (checkDraw() == true)
	{
		gameOver = true;
		result = 2;
	}

	if (gameOver == true)
	{
		glColor3f(0, 0, 0);

		drawString(GLUT_BITMAP_HELVETICA_18, "Game over", 550, 90);

		if (result == 0)
		{
			drawString(GLUT_BITMAP_HELVETICA_18, "Player2(O) wins!", 525, 140);
		}

		if (result == 1)
		{
			drawString(GLUT_BITMAP_HELVETICA_18, "Player1(X) wins!", 525, 140);
		}

		if (result == 2)
		{
			drawString(GLUT_BITMAP_HELVETICA_18, "It's a draw!", 550, 140);
		}

		drawString(GLUT_BITMAP_HELVETICA_18, "Play again? (press 'y' if yes, press 'n' if no)", 425, 290);
	}

	glutSwapBuffers();
}

void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 425);
	glutCreateWindow("Tic Tac Toe 3D");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardPress);
	glutMouseFunc(mouseClick);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}