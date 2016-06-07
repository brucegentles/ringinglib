// -*- C++ -*- parser.h - Tokenise and parse lines of input into statements
// Copyright (C) 2002, 2003 Richard Smith <richard@ex-parrot.com>

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

// $Id: parser.h,v 1.7 2003/07/30 20:56:31 ras52 Exp $

#ifndef GSIRIL_PARSER_INCLUDED
#define GSIRIL_PARSER_INCLUDED

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#if RINGING_OLD_INCLUDES
#include <utility.h>
#include <map.h>
#else
#include <utility>
#include <map>
#endif
#if RINGING_HAVE_OLD_IOSTREAMS
#include <istream.h>
#include <ostream.h>
#else
#include <iosfwd>
#endif
#include <string>
#include <ringing/pointers.h>

RINGING_USING_NAMESPACE

struct arguments;
class statement;

class parser
{
public:
  virtual ~parser() {}

  // Retrieves one statement from the input
  // or a null pointer for EOF
  virtual statement parse() = 0;
};

// if library_mode is set, the parser will not emit final
shared_pointer<parser> 
make_default_parser( istream& in, const arguments& args );


#endif // GSIRIL_PARSER_INCLUDED
