//#define BUILD_TEST

#ifndef MYMATH_H 
#define MYMATH_H

#if defined( BUILD_LIB )
# define EXPORT __declspec (dllexport)
#else
# if defined( BUILD_TEST )
#  define EXPORT
# else
#  define EXPORT __declspec (dllimport)
# endif
#endif

EXPORT int sign(double x);

EXPORT double sqr(double x);

EXPORT double rad( double grad );
EXPORT double grad( double rad );

EXPORT double priv2Pi(double rad);  // [0, 2pi)
EXPORT double privPi(double rad);   // (-pi, pi]

EXPORT double priv360(double grad); // [0, 360)
EXPORT double priv180(double grad); // (-180, 180]

EXPORT double coordX( double dist, double angleRad );
EXPORT double coordY( double dist, double angleRad );

EXPORT double dist_1to2( double x1, double y1, double x2, double y2 );
EXPORT double angle_1to2( double x1, double y1, double x2, double y2 );

struct TInFindPrj
{
	double speed;
	double speed_new;
	double acceleration;
	
	double heading;
	double heading_new;	
	double radiusCirc;
};

struct TOutFindPrj
{
	double x;
	double y;
	double path;
	double speed;
	double heading;
};

enum ResOfFindPrj
{
	ROFP_SUCCESS = 0,
	
	ROFP_ACCELERATION_IS_ZERO_SPEED_DIF_IS_NOT_ZERO = -1,
	ROFP_ACCELERATION_IS_NOT_ZERO_SPEED_DIF_IS_ZERO = -2,
	ROFP_ACCELERATION_AND_SPEED_DIF_ARE_LESS_THAN_ZERO = -3,
	ROFP_ACCELERATION_AND_SPEED_DIF_ARE_MORE_THAN_ZERO = -4,
	ROFP_RADIUS_CIRC_IS_ZERO_HEADING_DIF_IS_NOT_ZERO = -5,
	ROFP_RADIUS_CIRC_IS_NOT_ZERO_HEADING_DIF_IS_ZERO = -6,
	
	ROFP_NOT_ENOUGH_TIME_TO_ALTERATE_HEADING = -7,
	
	ROFP_NOT_ENOUGH_TIME = -8
};

EXPORT int findTimeToAlterate( struct TInFindPrj in, double * timeSpeedMan, double * timeHeadingMan );

EXPORT int verifyParams( struct TInFindPrj in );

EXPORT int findPrj( double time, struct TInFindPrj in, struct TOutFindPrj * out );

//EXPORT void findPos();

typedef
struct TInFPSC
{
	double x0;
	double y0;
	double speed;
	double headingRad;
	
} InFPSC;

EXPORT void findPos_sc( double time, InFPSC in, double * x, double * y ); //sc means straight, const speed

//================================================================================================

struct TDateTime
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;	
};

struct TDateTime getDateTime( );
EXPORT void randByTime();
EXPORT double uniformDistribution(double a, double b);
EXPORT double normalDistribution(double m, double sigma);

EXPORT double getMean( double * mas, unsigned int sizeMas );
EXPORT double getVariance( double * mas, unsigned int sizeMas );

//================================================================================================

typedef
struct TPoint2D
{
	double x;
	double y;
	
} Point2D;

struct TInFPMHS
{
	Point2D posStart;
	
	double speed;
	double heading;
	
	double timeBeforeMan;
	double acceleration;
	double speed_new;
	double radiusCirc;
	double heading_new;
};

EXPORT int findPos_manHS( double time, struct TInFPMHS in, struct TOutFindPrj * out );

//================================================================================================


typedef
struct TMotionParams
{
	double speed;
	double headingRad;
	
} MotionParams;

typedef
struct TMeasurement
{
	double time;
	double bearingRad;
	double distance;
		
} Measurement;

enum ModeEMP2Z
{
	MEMP2Z_ADD = 1,
	MEMP2Z_NULLIFY = 2
};

EXPORT MotionParams estimateMotionParams_2z( MotionParams motionParamsOwnObj, Measurement measurement, enum ModeEMP2Z mode );


/*
struct TIn2ZSimulation
{
	Point2D posOwnObj;
	MotionParams mpOwnObj;
	
	double distToObsObj;
	double bearingToObsObj;
	MotionParams mpObsObj;
	
	double sigmaBearing;
	double sigmaDistance;
	
	double timeMax;
	double timeStep;
};
*/

#endif // MYMATH_H
