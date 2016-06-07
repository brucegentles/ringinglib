// -*- C++ -*- libout.cpp - general classes for output of a method library
// Copyright (C) 2004 Richard Smith <richard@ex-parrot.com>.

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// $Id: libout.cpp,v 1.3 2005/03/31 19:15:02 ras52 Exp $

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma implementation
#endif

#include <ringing/libout.h>
#if RINGING_OLD_INCLUDES
#include <vector.h>
#else
#include <vector>
#endif

RINGING_START_NAMESPACE

RINGING_USING_STD

class multilibout::impl : public libout::interface {
public:
  impl() {}

  void add( shared_pointer<libout> const& outputer ) {
    outputers.push_back( outputer );
  }

  bool empty() const {
    return outputers.empty();
  }

private:
  virtual void append( library_entry const& entry ) {
    for ( vector< shared_pointer<libout> >::iterator 
	    i( outputers.begin() ), e( outputers.end() );  i != e;  ++i ) 
      (*i)->append( entry );
  }

  virtual void flush() {
    for ( vector< shared_pointer<libout> >::iterator 
	    i( outputers.begin() ), e( outputers.end() );  i != e;  ++i ) 
      (*i)->libout::flush();
  }

  // Data members
  vector< shared_pointer<libout> > outputers;
};

multilibout::multilibout()
  : libout( new impl )
{}

void multilibout::add( libout* outputer ) {
  // Note: do not use get_impl<impl>() syntax as this confuses MSVC 6.0
  get_impl( (impl*)NULL )->add( shared_pointer<libout>( outputer ) );
}

bool multilibout::empty() const {
  // Note: do not use get_impl<impl>() syntax as this confuses MSVC 6.0
  return get_impl( (impl*)NULL )->empty();
}

RINGING_END_NAMESPACE
