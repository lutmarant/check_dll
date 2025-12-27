#ifndef IMPORTED_MATH_H
#define IMPORTED_MATH_H

#include <QLibrary>

#include "myMath.h"

#include <stdio.h>

struct TDataPrj
{
    double x;
    double y;
    double speed;
    double headingGrad;
    double path;
    double time;
};

namespace importedMath
{

typedef int ( *FuncSign )( double );
typedef double ( *FuncSqr )( double );
typedef double ( *FuncRad )( double );
typedef double ( *FuncGrad )( double );
typedef double ( *FuncPriv2Pi )( double );
typedef double ( *FuncPrivPi )( double );
typedef double ( *FuncCoordX )( double, double );
typedef double ( *FuncCoordY )( double, double );
typedef double ( *FuncDist_1to2 )( double, double, double, double );
typedef double ( *FuncAngle_1to2 )( double, double, double, double );

typedef int ( *FuncVerifyParams )( struct TInFindPrj );
typedef int ( *FuncFindTimeToAlterate )( struct TInFindPrj, double *, double * );
typedef int ( *FuncFindPrj )( double, struct TInFindPrj, struct TOutFindPrj * );

typedef double ( *FuncUniformDistribution )( double, double );
typedef double ( *FuncNormalDistribution )( double, double );

typedef double ( *FuncGetMean )( double *, unsigned int );
typedef double ( *FuncGetVariance )( double *, unsigned int );

typedef void ( *FuncFindPos_sc  )( double, InFPSC, double *, double * ); //sc means straight, const speed
typedef MotionParams ( *FuncEstimateMotionParams_2z )( MotionParams, Measurement, ModeEMP2Z );

typedef int ( *FuncFindPos_complex  )( double, struct TInFPMHS, struct TOutFindPrj * );

class ImportedMath
{
    QLibrary * lib = nullptr;

    FILE * file;

    FuncSign sign = nullptr;
    FuncSqr sqr = nullptr;
    FuncRad rad = nullptr;
    FuncGrad grad = nullptr;
    FuncPriv2Pi priv2Pi = nullptr;
    FuncPrivPi privPi = nullptr;
    FuncCoordX coordX = nullptr;
    FuncCoordY coordY = nullptr;
    FuncDist_1to2 dist_1to2 = nullptr;
    FuncAngle_1to2 angle_1to2 = nullptr;
    FuncVerifyParams funcVerifyParams = nullptr;
    FuncFindTimeToAlterate funcFindTimeToAlterate = nullptr;
    FuncFindPrj funcFindPrj = nullptr;
    FuncUniformDistribution funcUniformDistribution = nullptr;
    FuncNormalDistribution funcNormalDistribution = nullptr;
    FuncFindPos_sc funcFindPos_sc = nullptr;
    FuncEstimateMotionParams_2z funcEstimateMotionParams_2z = nullptr;
    FuncGetMean funcGetMean = nullptr;
    FuncGetVariance funcGetVariance = nullptr;
    FuncFindPos_complex funcFindPos_complex = nullptr;

    bool funcSignIsOk = false;
    bool funcSqrIsOk = false;
    bool funcRadIsOk = false;
    bool funcGradIsOk = false;
    bool funcPriv2PiIsOk = false;
    bool funcPrivPiIsOk = false;
    bool funcCoordXIsOk = false;
    bool funcCoordYIsOk = false;
    bool funcDist1to2IsOk = false;
    bool funcAngle1to2IsOk = false;
    bool funcVerifyParamsIsOk = false;
    bool funcFindTimeToAlterateIsOk = false;
    bool funcFindPrjIsOk = false;
    bool funcUniformDistributionIsOk = false;
    bool funcNormalDistributionIsOk = false;
    bool funcFindPosSCIsOk = false;
    bool funcEstimateMotionParams2ZIsOk = false;
    bool funcGetMeanIsOk = false;
    bool funcGetVarianceIsOk = false;
    bool funcFindPosComplexIsOk = false;

public:
    ImportedMath();
    ~ImportedMath();

    bool checkAllFuncs();

    int checkFuncSign();
    int checkFuncSqr();
    int checkFuncRad();
    int checkFuncGrad();
    int checkFuncPriv2Pi();
    int checkFuncPrivPi();
    int checkFuncCoordX();
    int checkFuncCoordY();
    int checkFuncDist_1to2();
    int checkFuncAngle_1to2();
    int checkFuncVerifyParams();
    int checkFuncFindTimeToAlterate();
    int checkFuncFindPrj();
    int checkFuncUniformDistribution();
    int checkFuncNormalDistribution();
    int checkFuncFindPosSC();
    int checkFuncEstimateMotionParams2Z();
    int checkFuncGetMean();
    int checkFuncGetVariance();
    int checkFuncFindPosComplex();

    bool libIsLoaded();
    bool funcSignIsLoaded();
    bool funcSqrIsLoaded();
    bool funcRadIsLoaded();
    bool funcGradIsLoaded();
    bool funcPriv2PiIsLoaded();
    bool funcPrivPiIsLoaded();
    bool funcCoordXIsLoaded();
    bool funcCoordYIsLoaded();
    bool funcDist1to2IsLoaded();
    bool funcAngle1to2IsLoaded();
    bool funcVerifyParamsIsLoaded();
    bool funcFindTimeToAlterateIsLoaded();
    bool funcFindPrjIsLoaded();
    bool funcUniformDistributionIsLoaded();
    bool funcNormalDistributionIsLoaded();
    bool funcFindPosSCIsLoaded();
    bool funcFuncEstimateMotionParams2ZIsLoaded();
    bool funcGetMeanIsLoaded();
    bool funcGetVarianceIsLoaded();
    bool funcFindPosComplexIsLoaaded();

    bool getFuncSignIsOk();
    bool getFuncSqrIsOk() const;
    bool getFuncRadIsOk() const;
    bool getFuncGradIsOk() const;
    bool getFuncPriv2PiIsOk() const;
    bool getFuncPrivPiIsOk() const;
    bool getFuncCoordXIsOk() const;
    bool getFuncCoordYIsOk() const;
    bool getFuncDist1to2IsOk() const;
    bool getFuncAngle1to2IsOk() const;
    bool getFuncFindTimeToAlterateIsOk() const;
    bool getFuncVerifyParamsIsOk() const;
    bool getFuncFindPrjIsOk() const;
    bool getFuncUniformDistributionIsOk() const;
    bool getFuncNormalDistributionIsOk() const;
    bool getFuncFindPosSCIsOk() const;
    bool getFuncEstimateMotionParams2ZIsOk() const;
    bool getFuncGetMeanIsOk() const;
    bool getFuncGetVarianceIsOk() const;
    bool getFuncFindPosComplexIsOk() const;

    FuncSign getSign() const;
    FuncSqr getSqr() const;
    FuncRad getRad() const;
    FuncGrad getGrad() const;
    FuncPriv2Pi getPriv2Pi() const;
    FuncPrivPi getPrivPi() const;
    FuncCoordX getCoordX() const;
    FuncCoordY getCoordY() const;
    FuncDist_1to2 getDist_1to2() const;
    FuncAngle_1to2 getAngle_1to2() const;
    FuncVerifyParams getFuncVerifyParams() const;
    FuncFindTimeToAlterate getFuncFindTimeToAlterate() const;
    FuncFindPrj getFuncFindPrj() const;
    FuncUniformDistribution getFuncUniformDistribution() const;
    FuncNormalDistribution getFuncNormalDistribution() const;
    FuncFindPos_sc getFuncFindPos_sc() const;
    FuncEstimateMotionParams_2z getFuncEstimateMotionParams_2z() const;
    FuncGetMean getFuncGetMean() const;
    FuncGetVariance getFuncGetVariance() const;
    FuncFindPos_complex getFuncFindPos_complex() const;
};

}

#endif // IMPORTED_MATH_H
