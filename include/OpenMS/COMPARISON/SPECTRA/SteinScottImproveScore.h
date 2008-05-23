// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2008 -- Oliver Kohlbacher, Knut Reinert
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
// $Maintainer: Vipul Patel $
// --------------------------------------------------------------------------
//
#ifndef STEINSCOTTIMPROVESCORE_H
#define STEINSCOTTIMPROVESCORE_H

#include <OpenMS/COMPARISON/SPECTRA/PeakSpectrumCompareFunctor.h>
#include <OpenMS/KERNEL/StandardTypes.h>

namespace OpenMS
{

  /**
	  @brief Improvement Similarity score of Stein & Scott

		The details of the score can be found in:
		Signal Maps for Mass Spectrometry-based
		Comparative Proteomics

		

		@ref SteinScottImproveScore_Parameters are explained on a separate page.
		
		
  */
	
  class SteinScottImproveScore : public PeakSpectrumCompareFunctor
  {
  public:
	
		// @name Constructors and Destructors
		// @{
    /// default constructor
	  SteinScottImproveScore();

    /// copy constructor
	  SteinScottImproveScore(const SteinScottImproveScore& source);

    /// destructor
    virtual ~SteinScottImproveScore();
		// @}

		// @name Operators
		// @{
    /// assignment operator
    SteinScottImproveScore & operator = (const SteinScottImproveScore & source);
	
		/// 
		double operator () (const PeakSpectrum& spec1, const PeakSpectrum& spec2) const;

		double operator () (const PeakSpectrum& spec) const;
		// @}

		// @name Accessors
		// @{
		///
    static PeakSpectrumCompareFunctor* create() { return new SteinScottImproveScore(); }

		
		static const String getProductName()
		{
			return "SteinScottImproveScore";
		}

		

  };

}


#endif /*STEINSCOTTIMPROVESCORE_H*/
