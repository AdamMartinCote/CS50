//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

#define WPADDLE 75
#define HPADDLE 1

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));
    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    initBricks(window);

    GOval ball = initBall(window);

    GRect paddle = initPaddle(window);

    GLabel label = initScoreboard(window);

    // number of bricks, lives and points initially
    int bricks = COLS * ROWS;
    int lives = LIVES;
    int points = 0;

    waitForClick();
    // initial velocity of ball
    double xspeed = (3 * drand48());
    double yspeed = 3.0;
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
            //move the paddle
            GEvent event = getNextEvent(MOUSE_EVENT);
            if (event != NULL)
            {
                if (getEventType(event) == MOUSE_MOVED)
                {
                    double x = getX(event) - getWidth(paddle) / 2;
                    setLocation(paddle, x, 550);
                }
            }

            move(ball, xspeed, yspeed);

            // bounce off right edge of window
            if (getX(ball) + getWidth(ball) >= getWidth(window))
            {
                xspeed = -xspeed;
            }

            // bounce off left edge of window
            if (getX(ball) <= 0)
            {
                xspeed = -(drand48()+0.5)*xspeed;
            }
            
            // go past bottom edge of window
            if (getY(ball) + getHeight(ball) >= getHeight(window))
            {
                lives = lives -1;
                removeGWindow(window, ball);
                ball = initBall(window);
                waitForClick();
                double xspeed = (3 * drand48());
                double yspeed = 3.0;

                
            }
            // bounce off top edge of window
            if (getY(ball) <= 0)
            {
                yspeed = -yspeed;
            }        
// Collisions
            GObject object = detectCollision(window, ball);
            if (object == paddle)
            {
                xspeed = 3*drand48()-1.5;
                yspeed = -yspeed;
            } 
            if (object != NULL && object != paddle && object != label)
            {
                removeGWindow(window, object);
                yspeed = -yspeed;
                bricks--;
                points++;
                char s[3];
                sprintf(s, "%i", points);

                setLabel(label, s);
            } 
        
            // linger before moving again
            pause(10);
                
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    
    int colrot = 0;
    for (int b = 0; b < ROWS; b++)
    {

        for (int a = 0; a <= COLS; a++)
        {
            GRect brick = newGRect(a*(WIDTH/COLS)+12.5, 20+(15*b), 25, 10);
            setFilled(brick, true);
            if(colrot %5 == 0) {setColor(brick, "RED");}
            if(colrot %5 == 1) {setColor(brick, "ORANGE");}
            if(colrot %5 == 2) {setColor(brick, "YELLOW");}
            if(colrot %5 == 3) {setColor(brick, "GREEN");}
            if(colrot %5 == 4) {setColor(brick, "BLUE");}
            colrot++;
            add(window, brick);
            
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2-RADIUS, HEIGHT/2-RADIUS, 2*RADIUS, 2*RADIUS);
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect((200-(WPADDLE/2)), 550, WPADDLE, HPADDLE);
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-bold-36");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    add(window, label);
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
