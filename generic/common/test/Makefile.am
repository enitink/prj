bin_PROGRAMS = gBigIntegerMain
AM_CXXFLAGS = $(INTI_CFLAGS) \
				-Wall \
				-g 

AM_CPPFLAGS = \
	-I../inc \
	-I../../common/inc

gBigIntegerMain_SOURCES= \
			gBigIntegerMain.cpp
gBigIntegerMain_LDADD= $(INTI_LIBS) \
			../src/libGenCommon.a
