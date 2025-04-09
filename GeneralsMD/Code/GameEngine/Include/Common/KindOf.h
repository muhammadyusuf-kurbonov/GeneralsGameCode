/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: KindOf.h //////////////////////////////////////////////////////////////////////////
// Author: Steven Johnson, Dec 2001
// Desc:	 
///////////////////////////////////////////////////////////////////////////////////////////////////	

#pragma once

#ifndef __KINDOF_H_
#define __KINDOF_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "Lib/BaseType.h"
#include "Common/BitFlags.h"
#include "Common/BitFlagsIO.h"

//-------------------------------------------------------------------------------------------------
#include "KindOfTypes.h"

typedef BitFlags<KINDOF_COUNT>	KindOfMaskType;

#define MAKE_KINDOF_MASK(k) KindOfMaskType(KindOfMaskType::kInit, (k))

inline Bool TEST_KINDOFMASK(const KindOfMaskType& m, KindOfType t) 
{ 
	return m.test(t); 
}

inline Bool TEST_KINDOFMASK_ANY(const KindOfMaskType& m, const KindOfMaskType& mask) 
{ 
	return m.anyIntersectionWith(mask);
}

inline Bool TEST_KINDOFMASK_MULTI(const KindOfMaskType& m, const KindOfMaskType& mustBeSet, const KindOfMaskType& mustBeClear)
{
	return m.testSetAndClear(mustBeSet, mustBeClear);
}

inline Bool KINDOFMASK_ANY_SET(const KindOfMaskType& m) 
{ 
	return m.any(); 
}

inline void CLEAR_KINDOFMASK(KindOfMaskType& m) 
{ 
	m.clear(); 
}

inline void SET_ALL_KINDOFMASK_BITS(KindOfMaskType& m)
{
	m.clear();
	m.flip();
}

inline void FLIP_KINDOFMASK(KindOfMaskType& m)
{
	m.flip();
}

// defined in Common/System/Kindof.cpp
extern KindOfMaskType KINDOFMASK_NONE;	// inits to all zeroes
extern KindOfMaskType KINDOFMASK_FS;		// Initializes all FS types for faction structures.
void initKindOfMasks();

#endif	// __KINDOF_H_

