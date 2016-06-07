// -*- C++ -*- prog_args.h - program arguments
// Copyright (C) 2002, 2003, 2004 Richard Smith <richard@ex-parrot.com>

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

// $Id: prog_args.h,v 1.10 2004/03/20 18:50:26 ras52 Exp $

#ifndef METHSEARCH_ARGS_INCLUDED
#define METHSEARCH_ARGS_INCLUDED

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#include "init_val.h"
#include <string>
#if RINGING_OLD_INCLUDES
#include <vector.h>
#else
#include <vector>
#endif
#if RINGING_OLD_INCLUDES
#include <iosfwd.h>
#else
#include <iosfwd>
#endif
#include <ringing/row.h>
#include <ringing/pointers.h>
#include <ringing/libout.h>

class arg_parser;

RINGING_USING_NAMESPACE
RINGING_USING_STD

struct arguments
{
  init_val<int,-1> search_limit;

  init_val<int,0>  bells;
  init_val<int,0>  max_consec_blows;
  init_val<int,0>  max_places_per_change;
  init_val<int,0>  treble_dodges;
  init_val<int,1>  hunt_bells;
  init_val<int,0>  lead_len;
  init_val<int,0>  max_consec_places; 

  init_val<bool,false> require_limited_le;
  init_val<bool,false> prefer_limited_le;
  init_val<bool,false> require_pbles;
  init_val<bool,false> require_cyclic_les;
  init_val<bool,false> require_cyclic_hlh;
  init_val<bool,false> require_cyclic_hle;
  init_val<bool,false> require_rev_cyclic_hlh;
  init_val<bool,false> require_rev_cyclic_hle;
  init_val<bool,false> require_offset_cyclic;
  init_val<bool,false> require_reg_hls;
  init_val<bool,false> right_place;
  init_val<bool,false> show_all_meths;

  init_val<bool,false> quiet;
  init_val<bool,false> histogram;
  init_val<bool,false> status;
  init_val<bool,false> count;
  init_val<bool,false> raw_count;

  init_val<bool,false> no_78_pns;

  init_val<bool,false> skewsym;
  init_val<bool,false> sym;
  init_val<bool,false> doubsym;
  init_val<bool,false> surprise;
  init_val<bool,false> treble_bob;

  init_val<bool,false> same_place_parity;
  init_val<bool,true>  true_trivial;
  init_val<bool,true>  true_half_lead;
  init_val<bool,true>  true_lead;
  init_val<bool,false> true_course;
  init_val<bool,false> true_extent;
  init_val<bool,false> true_positive_extent;

  init_val<bool,false> require_CPS;

  string startmeth;

  string pn;

  string mask;

  vector< vector<change> > allowed_changes;
  vector<row>    required_rows;

  string H_fmt_str, R_fmt_str;
  string outfile;
  string outfmt;

  // TODO:  Isn't really part of this struct
  mutable multilibout outputs;

  string require_str;
  size_t require_expr_idx;

  arguments();

  void bind( arg_parser &p );
  bool validate( arg_parser &p );
};

#endif // METHSEARCH_ARGS_INCLUDED
