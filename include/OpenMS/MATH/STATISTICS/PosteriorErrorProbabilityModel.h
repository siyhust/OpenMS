// -*- mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2009 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: David Wojnar $
// $Authors: $
// --------------------------------------------------------------------------
//
#ifndef OPENMS_MATH_STATISTICS_POSTERIORERRORPROBABILITYMODEL_H
#define OPENMS_MATH_STATISTICS_POSTERIORERRORPROBABILITYMODEL_H

#include <OpenMS/DATASTRUCTURES/DPosition.h>
#include <OpenMS/MATH/STATISTICS/GumbelDistributionFitter.h>
#include <OpenMS/MATH/STATISTICS/GaussFitter.h>
#include <OpenMS/DATASTRUCTURES/DefaultParamHandler.h>
#include <vector>

namespace OpenMS
{
	namespace Math
	{
	  
	  
	  /** 
	  	@brief Implements a mixture model for the inverse gumbel and the gauss distribution
	
	    This class fits a Gumbel distribution and a Gauss distribution to a number of data points.
	    The result for each data points is stored in the second parameter of the fit function.
			GumbelDistributionFitResult and GaussFitResult.
	
	    The formula with the fitted parameters can be transformed into a
	    gnuplot formula using getGumbelGnuplotFormula() and getGaussGnuplotFormula() after fitting.
	
			
			@ingroup Math
		*/
		class OPENMS_DLLAPI PosteriorErrorProbabilityModel: public DefaultParamHandler
		{
			public:
	
		
				/// Default constructor
				PosteriorErrorProbabilityModel();

				/// Destructor
				virtual ~PosteriorErrorProbabilityModel(); 
				
				///fits the curves to the data points(x_scores) and writes the computed probabilites into the given vector.
				void fit(std::vector<double>& x_scores, std::vector<double>& probabilites);
				
				///returns estimated gauss parameters. Fit should be used before.
				GaussFitter::GaussFitResult getGaussFitResult()
				{
					return gauss_fit_param_;
				}
				
				///returns estimated gumbel parameters. Fit should be used before.
				GumbelDistributionFitter::GumbelDistributionFitResult getGumbelFitResult()
				{
					return gumbel_fit_param_;
				}
				
				/// returns the gnuplot formula of the fitted gumbel distribution.
				const String getGumbelGnuplotFormula() const;
				
				/// returns the gnuplot formula of the fitted gauss distribution.
				const String getGaussGnuplotFormula() const;
				
				/// returns the gnuplot formula of the fitted mixture distribution.
				const String getBothGnuplotFormula(double negative_prior) const;
				
			private:
				/// assignment operator (not implemented)
				PosteriorErrorProbabilityModel& operator = (const PosteriorErrorProbabilityModel& rhs);
				///Copy constructor
				PosteriorErrorProbabilityModel(const PosteriorErrorProbabilityModel& rhs);
				
				GumbelDistributionFitter::GumbelDistributionFitResult gumbel_fit_param_;
				GaussFitter::GaussFitResult	gauss_fit_param_;
		};
	}
}

#endif

