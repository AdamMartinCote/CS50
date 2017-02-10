/**
 * bounce.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Bounces a circle back and forth in a window.
 */

// standard libraries
#include <stdio.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 640);

    // instantiate circle
    GOval circle = newGOval(0, 110, 20, 20);
    setColor(circle, "BLUE");
    setFilled(circle, true);
    add(window, circle);
    
    // initial velocity
        double xspeed = 1.0;
        double yspeed = 2.0;
    
    // bounce forever
    while (true)
    {
            move(circle, xspeed, yspeed);

            // bounce off right edge of window
            if (getX(circle) + getWidth(circle) >= getWidth(window))
            {
                xspeed = -xspeed;
            }

            // bounce off left edge of window
            else if (getX(circle) <= 0)
            {
                xspeed = -xspeed;
            }
            
            // bounce off bottom edge of window
            else if (getY(circle) + getHeight(circle) >= getHeight(window))
            {
                yspeed = -yspeed;
            }
    
            // bounce off top edge of window
            else if (getY(circle) <= 0)
            {
                yspeed = -yspeed;
            }
        // linger before moving again
        pause(10);
    }
}
