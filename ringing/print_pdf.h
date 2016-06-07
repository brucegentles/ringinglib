// -*- c++ -*- print_pdf.h : printing things in PDF
// Copyright (C) 2002 Martin Bright <martin@boojum.org.uk>

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

// $Id: print_pdf.h,v 1.10 2004/10/27 15:45:07 mjb47 Exp $

#ifndef RINGING_PRINT_PDF_H
#define RINGING_PRINT_PDF_H

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#if RINGING_OLD_INCLUDES
#include <list.h>
#include <map.h>
#include <set.h>
#include <iostream.h>
#else
#include <list>
#include <map>
#include <set>
#include <iostream>
#endif
#include <ringing/print.h>
#include <ringing/pdf_fonts.h>
#include <stdio.h>

RINGING_START_NAMESPACE

RINGING_USING_STD

class counting_streambuf : public streambuf {
private:
  int c;
  streambuf& sb;

public:
  counting_streambuf(streambuf* s) : c(0), sb(*s) {}
  int sync() { 
    int n = pptr() - pbase(); c += n;
    return sb.sputn(pptr(), n); 
  }
  int overflow(int ch = EOF) { 
    int n = pptr() - pbase(); 
    if(n && sync()) return EOF; pbump(-n);
    if(ch != EOF) { ++c; sb.sputc(ch); }
    return 0;
  }
  int get_count() { if(pptr() != pbase()) sync(); return c; }
  void reset_count() { c = 0; }
};

// This represents a PDF file.
class pdf_file {
private:
  counting_streambuf csb;
  ostream os;
  int obj_count;
  map<int, int> offsets;
  int width, height;
  bool landscape;
  int pages;
  int stream_start;
  map<string, string> fonts;
  int font_counter;

public:
  pdf_file(ostream& o, bool l = false, int w = 590, int h = 835) 
    : csb(o.rdbuf()), os(&csb) , width(w), height(h), landscape(l) 
    { start(); }
  ~pdf_file() { end(); }

  void start();
  void end();
  int start_object(int n = 0);
  void end_object();
  void start_stream();
  void end_stream();
  void start_page();
  void end_page();
  void output_catalogue();
  void output_info();
  void output_pages();
  const string& get_font(const string& f);
  bool get_landscape() { return landscape; }
  void output_string(const string& s);
  int get_width() { return width; }
  int get_height() { return height; }

  template<class T> pdf_file& operator<<(const T& t)
    { os << t; return *this; }
};

class printrow_pdf;
class printpage_pdf;

class drawline_pdf {
private:
  const printrow_pdf& p;
  bell bellno;
  printrow::options::line_style s;
  list<int> l;
  int curr;
  
public:
  drawline_pdf(const printrow_pdf& pr, bell b, 
	   printrow::options::line_style st) : 
    p(pr), bellno(b), s(st), curr(-1) {}
  void add(const row& r);
  void output(pdf_file& f);

  RINGING_FAKE_DEFAULT_CONSTRUCTOR( drawline_pdf )
  RINGING_FAKE_COMPARATORS( drawline_pdf )
  RINGING_FAKE_ASSIGNMENT( drawline_pdf )
};

struct text_bit {
  float x, y;
  text_style::alignment al;
  bool squash;
  string s;

  RINGING_FAKE_COMPARATORS( text_bit )
};

class printrow_pdf : public printrow::base {
private:
  printpage_pdf& pp;
  int currx, curry;
  bool in_column;
  row lastrow;
  int count;
  int gapcount;
  printrow::options opt;
  charwidths cw;
  list<pair<string, int> > rows;
  list<text_bit> text_bits;

  list<drawline_pdf> drawlines;
  friend class drawline_pdf;
  bool has_line(int b) const { return opt.lines.find(b) != opt.lines.end(); }
  
  void start();
  void start_column();
  void end_column();
  void grid();

public:
  printrow_pdf(printpage_pdf& p, const printrow::options& op) 
    : pp(p), in_column(false), lastrow(8), opt(op) { start(); }
  ~printrow_pdf() { if(in_column) end_column(); }
  void print(const row& r);
  void rule();
  void set_position(const dimension& x, const dimension& y);
  void move_position(const dimension& x, const dimension& y);
  void set_options(const printrow::options& o) { opt = o; }
  const printrow::options& get_options() { return opt; }
  void dot(int i); 
  void placebell(int i);
  void text(const string& t, const dimension& x, 
	    text_style::alignment al, bool between, bool right);
};

class printpage_pdf : public printpage {
protected:
  pdf_file f;

public:
  printpage_pdf(ostream& o, const dimension& w, const dimension& y, 
		bool ls = false);
  printpage_pdf(ostream& o, bool ls = false);
  ~printpage_pdf();
  void text(const string t, const dimension& x, const dimension& y,
       text_style::alignment al, const text_style& s);
  void new_page();

private:
  friend class printrow;
  friend class printrow_pdf;
  friend class drawline_pdf;
  printrow::base* new_printrow(const printrow::options& o) 
    { return new printrow_pdf(*this, o); }

protected:
  void set_colour(const colour& c, bool nonstroke = false);
  void landscape_mode();
  void circle(float x, float y, float r, char op);
};

RINGING_END_NAMESPACE

#endif
