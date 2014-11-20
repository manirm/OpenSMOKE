/***************************************************************************
 *   Copyright (C) 2009 by Alberto Cuoci								   *
 *   alberto.cuoci@polimi.it                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <string>
#include "basic/OpenSMOKE_Constants.h"
#include "distributions/OpenSMOKE_SinDistribution.h"

const double OpenSMOKE_SinDistribution::c2=0.25;
const double OpenSMOKE_SinDistribution::c4=0.015625;
const double OpenSMOKE_SinDistribution::c6=4.340278E-4;
const double OpenSMOKE_SinDistribution::c8=6.7816840277e-6;
const double OpenSMOKE_SinDistribution::c10=6.7816840277e-8;
const double OpenSMOKE_SinDistribution::c12=4.709502797e-10;
const double OpenSMOKE_SinDistribution::c14=2.4028075495e-12;
const double OpenSMOKE_SinDistribution::c16=9.3859669903e-15;


void OpenSMOKE_SinDistribution::ErrorMessage(const std::string message)
{
    cout << endl;
    cout << "Class:  OpenSMOKE_SinDistribution"			<< endl;
    cout << "Error:  " << message           << endl;
    cout << "Press a key to continue... "   << endl;
    getchar();
    exit(-1);
}

void OpenSMOKE_SinDistribution::WarningMessage(const std::string message)
{
    cout << endl;
    cout << "Class:    OpenSMOKE_SinDistribution"		<< endl;
    cout << "Warning:  "	<< message      << endl;
    cout << "Press a key to continue... "   << endl;
    getchar();
}

OpenSMOKE_SinDistribution::OpenSMOKE_SinDistribution()
{
	iSinExpansion = 16;
}

OpenSMOKE_SinDistribution::~OpenSMOKE_SinDistribution()
{
}

double OpenSMOKE_SinDistribution::CorrectionCoefficient(const double qT2, const double EsuR, const double n, const double T)
{
	double d10, d12, d14, d16;

	double d2 = (n*n*T*T+2.0*n*T*EsuR+EsuR*EsuR-n*T*T-2.0*T*EsuR)/(T*T*T*T);
	double d4 = (-6.0*n+n*n*n*n-6.0*n*n*n+11.0*n*n)/(T*T*T*T)+(4.0*n*n*n*EsuR-24.0*EsuR-24.0*EsuR*n*n+44.0*EsuR*n)/(T*T*T*T*T)+(6.0*n*n*EsuR*EsuR-30.0*EsuR*EsuR*n+36.0*EsuR*EsuR)/(T*T*T*T*T*T)+(4.0*n*EsuR*EsuR*EsuR-12.0*EsuR*EsuR*EsuR)/(T*T*T*T*T*T*T)+1/(T*T*T*T*T*T*T*T)*EsuR*EsuR*EsuR*EsuR;
	double d6 = (-120.0*n+274.0*n*n+85.0*n*n*n*n-225.0*n*n*n+n*n*n*n*n*n-15.0*n*n*n*n*n)/(T*T*T*T*T*T)+(1644.0*EsuR*n-720.0*EsuR+6.0*n*n*n*n*n*EsuR-90.0*n*n*n*n*EsuR+510.0*n*n*n*EsuR-1350.0*EsuR*n*n)/(T*T*T*T*T*T*T)+(1065.0*n*n*EsuR*EsuR+15.0*n*n*n*n*EsuR*EsuR-210.0*n*n*n*EsuR*EsuR-2310.0*EsuR*EsuR*n+1800.0*EsuR*EsuR)/(T*T*T*T*T*T*T*T)+(-240.0*n*n*EsuR*EsuR*EsuR-1200.0*EsuR*EsuR*EsuR+940.0*n*EsuR*EsuR*EsuR+20.0*n*n*n*EsuR*EsuR*EsuR)/(T*T*T*T*T*T*T*T*T)+(300.0*EsuR*EsuR*EsuR*EsuR+15.0*n*n*EsuR*EsuR*EsuR*EsuR-135.0*n*EsuR*EsuR*EsuR*EsuR)/pow(T,10.0)+(6.0*n*EsuR*EsuR*EsuR*EsuR*EsuR-30.0*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,11.0)+1/pow(T,12.0)*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR;
	double d8 = (n*n*n*n*n*n*n*n-5040.0*n+13068.0*n*n+6769.0*n*n*n*n-13132.0*n*n*n+322.0*n*n*n*n*n*n-28.0*n*n*n*n*n*n*n-1960.0*n*n*n*n*n)/(T*T*T*T*T*T*T*T)+(-15680.0*n*n*n*n*EsuR-40320.0*EsuR-105056.0*EsuR*n*n-224.0*n*n*n*n*n*n*EsuR+8.0*n*n*n*n*n*n*n*EsuR+2576.0*n*n*n*n*n*EsuR+54152.0*n*n*n*EsuR+104544.0*EsuR*n)/(T*T*T*T*T*T*T*T*T)+(-46620.0*n*n*n*EsuR*EsuR-224784.0*EsuR*EsuR*n+141120.0*EsuR*EsuR+28.0*n*n*n*n*n*n*EsuR*EsuR+142912.0*n*n*EsuR*EsuR+8260.0*n*n*n*n*EsuR*EsuR-756.0*n*n*n*n*n*EsuR*EsuR)/pow(T,10.0)+(56.0*n*n*n*n*n*EsuR*EsuR*EsuR-1400.0*n*n*n*n*EsuR*EsuR*EsuR+13720.0*n*n*n*EsuR*EsuR*EsuR-65800.0*n*n*EsuR*EsuR*EsuR+154224.0*n*EsuR*EsuR*EsuR-141120.0*EsuR*EsuR*EsuR)/pow(T,11.0)+(-1540.0*n*n*n*EsuR*EsuR*EsuR*EsuR+58800.0*EsuR*EsuR*EsuR*EsuR+70.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR+12530.0*n*n*EsuR*EsuR*EsuR*EsuR-44660.0*n*EsuR*EsuR*EsuR*EsuR)/pow(T,12.0)+(5992.0*n*EsuR*EsuR*EsuR*EsuR*EsuR-11760.0*EsuR*EsuR*EsuR*EsuR*EsuR+56.0*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR-1008.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,13.0)+(-364.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+1176.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+28.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,14.0)+(-56.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+8.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,15.0)+1/pow(T,16.0)*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR;

	if (iSinExpansion >= 10)
	{
		double MapleGenVar10 = (-362880.0*n-1172700.0*n*n*n+723680.0*n*n*n*n+pow(n,10.0)-9450.0*n*n*n*n*n*n*n-45.0*n*n*n*n*n*n*n*n*n+1026576.0*n*n+870.0*n*n*n*n*n*n*n*n-269325.0*n*n*n*n*n+63273.0*n*n*n*n*n*n)/pow(T,10.0)+(-11727000.0*EsuR*n*n-450.0*EsuR*n*n*n*n*n*n*n*n-3628800.0*EsuR+632730.0*n*n*n*n*n*EsuR-94500.0*n*n*n*n*n*n*EsuR+10265760.0*EsuR*n+10.0*EsuR*n*n*n*n*n*n*n*n*n+8700.0*n*n*n*n*n*n*n*EsuR-2693250.0*n*n*n*n*EsuR+7236800.0*n*n*n*EsuR)/pow(T,11.0)+(2459205.0*n*n*n*n*EsuR*EsuR-9660420.0*n*n*n*EsuR*EsuR-388080.0*n*n*n*n*n*EsuR*EsuR+37170.0*n*n*n*n*n*n*EsuR*EsuR-1980.0*EsuR*EsuR*n*n*n*n*n*n*n+45.0*EsuR*EsuR*n*n*n*n*n*n*n*n+16329600.0*EsuR*EsuR+22905180.0*n*n*EsuR*EsuR-29866320.0*EsuR*EsuR*n)/pow(T,12.0)+(-856800.0*n*n*n*n*EsuR*EsuR*EsuR-5040.0*EsuR*EsuR*EsuR*n*n*n*n*n*n+4844280.0*n*n*n*EsuR*EsuR*EsuR+28935360.0*n*EsuR*EsuR*EsuR-16072560.0*n*n*EsuR*EsuR*EsuR+120.0*EsuR*EsuR*EsuR*n*n*n*n*n*n*n+89040.0*n*n*n*n*n*EsuR*EsuR*EsuR-21772800.0*EsuR*EsuR*EsuR)/pow(T,13.0)+(-12645360.0*n*EsuR*EsuR*EsuR*EsuR-8190.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+131250.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR+12700800.0*EsuR*EsuR*EsuR*EsuR+5160540.0*n*n*EsuR*EsuR*EsuR*EsuR+210.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-1105650.0*n*n*n*EsuR*EsuR*EsuR*EsuR)/pow(T,14.0);      
		d10 = MapleGenVar10+(-8820.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n+2841048.0*n*EsuR*EsuR*EsuR*EsuR*EsuR+122220.0*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR+252.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n-837900.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR-3810240.0*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,15.0)+(210.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-6300.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-346500.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+70350.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+635040.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,16.0)+(-2880.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n+22920.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+120.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-60480.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,17.0)+(3240.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+45.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n-765.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,18.0)+(10.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n-90.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,19.0)+1/pow(T,20.0)*pow(EsuR,10.0);
	
		if (iSinExpansion >= 12)
		{
			double MapleGenVar12A = (120543840.0*n*n+1925.0*pow(n,10.0)-66.0*pow(n,11.0)-39916800.0*n-32670.0*n*n*n*n*n*n*n*n*n-150917976.0*n*n*n+pow(n,12.0)+13339535.0*n*n*n*n*n*n-45995730.0*n*n*n*n*n+357423.0*n*n*n*n*n*n*n*n-2637558.0*n*n*n*n*n*n*n+105258076.0*n*n*n*n)/pow(T,12.0)+(1263096912.0*n*n*n*EsuR-479001600.0*EsuR-792.0*pow(n,10.0)*EsuR+23100.0*EsuR*n*n*n*n*n*n*n*n*n+12.0*EsuR*pow(n,11.0)-31650696.0*n*n*n*n*n*n*EsuR+1446526080.0*EsuR*n-1811015712.0*EsuR*n*n-551948760.0*n*n*n*n*EsuR+4289076.0*n*n*n*n*n*n*n*EsuR+160074420.0*n*n*n*n*n*EsuR-392040.0*EsuR*n*n*n*n*n*n*n*n)/pow(T,13.0)+(-152522370.0*n*n*n*n*n*EsuR*EsuR-2033460.0*EsuR*EsuR*n*n*n*n*n*n*n-5321384640.0*EsuR*EsuR*n+2634508800.0*EsuR*EsuR-2307831240.0*n*n*n*EsuR*EsuR+122760.0*EsuR*EsuR*n*n*n*n*n*n*n*n+4639201776.0*n*n*EsuR*EsuR+727886940.0*n*n*n*n*EsuR*EsuR+66.0*EsuR*EsuR*pow(n,10.0)-4290.0*EsuR*EsuR*n*n*n*n*n*n*n*n*n+21556458.0*n*n*n*n*n*n*EsuR*EsuR)/pow(T,14.0); 
			double MapleGenVar12B = MapleGenVar12A+(381480.0*EsuR*EsuR*EsuR*n*n*n*n*n*n*n+59824380.0*n*n*n*n*n*EsuR*EsuR*EsuR+220.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR+1648771520.0*n*n*n*EsuR*EsuR*EsuR+6673550400.0*n*EsuR*EsuR*EsuR-13860.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR-388759140.0*n*n*n*n*EsuR*EsuR*EsuR-4390848000.0*EsuR*EsuR*EsuR-6015240.0*EsuR*EsuR*EsuR*n*n*n*n*n*n-4395227760.0*n*n*EsuR*EsuR*EsuR)/pow(T,15.0)+(-11226600.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+495.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR+1993937220.0*n*n*EsuR*EsuR*EsuR*EsuR-29700.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR+100925055.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR+769230.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n+3293136000.0*EsuR*EsuR*EsuR*EsuR-571932900.0*n*n*n*EsuR*EsuR*EsuR*EsuR-3907450800.0*n*EsuR*EsuR*EsuR*EsuR)/pow(T,16.0)+(1053360.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+1233666720.0*n*EsuR*EsuR*EsuR*EsuR*EsuR-44352.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-1317254400.0*EsuR*EsuR*EsuR*EsuR*EsuR+792.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR+106483608.0*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR-13749120.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-489158208.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,17.0);
			d12 = MapleGenVar12B+(-11074140.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-47124.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+307359360.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+68860176.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+993300.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-226383696.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+924.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n)/pow(T,18.0)+(-35640.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+792.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+25022448.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-43908480.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+637560.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-5666760.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n)/pow(T,19.0)+(3920400.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+495.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-18810.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+266805.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n-1674090.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,20.0)+(-217800.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+220.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+65780.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n-6600.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n)/pow(T,21.0)+(7260.0*pow(EsuR,10.0)+66.0*pow(EsuR,10.0)*n*n-1386.0*pow(EsuR,10.0)*n)/pow(T,22.0)+(-132.0*pow(EsuR,11.0)+12.0*pow(EsuR,11.0)*n)/pow(T,23.0)+1/pow(T,24.0)*pow(EsuR,12.0);
		
			if (iSinExpansion >= 14)
			{
				double MapleGenVar14A = (pow(n,14.0)+20313753096.0*n*n*n*n-91091.0*pow(n,11.0)-9957703756.0*n*n*n*n*n-26596717056.0*n*n*n-6227020800.0*n-16669653.0*n*n*n*n*n*n*n*n*n+19802759040.0*n*n-91.0*pow(n,13.0)+135036473.0*n*n*n*n*n*n*n*n-790943153.0*n*n*n*n*n*n*n+1474473.0*pow(n,10.0)+3731.0*pow(n,12.0)+3336118786.0*n*n*n*n*n*n)/pow(T,14.0)+(-11073204142.0*n*n*n*n*n*n*EsuR-372354038784.0*EsuR*n*n+46705663004.0*n*n*n*n*n*EsuR-1274.0*pow(n,12.0)*EsuR-87178291200.0*EsuR+284392543344.0*n*n*n*EsuR-233375142.0*EsuR*n*n*n*n*n*n*n*n+20642622.0*EsuR*n*n*n*n*n*n*n*n*n+14.0*pow(n,13.0)*EsuR+1890510622.0*n*n*n*n*n*n*n*EsuR+52234.0*EsuR*pow(n,11.0)-1275274.0*pow(n,10.0)*EsuR-139407852584.0*n*n*n*n*EsuR+277238626560.0*EsuR*n)/pow(T,15.0)+(-1235392179840.0*EsuR*EsuR*n+1184909072256.0*n*n*EsuR*EsuR+91.0*pow(n,12.0)*EsuR*EsuR+10897599713.0*n*n*n*n*n*n*EsuR*EsuR-663642459480.0*n*n*n*EsuR*EsuR-8190.0*pow(n,11.0)*EsuR*EsuR+331331.0*EsuR*EsuR*pow(n,10.0)+242508582316.0*n*n*n*n*EsuR*EsuR-1390719330.0*EsuR*EsuR*n*n*n*n*n*n*n-7957950.0*EsuR*EsuR*n*n*n*n*n*n*n*n*n+566658892800.0*EsuR*EsuR-61078227210.0*n*n*n*n*n*EsuR*EsuR+126219093.0*EsuR*EsuR*n*n*n*n*n*n*n*n)/pow(T,16.0);
				double MapleGenVar14B = MapleGenVar14A+(-1133317785600.0*EsuR*EsuR*EsuR-29309280.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR+1904125466880.0*n*EsuR*EsuR*EsuR+1261260.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR-4670361696.0*EsuR*EsuR*EsuR*n*n*n*n*n*n+446257812.0*EsuR*EsuR*EsuR*n*n*n*n*n*n*n+618407213424.0*n*n*n*EsuR*EsuR*EsuR+34249675460.0*n*n*n*n*n*EsuR*EsuR*EsuR-175813557920.0*n*n*n*n*EsuR*EsuR*EsuR+364.0*pow(n,11.0)*EsuR*EsuR*EsuR-32032.0*pow(n,10.0)*EsuR*EsuR*EsuR-1417755411072.0*n*n*EsuR*EsuR*EsuR)/pow(T,17.0)+(64785060340.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR+1038874636800.0*EsuR*EsuR*EsuR*EsuR-70960890.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR-9800515725.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+833223527136.0*n*n*EsuR*EsuR*EsuR*EsuR+3213210.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR-1399156799040.0*n*EsuR*EsuR*EsuR*EsuR-85085.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR-289132103260.0*n*n*n*EsuR*EsuR*EsuR*EsuR+1014326313.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n+1001.0*pow(n,10.0)*EsuR*EsuR*EsuR*EsuR)/pow(T,18.0)+(5777772.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR+569719069920.0*n*EsuR*EsuR*EsuR*EsuR*EsuR+76020552608.0*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR+1553409858.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n-13387392018.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-162162.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR-118810692.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-519437318400.0*EsuR*EsuR*EsuR*EsuR*EsuR-274181996088.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR+2002.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,19.0)+(3003.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+155831195520.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+54304702452.0*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-139749481872.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+1627172547.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-228228.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-140588448.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+7525518.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-11945225292.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n)/pow(T,20.0);
				d14 = MapleGenVar14B+(-29682132480.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-240240.0*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+7159152.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n+1153320168.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-117717600.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-6731765040.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n+21671926848.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+3432.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,21.0)+(530191662.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n+4939935.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n-2178952776.0*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-189189.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-68423355.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+3003.0*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+3710266560.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR)/pow(T,22.0)+(142930788.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n-309188880.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-110110.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+2412410.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+2002.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-26316290.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n)/pow(T,23.0)+(1001.0*n*n*n*n*pow(EsuR,10.0)-6032026.0*pow(EsuR,10.0)*n+791791.0*pow(EsuR,10.0)*n*n+17177160.0*pow(EsuR,10.0)-46046.0*n*n*n*pow(EsuR,10.0))/pow(T,24.0)+(-13104.0*n*n*pow(EsuR,11.0)+364.0*n*n*n*pow(EsuR,11.0)-624624.0*pow(EsuR,11.0)+156884.0*pow(EsuR,11.0)*n)/pow(T,25.0)+(-2275.0*n*pow(EsuR,12.0)+91.0*n*n*pow(EsuR,12.0)+14196.0*pow(EsuR,12.0))/pow(T,26.0)+(-182.0*pow(EsuR,13.0)+14.0*n*pow(EsuR,13.0))/pow(T,27.0)+1/pow(T,28.0)*pow(EsuR,14.0);
				
				if (iSinExpansion >= 16)
				{
					double	MapleGenVar3 = (pow(n,16.0)-1307674368000.0*n+928095740.0*pow(n,10.0)+54631129553.0*n*n*n*n*n*n*n*n+4899622.0*pow(n,12.0)+1009672107080.0*n*n*n*n*n*n+6580.0*pow(n,14.0)-120.0*pow(n,15.0)+5056995703824.0*n*n*n*n-78558480.0*pow(n,11.0)-272803210680.0*n*n*n*n*n*n*n-218400.0*pow(n,13.0)-8207628000.0*n*n*n*n*n*n*n*n*n-6165817614720.0*n*n*n+4339163001600.0*n*n-2706813345600.0*n*n*n*n*n)/pow(T,16.0)+(80911931261184.0*n*n*n*EsuR-4364851370880.0*EsuR*n*n*n*n*n*n-20922789888000.0*EsuR-98653081835520.0*EsuR*n*n+78393952.0*pow(n,11.0)*EsuR+105280.0*pow(n,13.0)*EsuR-1920.0*EsuR*pow(n,14.0)+874098072848.0*n*n*n*n*n*n*n*EsuR-3494400.0*pow(n,12.0)*EsuR-1256935680.0*pow(n,10.0)*EsuR+16154753713280.0*n*n*n*n*n*EsuR+16.0*EsuR*pow(n,15.0)-43309013529600.0*n*n*n*n*EsuR-131322048000.0*EsuR*n*n*n*n*n*n*n*n+14849531840.0*EsuR*n*n*n*n*n*n*n*n*n+69426608025600.0*EsuR*n)/pow(T,17.0);
					double	MapleGenVar2 = MapleGenVar3+(156920924160000.0*EsuR*EsuR+562521960.0*EsuR*EsuR*pow(n,10.0)+102506993160.0*EsuR*EsuR*n*n*n*n*n*n*n*n-14280.0*pow(n,13.0)*EsuR*EsuR-8864495640.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR-363778636032000.0*EsuR*EsuR*n+94097594747520.0*n*n*n*n*EsuR*EsuR-25432680.0*EsuR*EsuR*pow(n,11.0)+120.0*pow(n,14.0)*EsuR*EsuR-27063058102080.0*EsuR*EsuR*n*n*n*n*n-882408366840.0*n*n*n*n*n*n*n*EsuR*EsuR+775320.0*EsuR*EsuR*pow(n,12.0)-230720006724480.0*n*n*n*EsuR*EsuR+5673327179520.0*EsuR*EsuR*n*n*n*n*n*n+376119477734400.0*n*n*EsuR*EsuR)/pow(T,18.0)+(3487120.0*pow(n,11.0)*EsuR*EsuR*EsuR+19860664984160.0*n*n*n*n*n*EsuR*EsuR*EsuR-366148823040000.0*EsuR*EsuR*EsuR+665742405888000.0*n*EsuR*EsuR*EsuR-3307430926800.0*EsuR*EsuR*EsuR*n*n*n*n*n*n-65520.0*pow(n,12.0)*EsuR*EsuR*EsuR+560.0*EsuR*EsuR*EsuR*pow(n,13.0)+2401679280.0*n*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR+265976226472320.0*n*n*n*EsuR*EsuR*EsuR-86572941174720.0*EsuR*EsuR*EsuR*n*n*n*n-36564287760.0*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n-111711600.0*pow(n,10.0)*EsuR*EsuR*EsuR+405237392560.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR-544740911769600.0*n*n*EsuR*EsuR*EsuR)/pow(T,19.0); 
							MapleGenVar3 = MapleGenVar2+(10710700.0*pow(n,10.0)*EsuR*EsuR*EsuR*EsuR+1021833712900.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-98395937640.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR+41496213078320.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n-7683649373400.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR+396661224960000.0*EsuR*EsuR*EsuR*EsuR-330930600.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n*n+1820.0*EsuR*EsuR*EsuR*EsuR*pow(n,12.0)+6812665860.0*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n-589000531392000.0*n*EsuR*EsuR*EsuR*EsuR-207480.0*pow(n,11.0)*EsuR*EsuR*EsuR*EsuR+393802477286400.0*n*n*EsuR*EsuR*EsuR*EsuR-156873419582880.0*EsuR*EsuR*EsuR*EsuR*n*n*n)/pow(T,20.0);
					double	MapleGenVar1 = MapleGenVar3+(13554004464.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n+1724663981040.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR-162806202599040.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n-11542102572000.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n+293901135091200.0*n*EsuR*EsuR*EsuR*EsuR*EsuR-237996734976000.0*EsuR*EsuR*EsuR*EsuR*EsuR-699098400.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n-181934232480.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n-480480.0*pow(n,10.0)*EsuR*EsuR*EsuR*EsuR*EsuR+4368.0*pow(n,11.0)*EsuR*EsuR*EsuR*EsuR*EsuR+53422501099968.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+23783760.0*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n*n)/pow(T,21.0)+(-90310655635200.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n+39399360.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-1084683600.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-11261555104800.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+41633476492608.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n-236418141960.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+19425590184.0*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+1979793255440.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+87265469491200.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+8008.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*pow(n,10.0)-840840.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n*n)/pow(T,22.0)+(1530301160960.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-1252611360.0*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+49489440.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+18039621600000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n-20777492736000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-1132560.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+20235174960.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+11440.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n*n*n-6906128898240.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n-216329153040.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n)/pow(T,23.0);
							MapleGenVar2 = MapleGenVar1+(12870.0*n*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-1077476400.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+47387340.0*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-1184040.0*n*n*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-136814637960.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n-2422190628000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n+15222237030.0*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+3339239904000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR+763886340360.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n)/pow(T,24.0)+(-960960.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n+222753960000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n+8072624560.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n+34434400.0*n*n*n*n*n*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-371026656000.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR-57032015040.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n+11440.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n*n*n*n-682281600.0*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*EsuR*n*n*n*n)/pow(T,25.0)+(-14118904800.0*pow(EsuR,10.0)*n+18698680.0*pow(EsuR,10.0)*n*n*n*n+28857628800.0*pow(EsuR,10.0)-309309000.0*pow(EsuR,10.0)*n*n*n+8008.0*pow(EsuR,10.0)*n*n*n*n*n*n-600600.0*pow(EsuR,10.0)*n*n*n*n*n+2867056192.0*pow(EsuR,10.0)*n*n)/pow(T,26.0)+(7360080.0*pow(EsuR,11.0)*n*n*n-283920.0*pow(EsuR,11.0)*n*n*n*n+4368.0*pow(EsuR,11.0)*n*n*n*n*n-95113200.0*pow(EsuR,11.0)*n*n+612716832.0*pow(EsuR,11.0)*n-1574052480.0*pow(EsuR,11.0))/pow(T,27.0);
					d16 = MapleGenVar2+(-98280.0*pow(EsuR,12.0)*n*n*n+59623200.0*pow(EsuR,12.0)-17788680.0*pow(EsuR,12.0)*n+1985620.0*pow(EsuR,12.0)*n*n+1820.0*pow(EsuR,12.0)*n*n*n*n)/pow(T,28.0)+(560.0*pow(EsuR,13.0)*n*n*n+328720.0*pow(EsuR,13.0)*n-23520.0*pow(EsuR,13.0)*n*n-1528800.0*pow(EsuR,13.0))/pow(T,29.0)+(25200.0*pow(EsuR,14.0)-3480.0*pow(EsuR,14.0)*n+120.0*pow(EsuR,14.0)*n*n)/pow(T,30.0)+(-240.0*pow(EsuR,15.0)+16.0*n*pow(EsuR,15.0))/pow(T,31.0)+1/pow(T,32.0)*pow(EsuR,16.0);
				}
			}
		}
	}
	
	double CoeffCorr;
	if (iSinExpansion == 8)			CoeffCorr = 1.+qT2*(c2*d2+qT2*(c4*d4+qT2*(c6*d6+qT2*c8*d8)));
	else if (iSinExpansion == 10)	CoeffCorr = 1.+qT2*(c2*d2+qT2*(c4*d4+qT2*(c6*d6+qT2*(c8*d8+qT2*c10*d10))));
	else if (iSinExpansion == 12)	CoeffCorr = 1.+qT2*(c2*d2+qT2*(c4*d4+qT2*(c6*d6+qT2*(c8*d8+qT2*(c10*d10+qT2*c12*d12)))));
	else if (iSinExpansion == 14)	CoeffCorr = 1.+qT2*(c2*d2+qT2*(c4*d4+qT2*(c6*d6+qT2*(c8*d8+qT2*(c10*d10+qT2*(c12*d12+qT2*c14*d14))))));
	else if (iSinExpansion == 16)	CoeffCorr = 1.+qT2*(c2*d2+qT2*(c4*d4+qT2*(c6*d6+qT2*(c8*d8+qT2*(c10*d10+qT2*(c12*d12+qT2*(c14*d14+qT2*c16*d16)))))));

	return CoeffCorr;
}

