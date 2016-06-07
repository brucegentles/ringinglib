// -*- C++ -*- streamutils.cpp - Utilities to cope with old iostream libraries
// Copyright (C) 2002, 2005 Richard Smith <richard@ex-parrot.com>

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

// Part of this file is taken from the boost lexical_cast library,
// version 1.28.0 [see http://www.boost.org for details], and is under
// the following copyright:

//  Copyright Kevlin Henney, 2000, 2001, 2002. All rights reserved.
//
//  Permission to use, copy, modify, and distribute this software for any
//  purpose is hereby granted without fee, provided that this copyright and
//  permissions notice appear in all copies and derivatives.
//
//  This software is provided "as is" without express or implied warranty.

// The getline function is taken from the GNU ISO C++ Library,
// version 3.2.3 [see http://gcc.gnu.org/libstdc++/ for details], and is 
// under the GPL under following copyright:

//  Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002
//  Free Software Foundation, Inc.

// $Id: streamutils.cpp,v 1.6 2005/03/29 13:20:04 ras52 Exp $

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma implementation
#endif

#include <ringing/streamutils.h>


RINGING_START_NAMESPACE

RINGING_USING_STD

const char* bad_lexical_cast::what() const throw()
{
  return "bad cast: "
    "source type value could not be interpreted as target";
}

make_string::operator string()
{
#if RINGING_USE_STRINGSTREAM
  return os.str();
#else
  string s( os.str(), os.pcount() ); 
  os.freeze(0); 
  return s;
#endif
}


RINGING_END_NAMESPACE


#if defined(_MSC_VER) && _MSC_VER <= 1200 && defined(_YVALS) && (!defined(_CPPLIB_VER) || _CPPLIB_VER < 306)
istream& getline( istream& in, string &str, char delim )
{
  size_t extracted = 0;
  bool testdelim = false;
  istream::sentry cerb(in, true);
  if (cerb) 
    {
      str.erase();
      size_t n = str.max_size();

      int idelim = string::traits_type::to_int_type(delim);
      streambuf* sb = in.rdbuf();
      int c = sb->sbumpc();
      const int eof = string::traits_type::eof();
      testdelim = string::traits_type::eq_int_type(c, idelim);

      while (extracted <= n 
	     && !string::traits_type::eq_int_type(c, eof)
	     && !testdelim)
	{
	  str += string::traits_type::to_char_type(c);
	  ++extracted;
	  c = sb->sbumpc();
	  testdelim = string::traits_type::eq_int_type(c, idelim);
	}
      if (string::traits_type::eq_int_type(c, eof))
	in.setstate(ios_base::eofbit);
    }
  if (!extracted && !testdelim)
    in.setstate(ios_base::failbit);
  return in;
}
#endif
