// -*- C++ -*- testmusic.cpp - test the base classes
// Copyright (C) 2001 Mark Banner <mark@standard8.co.uk>

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

// $Id: testmusic.cpp,v 1.9 2002/12/18 20:18:10 standardeight Exp $

#if RINGING_OLD_INCLUDES
#include <iostream.h>
#include <stdexcept.h>
#else
#include <iostream>
#include <stdexcept>
#endif
#include <ringing/row.h>
#include <ringing/method.h>
#include <ringing/touch.h>
#include <ringing/music.h>
#include <string>

#if RINGING_USE_NAMESPACES
using namespace ringing;
#endif

int main()
{
  // Setup

  // construct a 120 of Plain Bob Doubles
  touch_changes lead("5.1.5.1.5.1.5.1.5", 5);
  touch_changes lhplain("125", 5);
  touch_changes lhbob("145", 5);
  
  touch_child_list p, b, pppb, touch;
  
  p.push_back(1, &lead); p.push_back(1, &lhplain);
  b.push_back(1, &lead); b.push_back(1, &lhbob);
  pppb.push_back(3, &p);
  pppb.push_back(1, &b);
  touch.push_back(3, &pppb);

  touch_node::const_iterator i;
  vector<row> pbdoubles;
  row r(5); r.rounds();
  // Don't put the first row on, as otherwise we have rounds twice
  for(i = touch.begin(); i != touch.end(); ++i)
    {
      r *= *i;
      pbdoubles.push_back(r);
    }

  {
    music::const_iterator k;

    cout << "Testing Music Class...\n\n";
    
    cout << "Testing in Plain Bob Doubles (120)\n";
    
    music mu(5);

#if RINGING_USE_EXCEPTIONS
    try
      {
#endif
	music_details md("*45");
	mu.push_back(md);

	md.set("54*", 2);
	mu.push_back(md);

	md.set("12??5", 4);
	mu.push_back(md);
	
	md.set("13524", 6);
	mu.push_back(md);

	md.set("*[34]5");
	mu.push_back(md);

	md.set("*34?");
	mu.push_back(md);
       
	md.set("?45*");
	mu.push_back(md);
	
	md.set("5[34]*");
	mu.push_back(md);

	md.set("*345*");
	mu.push_back(md);

	md.set("?*34*");
	mu.push_back(md);

#if RINGING_USE_EXCEPTIONS
      }
    catch (exception &e)
      {
	cerr << "Error cannot specify music: " << e.what() << endl;
      }
#endif
    mu.process_rows(pbdoubles.begin(), pbdoubles.end());

    cout << "Results for both strokes (and max possibilities in last column):\n";

    for (k = mu.begin(); k != mu.end(); k++)
      cout << "Total " << k->get() << "\t: " << k->count() << " : " << k->total() << " : " << k->possible_matches(5) << endl;

    cout << "Total Score: " << mu.get_score() << "\tTotal Possible Score: " << mu.get_possible_score() << endl;

    cout << "Results for handstrokes:\n";

    for (k = mu.begin(); k != mu.end(); k++)
      cout << "Total " << k->get() << "\t: " << k->count(eHandstroke) << " : " << k->total(eHandstroke) << endl;

    cout << "Total Score: " << mu.get_score(eHandstroke) << endl;

    cout << "Results for backstrokes:\n";

    for (k = mu.begin(); k != mu.end(); k++)
      cout << "Total " << k->get() << "\t: " << k->count(eBackstroke) << " : " << k->total(eBackstroke) << endl;

    cout << "Total Score: " << mu.get_score(eBackstroke) << endl;
  }
  return 0;
}
