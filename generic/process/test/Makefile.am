bin_PROGRAMS = messageConsumer 
AM_CXXFLAGS = $(INTI_CFLAGS) \
				-Wall \
				-g 

AM_CPPFLAGS = \
	-I../lib/inc \
	-I../inc


messageConsumer_SOURCES = \
				messageConsumer.cpp
messageConsumer_LDADD = $(INTI_LIBS) \
				../lib/src/libGenProcess.a \
				../../common/src/libGenCommon.a \
				-lrt \
				-lpthread
