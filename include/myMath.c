// myMath.c

#include "myMath.h"

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int bool;
#define false 0
#define true 1

int sign(double x)
{
    if (x >= 0) 
		return 1;
    else 
		return -1;
}

double sqr(double x)
{
    return x * x;
}

double rad( double grad )
{
	return grad * M_PI / 180;
}

double grad( double rad )
{
	return rad * 180 / M_PI;
}

double priv2Pi(double rad)
{
	while (rad < 0)
    {
        rad = rad + 2 * M_PI;
    }

    while (rad >= 2 * M_PI)
    {
        rad = rad - 2 * M_PI;
    }

    return rad;
}

double privPi(double rad)
{
	while (rad <= - M_PI)
    {
        rad = rad + 2 * M_PI;
    }

    while (rad > M_PI)
    {
        rad = rad - 2 * M_PI;
    }

    return rad;
}

double priv360(double grad)
{
	while (grad < 0)
    {
        grad = grad + 360;
    }

    while (grad >= 360)
    {
        grad = grad - 360;
    }

    return grad;
}

double priv180(double grad)
{
	while (grad <= -180)
    {
        grad = grad + 360;
    }

    while (grad > 180)
    {
        grad = grad - 360;
    }

    return grad;
}

double coordX( double dist, double angleRad )
{
	return dist * sin( angleRad );
}

double coordY( double dist, double angleRad )
{
	return dist * cos( angleRad );
}

double dist_1to2( double x1, double y1, double x2, double y2 )
{
	double x = x2 - x1;
	double y = y2 - y1;
	return sqrt( x * x + y * y );
}

double angle_1to2( double x1, double y1, double x2, double y2 )
{
	double x = x2 - x1;
    double y = y2 - y1;

    double angle = 0;

    if (y > 0)
    {
        if (x >= 0) angle = atan(x / y);
        if (x < 0)  angle = atan(x / y) + 2 * M_PI; // rad(360)
    }
    else
    {
        if (y < 0)
        {
            angle = atan(x / y) + M_PI; // rad(180)
        }
        else
        {
            if (x >= 0) angle = M_PI / 2; // rad(90)
            if (x < 0)  angle = M_PI + M_PI/2; // rad(270)
        }
    }

    return angle;
}


int findTimeToAlterate( struct TInFindPrj in, double * timeSpeedMan, double * timeHeadingMan )
{
	const double EPS = 10e-5;
	
	double deltaV = in.speed_new - in.speed;
	double deltaK = privPi( in.heading_new - in.heading );
	
	int resVerify = verifyParams( in );
	if ( resVerify != ROFP_SUCCESS )
		return resVerify;
	
	if ( fabs( deltaV ) <= EPS )
	{
		(*timeSpeedMan) = 0;
	}
	else
	{
		(*timeSpeedMan) = fabs( deltaV / in.acceleration );
		(*timeSpeedMan) = deltaV / in.acceleration;
	}
	
	if ( fabs( deltaK ) <= EPS )
	{
		(*timeHeadingMan) = 0;
	}
	else
	{
		if ( fabs( deltaV ) <= EPS )
		{
			(*timeHeadingMan) = fabs( deltaK ) * fabs( in.radiusCirc ) / in.speed;
		}
		else
		{
			if ( fabs( in.acceleration ) < EPS )
				return -1;
			
			double a = sqr( in.speed / in.acceleration );
			double b = 2 * fabs( deltaK ) * in.radiusCirc / in.acceleration;
			double c = sqrt( a + b );
			
			a = sqr( in.speed / in.acceleration );
			b = 2 * fabs( deltaK ) * in.radiusCirc / in.acceleration;
			c = sqrt( a + b );
			
			if ( ( a + b ) < 0 )
			{
				(*timeHeadingMan) = fabs( in.speed / in.acceleration );
				return ROFP_NOT_ENOUGH_TIME_TO_ALTERATE_HEADING;
			}
			
			(*timeHeadingMan) = fabs( sign( deltaV ) * c - in.speed / in.acceleration );
		}
	}
	
	return ROFP_SUCCESS;
}

int verifyParams( struct TInFindPrj in )
{
	const double EPS = 10e-5;
	
	if ( fabs( in.acceleration ) < EPS && fabs( in.speed - in.speed_new ) > EPS )
		return ROFP_ACCELERATION_IS_ZERO_SPEED_DIF_IS_NOT_ZERO;
		
	if ( fabs( in.acceleration ) > EPS && fabs( in.speed - in.speed_new ) < EPS )
		return ROFP_ACCELERATION_IS_NOT_ZERO_SPEED_DIF_IS_ZERO;
		
	if ( in.acceleration < - EPS && ( in.speed - in.speed_new ) < - EPS )
		return ROFP_ACCELERATION_AND_SPEED_DIF_ARE_LESS_THAN_ZERO;
		
	if ( in.acceleration > EPS && ( in.speed - in.speed_new ) > EPS )
		return ROFP_ACCELERATION_AND_SPEED_DIF_ARE_MORE_THAN_ZERO;
		
	if ( fabs( in.radiusCirc ) < EPS && fabs( in.heading - in.heading_new ) > EPS )
		return ROFP_RADIUS_CIRC_IS_ZERO_HEADING_DIF_IS_NOT_ZERO;
	
	if ( in.radiusCirc > EPS && fabs( in.heading - in.heading_new ) < EPS )
		return ROFP_RADIUS_CIRC_IS_NOT_ZERO_HEADING_DIF_IS_ZERO;
		
	return ROFP_SUCCESS;
}

int findPrj( double time, struct TInFindPrj in, struct TOutFindPrj * out  )
{
	//printf( "\n\nfinPrj" );
	
	const double EPS = 10e-5;
	
	double deltaV = in.speed_new - in.speed;
	
	double deltaK = privPi( in.heading_new - in.heading );
	double rSigned = in.radiusCirc * sign( deltaK );
	
	double timeSpeed = 0;
	double timeHeading = 0;
	int res = findTimeToAlterate( in, &timeSpeed, &timeHeading );
	if ( ( res != ROFP_SUCCESS ) && ( res != ROFP_NOT_ENOUGH_TIME_TO_ALTERATE_HEADING ) )
		return res;
	
	double timeMax = time;
	if ( ( fabs( deltaV ) > EPS ) && ( fabs( deltaK ) > EPS ) )
	{
		//printf( "\nif1" );
		
		if ( timeSpeed < timeHeading )
		{
			//printf( "\nif1.2" );
			timeMax = timeSpeed;
		}
		else
		{
			//printf( "\nif1.2" );
			timeMax = timeHeading;
		}
	}
	else if ( fabs( deltaV ) > EPS )
	{
		//printf( "\nif2" );
		timeMax = timeSpeed;
	}
	else if ( fabs( deltaK ) > EPS )
	{
		//printf( "\nif3" );
		timeMax = timeHeading;
	}
	
	if ( time > timeMax + EPS ) // 2022-12-01 EPS
		return ROFP_NOT_ENOUGH_TIME;
	
	(*out).path = in.speed * time + in.acceleration * time * time / 2;		
	(*out).speed = in.speed + in.acceleration * time;
	
	if ( fabs( deltaK ) <= EPS )
	{
		//printf( "\nif4" );
		(*out).x = (*out).path * sin( in.heading );
		(*out).y = (*out).path * cos( in.heading );
		(*out).heading = in.heading;
	}
	else
	{	
		//printf( "\nif5" );
		double psi = in.heading + (*out).path / in.radiusCirc * sign( deltaK );
		(*out).x = rSigned * ( cos( in.heading ) - cos( psi ) );
		(*out).y = rSigned * ( sin( psi ) - sin( in.heading ) );
		
		(*out).heading = priv2Pi( in.heading + (*out).path / in.radiusCirc * sign( deltaK ) );
	}
	
	return ROFP_SUCCESS;
}

struct TDateTime getDateTime( )
{
    struct TDateTime dateTime;
	
	time_t now = time(0);
    struct tm * localTimeNow = localtime(&now);
    dateTime.year = 1900 + localTimeNow->tm_year;
    dateTime.month = 1 + localTimeNow->tm_mon;
    dateTime.day = localTimeNow->tm_mday;
    dateTime.hour = localTimeNow->tm_hour;
    dateTime.min = localTimeNow->tm_min;
    dateTime.sec = localTimeNow->tm_sec;

    return dateTime;
}

void randByTime()
{
	static bool isTimeRandomed = false;
    if ( isTimeRandomed ) return;
    isTimeRandomed = true;
    time_t timeNull = time( NULL );

    srand( timeNull );
}

double uniformDistribution(double a, double b)
{
    return a + rand() * (b - a) / RAND_MAX;
}

double normalDistribution(double m, double sigma)
{
    double r = 0;
    int i = 0;
    for (i = 1; i <= 12; i++)
    {
        r = r + uniformDistribution(0, 1);
    }
    return( m + sigma * (r - 6) );
}

EXPORT double getMean( double * mas, unsigned int sizeMas )
{
	double mean = 0;
	unsigned int i = 0;
    for ( i = 0; i < sizeMas; ++i )
    {
        mean += mas[i];
    }

    mean = mean / sizeMas;

    return mean;
}

EXPORT double getVariance( double * mas, unsigned int sizeMas )
{
    double variance = 0;
	unsigned int i = 0;
    for ( i = 0; i < sizeMas; ++i )
    {
        variance += mas[i] * mas[i];
    }
    double mean = getMean( mas, sizeMas );
    variance = variance / sizeMas - mean * mean;

    return variance;
}

void findPos_sc( double time, InFPSC in, double * x, double * y )
{
	(*x) = in.x0 + time * in.speed * sin( in.headingRad );
	(*y) = in.y0 + time * in.speed * cos( in.headingRad );
}


MotionParams estimateMotionParams_2z( MotionParams motionParamsOwnObj, Measurement measurement, enum ModeEMP2Z mode )
{
	MotionParams kpdoObsObj;
	kpdoObsObj.speed = 0;
	kpdoObsObj.headingRad = 0;
	
	static unsigned int counterThisFuncCalls = 0;
	
	static Measurement measurement1;
	Measurement measurement2;
	
	if ( mode == MEMP2Z_NULLIFY )
	{
		counterThisFuncCalls = 0;
		return kpdoObsObj;
	}
	else
	{
		if ( counterThisFuncCalls == 0 )
		{
			measurement1 = measurement;
			
			++counterThisFuncCalls;
			
			return kpdoObsObj;
		}
		else
		{
			measurement2 = measurement;
		
			double time = measurement2.time - measurement1.time;
		
			double Vx = ( motionParamsOwnObj.speed * time * sin( motionParamsOwnObj.headingRad ) + measurement2.distance * sin( measurement2.bearingRad ) - measurement1.distance * sin( measurement1.bearingRad ) ) / time;
	    	double Vy = ( motionParamsOwnObj.speed * time * cos( motionParamsOwnObj.headingRad ) + measurement2.distance * cos( measurement2.bearingRad ) - measurement1.distance * cos( measurement1.bearingRad ) ) / time;
	    		
	    	kpdoObsObj.speed = dist_1to2( 0, 0, Vx, Vy );
	    	kpdoObsObj.headingRad = angle_1to2( 0, 0, Vx, Vy );
	    	
	    	++counterThisFuncCalls;
	    	
	    	return kpdoObsObj;
		}
	}
}


double max( double a, double b )
{
	if ( a >= b )
		return a;
	else
		return b;
}

double min( double a, double b )
{
	if ( a < b )
		return a;
	else
		return b;
}

int findPos_manHS( double time, struct TInFPMHS in, struct TOutFindPrj * out )
{
	const double EPS = 10e-5;
	
	(*out).x = in.posStart.x;
	(*out).y = in.posStart.y;
	(*out).path = 0;
	(*out).speed = 0;
	(*out).heading = 0;
	
	if ( in.timeBeforeMan < 0 )
		return -34;
		
	double timeLeft = time;
	
	// 1. Участок прямолинейного равномерного движения до маневра
	//==================================================================
	struct TInFindPrj inStraightConst;
	inStraightConst.speed = in.speed;
	inStraightConst.speed_new = in.speed;
	inStraightConst.acceleration = 0;	
	inStraightConst.heading = in.heading;
	inStraightConst.heading_new = in.heading;
	inStraightConst.radiusCirc = 0;
		
	double timeLeftForMotionBeforeMan = 0;
	if ( time <= in.timeBeforeMan )
		timeLeftForMotionBeforeMan = timeLeft;
	else
		timeLeftForMotionBeforeMan = in.timeBeforeMan;
	
	struct TOutFindPrj outStraightConst_beforeMan;
	int resFindPrj = findPrj( timeLeftForMotionBeforeMan, inStraightConst, &outStraightConst_beforeMan );
	if ( resFindPrj != ROFP_SUCCESS )
		return resFindPrj;
			
	(*out).x += outStraightConst_beforeMan.x;
	(*out).y += outStraightConst_beforeMan.y;
	(*out).path += outStraightConst_beforeMan.path;
	(*out).speed = outStraightConst_beforeMan.speed;
	(*out).heading = outStraightConst_beforeMan.heading;
	
	//if ( time <= in.timeBeforeMan )
	//	return ROFP_SUCCESS;
	
	// 2. участок совершения маневра по курсу и скорости
	//==================================================================
	struct TInFindPrj inMan_speedAndHeading;
	inMan_speedAndHeading.speed = in.speed;
	inMan_speedAndHeading.speed_new = in.speed_new;
	inMan_speedAndHeading.acceleration = in.acceleration;
	inMan_speedAndHeading.heading = in.heading;
	inMan_speedAndHeading.heading_new = in.heading_new;
	inMan_speedAndHeading.radiusCirc = in.radiusCirc;
	
	double timeManSpeed = 0;
	double timeManHeading = 0;
	int resFindTimeMan = findTimeToAlterate( inMan_speedAndHeading, &timeManSpeed, &timeManHeading );
	if ( resFindTimeMan != ROFP_SUCCESS && resFindTimeMan != ROFP_NOT_ENOUGH_TIME_TO_ALTERATE_HEADING )
		return resFindTimeMan;
		
	double timeManMax = max( timeManSpeed, timeManHeading );
	double timeManSpeedAndHeading = min( timeManSpeed, timeManHeading );
	double timeManSpeedOrHeading = fabs( timeManSpeed - timeManHeading );
	
	double timeLeftForManSpeedAndHeading = 0;
	if ( time > in.timeBeforeMan )
	{
		timeLeft = time - in.timeBeforeMan;
		
		if ( timeLeft <= timeManSpeedAndHeading )
			timeLeftForManSpeedAndHeading = timeLeft;
		else
			timeLeftForManSpeedAndHeading = timeManSpeedAndHeading;
	
		if ( fabs( timeLeftForManSpeedAndHeading ) > EPS )
		{
			struct TOutFindPrj outMan_speedAndHeading;
			resFindPrj = findPrj( timeLeftForManSpeedAndHeading, inMan_speedAndHeading, &outMan_speedAndHeading );
			if ( resFindPrj != ROFP_SUCCESS )
				return resFindPrj;
	
			(*out).x += outMan_speedAndHeading.x;
			(*out).y += outMan_speedAndHeading.y;
			(*out).path += outMan_speedAndHeading.path;
			(*out).speed = outMan_speedAndHeading.speed;
			(*out).heading = outMan_speedAndHeading.heading;
		}
	}
	
	// 3. участок совершения маневра по курсу или скорости
	//==================================================================
	if ( time > in.timeBeforeMan + timeManSpeedAndHeading )
	{
		struct TInFindPrj inManLeft;
		if ( timeManSpeed <= timeManHeading )
		{
			inManLeft.speed = in.speed_new;
			inManLeft.speed_new = in.speed_new;
			inManLeft.acceleration = 0;
			inManLeft.heading = (*out).heading;
			inManLeft.heading_new = in.heading_new;
			inManLeft.radiusCirc = in.radiusCirc;
		}
		else
		{
			inManLeft.speed = (*out).speed;
			inManLeft.speed_new = in.speed_new;
			inManLeft.acceleration = in.acceleration;
			inManLeft.heading = in.heading_new;
			inManLeft.heading_new = in.heading_new;
			inManLeft.radiusCirc = 0;
		}
		
		// пересчет времени для маневра по скорости или курсу
		resFindTimeMan = findTimeToAlterate( inManLeft, &timeManSpeed, &timeManHeading );
		if ( resFindTimeMan != ROFP_SUCCESS )
			return resFindTimeMan;
			
		timeManMax = timeManSpeedAndHeading + max( timeManSpeed, timeManHeading );
		timeManSpeedOrHeading = fabs( timeManSpeed - timeManHeading );
		
		double timeLeftForManSpeedOrHeading = 0;
		timeLeft = time - in.timeBeforeMan - timeManSpeedAndHeading;		
		if ( timeLeft <= timeManSpeedOrHeading )
			timeLeftForManSpeedOrHeading = timeLeft;
		else
			timeLeftForManSpeedOrHeading = timeManSpeedOrHeading;
		
		if ( fabs( timeLeftForManSpeedOrHeading ) > EPS )
		{
			struct TOutFindPrj outManLeft;
			resFindPrj = findPrj( timeLeftForManSpeedOrHeading, inManLeft, &outManLeft );
			
			if ( resFindPrj != ROFP_SUCCESS )
				return resFindPrj;
		
			(*out).x += outManLeft.x;
			(*out).y += outManLeft.y;
			(*out).path += outManLeft.path;
			(*out).speed = outManLeft.speed;
			(*out).heading = outManLeft.heading;
		}
	
	}
	
	// 4. участок прямолинейного равномерного движения
	//==================================================================
	timeLeft = 0;
	if ( time > in.timeBeforeMan + timeManMax )
		timeLeft = time - in.timeBeforeMan - timeManMax;
	
	//if ( fabs( timeLeft ) < EPS )
	//	return ROFP_SUCCESS;
	
	struct TInFindPrj inStraightConst_afterMan;
	inStraightConst_afterMan.speed = (*out).speed;
	inStraightConst_afterMan.speed_new = (*out).speed;
	inStraightConst_afterMan.acceleration = 0;	
	inStraightConst_afterMan.heading = (*out).heading;
	inStraightConst_afterMan.heading_new = (*out).heading;
	inStraightConst_afterMan.radiusCirc = 0;
	
	struct TOutFindPrj outStraightConst_afterMan;
	resFindPrj = findPrj( timeLeft, inStraightConst_afterMan, &outStraightConst_afterMan );
	if ( resFindPrj != ROFP_SUCCESS )
		return resFindPrj;
			
	(*out).x += outStraightConst_afterMan.x;
	(*out).y += outStraightConst_afterMan.y;
	(*out).path += outStraightConst_afterMan.path;
	(*out).speed = outStraightConst_afterMan.speed;
	(*out).heading = outStraightConst_afterMan.heading;
	
	return ROFP_SUCCESS;
}
