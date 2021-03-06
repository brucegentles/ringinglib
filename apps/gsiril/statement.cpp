// statement.cpp - Code to execute different types of statement
// Copyright (C) 2002, 2003, 2004, 2005 Richard Smith <richard@ex-parrot.com>

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

// $Id: statement.cpp,v 1.1 2005/01/31 17:51:00 ras52 Exp $

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma implementation
#endif

#include "statement.h"
#include "parser.h"
#include "execution_context.h"
#include "proof_context.h"
#if RINGING_OLD_IOSTREAMS
#include <fstream.h>
#else
#include <fstream>
#endif
#include <ringing/streamutils.h>

void definition_stmt::execute( execution_context& e ) const
{
  if ( e.define_symbol( defn ) )
    {
      if ( e.verbose() ) {
	if ( defn.second.isnop() )
	  e.output() << "Definition of '" << defn.first << "' cleared." << endl;
	else
	  e.output() << "Redefinition of '" << defn.first << "'." << endl;
      }
    }
  else
    {
      if ( e.verbose() ) {
	if ( ! defn.second.isnop() )
	  e.output() << "Definition of '" << defn.first << "' added." << endl;
      }
    }
}

void default_defn_stmt::execute( execution_context& e ) const
{
  if ( e.default_define_symbol( defn ) )
    {
      if ( e.verbose() ) {
	if ( ! defn.second.isnop() )
	  e.output() << "Definition of '" << defn.first << "' added." << endl;
      }
    }
}

void null_stmt::execute( execution_context& e ) const
{
  if ( e.verbose() )
    e.output() << diagnostic;
}

void prove_stmt::execute( execution_context& e ) const
{
  try
    {
      proof_context p(e);

      try
	{
	  p.execute_symbol( "start" );
	  expr.execute(p);
	  p.execute_symbol( "finish" );
      	} 
      catch( const script_exception& ex ) 
	{
	  if ( ex.t == script_exception::do_abort )
	    p.execute_symbol( "abort" );
	  return;
	}
    
      switch ( p.state() )
	{
	case proof_context::rounds: 
	  p.execute_symbol( "true" ); 
	  break;
	case proof_context::notround:
	  p.execute_symbol( "notround" ); 
	  break;
	case proof_context::isfalse:
	  p.execute_symbol( "false" ); 
	  break;
	}
    } 
  catch ( const script_exception& ) 
    {
    }
}

void extents_stmt::execute( execution_context& e ) const
{
  e.extents( n );

  if ( e.verbose() )
    e.output() << "Set extents to " << n << endl;
}

void bells_stmt::execute( execution_context& e ) const
{
  e.bells( bells );

  if ( e.verbose() )
    e.output() << "Set bells to " << bells << endl;
}

void rounds_stmt::execute( execution_context& e ) const
{
  e.rounds( rounds );

  if ( e.verbose() )
    e.output() << "Set rounds to " << rounds << endl;
}

void import_stmt::execute( execution_context& e ) const
{
  bool i( e.interactive() );
  bool v( e.verbose() );
  int b( e.bells() );

  try
    {
      ifstream ifs( name.c_str() );
      if ( !ifs )
	throw runtime_error
	  ( make_string() << "Unable to load resource: " << name );
      
      shared_pointer<parser> p( make_default_parser(ifs, e.get_args() ) );
      e.interactive(false);
      e.verbose(false);
      while (true)
	{
	  statement s( p->parse() );
	  if ( s.eof() ) break;
	  s.execute(e);
	}
    }
  catch (...)
    {
      // Restore bells, verbose, interactive flags
      if (b > 0) e.bells(b);
      e.interactive(i);
      e.verbose(v);
      throw;
    }

  // Restore bells, verbose, interactive flags
  if (b > 0) e.bells(b);
  e.interactive(i);
  e.verbose(v);

  if ( e.verbose() )
    e.output() << "Resource \"" << name << "\" loaded" << endl;
}

