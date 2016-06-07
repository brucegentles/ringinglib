// -*- C++ -*-  util.h - Various utility functions needed in gsiril
// Copyright (C) 2002 Richard Smith <richard@ex-parrot.com>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// $Id: util.h,v 1.4 2003/07/30 20:56:32 ras52 Exp $
#ifndef GSIRIL_UTIL_INCLUDED
#define GSIRIL_UTIL_INCLUDED

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#include <string>

RINGING_USING_NAMESPACE

int string_to_int( const string &num );

void trim_leading_whitespace( string &line );
void trim_trailing_whitespace( string &line );

string lower_case( const string& str );

#endif // GSIRIL_UTIL_INCLUDED
