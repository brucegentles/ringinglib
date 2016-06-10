## Process this file with automake to produce Makefile.in

MAINTAINERCLEANFILES = Makefile.in
AM_CPPFLAGS = -I$(top_srcdir)

noinst_PROGRAMS = test

TESTS = test

LDADD = $(top_builddir)/ringing/libringing.la

test_SOURCES = test-main.cpp test-base.cpp test-base.h \
	change-test.cpp row-test.cpp method-test.cpp music-test.cpp
