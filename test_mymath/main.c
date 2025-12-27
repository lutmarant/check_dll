#include <stdio.h>

#include "myMath.h"

int main()
{
    struct TInFPMHS in;
    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 20;
    in.speed = 10;
    in.speed_new = 15;
    in.acceleration = 0.001;
    in.heading = 0;
    in.heading_new = 0;
    in.radiusCirc = 0;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 50;
    in.speed = 10;
    in.speed_new = 10;
    in.acceleration = 0;
    in.heading = 0;
    in.heading_new = 3;
    in.radiusCirc = 500;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 80;
    in.speed = 10;
    in.speed_new = 15;
    in.acceleration = 0.1;
    in.heading = 0;
    in.heading_new = 3;
    in.radiusCirc = 500;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 10;
    in.speed = 10;
    in.speed_new = 15;
    in.acceleration = 0.1;
    in.heading = 0;
    in.heading_new = 3;
    in.radiusCirc = 500;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 10;
    in.speed = 10;
    in.speed_new = 15;
    in.acceleration = 0.1;
    in.heading = 0;
    in.heading_new = 3;
    in.radiusCirc = 500;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 10;
    in.speed = 10;
    in.speed_new = 15;
    in.acceleration = 0.1;
    in.heading = 3.280;
    in.heading_new = 3;
    in.radiusCirc = 500;

    in.posStart.x = 0;
    in.posStart.y = 0;
    in.timeBeforeMan = 0;
    in.speed = 15;
    in.speed_new = 10;
    in.acceleration = -0.05;
    in.heading = 3;
    in.heading_new = 6;
    in.radiusCirc = 1000;

    printf( "\n\nin:" );
    printf( "\nin.posStart.x = %f", in.posStart.x );
    printf( "\nin.posStart.y = %f", in.posStart.y );
    printf( "\nin.timeBeforeMan = %f", in.timeBeforeMan );
    printf( "\nin.speed = %f", in.speed );
    printf( "\nin.speed_new = %f", in.speed_new );
    printf( "\nin.acceleration = %f", in.acceleration );
    printf( "\nin.heading = %f rad = %f grad", in.heading, grad( in.heading ) );
    printf( "\nin.heading_new = %f rad = %f grad", in.heading_new, grad( in.heading_new ) );
    printf( "\nin.radiusCirc = %f", in.radiusCirc );

    /*
    double time = 0;
    double timeMax = 30;
    double timeStep = 1;
    for ( time = 0; time < timeMax; time += timeStep )
    {
        printf( "\n\ntime = %f", time );

        struct TOutFindPrj out;
        int res = findPos_manHS( time, in, &out );

        printf( "\nres = %d", res );
        printf( "\nout:" );
        printf( "\nout.x  = %f", out.x );
        printf( "\nout.y  = %f", out.y );
        printf( "\nout.path  = %f", out.path );
        printf( "\nout.speed  = %f", out.speed );
        printf( "\nout.heading  = %f", out.heading );
    }
    */

    /*
    double time = 25;
    printf( "\n\ntime = %f", time );

    struct TOutFindPrj out;
    int res = findPos_manHS( time, in, &out );

    printf( "\nres = %d", res );
    printf( "\nout:" );
    printf( "\nout.x  = %f", out.x );
    printf( "\nout.y  = %f", out.y );
    printf( "\nout.path  = %f", out.path );
    printf( "\nout.speed  = %f", out.speed );
    printf( "\nout.heading  = %f", out.heading );
    */

    double time = 9;
    time = 120;
    time = 11;
    time = 130;
    time = 150;
    time = 1300;
    printf( "\n\ntime = %f", time );

    struct TOutFindPrj out;
    int res = findPos_manHS( time, in, &out );

    printf( "\nres = %d", res );
    printf( "\nout:" );
    printf( "\nout.x  = %f", out.x );
    printf( "\nout.y  = %f", out.y );
    printf( "\nout.path  = %f", out.path );
    printf( "\nout.speed  = %f", out.speed );
    printf( "\nout.heading  = %f", out.heading );
    printf( "\n" );

    system( "pause" );

    return 0;
}
