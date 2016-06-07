// -*- C++ -*- expression.h - classes to handle expressions
// Copyright (C) 2003 Richard Smith <richard@ex-parrot.com>

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

// $Id: expression.h,v 1.1 2003/11/26 20:29:28 ras52 Exp $


#ifndef METHSEARCH_EXPRESSION_INCLUDED
#define METHSEARCH_EXPRESSION_INCLUDED

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#if RINGING_OLD_INCLUDES
#include <vector.h>
#else
#include <vector>
#endif
#include <string>
#include <ringing/pointers.h>

RINGING_USING_NAMESPACE
RINGING_USING_STD

class method_properties;

class expression
{
public:
  class node;

  expression() {}
  explicit expression( node* impl ) : pimpl(impl) {}

  explicit expression( const string& str );

  class node {
  public:
    node() {} // Keep gcc-2.95.3 happy
    virtual ~node() {}
    virtual string s_evaluate( const method_properties& m ) const = 0;
    virtual long   i_evaluate( const method_properties& m ) const = 0;
    
  private:
    node(const node&); // Unimplemented
    node& operator=(const node&); // Unimplemented
  };

  // Implements s_evaluate in terms of i_evaluate
  class i_node : public node {
    virtual string s_evaluate( const method_properties& m ) const;
  };

  // Implements i_evaluate in terms of s_evaluate
  class s_node : public node {
    virtual long   i_evaluate( const method_properties& m ) const;
  };

  bool null() const { return !pimpl; }
  string evaluate( const method_properties& m ) const;
  bool b_evaluate( const method_properties& m ) const;

private:
  class parser;
  shared_pointer<node> pimpl;
};

class script_exception 
{
public:
  enum type_t { suppress_output, abort_search };
  explicit script_exception( type_t t ) : t(t) {}
  type_t type() const { return t; }

private:
  type_t t;
};

class expression_cache 
{
public:
  static size_t store( const expression& expr ); 
  static string evaluate( size_t idx, const method_properties& props );
  static bool b_evaluate( size_t idx, const method_properties& props );

private:
  static vector<expression>& exprs();
};

#endif // METHSEARCH_EXPRESSION_INCLUDED

