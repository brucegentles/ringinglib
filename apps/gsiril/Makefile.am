# -*- Makefile -*- gsiril/Makefile.am - Automake script for GSiril

# Process this file with automake to produce Makefile.in

# Copyright (C) 2002, 2003, 2004, 2005 Richard Smith <richard@ex-parrot.com>

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# $Id: Makefile.am,v 1.12 2005/01/31 17:51:00 ras52 Exp $

MAINTAINERCLEANFILES = Makefile.in

bin_PROGRAMS = gsiril

AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/apps/utils

gsiril_LDADD = $(top_builddir)/apps/utils/libstuff.a \
$(top_builddir)/ringing/libringing.la @READLINE_LIBS@

if USE_READLINE
additional =  rlstream.cpp rlstream.h
endif

gsiril_SOURCES = main.cpp console_stream.cpp console_stream.h \
execution_context.cpp execution_context.h expr_base.cpp expr_base.h \
proof_context.cpp proof_context.h symbol_table.cpp symbol_table.h \
expression.h expression.cpp statement.h statement.cpp \
parser.cpp parser.h util.cpp util.h prog_args.h $(additional)

EXTRA_gsiril_SOURCES = rlstream.cpp rlstream.h

# When gsiril is run under the name msiril, it automatically
# runs in MicroSiril compatibility mode.  Create a symlink to 
# assist in this.
install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(RM) msiril && $(LN_S) gsiril msiril

uninstall-hook:
	cd $(DESTDIR)$(bindir) && $(RM) gsiril msiril
