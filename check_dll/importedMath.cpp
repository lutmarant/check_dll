#include "importedMath.h"

#include <iostream>

#include <cmath>
#define EPS 10e-5

namespace importedMath
{

using namespace std;

bool ImportedMath::getFuncSqrIsOk() const
{
    return funcSqrIsOk;
}

bool ImportedMath::getFuncRadIsOk() const
{
    return funcRadIsOk;
}

bool ImportedMath::getFuncGradIsOk() const
{
    return funcGradIsOk;
}

bool ImportedMath::getFuncPriv2PiIsOk() const
{
    return funcPriv2PiIsOk;
}

bool ImportedMath::getFuncPrivPiIsOk() const
{
    return funcPrivPiIsOk;
}

bool ImportedMath::getFuncCoordXIsOk() const
{
    return funcCoordXIsOk;
}

bool ImportedMath::getFuncCoordYIsOk() const
{
    return funcCoordYIsOk;
}

bool ImportedMath::getFuncDist1to2IsOk() const
{
    return funcDist1to2IsOk;
}

bool ImportedMath::getFuncAngle1to2IsOk() const
{
    return funcAngle1to2IsOk;
}

FuncSign ImportedMath::getSign() const
{
    return sign;
}

FuncSqr ImportedMath::getSqr() const
{
    return sqr;
}

bool ImportedMath::getFuncFindTimeToAlterateIsOk() const
{
    return funcFindTimeToAlterateIsOk;
}

bool ImportedMath::getFuncVerifyParamsIsOk() const
{
    return funcVerifyParamsIsOk;
}

bool ImportedMath::getFuncFindPrjIsOk() const
{
    return funcFindPrjIsOk;
}

FuncRad ImportedMath::getRad() const
{
    return rad;
}

FuncGrad ImportedMath::getGrad() const
{
    return grad;
}

FuncPriv2Pi ImportedMath::getPriv2Pi() const
{
    return priv2Pi;
}

FuncPrivPi ImportedMath::getPrivPi() const
{
    return privPi;
}

FuncCoordX ImportedMath::getCoordX() const
{
    return coordX;
}

FuncCoordY ImportedMath::getCoordY() const
{
    return coordY;
}

FuncDist_1to2 ImportedMath::getDist_1to2() const
{
    return dist_1to2;
}

FuncAngle_1to2 ImportedMath::getAngle_1to2() const
{
    return angle_1to2;
}

FuncVerifyParams ImportedMath::getFuncVerifyParams() const
{
    return funcVerifyParams;
}

FuncFindTimeToAlterate ImportedMath::getFuncFindTimeToAlterate() const
{
    return funcFindTimeToAlterate;
}

FuncFindPrj ImportedMath::getFuncFindPrj() const
{
    return funcFindPrj;
}

bool ImportedMath::getFuncUniformDistributionIsOk() const
{
    return funcUniformDistributionIsOk;
}

bool ImportedMath::getFuncNormalDistributionIsOk() const
{
    return funcNormalDistributionIsOk;
}

FuncUniformDistribution ImportedMath::getFuncUniformDistribution() const
{
    return funcUniformDistribution;
}

FuncNormalDistribution ImportedMath::getFuncNormalDistribution() const
{
    return funcNormalDistribution;
}

bool ImportedMath::getFuncFindPosSCIsOk() const
{
    return funcFindPosSCIsOk;
}

FuncFindPos_sc ImportedMath::getFuncFindPos_sc() const
{
    return funcFindPos_sc;
}

bool ImportedMath::getFuncEstimateMotionParams2ZIsOk() const
{
    return funcEstimateMotionParams2ZIsOk;
}

FuncEstimateMotionParams_2z ImportedMath::getFuncEstimateMotionParams_2z() const
{
    return funcEstimateMotionParams_2z;
}

bool ImportedMath::getFuncGetMeanIsOk() const
{
    return funcGetMeanIsOk;
}

bool ImportedMath::getFuncGetVarianceIsOk() const
{
    return funcGetVarianceIsOk;
}

FuncGetMean ImportedMath::getFuncGetMean() const
{
    return funcGetMean;
}

FuncGetVariance ImportedMath::getFuncGetVariance() const
{
    return funcGetVariance;
}

FuncFindPos_complex ImportedMath::getFuncFindPos_complex() const
{
    return funcFindPos_complex;
}

bool ImportedMath::getFuncFindPosComplexIsOk() const
{
    return funcFindPosComplexIsOk;
}

ImportedMath::ImportedMath()
{
    file = fopen( "log.txt", "w" );
    
    lib = new QLibrary( "mymathlib.dll" );

    if ( !lib->load() )
    {
        std::cout << "lib NOT loaded" << std::endl;
        fprintf( file, "\nlib NOT loaded");
    }
    else
    {
        std::cout << "lib loaded" << std::endl;
        fprintf( file, "\nlib loaded");

        sign = ( FuncSign )lib->resolve( "sign" );
        sqr = ( FuncSqr )lib->resolve( "sqr" );
        rad = ( FuncRad )lib->resolve( "rad" );
        grad = ( FuncGrad )lib->resolve( "grad" );
        priv2Pi = ( FuncPriv2Pi )lib->resolve( "priv2Pi" );
        privPi = ( FuncPrivPi )lib->resolve( "privPi" );
        coordX = ( FuncCoordX )lib->resolve( "coordX" );
        coordY = ( FuncCoordY )lib->resolve( "coordY" );
        dist_1to2 = ( FuncDist_1to2 )lib->resolve( "dist_1to2" );
        angle_1to2 = ( FuncAngle_1to2 )lib->resolve( "angle_1to2" );
        funcVerifyParams = ( FuncVerifyParams )lib->resolve( "verifyParams" );
        funcFindTimeToAlterate = ( FuncFindTimeToAlterate )lib->resolve( "findTimeToAlterate" );
        funcFindPrj = ( FuncFindPrj )lib->resolve( "findPrj" );

        funcUniformDistribution = ( FuncUniformDistribution )lib->resolve( "uniformDistribution" );
        funcNormalDistribution = ( FuncNormalDistribution )lib->resolve( "normalDistribution" );

        funcFindPos_sc = ( FuncFindPos_sc )lib->resolve( "findPos_sc" );

        funcEstimateMotionParams_2z = ( FuncEstimateMotionParams_2z )lib->resolve( "estimateMotionParams_2z" );

        funcGetMean = ( FuncGetMean )lib->resolve( "getMean" );
        funcGetVariance = ( FuncGetVariance )lib->resolve( "getVariance" );

        funcFindPos_complex = ( FuncFindPos_complex )lib->resolve( "findPos_manHS" );
    }
}

ImportedMath::~ImportedMath()
{
    if ( lib )
    {
        delete lib;
        lib = nullptr;
    }

    fclose( file );
}

bool ImportedMath::checkAllFuncs()
{
    funcSignIsOk = ( checkFuncSign() == 0 );
    funcSqrIsOk = ( checkFuncSqr() == 0 );
    funcRadIsOk = ( checkFuncRad() == 0 );
    funcGradIsOk = ( checkFuncGrad() == 0 );
    funcPriv2PiIsOk = ( checkFuncPriv2Pi() == 0 );
    funcPrivPiIsOk = ( checkFuncPrivPi() == 0 );
    funcCoordXIsOk = ( checkFuncCoordX() == 0 );
    funcCoordYIsOk = ( checkFuncCoordY() == 0 );
    funcDist1to2IsOk = ( checkFuncDist_1to2() == 0 );
    funcAngle1to2IsOk = ( checkFuncAngle_1to2() == 0 );
    funcVerifyParamsIsOk = ( checkFuncVerifyParams() == 0 );
    funcFindTimeToAlterateIsOk = ( checkFuncFindTimeToAlterate() == 0 );
    funcFindPrjIsOk = ( checkFuncFindPrj() == 0 );
    funcUniformDistributionIsOk = ( checkFuncUniformDistribution() == 0 );
    funcNormalDistributionIsOk = ( checkFuncNormalDistribution() == 0 );
    funcFindPosSCIsOk = ( checkFuncFindPosSC() == 0 );
    funcEstimateMotionParams2ZIsOk = ( checkFuncEstimateMotionParams2Z() == 0 );
    funcGetMeanIsOk = ( checkFuncGetMean() == 0 );
    funcGetVarianceIsOk = ( checkFuncGetVariance() == 0 );
    funcFindPosComplexIsOk = ( checkFuncFindPosComplex() == 0 );

    return funcSignIsOk
    && funcSqrIsOk
    && funcRadIsOk
    && funcGradIsOk
    && funcPriv2PiIsOk
    && funcPrivPiIsOk
    && funcCoordXIsOk
    && funcCoordYIsOk
    && funcDist1to2IsOk
    && funcAngle1to2IsOk
    && funcVerifyParamsIsOk
    && funcFindTimeToAlterateIsOk
    && funcFindPrjIsOk
    && funcUniformDistributionIsOk
    && funcNormalDistributionIsOk
    && funcGetMeanIsOk
    && funcGetVarianceIsOk
    && funcFindPosComplexIsOk;

    /*
    return funcSignIsOk
    && funcSqrIsOk
    && funcRadIsOk
    && funcGradIsOk
    && funcPriv2PiIsOk
    && funcPrivPiIsOk
    && funcCoordXIsOk
    && funcCoordYIsOk
    && funcDist1to2IsOk
    && funcAngle1to2IsOk
    && funcVerifyParamsIsOk
    && funcFindTimeToAlterateIsOk
    && funcFindPrjIsOk
    && funcUniformDistributionIsOk
    && funcNormalDistributionIsOk
    && funcFindPosSCIsOk
    && funcEstimateMotionParams2ZIsOk //
    && funcGetMeanIsOk
    && funcGetVarianceIsOk;
    */
}

template< typename T >
unsigned int checkFunc1Arg( FILE * file, char * nameFunc, T ( *func )( double x ), double * inMas, T * outMas, unsigned int numOfChecks )
{
    unsigned int numOfErrors = 0;

    unsigned int ii = 0;

    for ( ii = 0; ii < numOfChecks; ++ii )
    {
        double resToCheck = (*func)( inMas[ ii ] );
        double resIst = outMas[ ii ];

        fprintf( file, "\n%s( %f ) == %f == %f", nameFunc, inMas[ ii ], resToCheck, resIst );

        double xDifference = fabs( resIst - resToCheck  );
        bool funcIsOk = xDifference < EPS;
        if ( !funcIsOk )
        {
            ++numOfErrors;
            fprintf( file, "\nerror xIn: %f \n", inMas[ ii ] );
        }
    }

    if ( numOfErrors != 0 )
    {
        fprintf( file, "\n%s FAILED with num of errors = %d \n", nameFunc, numOfErrors );
    }
    else
    {
        fprintf( file, "\n%s is OK\n", nameFunc );
    }

    return numOfErrors;
}

unsigned int checkFunc2Args( FILE * file, char * nameFunc, double ( *func )( double x, double y ), double * inMas1, double * inMas2, double * outMas, unsigned int numOfChecks )
{
    unsigned int numOfErrors = 0;

    unsigned int ii = 0;

    for ( ii = 0; ii < numOfChecks; ++ii )
    {
        double resToCheck = (*func)( inMas1[ ii ], inMas2[ ii ] );
        double resIst = outMas[ ii ];

        fprintf( file, "\n%s( %f, %f ) == %f == %f", nameFunc, inMas1[ ii ], inMas2[ ii ], resToCheck, resIst );

        double xDifference = fabs( resIst - resToCheck  );
        bool funcIsOk = xDifference < EPS;
        if ( !funcIsOk )
        {
            ++numOfErrors;
            fprintf( file, "\nerror xIn: %f, %f \n", inMas1[ ii ], inMas2[ ii ] );
        }
    }

    if ( numOfErrors != 0 )
    {
        fprintf( file, "\n%s FAILED with num of errors = %d \n", nameFunc, numOfErrors ); // ???-?? ?????
    }
    else
    {
        fprintf( file, "\n%s is OK\n", nameFunc );
    }

    return numOfErrors;
}

unsigned int checkFunc4Args( FILE * file, char * nameFunc, double ( *func )( double x1, double y1, double x2, double y2 ), double * inMas1, double * inMas2, double * inMas3, double * inMas4, double * outMas, unsigned int numOfChecks )
{
    unsigned int numOfErrors = 0;

    unsigned int ii = 0;

    for ( ii = 0; ii < numOfChecks; ++ii )
    {
        double resToCheck = (*func)( inMas1[ ii ], inMas2[ ii ], inMas3[ ii ], inMas4[ ii ] );
        double resIst = outMas[ ii ];

        fprintf( file, "\n%s( %f, %f, %f, %f ) == %f == %f", nameFunc, inMas1[ ii ], inMas2[ ii ], inMas3[ ii ], inMas4[ ii ], resToCheck, resIst );

        double xDifference = fabs( resIst - resToCheck  );
        bool funcIsOk = xDifference < EPS;
        if ( !funcIsOk )
        {
            ++numOfErrors;
            fprintf( file, "\nerror xIn: %f, %f, %f, %f \n", inMas1[ ii ], inMas2[ ii ], inMas3[ ii ], inMas4[ ii ] );
        }
    }

    if ( numOfErrors != 0 )
    {
        fprintf( file, "\n%s FAILED with num of errors = %d \n", nameFunc, numOfErrors ); // ???-?? ?????
    }
    else
    {
        fprintf( file, "\n\n%s is OK\n", nameFunc );
    }

    return numOfErrors;
}

//=====================================================================

int ImportedMath::checkFuncSign()
{
    std::string nameString = "sign";

    std::cout << "\n=====================================================================" << std::endl;

    if ( sign )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 12;
        double xIn[ nChecks ]  = { 10, 0, -198, -100, 0, 100, 0.1, 0.5, 0.7, -0.1, -0.5, -0.7 };
        int xOut[ nChecks ] = { 1 , 1, -1, -1, 1, 1, 1, 1, 1, -1, -1, -1 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, sign, xIn, xOut, nChecks );
    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncSqr()
{
    std::string nameString = "sqr";

    std::cout << "\n=====================================================================" << std::endl;

    if ( sqr )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 6;
        double xIn[ nChecks ]  = { 5,   6,  2, -36,  -2, 0 };
        double xOut[ nChecks ] = { 25 , 36, 4, 1296, 4,  0 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, sqr, xIn, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncRad()
{
    std::string nameString = "rad";

    std::cout << "\n=====================================================================" << std::endl;

    if ( rad )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 10;
        double xIn[ nChecks ]  = { 0, 90,     180,  270,           360,      45,           135,                   225,               315  };
        double xOut[ nChecks ] = { 0, M_PI_2, M_PI, M_PI + M_PI_2, 2 * M_PI, M_PI_2 / 2.0, M_PI_2 + M_PI_2 / 2.0, M_PI + M_PI_2/2.0, M_PI + M_PI_2+ M_PI_2/2.0 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, rad, xIn, xOut, nChecks );
    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncGrad()
{
    std::string nameString = "grad";

    std::cout << "\n=====================================================================" << std::endl;

    if ( grad )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 10;
        double xIn[ nChecks ] = { 0, M_PI_2, M_PI, M_PI + M_PI_2, 2 * M_PI, M_PI_2 / 2.0, M_PI_2 + M_PI_2 / 2.0, M_PI + M_PI_2/2.0, M_PI + M_PI_2+ M_PI_2/2.0 };
        double xOut[ nChecks ]  = { 0, 90,     180,  270,           360,      45,           135,                   225,               315  };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, grad, xIn, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncPriv2Pi()
{
    std::string nameString = "priv2Pi";

    std::cout << "\n=====================================================================" << std::endl;

    if ( priv2Pi )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 2;
        double xIn[ nChecks ] = { M_PI + 4 * 2 * M_PI, - M_PI - 4 * 2 * M_PI };
        double xOut[ nChecks ]  = { M_PI, M_PI };


        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, priv2Pi, xIn, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncPrivPi()
{
    std::string nameString = "privPi";

    std::cout << "\n=====================================================================" << std::endl;

    if ( privPi )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 2;
        double xIn[ nChecks ] = { M_PI_2 + 4 * 2 * M_PI, - M_PI_2 - 4 * 2 * M_PI };
        double xOut[ nChecks ]  = { M_PI_2, -M_PI_2 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc1Arg( file, nameChar, privPi, xIn, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncCoordX()
{
    std::string nameString = "coordX";

    std::cout << "\n=====================================================================" << std::endl;

    if ( coordX )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 2;
        double xIn1[ nChecks ]  = { 10000, 10000 };
        double xIn2[ nChecks ]  = { 0,     M_PI_2 };
        double xOut[ nChecks ] = {  0,     10000 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc2Args( file, nameChar, coordX, xIn1, xIn2, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncCoordY()
{
    std::string nameString = "coordY";

    std::cout << "\n=====================================================================" << std::endl;

    if ( coordY )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 2;
        double xIn1[ nChecks ]  = { 10000, 10000 };
        double xIn2[ nChecks ]  = { 0,     M_PI_2 };
        double xOut[ nChecks ] = {  10000, 0 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc2Args( file, nameChar, coordY, xIn1, xIn2, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncDist_1to2()
{
    std::string nameString = "dist_1to2";

    std::cout << "\n=====================================================================" << std::endl;

    if ( dist_1to2 )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 2;
        double xIn1[ nChecks ]  = { 0,     0 };
        double xIn2[ nChecks ]  = { 0,     0 };
        double xIn3[ nChecks ]  = { 10000, 0 };
        double xIn4[ nChecks ]  = { 0,     10000 };
        double xOut[ nChecks ]  = { 10000, 10000 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc4Args( file, nameChar, dist_1to2, xIn1, xIn2, xIn3, xIn4, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncAngle_1to2()
{
    std::string nameString = "angle_1to2";

    std::cout << "\n=====================================================================" << std::endl;

    if ( angle_1to2 )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        unsigned int counterErrors = 0;

        if ( funcRadIsOk && funcGradIsOk && funcCoordXIsOk && funcCoordYIsOk )
        {
            double dist_ist = 100000;
            double peleng_ist = rad( 0 );
            double peleng_min = rad( 0 );
            double peleng_max = rad( 360 );
            double peleng_step = rad( 10 );

            double posZero_x = 10000;
            double posZero_y = -100000;

            fprintf( file, "\nist == check" );
            for( peleng_ist = peleng_min; peleng_ist < peleng_max; peleng_ist = peleng_ist + peleng_step )
            {
                double posX_ist = posZero_x + coordX( dist_ist, peleng_ist );
                double posY_ist = posZero_y + coordY( dist_ist, peleng_ist );

                double pelengToCheck = angle_1to2( posZero_x, posZero_y, posX_ist, posY_ist);

                fprintf( file, "\n%f == %f", grad( peleng_ist ), grad( pelengToCheck ) );

                // ????????? ????????? ?? ???????? ? ???????????? ???????
                double pelengDifference = fabs( peleng_ist - pelengToCheck );
                bool pelengIsOk = pelengDifference < EPS; // ???? 1 (true), ?? ? ???????? ??? ??????
                if ( !pelengIsOk ) // ???? ??? ?????, ?? ?????????? ? ???????? ?????? 1
                {
                    ++counterErrors;
                    fprintf( file, "\nerror for peleng_ist = %f \n", grad( peleng_ist ) );
                    fprintf( file, "       pelengToCheck = %f \n", grad( pelengToCheck ) );
                    fprintf( file, "   peleng difference = %f \n", grad( pelengDifference ) );
                }
            }

            //            if ( counterErrors != 0 )
            //            {
            //                //printf( "\n\ntests FAILED with num of errors = %d \n", ++counterErrors ); // ???-?? ?????
            //                //return counterErrors;
            //            }
            //            else
            //            {
            //                //printf( "\n\nfunc is OK \n", ++counterErrors ); // ???-?? ?????
            //                //return 0;
            //            }

        }

        double posZero_x = 10000;
        double posZero_y = -100000;

        const unsigned int nChecks = 4;
        double xIn1[ nChecks ]  = { posZero_x,       posZero_x,       posZero_x,        posZero_x };
        double xIn2[ nChecks ]  = { posZero_y,       posZero_y,       posZero_y,        posZero_y };
        double xIn3[ nChecks ]  = { posZero_x,       posZero_x + 100, posZero_x,        posZero_x - 467429};
        double xIn4[ nChecks ]  = { posZero_y + 100, posZero_y,       posZero_y - 2285, posZero_y };
        double xOut[ nChecks ]  = { 0,        M_PI/2,       M_PI,       M_PI+M_PI/2 };

        char * nameChar = const_cast <char*>(nameString.c_str());
        return counterErrors + checkFunc4Args( file, nameChar, angle_1to2, xIn1, xIn2, xIn3, xIn4, xOut, nChecks );
    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncVerifyParams()
{
    std::string nameString = "verifyParams";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcVerifyParams )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const int nChecks = 10;
        double inSpeed[ nChecks ]         = { 10.0, 10.0, 10.0, 5.0,  10.0, 10.0, 10.0,  10.0, 15.0, 1.0 };
        double inSpeedNew[ nChecks ]      = { 15.0, 10.0, 5.0,  10.0, 10.0, 10.0, 15.0,  15.0, 10.0, 1.0 };
        double inAcceleration[ nChecks ]  = { 0.0,  1.0,  1.0,  -1.0, 0.0,  0.0,  1.0,   1.0,  -1.0, 0.0 };
        double inHeading[ nChecks ]       = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,   1.0,  0.0,  0.0 };
        double inHeadingNew[ nChecks ]    = { 0.0,  0.0,  0.0,  0.0,  1.0,  0.0,  1.0,   2.0,  0.0,  0.0 };
        double inRadiusCirc[ nChecks ]    = { 0.0,  0.0,  0.0,  0.0,  0.0,  50.0, 50.0 , 50.0, 0.0,  0.0 };

//        inAcceleration[ 3 ] = -1;
//        inAcceleration[ 8 ] = -1;

//        struct TInFindPrj inFindPrj_mas[ nChecks ];
//        inFindPrj_mas[ 0 ]  = { 10.0, 15.0,   0.0,    0.0,    0.0,   0.0 };
//        inFindPrj_mas[ 1 ]  = { 10.0, 10.0,   1.0,    0.0,    0.0,   0.0 };
//        inFindPrj_mas[ 2 ]  = { 10.0,  5.0,   1.0,    0.0,    0.0,   0.0 };
//        inFindPrj_mas[ 3 ]  = {  5.0, 10.0,  -1.0,    0.0,    0.0,   0.0 };
//        inFindPrj_mas[ 4 ]  = { 10.0, 10.0,   0.0,    0.0,    1.0,   0.0 };
//        inFindPrj_mas[ 5 ]  = { 10.0, 10.0,   0.0,    0.0,    0.0,  50.0 };
//        inFindPrj_mas[ 6 ]  = { 10.0, 15.0,   1.0,    0.0, M_PI/2,  50.0 };
//        inFindPrj_mas[ 7 ]  = {  5.0,  2.0,  -1.0,   M_PI, M_PI/2, 300.0 };
//        inFindPrj_mas[ 8 ]  = {  5.0,  2.0, -0.01,   M_PI, M_PI/2, 300.0 };
//        inFindPrj_mas[ 9 ]  = { 15.0, 10.0,  -1.0,    0.0,    0.0,   0.0 };

        struct TInFindPrj inFindPrj_mas[ nChecks ] //=
        {
            { 10.0, 15.0,   0.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   1.0,    0.0,    0.0,   0.0 },
            { 10.0,  5.0,   1.0,    0.0,    0.0,   0.0 },
            {  5.0, 10.0,  -1.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    1.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    0.0,  50.0 },
            { 10.0, 15.0,   1.0,    0.0, M_PI/2,  50.0 },
            {  5.0,  2.0,  -1.0,   M_PI, M_PI/2, 300.0 },
            {  5.0,  2.0, -0.01,   M_PI, M_PI/2, 300.0 },
            { 15.0, 10.0,  -1.0,    0.0,    0.0,   0.0 }
        };

        int outCode[ nChecks ]    = { ROFP_ACCELERATION_IS_ZERO_SPEED_DIF_IS_NOT_ZERO,
                                      ROFP_ACCELERATION_IS_NOT_ZERO_SPEED_DIF_IS_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_MORE_THAN_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_LESS_THAN_ZERO,
                                      ROFP_RADIUS_CIRC_IS_ZERO_HEADING_DIF_IS_NOT_ZERO,
                                      ROFP_RADIUS_CIRC_IS_NOT_ZERO_HEADING_DIF_IS_ZERO,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS
                                    };

        char * nameChar = const_cast <char*>(nameString.c_str());


        unsigned int numOfErrors = 0;

        unsigned int ii = 0;

        for ( ii = 0; ii < nChecks; ++ii )
        {
            struct TInFindPrj inFindPrj;
            inFindPrj.speed        = inSpeed[ ii ];
            inFindPrj.speed_new    = inSpeedNew[ ii ];
            inFindPrj.acceleration = inAcceleration[ ii ];
            inFindPrj.heading      = inHeading[ ii ];
            inFindPrj.heading_new  = inHeadingNew[ ii ];
            inFindPrj.radiusCirc   = inRadiusCirc[ ii ];

            fprintf( file, "\n\n in %s 1:", nameChar );
            fprintf( file, "\n inFindPrj_mas[ ii ].speed = %f", inFindPrj_mas[ ii ].speed );
            fprintf( file, "\n inFindPrj_mas[ ii ].speed_new = %f", inFindPrj_mas[ ii ].speed_new );
            fprintf( file, "\n inFindPrj_mas[ ii ].acceleration = %f", inFindPrj_mas[ ii ].acceleration );
            fprintf( file, "\n inFindPrj_mas[ ii ].heading = %f:", inFindPrj_mas[ ii ].heading );
            fprintf( file, "\n inFindPrj_mas[ ii ].heading_new = %f", inFindPrj_mas[ ii ].heading_new );
            fprintf( file, "\n inFindPrj_mas[ ii ].radiusCirc = %f", inFindPrj_mas[ ii ].radiusCirc );

            inFindPrj = inFindPrj_mas[ ii ];

            std::cout << "size = " << sizeof( inFindPrj_mas[ 0 ] ) << std::endl;
            std::cout << "size = " << sizeof( inFindPrj.speed ) << " == " << sizeof( inSpeed[ 0 ] ) << std::endl;

            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n inFindPrj.speed = %f", inFindPrj.speed );
            fprintf( file, "\n inFindPrj.speed_new = %f", inFindPrj.speed_new );
            fprintf( file, "\n inFindPrj.acceleration = %f", inFindPrj.acceleration );
            fprintf( file, "\n inFindPrj.heading = %f:", inFindPrj.heading );
            fprintf( file, "\n inFindPrj.heading_new = %f", inFindPrj.heading_new );
            fprintf( file, "\n inFindPrj.radiusCirc = %f", inFindPrj.radiusCirc );
            fprintf( file, "\n%f", inRadiusCirc[ ii ] );

            fprintf( file, "\n\n in %s 2:", nameChar );
            fprintf( file, "\n inFindPrj_mas[ ii ].speed = %f", inFindPrj_mas[ ii ].speed );
            fprintf( file, "\n inFindPrj_mas[ ii ].speed_new = %f", inFindPrj_mas[ ii ].speed_new );
            fprintf( file, "\n inFindPrj_mas[ ii ].acceleration = %f", inFindPrj_mas[ ii ].acceleration );
            fprintf( file, "\n inFindPrj_mas[ ii ].heading = %f:", inFindPrj_mas[ ii ].heading );
            fprintf( file, "\n inFindPrj_mas[ ii ].heading_new = %f", inFindPrj_mas[ ii ].heading_new );
            fprintf( file, "\n inFindPrj_mas[ ii ].radiusCirc = %f", inFindPrj_mas[ ii ].radiusCirc );
            fprintf( file, "\n%f", inRadiusCirc[ ii ] );

            int resToCheck = funcVerifyParams( inFindPrj );
            int resIst = outCode[ ii ];

            fprintf( file, "\n%s( %f, %f, %f, %f, %f, %f ) == %d == %d", nameChar, inFindPrj.speed, inFindPrj.speed_new, inFindPrj.acceleration, inFindPrj.heading, inFindPrj.heading_new, inFindPrj.radiusCirc, resToCheck, resIst );

            double xDifference = fabs( resIst - resToCheck  );
            bool funcIsOk = xDifference < EPS;
            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror for in params: %f, %f, %f, %f, %f, %f\n", inFindPrj.speed, inFindPrj.speed_new, inFindPrj.acceleration, inFindPrj.heading, inFindPrj.heading_new, inFindPrj.radiusCirc );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncFindTimeToAlterate()
{
    std::string nameString = "funcFindTimeToAlterate";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcFindTimeToAlterate )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 13;
//        double inSpeed[ nChecks ]         = { 10.0, 10.0, 10.0, 5.0,  10.0, 10.0, 10.0,     5.0,    5.0,       15.0, 1.0, 10.0,     5.0 };
//        double inSpeedNew[ nChecks ]      = { 15.0, 10.0, 5.0,  10.0, 10.0, 10.0, 15.0,     2.0,    2.0,       10.0, 1.0, 10.0,     5.0 };
//        double inAcceleration[ nChecks ]  = { 0.0,  1.0,  1.0,  -1.0, 0.0,  0.0,  1.0,      -1.0,   -0.01,     -1.0, 0.0, 0.0,      0.0 };
//        double inHeading[ nChecks ]       = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,      M_PI,   M_PI,      0.0,  0.0, 0.0,      M_PI };
//        double inHeadingNew[ nChecks ]    = { 0.0,  0.0,  0.0,  0.0,  1.0,  0.0,  M_PI/2,   M_PI/2, M_PI/2,    0.0,  0.0, M_PI/2,   M_PI/2 };
//        double inRadiusCirc[ nChecks ]    = { 0.0,  0.0,  0.0,  0.0,  0.0,  50.0, 50.0 ,    300.0,  300.0,     0.0,  0.0, 100.0,    300 };

        double inSpeed[]         = { 10.0, 10.0, 10.0, 5.0,  10.0, 10.0, 10.0,     5.0,    5.0,       15.0, 1.0, 10.0,     5.0 };
        double inSpeedNew[]      = { 15.0, 10.0, 5.0,  10.0, 10.0, 10.0, 15.0,     2.0,    2.0,       10.0, 1.0, 10.0,     5.0 };
        double inAcceleration[]  = { 0.0,  1.0,  1.0,  -1.0, 0.0,  0.0,  1.0,      -1.0,   -0.01,     -1.0, 0.0, 0.0,      0.0 };
        double inHeading[]       = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,      M_PI,   M_PI,      0.0,  0.0, 0.0,      M_PI };
        double inHeadingNew[]    = { 0.0,  0.0,  0.0,  0.0,  1.0,  0.0,  M_PI/2,   M_PI/2, M_PI/2,    0.0,  0.0, M_PI/2,   M_PI/2 };
        double inRadiusCirc[]    = { 0.0,  0.0,  0.0,  0.0,  0.0,  50.0, 50.0 ,    300.0,  300.0,     0.0,  0.0, 100.0,    300 };

        double outTimeSpeed[ nChecks ]    = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  5.0,       3.0,   300.0,     5.0,  0.0, 0.0,      0.0 };
        //double outTimeHeading[ nChecks ]  = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  6.033703 , 50.0,  389.65456, 0.0,  0.0, 15.70796, 94.24778 };
        double outTimeHeading[ nChecks ]  = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  6.033703 , 50.0,  105.345442, 0.0,  0.0, 15.70796, 94.24778 };

        int outCode[ nChecks ]    = { ROFP_ACCELERATION_IS_ZERO_SPEED_DIF_IS_NOT_ZERO,
                                      ROFP_ACCELERATION_IS_NOT_ZERO_SPEED_DIF_IS_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_MORE_THAN_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_LESS_THAN_ZERO,
                                      ROFP_RADIUS_CIRC_IS_ZERO_HEADING_DIF_IS_NOT_ZERO,
                                      ROFP_RADIUS_CIRC_IS_NOT_ZERO_HEADING_DIF_IS_ZERO,
                                      ROFP_SUCCESS,//
                                      ROFP_NOT_ENOUGH_TIME_TO_ALTERATE_HEADING,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS,
                                      ROFP_SUCCESS
                                    };

        struct TInFindPrj inFindPrj_mas[ nChecks ] //=
        {
            { 10.0, 15.0,   0.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   1.0,    0.0,    0.0,   0.0 },
            { 10.0,  5.0,   1.0,    0.0,    0.0,   0.0 },
            {  5.0, 10.0,  -1.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    1.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    0.0,  50.0 },
            { 10.0, 15.0,   1.0,    0.0, M_PI/2,  50.0 }, //
            {  5.0,  2.0,  -1.0,   M_PI, M_PI/2, 300.0 },
            {  5.0,  2.0, -0.01,   M_PI, M_PI/2, 300.0 },
            { 15.0, 10.0,  -1.0,    0.0,    0.0,   0.0 },
            {  1.0,  1.0,   0.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0, M_PI/2, 100.0 },
            {  5.0,  5.0,   0.0,   M_PI, M_PI/2, 300.0 }
        };

        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int ii = 0;
//        for ( ii = 0; ii < nChecks; ++ii )
//        {
//            fprintf( file, "\n inFindPrj.radiusCirc = %f:", inRadiusCirc[ ii ] );
//        }

        unsigned int numOfErrors = 0;

        for ( ii = 0; ii < nChecks; ++ii )
        {
            struct TInFindPrj inFindPrj;
            inFindPrj.speed        = inSpeed[ ii ];
            inFindPrj.speed_new    = inSpeedNew[ ii ];
            inFindPrj.acceleration = inAcceleration[ ii ];
            inFindPrj.heading      = inHeading[ ii ];
            inFindPrj.heading_new  = inHeadingNew[ ii ];
            inFindPrj.radiusCirc   = inRadiusCirc[ ii ];

            //if ( ii == 0 )
                inFindPrj = inFindPrj_mas[ ii ];

            //std::cout << "inFindPrj.radiusCirc = " << inFindPrj.radiusCirc << std::endl;

//            printf( "\n inRadiusCirc[ ii ] = %f:", inRadiusCirc[ ii ] );

            //std::cout << "inFindPrj.radiusCirc = " << inFindPrj.radiusCirc << std::endl;

            double timeSpeedToCheck = -1;
            double timeHeadingToCheck = -1;

            fprintf( file, "\n\n in %s 1:", nameChar );
            fprintf( file, "\n inFindPrj.speed = %f", inFindPrj.speed );
            fprintf( file, "\n inFindPrj.speed_new = %f", inFindPrj.speed_new );
            fprintf( file, "\n inFindPrj.acceleration = %f", inFindPrj.acceleration );
            fprintf( file, "\n inFindPrj.heading = %f:", inFindPrj.heading );
            fprintf( file, "\n inFindPrj.heading_new = %f", inFindPrj.heading_new );
            fprintf( file, "\n inFindPrj.radiusCirc = %f", inFindPrj.radiusCirc );
            fprintf( file, "\n%f", inRadiusCirc[ ii ] );

            int resToCheck = funcFindTimeToAlterate( inFindPrj, &timeSpeedToCheck, &timeHeadingToCheck );
            int resIst = outCode[ ii ];

            double timeSpeedIst = outTimeSpeed[ ii ];
            double timeHeadingIst = outTimeHeading[ ii ];

            fprintf( file, "\n\n in %s: 2", nameChar );
            fprintf( file, "\n inFindPrj.speed = %f", inFindPrj.speed );
            fprintf( file, "\n inFindPrj.speed_new = %f", inFindPrj.speed_new );
            fprintf( file, "\n inFindPrj.acceleration = %f", inFindPrj.acceleration );
            fprintf( file, "\n inFindPrj.heading = %f:", inFindPrj.heading );
            fprintf( file, "\n inFindPrj.heading_new = %f", inFindPrj.heading_new );
            fprintf( file, "\n inFindPrj.radiusCirc = %f", inFindPrj.radiusCirc );
            fprintf( file, "\n%f", inRadiusCirc[ ii ] );

            std::cout << sizeof(inRadiusCirc[ ii ]) << "==" << sizeof(inFindPrj.radiusCirc) << std::endl;

            //std::cout << "inFindPrj.radiusCirc = " << inFindPrj.radiusCirc << std::endl;

            fprintf( file, "\n out %s: %d == %d, %f == %f, %f == %f", nameChar, resToCheck, resIst, timeSpeedToCheck, timeSpeedIst, timeHeadingToCheck, timeHeadingIst );

            double xDifference = fabs( resIst - resToCheck  );
            bool funcIsOk_res = xDifference < EPS;

            double timeSpeedDif = fabs( timeSpeedIst - timeSpeedToCheck  );
            bool funcIsOk_ts = timeSpeedDif < EPS;

            double timeHeadingDif = fabs( timeHeadingIst - timeHeadingToCheck  );
            bool funcIsOk_th = timeHeadingDif < EPS;

            bool funcIsOk = 0;

            if ( resIst != ROFP_SUCCESS )
                funcIsOk = funcIsOk_res;
            else
                funcIsOk = funcIsOk_res && funcIsOk_ts && funcIsOk_th;


            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncFindPrj()
{
    std::string nameString = "funcFindPrj";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcFindPrj )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 15;

        struct TInFindPrj inFindPrj_mas[ nChecks ] //=
        {
            { 10.0, 15.0,   0.0,    0.0,    0.0,   0.0 }, //0
            { 10.0, 10.0,   1.0,    0.0,    0.0,   0.0 },
            { 10.0,  5.0,   1.0,    0.0,    0.0,   0.0 },
            {  5.0, 10.0,  -1.0,    0.0,    0.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    1.0,   0.0 },
            { 10.0, 10.0,   0.0,    0.0,    0.0,  50.0 },

            { 10.0, 15.0,   1.0,    0.0, M_PI/2,  50.0 }, //6
            { 10.0, 15.0,   1.0,    0.0, M_PI/2,  50.0 }, //7
            {  5.0,  2.0,  -1.0,   M_PI, M_PI/2, 300.0 }, //8
            {  5.0,  2.0,  -1.0,   M_PI, M_PI/2, 300.0 }, //9
            {  5.0,  2.0, -0.01,   M_PI, M_PI/2, 300.0 }, //10
            {  5.0,  2.0, -0.01,   M_PI, M_PI/2, 300.0 }, //11
            { 15.0, 10.0,  -1.0,    0.0,    0.0,   0.0 }, //12
            { 10.0, 10.0,   0.0,    0.0, M_PI/2, 100.0 }, //13
            {  5.0,  5.0,   0.0,   M_PI, M_PI/2, 300.0 }  //14
        };

        double inTime[ nChecks ];
        inTime[ 0 ] = 10;
        inTime[ 1 ] = 10;
        inTime[ 2 ] = 10;
        inTime[ 3 ] = 10;
        inTime[ 4 ] = 10;
        inTime[ 5 ] = 10;

        inTime[ 6 ] = 5.000000;
        inTime[ 7 ] = 6.033703;
        inTime[ 8 ] = 3.000000;
        inTime[ 9 ] = 5.000000;
        inTime[ 10 ] = 300.000000;
        inTime[ 11 ] = 105.345441;
        inTime[ 12 ] = 5.000000;
        inTime[ 13 ] = 15.707963;
        inTime[ 14 ] = 94.247770;

        int outCode[ nChecks ]    = { ROFP_ACCELERATION_IS_ZERO_SPEED_DIF_IS_NOT_ZERO,
                                      ROFP_ACCELERATION_IS_NOT_ZERO_SPEED_DIF_IS_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_MORE_THAN_ZERO,
                                      ROFP_ACCELERATION_AND_SPEED_DIF_ARE_LESS_THAN_ZERO,
                                      ROFP_RADIUS_CIRC_IS_ZERO_HEADING_DIF_IS_NOT_ZERO,
                                      ROFP_RADIUS_CIRC_IS_NOT_ZERO_HEADING_DIF_IS_ZERO,
                                      ROFP_SUCCESS, //6
                                      ROFP_NOT_ENOUGH_TIME, //7
                                      ROFP_SUCCESS, //8
                                      ROFP_NOT_ENOUGH_TIME, //9
                                      ROFP_NOT_ENOUGH_TIME, //10
                                      ROFP_SUCCESS, //11
                                      ROFP_SUCCESS, //12
                                      ROFP_SUCCESS, //13
                                      ROFP_SUCCESS  //14
                                    };

        double outSpeed[ nChecks ];
        outSpeed[ 0 ] = 0;
        outSpeed[ 1 ] = 0;
        outSpeed[ 2 ] = 0;
        outSpeed[ 3 ] = 0;
        outSpeed[ 4 ] = 0;
        outSpeed[ 5 ] = 0;

        outSpeed[ 6 ] = 15.000000;
        outSpeed[ 7 ] = 0;
        outSpeed[ 8 ] = 2.000000;
        outSpeed[ 9 ] = 0;
        outSpeed[ 10 ] = 0;
        outSpeed[ 11 ] = 3.946546;
        outSpeed[ 12 ] = 10.000000;
        outSpeed[ 13 ] = 10.000000;
        outSpeed[ 14 ] = 5.000000;

        double outHeading[ nChecks ];
        outHeading[ 0 ] = 0;
        outHeading[ 1 ] = 0;
        outHeading[ 2 ] = 0;
        outHeading[ 3 ] = 0;
        outHeading[ 4 ] = 0;
        outHeading[ 5 ] = 0;

        outHeading[ 6 ] = 1.250000;
        outHeading[ 7 ] = 0;
        outHeading[ 8 ] = 3.106593;
        outHeading[ 9 ] = 0;
        outHeading[ 10 ] = 0;
        outHeading[ 11 ] = 1.570796;
        outHeading[ 12 ] = 0;
        outHeading[ 13 ] = 1.570796;
        outHeading[ 14 ] = 1.570796;

        std::vector < struct TOutFindPrj > outFindPrj_vec;
        outFindPrj_vec.resize( nChecks );

        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int ii = 0;
//        for ( ii = 0; ii < nChecks; ++ii )
//        {
//            fprintf( file, "\n inFindPrj.radiusCirc = %f:", inRadiusCirc[ ii ] );
//        }

        unsigned int numOfErrors = 0;

        for ( ii = 0; ii < nChecks; ++ii )
        {
            struct TInFindPrj inFindPrj;
            inFindPrj = inFindPrj_mas[ ii ];

            double timeSpeedToCheck = -1;
            double timeHeadingToCheck = -1;

            int resToCheck = funcFindTimeToAlterate( inFindPrj, &timeSpeedToCheck, &timeHeadingToCheck );
            int resIst = outCode[ ii ];

            resToCheck = funcFindPrj( inTime[ ii ], inFindPrj, &(outFindPrj_vec[ ii ]) );

            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n inFindPrj.speed = %f", inFindPrj.speed );
            fprintf( file, "\n inFindPrj.speed_new = %f", inFindPrj.speed_new );
            fprintf( file, "\n inFindPrj.acceleration = %f", inFindPrj.acceleration );
            fprintf( file, "\n inFindPrj.heading = %f:", inFindPrj.heading );
            fprintf( file, "\n inFindPrj.heading_new = %f", inFindPrj.heading_new );
            fprintf( file, "\n inFindPrj.radiusCirc = %f", inFindPrj.radiusCirc );
            fprintf( file, "\n inTime = %f", inTime[ ii ] );

            fprintf( file, "\n out %s: %d == %d, %f, %f", nameChar, resToCheck, resIst, timeSpeedToCheck, timeHeadingToCheck );
            fprintf( file, "\n out %s: %f, %f, %f, %f, %f", nameChar, outFindPrj_vec[ ii ].x, outFindPrj_vec[ ii ].y, outFindPrj_vec[ ii ].path, outFindPrj_vec[ ii ].speed, outFindPrj_vec[ ii ].heading );

            double resDifference = fabs( resIst - resToCheck  );
            bool funcIsOk_res = resDifference < EPS;

            bool funcIsOk = funcIsOk_res;

            if ( resToCheck == ROFP_SUCCESS )
            {
                bool funcIsOk_s = fabs( outFindPrj_vec[ ii ].speed - outSpeed[ ii ]  ) < EPS ;
                bool funcIsOk_h = fabs( outFindPrj_vec[ ii ].heading - outHeading[ ii ]  ) < EPS ;

                funcIsOk = funcIsOk_res && funcIsOk_s && funcIsOk_h;
            }

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncUniformDistribution()
{
    std::string nameString = "uniformDistribution";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcUniformDistribution )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 4;
        double xIn1[ nChecks ]  = { 0,        0,       -1,      -147 };
        double xIn2[ nChecks ]  = { 0,       10,       35,       -23 };
        double xOut[ nChecks ]  = { 0, 5.157323, 2.594836, -95.177862  };

        srand( 10 );

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc2Args( file, nameChar, funcUniformDistribution, xIn1, xIn2, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncNormalDistribution()
{
    std::string nameString = "normalDistribution";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcNormalDistribution )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 4;
        double xIn1[ nChecks ]  = { 0,        10,        -35,        -147 };
        double xIn2[ nChecks ]  = { 0,         3,          1,          10 };
        double xOut[ nChecks ]  = { 0, 10.543107, -36.209143, -134.958617 };

        srand( 10 );

        char * nameChar = const_cast <char*>(nameString.c_str());
        return checkFunc2Args( file, nameChar, funcNormalDistribution, xIn1, xIn2, xOut, nChecks );

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncFindPosSC()
{
    std::string nameString = "findPos_sc";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcFindPos_sc )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 4;

        double timeIn[ nChecks ];
        timeIn[ 0 ] = 100;
        timeIn[ 1 ] = 23;
        timeIn[ 2 ] = 100;
        timeIn[ 3 ] = 23;

        InFPSC inFPSC_mas[ nChecks ];

        inFPSC_mas[ 0 ].x0 = 0;
        inFPSC_mas[ 0 ].y0 = 0;
        inFPSC_mas[ 0 ].speed = 10;
        inFPSC_mas[ 0 ].headingRad = M_PI / 2;

        inFPSC_mas[ 1 ].x0 = 0;
        inFPSC_mas[ 1 ].y0 = 0;
        inFPSC_mas[ 1 ].speed = -17.5;
        inFPSC_mas[ 1 ].headingRad = M_PI;

        inFPSC_mas[ 2 ].x0 = -75000;
        inFPSC_mas[ 2 ].y0 = -350;
        inFPSC_mas[ 2 ].speed = -10;
        inFPSC_mas[ 2 ].headingRad = M_PI / 2;

        inFPSC_mas[ 3 ].x0 = -75000;
        inFPSC_mas[ 3 ].y0 = -350;
        inFPSC_mas[ 3 ].speed = 17.5;
        inFPSC_mas[ 3 ].headingRad = M_PI;

        double xOut[ nChecks ];
        double yOut[ nChecks ];

        xOut[ 0 ] = 1000;
        yOut[ 0 ] = 0;

        xOut[ 1 ] = 0;
        yOut[ 1 ] = 402.5;

        xOut[ 2 ] = -76000;
        yOut[ 2 ] = -350;

        xOut[ 3 ] = -75000;
        yOut[ 3 ] = -752.5;

        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int numOfErrors = 0;

        unsigned int ii = 0;
        for ( ii = 0; ii < nChecks; ++ii )
        {
            double xToCheck = -1;
            double yToCheck = -1;

            funcFindPos_sc( timeIn[ ii ], inFPSC_mas[ ii ], &xToCheck, &yToCheck );
            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n timeIn = %f", timeIn[ ii ] );
            fprintf( file, "\n inFPSC.x0 = %f", inFPSC_mas[ ii ].x0 );
            fprintf( file, "\n inFPSC.y0 = %f", inFPSC_mas[ ii ].y0 );
            fprintf( file, "\n inFPSC.speed = %f", inFPSC_mas[ ii ].speed );
            fprintf( file, "\n inFPSC.headingRad = %f:", inFPSC_mas[ ii ].headingRad );

            fprintf( file, "\n out %s: %f == %f, %f == %f", nameChar, xToCheck, xOut[ ii ], yToCheck, yOut[ ii ] );

            double xDif = fabs( xOut[ ii ] - xToCheck  );
            bool funcIsOk_x = xDif < EPS;

            double yDif = fabs( yOut[ ii ] - yToCheck  );
            bool funcIsOk_y = yDif < EPS;

            bool funcIsOk = funcIsOk_x && funcIsOk_y;

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncEstimateMotionParams2Z()
{
    std::string nameString = "estimateMotionParams_2z";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcEstimateMotionParams_2z )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 5;

        MotionParams motionParamsOwnObj[ nChecks ];
        motionParamsOwnObj[ 0 ].speed = 100;
        motionParamsOwnObj[ 0 ].headingRad = M_PI / 2;
        motionParamsOwnObj[ 1 ].speed = 100;
        motionParamsOwnObj[ 1 ].headingRad = M_PI / 2;
        motionParamsOwnObj[ 2 ].speed = 100;
        motionParamsOwnObj[ 2 ].headingRad = M_PI / 2;
        motionParamsOwnObj[ 3 ].speed = 100;
        motionParamsOwnObj[ 3 ].headingRad = M_PI / 2;
        motionParamsOwnObj[ 4 ].speed = 100;
        motionParamsOwnObj[ 4 ].headingRad = M_PI / 2;

        Measurement measurements[ nChecks ];
        measurements[ 0 ].time = 10;
        measurements[ 0 ].distance = 1000;
        measurements[ 0 ].bearingRad = 45 * M_PI / 180;
        measurements[ 1 ].time = 110;
        measurements[ 1 ].distance = 2000;
        measurements[ 1 ].bearingRad = 300 * M_PI / 180;
        measurements[ 2 ].time = 10;
        measurements[ 2 ].distance = 1000;
        measurements[ 2 ].bearingRad = 45 * M_PI / 180;
        measurements[ 3 ].time = 10;
        measurements[ 3 ].distance = 1000;
        measurements[ 3 ].bearingRad = 45 * M_PI / 180;
        measurements[ 4 ].time = 110;
        measurements[ 4 ].distance = 2000;
        measurements[ 4 ].bearingRad = 300 * M_PI / 180;

        ModeEMP2Z mode[ nChecks ];
        mode[ 0 ] = MEMP2Z_ADD;
        mode[ 1 ] = MEMP2Z_ADD;
        mode[ 2 ] = MEMP2Z_NULLIFY;
        mode[ 3 ] = MEMP2Z_ADD;
        mode[ 4 ] = MEMP2Z_ADD;

        double x0 = 0;
        double y0 = 0;

        double x1 = x0 + coordX( 1000, 45 * M_PI / 180 );
        double y1 = y0 + coordY( 1000, 45 * M_PI / 180 );

        double x2 = 10000;
        double y2 = 0;

        double x3 = x2 + coordX( 2000, 300 * M_PI / 180 );
        double y3 = y2 + coordY( 2000, 300 * M_PI / 180 );

        MotionParams motionParamsOut[ nChecks ];
        motionParamsOut[ 0 ].speed = 0;
        motionParamsOut[ 0 ].headingRad = 0;
        motionParamsOut[ 1 ].speed = 75.665134;
        motionParamsOut[ 1 ].headingRad = 1.532078;
        motionParamsOut[ 2 ].speed = 0;
        motionParamsOut[ 2 ].headingRad = 0;
        motionParamsOut[ 3 ].speed = 0;
        motionParamsOut[ 3 ].headingRad = 0;
        motionParamsOut[ 4 ].speed = 75.665134;
        motionParamsOut[ 4 ].headingRad = 1.532078;

        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int numOfErrors = 0;

        unsigned int ii = 0;
        for ( ii = 0; ii < nChecks; ++ii )
        {
            MotionParams motionParamsToCheck;

            motionParamsToCheck = funcEstimateMotionParams_2z( motionParamsOwnObj[ ii ], measurements[ ii ], mode[ ii ] );
            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n motionParamsOwnObj[ ii ].speed = %f", motionParamsOwnObj[ ii ].speed );
            fprintf( file, "\n motionParamsOwnObj[ ii ].headingRad = %f", motionParamsOwnObj[ ii ].headingRad );
            fprintf( file, "\n measurements[ ii ].time = %f", measurements[ ii ].time );
            fprintf( file, "\n measurements[ ii ].distance = %f", measurements[ ii ].distance );
            fprintf( file, "\n measurements[ ii ].bearingRad = %f:", measurements[ ii ].bearingRad );
            fprintf( file, "\n mode[ ii ] = %f:", mode[ ii ] );
            fprintf( file, "\n measurements[ ii ].bearingRad = %f:", measurements[ ii ].bearingRad );

            fprintf( file, "\n out %s: %f == %f, %f == %f", nameChar, motionParamsToCheck.speed, motionParamsOut[ ii ].speed, motionParamsToCheck.headingRad, motionParamsOut[ ii ].headingRad );

            double sDif = fabs( motionParamsOut[ ii ].speed - motionParamsToCheck.speed  );
            bool funcIsOk_s = sDif < EPS;

            double hDif = fabs( motionParamsOut[ ii ].headingRad - motionParamsToCheck.headingRad );
            bool funcIsOk_h = hDif < EPS;

            bool funcIsOk = funcIsOk_s && funcIsOk_h;

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncGetMean()
{
    std::string nameString = "getMean";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcGetMean )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        std::vector < std::vector < double > > inFunc;
        inFunc.resize( 3 );
        inFunc[ 0 ] = { 10, 10, 10, 10, 10 };
        inFunc[ 1 ] = { -10, -10, 0, 10, 10 };
        inFunc[ 2 ] = { -10, -10, 0, 0 };

        std::vector < double > outFunc = { 10, 0, -5 };


        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int numOfErrors = 0;

        unsigned int ii = 0;
        for ( ii = 0; ii < inFunc.size(); ++ii )
        {
            std::vector < double > mas = inFunc[ ii ];
            double resToCheck = funcGetMean( mas.data(), mas.size() );
            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n masIn ( size = %d ): ", mas.size() );

            for ( unsigned int jj = 0; jj < mas.size(); ++jj )
            {
                fprintf( file, " %f", mas[ jj ] );
            }
            fprintf( file, "\n" );

            fprintf( file, "\n out %s: %f == %f", nameChar, resToCheck, outFunc[ ii ] );

            double xDif = fabs( outFunc[ ii ] - resToCheck  );
            bool funcIsOk = xDif < EPS;

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncGetVariance()
{
    std::string nameString = "getVariance";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcGetVariance )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        std::vector < std::vector < double > > inFunc;
        inFunc.resize( 3 );
        inFunc[ 0 ] = { 10, 10, 10, 10, 10 };
        inFunc[ 1 ] = { -10, -10, 0, 10, 10 };
        inFunc[ 2 ] = { -10, -10, 0, 0 };

        std::vector < double > outFunc = { 0, 80, 25 };


        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int numOfErrors = 0;

        unsigned int ii = 0;
        for ( ii = 0; ii < inFunc.size(); ++ii )
        {
            std::vector < double > mas = inFunc[ ii ];
            double resToCheck = funcGetVariance( mas.data(), mas.size() );
            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n masIn ( size = %d ): ", mas.size() );

            for ( unsigned int jj = 0; jj < mas.size(); ++jj )
            {
                fprintf( file, " %f", mas[ jj ] );
            }
            fprintf( file, "\n" );

            fprintf( file, "\n out %s: %f == %f", nameChar, resToCheck, outFunc[ ii ] );

            double xDif = fabs( outFunc[ ii ] - resToCheck  );
            bool funcIsOk = xDif < EPS;

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

int ImportedMath::checkFuncFindPosComplex()
{
    std::string nameString = "findPos_manHS";

    std::cout << "\n=====================================================================" << std::endl;

    if ( funcFindPos_complex )
    {
        std::cout << "\nfunc " << nameString << " is found" << std::endl;

        fprintf( file, "\nfunc %s is found", nameString.c_str() );

        const unsigned int nChecks = 16;

        double timeIn[ nChecks ];
        timeIn[ 0 ] = 20;
        timeIn[ 1 ] = 100;
        timeIn[ 2 ] = 100;
        timeIn[ 3 ] = 100;
        timeIn[ 4 ] = 100;
        timeIn[ 5 ] = 10;
        timeIn[ 6 ] = 100;
        timeIn[ 7 ] = 200;
        timeIn[ 8 ] = 10;
        timeIn[ 9 ] = 50;
        timeIn[ 10 ] = 100;
        timeIn[ 11 ] = 200;
        timeIn[ 12 ] = 10;
        timeIn[ 13 ] = 25;
        timeIn[ 14 ] = 100;
        timeIn[ 15 ] = 200;

        struct TInFPMHS in[ nChecks ];

        in[ 0 ].posStart.x = 0;
        in[ 0 ].posStart.y = 0;
        in[ 0 ].timeBeforeMan = 30;
        in[ 0 ].speed = 10;
        in[ 0 ].speed_new = 15;
        in[ 0 ].acceleration = 0.01;
        in[ 0 ].heading = M_PI;
        in[ 0 ].heading_new = M_PI + 1.0/2.0 * M_PI;
        in[ 0 ].radiusCirc = 10;

        in[ 1 ].posStart.x = 0;
        in[ 1 ].posStart.y = 0;
        in[ 1 ].timeBeforeMan = 20;
        in[ 1 ].speed = 10;
        in[ 1 ].speed_new = 15;
        in[ 1 ].acceleration = 0.001;
        in[ 1 ].heading = 0;
        in[ 1 ].heading_new = 0;
        in[ 1 ].radiusCirc = 0;

        in[ 2 ].posStart.x = 0;
        in[ 2 ].posStart.y = 0;
        in[ 2 ].timeBeforeMan = 20;
        in[ 2 ].speed = 10;
        in[ 2 ].speed_new = 10;
        in[ 2 ].acceleration = 0;
        in[ 2 ].heading = 0;
        in[ 2 ].heading_new = 0;
        in[ 2 ].radiusCirc = 0;

        in[ 3 ].posStart.x = 0;
        in[ 3 ].posStart.y = 0;
        in[ 3 ].timeBeforeMan = 20;
        in[ 3 ].speed = 10;
        in[ 3 ].speed_new = 15;
        in[ 3 ].acceleration = 0.1;
        in[ 3 ].heading = 0;
        in[ 3 ].heading_new = 0;
        in[ 3 ].radiusCirc = 0;

        in[ 4 ].posStart.x = 0;
        in[ 4 ].posStart.y = 0;
        in[ 4 ].timeBeforeMan = 20;
        in[ 4 ].speed = 10;
        in[ 4 ].speed_new = 15;
        in[ 4 ].acceleration = 0.1;
        in[ 4 ].heading = M_PI;
        in[ 4 ].heading_new = M_PI;
        in[ 4 ].radiusCirc = 0;

        in[ 5 ].posStart.x = 0;
        in[ 5 ].posStart.y = 0;
        in[ 5 ].timeBeforeMan = 20;
        in[ 5 ].speed = 10;
        in[ 5 ].speed_new = 10;
        in[ 5 ].acceleration = 0;
        in[ 5 ].heading = 0;
        in[ 5 ].heading_new = 0;
        in[ 5 ].radiusCirc = 0;

        in[ 6 ].posStart.x = 0;
        in[ 6 ].posStart.y = 0;
        in[ 6 ].timeBeforeMan = 20;
        in[ 6 ].speed = 10;
        in[ 6 ].speed_new = 10;
        in[ 6 ].acceleration = 0;
        in[ 6 ].heading = 0;
        in[ 6 ].heading_new = 3;
        in[ 6 ].radiusCirc = 500;

        in[ 7 ].posStart.x = 0;
        in[ 7 ].posStart.y = 0;
        in[ 7 ].timeBeforeMan = 20;
        in[ 7 ].speed = 10;
        in[ 7 ].speed_new = 10;
        in[ 7 ].acceleration = 0;
        in[ 7 ].heading = 0;
        in[ 7 ].heading_new = 3;
        in[ 7 ].radiusCirc = 500;

        in[ 8 ].posStart.x = 0;
        in[ 8 ].posStart.y = 0;
        in[ 8 ].timeBeforeMan = 20;
        in[ 8 ].speed = 10;
        in[ 8 ].speed_new = 15;
        in[ 8 ].acceleration = 0.1;
        in[ 8 ].heading = 0;
        in[ 8 ].heading_new = 3;
        in[ 8 ].radiusCirc = 500;

        in[ 9 ].posStart.x = 0;
        in[ 9 ].posStart.y = 0;
        in[ 9 ].timeBeforeMan = 20;
        in[ 9 ].speed = 10;
        in[ 9 ].speed_new = 15;
        in[ 9 ].acceleration = 0.1;
        in[ 9 ].heading = 0;
        in[ 9 ].heading_new = 3;
        in[ 9 ].radiusCirc = 500;

        in[ 10 ].posStart.x = 0;
        in[ 10 ].posStart.y = 0;
        in[ 10 ].timeBeforeMan = 20;
        in[ 10 ].speed = 10;
        in[ 10 ].speed_new = 15;
        in[ 10 ].acceleration = 0.1;
        in[ 10 ].heading = 0;
        in[ 10 ].heading_new = 3;
        in[ 10 ].radiusCirc = 500;

        in[ 11 ].posStart.x = 0;
        in[ 11 ].posStart.y = 0;
        in[ 11 ].timeBeforeMan = 20;
        in[ 11 ].speed = 10;
        in[ 11 ].speed_new = 15;
        in[ 11 ].acceleration = 0.1;
        in[ 11 ].heading = 0;
        in[ 11 ].heading_new = 3;
        in[ 11 ].radiusCirc = 500;

        in[ 12 ].posStart.x = 0;
        in[ 12 ].posStart.y = 0;
        in[ 12 ].timeBeforeMan = 20;
        in[ 12 ].speed = 10;
        in[ 12 ].speed_new = 15;
        in[ 12 ].acceleration = 0.05;
        in[ 12 ].heading = 6;
        in[ 12 ].heading_new = 3;
        in[ 12 ].radiusCirc = 100;

        in[ 13 ].posStart.x = 0;
        in[ 13 ].posStart.y = 0;
        in[ 13 ].timeBeforeMan = 20;
        in[ 13 ].speed = 10;
        in[ 13 ].speed_new = 15;
        in[ 13 ].acceleration = 0.05;
        in[ 13 ].heading = 6;
        in[ 13 ].heading_new = 3;
        in[ 13 ].radiusCirc = 100;

        in[ 14 ].posStart.x = 0;
        in[ 14 ].posStart.y = 0;
        in[ 14 ].timeBeforeMan = 20;
        in[ 14 ].speed = 10;
        in[ 14 ].speed_new = 15;
        in[ 14 ].acceleration = 0.05;
        in[ 14 ].heading = 6;
        in[ 14 ].heading_new = 3;
        in[ 14 ].radiusCirc = 100;

        in[ 15 ].posStart.x = 0;
        in[ 15 ].posStart.y = 0;
        in[ 15 ].timeBeforeMan = 20;
        in[ 15 ].speed = 10;
        in[ 15 ].speed_new = 15;
        in[ 15 ].acceleration = 0.05;
        in[ 15 ].heading = 6;
        in[ 15 ].heading_new = 3;
        in[ 15 ].radiusCirc = 100;

        struct TOutFindPrj out[ nChecks ];
        out[ 0 ].x = 0;
        out[ 0 ].y = -200;
        out[ 0 ].path = 200;
        out[ 0 ].speed = 10;
        out[ 0 ].heading = 3.141593;

        out[ 1 ].x = 0;
        out[ 1 ].y = 1003.200000;
        out[ 1 ].path = 1003.200000;
        out[ 1 ].speed = 10.08;
        out[ 1 ].heading = 0;

        out[ 2 ].x = 0;
        out[ 2 ].y = 1000;
        out[ 2 ].path = 1000;
        out[ 2 ].speed = 10;
        out[ 2 ].heading = 0;

        out[ 3 ].x = 0;
        out[ 3 ].y = 1275;
        out[ 3 ].path = 1275;
        out[ 3 ].speed = 15;
        out[ 3 ].heading = 0;

        out[ 4 ].x = 0;
        out[ 4 ].y = -1275;
        out[ 4 ].path = 1275;
        out[ 4 ].speed = 15;
        out[ 4 ].heading = M_PI;

        out[ 5 ].x = 0;
        out[ 5 ].y = 100;
        out[ 5 ].path = 100;
        out[ 5 ].speed = 10;
        out[ 5 ].heading = 0;

        out[ 6 ].x = 514.599761;
        out[ 6 ].y = 699.786802;
        out[ 6 ].path = 1000;
        out[ 6 ].speed = 10;
        out[ 6 ].heading = 1.6;

        out[ 7 ].x = 1037.332251;
        out[ 7 ].y = -26.437745;
        out[ 7 ].path = 2000;
        out[ 7 ].speed = 10;
        out[ 7 ].heading = 3;

        out[ 8 ].x = 0;
        out[ 8 ].y = 100;
        out[ 8 ].path = 100;
        out[ 8 ].speed = 10;
        out[ 8 ].heading = 0;

        out[ 9 ].x = 114.376993;
        out[ 9 ].y = 518.268591;
        out[ 9 ].path = 545;
        out[ 9 ].speed = 13;
        out[ 9 ].heading = 0.69;

        out[ 10 ].x = 773.678833;
        out[ 10 ].y = 618.449395;
        out[ 10 ].path = 1275;
        out[ 10 ].speed = 15;
        out[ 10 ].heading = 2.15;

        out[ 11 ].x = 1146.700257;
        out[ 11 ].y = -793.681930;
        out[ 11 ].path = 2775;
        out[ 11 ].speed = 15;
        out[ 11 ].heading = 3;

        out[ 12 ].x = -27.941550;
        out[ 12 ].y = 96.017029;
        out[ 12 ].path = 100;
        out[ 12 ].speed = 10;
        out[ 12 ].heading = 6;

        out[ 13 ].x = -81.475495;
        out[ 13 ].y = 235.088078;
        out[ 13 ].path = 250.625000;
        out[ 13 ].speed = 10.25;
        out[ 13 ].heading = 5.493750;

        out[ 14 ].x = -157.760173;
        out[ 14 ].y = -503.414541;
        out[ 14 ].path = 1160;
        out[ 14 ].speed = 14;
        out[ 14 ].heading = 3;

        out[ 15 ].x = 52.508639;
        out[ 15 ].y = -1978.503361;
        out[ 15 ].path = 2650;
        out[ 15 ].speed = 15;
        out[ 15 ].heading = 3;

        int res[ nChecks ];
        res[ 0 ] = ROFP_SUCCESS;
        res[ 1 ] = ROFP_SUCCESS;
        res[ 2 ] = ROFP_SUCCESS;
        res[ 3 ] = ROFP_SUCCESS;
        res[ 4 ] = ROFP_SUCCESS;
        res[ 5 ] = ROFP_SUCCESS;
        res[ 6 ] = ROFP_SUCCESS;
        res[ 7 ] = ROFP_SUCCESS;
        res[ 8 ] = ROFP_SUCCESS;
        res[ 9 ] = ROFP_SUCCESS;
        res[ 10 ] = ROFP_SUCCESS;
        res[ 11 ] = ROFP_SUCCESS;
        res[ 12 ] = ROFP_SUCCESS;
        res[ 13 ] = ROFP_SUCCESS;
        res[ 14 ] = ROFP_SUCCESS;
        res[ 15 ] = ROFP_SUCCESS;

        char * nameChar = const_cast <char*>(nameString.c_str());

        unsigned int numOfErrors = 0;

        unsigned int ii = 0;
        for ( ii = 0; ii < nChecks; ++ii )
        {
            struct TOutFindPrj outToCheck;
            int resToCheck = funcFindPos_complex( timeIn[ ii ], in[ ii ], &outToCheck );
            fprintf( file, "\n\n in %s:", nameChar );
            fprintf( file, "\n timeIn = %f", timeIn[ ii ] );
            fprintf( file, "\n inFPMHS.posStart.x = %f", in[ ii ].posStart.x );
            fprintf( file, "\n inFPMHS.posStart.y = %f", in[ ii ].posStart.y );
            fprintf( file, "\n inFPMHS.speed = %f", in[ ii ].speed );
            fprintf( file, "\n inFPMHS.heading = %f:", in[ ii ].heading );
            fprintf( file, "\n inFPMHS.timeBeforeMan = %f:", in[ ii ].timeBeforeMan );
            fprintf( file, "\n inFPMHS.acceleration = %f:", in[ ii ].acceleration );
            fprintf( file, "\n inFPMHS.speed_new = %f:", in[ ii ].speed_new );
            fprintf( file, "\n inFPMHS.heading_new = %f:", in[ ii ].heading_new );
            fprintf( file, "\n inFPMHS.radiusCirc = %f:", in[ ii ].radiusCirc );

            fprintf( file, "\n out %s: %d == %d, %f == %f, %f == %f, %f == %f, %f == %f, %f == %f"
            , nameChar
            , resToCheck, res[ ii ]
            , outToCheck.x, out[ ii ].x
            , outToCheck.y, out[ ii ].y
            , outToCheck.path, out[ ii ].path
            , outToCheck.speed, out[ ii ].speed
            , outToCheck.heading, out[ ii ].heading );

            int resDif = fabs( resToCheck - res[ ii ] );
            bool funcIsOk_res = resDif == 0;

            double xDif = fabs( outToCheck.x - out[ ii ].x );
            bool funcIsOk_x = xDif < EPS;

            double yDif = fabs( outToCheck.y - out[ ii ].y );
            bool funcIsOk_y = yDif < EPS;

            double pathDif = fabs( outToCheck.path - out[ ii ].path );
            bool funcIsOk_path = pathDif < EPS;

            double speedDif = fabs( outToCheck.speed - out[ ii ].speed );
            bool funcIsOk_speed = speedDif < EPS;

            double headingDif = fabs( outToCheck.heading - out[ ii ].heading );
            bool funcIsOk_heading = headingDif < EPS;

            bool funcIsOk = funcIsOk_res
            && funcIsOk_x
            && funcIsOk_y
            && funcIsOk_path
            && funcIsOk_speed
            && funcIsOk_heading;

            if ( !funcIsOk )
            {
                ++numOfErrors;
                fprintf( file, "\nerror" );
            }
        }

        if ( numOfErrors != 0 )
        {
            fprintf( file, "\n%s FAILED with num of errors = %d \n", nameChar, numOfErrors ); // ???-?? ?????
        }
        else
        {
            fprintf( file, "\n\n%s is OK\n", nameChar );
        }

        return numOfErrors;

    }
    else
    {
        std::cout << "\nfunc " << nameString << " is NOT found" << std::endl;

        fprintf( file, "\nfunc %s is NOT found", nameString.c_str() );

        return -1;
    }

    return 0;
}

bool ImportedMath::libIsLoaded()
{
    if ( lib->load() )
        return true;
    else
        return false;
}

bool ImportedMath::funcSignIsLoaded()
{
    if ( sign )
        return true;
    else
        return false;
}

bool ImportedMath::funcSqrIsLoaded()
{
    if ( sqr )
        return true;
    else
        return false;
}

bool ImportedMath::funcRadIsLoaded()
{
    if ( rad )
        return true;
    else
        return false;
}

bool ImportedMath::funcGradIsLoaded()
{
    if ( grad )
        return true;
    else
        return false;
}

bool ImportedMath::funcPriv2PiIsLoaded()
{
    if ( priv2Pi )
        return true;
    else
        return false;
}

bool ImportedMath::funcPrivPiIsLoaded()
{
    if ( privPi )
        return true;
    else
        return false;
}

bool ImportedMath::funcCoordXIsLoaded()
{
    if ( coordX )
        return true;
    else
        return false;
}

bool ImportedMath::funcCoordYIsLoaded()
{
    if ( coordY )
        return true;
    else
        return false;
}

bool ImportedMath::funcDist1to2IsLoaded()
{
    if ( dist_1to2 )
        return true;
    else
        return false;
}

bool ImportedMath::funcAngle1to2IsLoaded()
{
    if ( angle_1to2 )
        return true;
    else
        return false;
}

bool ImportedMath::funcVerifyParamsIsLoaded()
{
    if ( funcVerifyParams )
        return true;
    else
        return false;
}

bool ImportedMath::funcFindTimeToAlterateIsLoaded()
{
    if ( funcFindTimeToAlterate )
        return true;
    else
        return false;
}

bool ImportedMath::funcFindPrjIsLoaded()
{
    if ( funcFindPrj )
        return true;
    else
        return false;
}

bool ImportedMath::funcUniformDistributionIsLoaded()
{
    if ( funcUniformDistribution )
        return true;
    else
        return false;
}

bool ImportedMath::funcNormalDistributionIsLoaded()
{
    if ( funcNormalDistribution )
        return true;
    else
        return false;
}

bool ImportedMath::funcFindPosSCIsLoaded()
{
    if ( funcFindPos_sc )
        return true;
    else
        return false;
}

bool ImportedMath::funcFuncEstimateMotionParams2ZIsLoaded()
{
    if ( funcEstimateMotionParams_2z )
        return true;
    else
        return false;
}

bool ImportedMath::funcGetMeanIsLoaded()
{
    if ( funcGetMean )
        return true;
    else
        return false;
}

bool ImportedMath::funcGetVarianceIsLoaded()
{
    if ( funcGetVariance )
        return true;
    else
        return false;
}

bool ImportedMath::funcFindPosComplexIsLoaaded()
{
    if ( funcFindPos_complex )
        return true;
    else
        return false;
}

bool ImportedMath::getFuncSignIsOk()
{
    return funcSignIsOk;
}

}
