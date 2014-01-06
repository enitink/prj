bin_PROGRAMS = messageConsumer 
AM_CXXFLAGS = $(INTI_CFLAGS) \
				-Wall \
				-g 

INCLUDES = \
	-I../inc \
	-I../../common/inc


messageConsumer_SOURCES = \
				messageConsumer.cpp
messageConsumer_LDADD = $(INTI_LIBS) \
				../src/libGenProcess.a \
				../../common/src/libGenCommon.a \
				-lrt
