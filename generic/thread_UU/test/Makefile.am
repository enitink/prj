bin_PROGRAMS = threadMain 
AM_CXXFLAGS = $(INTI_CFLAGS) \
				-Wall \
				-g 

INCLUDES = \
	-I../inc \
	-I../../common/inc

threadMain_SOURCES= \
				threadMain.cpp
threadMain_LDADD= $(INTI_LIBS) \
				../src/libGenThread.a \
				-lpthread
