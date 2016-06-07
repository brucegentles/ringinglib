// -*- C++ -*- extent.h - Classes for iterating through an extent
// Copyright (C) 2001, 2002, 2003, 2005 
// Richard Smith <richard@ex-parrot.com>

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

// $Id: extent.cpp,v 1.10 2005/03/29 10:08:59 ras52 Exp $

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma implementation
#endif

#include <ringing/extent.h>
#if RINGING_OLD_C_INCLUDES
#include <assert.h>
#else
#include <cassert>
#endif
#if RINGING_OLD_INCLUDES
#include <algo.h>
#else
#include <algorithm>
#endif


RINGING_START_NAMESPACE

RINGING_USING_STD

unsigned factorial(unsigned n)
{
  if (!n) return 1;
  unsigned f = n;
  while (--n)
    f *= n;
  return f;
}

unsigned fibonacci(unsigned n)
{
  if (!n) return 1;
  unsigned f1=1, f2=1;
  while (--n)
    {
      unsigned sum =f1+f2;
      f1 = f2;
      f2 = sum;
    }
  return f2;
}

RINGING_START_ANON_NAMESPACE

static int (*rand_fn)() = &rand;
static int rand_max    = RAND_MAX;

RINGING_END_ANON_NAMESPACE

pair<int (*)(), int> random_fn( int (*randfn)(), int randmax )
{
  pair< int(*)(), int > old = make_pair( rand_fn, rand_max );

  if (randfn) {
    rand_fn  = randfn;
    rand_max = randmax;
  }
  
  return old;
}


unsigned random_int(unsigned max) 
{
  assert( max );

  unsigned r;
  do 
    r = (unsigned)( (double)rand_fn() * ((double)max / (double)rand_max) );
  while ( r == max );
  
  assert( r < max );
  return r;
}

struct extent_iterator::bellsym_cmp
{
  bool operator()( char a, char b )
  {
    bell aa, bb;
    aa.from_char(a);
    bb.from_char(b);
    return aa < bb;
  }
};

extent_iterator::extent_iterator( unsigned int nw, unsigned int nh, 
				  unsigned int nt )
  : nw(nw), nh(nh), nt(nt), end(false), 
    r(nt), s(r.print())
{}

extent_iterator::extent_iterator( unsigned int nw, unsigned int nh )
  : nw(nw), nh(nh), nt(nw+nh), 
    end(false),
    r(nt), s(r.print())
{}

extent_iterator &extent_iterator::operator++()
{
  end = ! next_permutation( s.begin() + nh, s.end() + (nh + nw - nt),
			    bellsym_cmp() );
  if (!end) r = s.c_str();
  return *this;
}

incourse_extent_iterator &incourse_extent_iterator::operator++() 
{
  do { 
    ++ei; 
  } while (ei != ee && ei->sign() < 0);
  return *this;
}

void changes_iterator::next()
{
  if ( nw == 0 || stk.size() == nw && stk.back() == nw+nh-1 )
    {
      end = true;
      return;
    }
  
  while ( stk.back() > nh+1 && !c.findswap( stk.back()-2 ) )
    stk.pop_back();
  
  if ( c.findswap( stk.back()-2 ) )
    {
      c.swappair( stk.back() - 2 );
      --stk.back();
    }
  
  while ( stk.back() < nw+nh-1 )
    {
      c.swappair( stk.back() );
      stk.push_back( stk.back() + 2 );
    }
}

changes_iterator::changes_iterator( unsigned int nw, unsigned int nh )
  : nw(nw), nh(nh), end(false), c(nw+nh)
{
  stk.push_back(nh); 
  if ( nw>1 ) next(); 
}

changes_iterator::changes_iterator( unsigned int nw, unsigned int nh, 
				    unsigned int nt )
  : nw(nw), nh(nh), end(false), c(nt) 
{
  stk.push_back(nh); 
  if ( nw>1 ) next(); 
}

bool random_bool( double ptrue )
{
  assert( ptrue <= 1 );
  return rand_fn() < rand_max * ptrue;
}

row random_row( unsigned int nw, unsigned int nh, unsigned int nt )
{
  int idx( random_int( factorial(nw) ) );
  string s( nt, '?' );
  unsigned i;
  for (i=0; i<nh; ++i) s[i] = bell(i).to_char();
  for (i=nh; i<nw+nh; ++i)
    {
      const int fact( factorial(nw-i+nh-1) );
      unsigned int b = idx / fact;
      idx %= fact;
      
      for (unsigned ob=0; ob<=b; ++ob)
	for (unsigned j=0; j<i; ++j)
	  if ( bell(ob).to_char() == s[j] )
	    ++b;
      
      s[i] = bell(b).to_char();
    }
  for (i=nw+nh; i<nt; ++i) s[i] = bell(i).to_char();
  return s;
}


RINGING_END_NAMESPACE

