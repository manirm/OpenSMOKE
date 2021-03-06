/***************************************************************************
 *   Copyright (C) 2009 by Tiziano Maffei and Alberto Cuoci  	           *
 *   tiziano.maffei@chem.polimi.it   				                       *
 *   alberto.cuoci@polimi.it   						                       *
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

#include "basic/OpenSMOKE_Utilities.h"
#include "basic/OpenSMOKE_Constants.h"
#include "basic/OpenSMOKE_Conversions.h"
#include "engine/OpenSMOKE_ReactingGas.h"
#include "OpenSMOKE_SolidExperiment_DSmoke_Bio.h"

void OpenSMOKE_SolidExperiment_DSmoke_Bio::ErrorMessage(const string message)
{
    cout << endl;
    cout << "Class:  OpenSMOKE_SolidExperiment_DSmoke_Bio"		<< endl;
    cout << "File:   " << name_of_file			<< endl;
    cout << "Error:  " << message				<< endl;
    cout << "Press enter to continue... "		<< endl;
    getchar();
    exit(-1);
}

void OpenSMOKE_SolidExperiment_DSmoke_Bio::WarningMessage(const string message)
{
    cout << endl;
    cout << "Class:	  OpenSMOKE_SolidExperiment_DSmoke_Bio"	<< endl;
    cout << "File:    " << name_of_file			<< endl;
    cout << "Warning: " << message				<< endl;
	cout << endl;
}

void OpenSMOKE_SolidExperiment_DSmoke_Bio::ReadFromFile(const string filename)
{
	string dummy;
	double dummy_double;

	string x_type;
	string y_type;
	string x_units;
	string y_units;

	name_of_file = filename;
	ifstream fInput;
	openInputFileAndControl(fInput, filename);

	solid_names.push_back("solid names");
	solid_mass_fraction.push_back(0.);
	solid_index.push_back(-1);
	mass_ratio_names.push_back("mass ratio names");

	// TODO
	for(;;)
	{
		fInput >> dummy;
		if (dummy == "PRESSURE") break;

		if (dummy!="TEMPERATURE")	ErrorMessage("Expected: TEMPERATURE - Found: " + dummy);

		fInput >> dummy_double;
		fInput >> dummy;
		times.Append(OpenSMOKE_Conversions::conversion_time(dummy_double, dummy));
		fInput >> dummy_double;
		fInput >> dummy;
		temperatures.Append(OpenSMOKE_Conversions::conversion_temperature(dummy_double, dummy));
	}
	

	if (dummy!="PRESSURE")	ErrorMessage("Expected: PRESSURE - Found: " + dummy);
	fInput >> pressure_atm;
	fInput >> dummy;
	pressure_atm = OpenSMOKE_Conversions::conversion_pressure(pressure_atm, dummy)/101325.;

	for(;;)
	{
		fInput >> dummy;
		if (dummy == "X") break;
		if (dummy != "SOLID_MASS_FRACTION")	ErrorMessage("Expected: SOLID_MASS_FRACTION - Found: " + dummy);
		fInput >> dummy;
		solid_names.push_back(dummy);
		fInput >> dummy;
		solid_mass_fraction.push_back(atof(dummy.c_str()));
	}

	fInput >> x_type;	if (x_type != "TIME")	ErrorMessage("Expected: TIME - Found: " + x_type);
	fInput >> dummy;	if (dummy  != "UNITS")	ErrorMessage("Expected: UNITS - Found: " + dummy);
	fInput >> x_units;

	fInput >> dummy;
	if (dummy != "Y")			ErrorMessage("Expected: Y - Found: " + dummy);
	fInput >> y_type;
	if (y_type == "MASS_RATIO")
	{
		kind_of_experimental_data = DSMOKE_BIO_MASS_RATIO;
		for(;;)
		{
			fInput >> dummy;
			if (dummy == "UNITS") break;
			mass_ratio_names.push_back(dummy);
		}
	}
	else if (y_type == "D_MASS_RATIO")
	{
		kind_of_experimental_data = DSMOKE_BIO_D_MASS_RATIO;
		for(;;)
		{
			fInput >> dummy;
			if (dummy == "UNITS") break;
			mass_ratio_names.push_back(dummy);
		}
	}
	else	ErrorMessage("Expected: MASS_RATIO || D_MASS_RATIO - Found: " + y_type);
	
	if (dummy != "UNITS")		ErrorMessage("Expected: UNITS - Found: " + dummy);
	fInput >> y_units;
	
	if (y_type == "MASS_RATIO" && y_units != "none") 
		ErrorMessage("Wrong units of experimental data (y column)...");

	// Reading times
	for(;;)
	{
		fInput >> dummy;
		if (dummy == "//")	break;
		
		if (x_type == "TIME")	x.Append( OpenSMOKE_Conversions::conversion_time(atof(dummy.c_str()), x_units) );

		fInput >> dummy;
		if (y_type == "MASS_RATIO")		y.Append(atof(dummy.c_str()));
		if (y_type == "D_MASS_RATIO")	y.Append(OpenSMOKE_Conversions::conversion_frequency(atof(dummy.c_str()), y_units));
	}
	fInput.close();

	nPoints = x.Size();

	CheckUserInputs();

	cout << "-------------------------------------------"		<< endl;
	cout << "Experiment:      " << filename						<< endl;
	cout << "-------------------------------------------"		<< endl;
	cout << "  * Temperature (initial): " << temperatures[1]					<< " K"			<< endl;
	cout << "  * Temperature (final):   " << temperatures[temperatures.Size()]	<< " K"			<< endl;
	cout << "  * Pressure:              " << pressure_atm						<< " atm"		<< endl;
	
	for(int j=1;j<=int(solid_names.size())-1;j++)
		cout << "  * x_mass " << solid_names[j] << "\t" << solid_mass_fraction[j] << endl;
	
	cout << "  * #points:      " << nPoints						<< endl;
	cout << "  * x0:           " << x[1]						<< endl;
	cout << "  * xF:           " << x[nPoints]					<< endl;
	cout << "  * yMean:        " << Mean(y)						<< endl;
	cout << "-------------------------------------------"		<< endl;
	
	cout << endl;
}

void OpenSMOKE_SolidExperiment_DSmoke_Bio::CheckUserInputs()
{
	int j;

	if (times.Size()<2)	ErrorMessage("At least a couple of temperatures must be specified...");
	
	for(j=2;j<=times.Size();j++)
	{
		if (times[j]<=times[j-1])								ErrorMessage("Error in the temperature profile definition...");
		if (times[j]<0.)										ErrorMessage("Error in the temperature profile definition...");
		if (temperatures[j]<=200. || temperatures[j]>=5000.)	ErrorMessage("Error in the temperature profile definition...");
	}
	
	if (pressure_atm <= 1e-10 || pressure_atm >= 1000.)			ErrorMessage("Error in the pressure definition...");

	if (x[x.Size()] >= times[times.Size()])						ErrorMessage("The last time in the temperature profile is not enough to cover the whole experiment...");

	for(j=2;j<=x.Size();j++)
		if (x[j] <= x[j-1])										ErrorMessage("Error in the x profile definition...");
}

void OpenSMOKE_SolidExperiment_DSmoke_Bio::PrepareMasses(OpenSMOKE_ReactingGas &mix)
{
	int j;

	double sum = 0.;
	for(j=1;j<=int(solid_names.size())-1;j++)
		sum += solid_mass_fraction[j];

	if ( sum > 1.0001 || sum < 0.9999)
		ErrorMessage("The sum of solid mass fractions must be equal to 1...");
	
	for(j=1;j<=int(solid_names.size())-1;j++)
		solid_mass_fraction[j] /= sum;
	
	ChangeDimensions(mix.NumberOfSpecies(), &initial_masses);
	for(j=1;j<=int(solid_names.size())-1;j++)
		initial_masses[mix.recognize_species(solid_names[j])] = solid_mass_fraction[j];

	for(j=1;j<=int(mass_ratio_names.size())-1;j++)
		mass_ratio_indices.Append(mix.recognize_species(mass_ratio_names[j]));

	temperature_mean = temperatures.GetSumElements()/temperatures.Size();

	ChangeDimensions(times.Size()-1, &dtemperatures);
	for(j=1;j<=times.Size()-1;j++)
		dtemperatures[j] = (temperatures[j+1]-temperatures[j])/(times[j+1]-times[j]);
}

double OpenSMOKE_SolidExperiment_DSmoke_Bio::GetTemperature(const double t)
{

	for(int j=1;j<=times.Size()-1;j++)
		if (t<=times[j+1])
			return temperatures[j] + dtemperatures[j]*(t-times[j]);
	if (t>=times[times.Size()])	return temperatures[times.Size()];

	{
		cout << "Ode time: " << t << " s" << endl;
		cout << "T minimum time: " << times[1] << " s" << endl;
		cout << "T maximum time: " << times[times.Size()] << " s" << endl;
		ErrorMessage("Time below the minimum value in the defined temperature profile...");
	}
	return -1;
}