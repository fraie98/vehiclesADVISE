OBJS=rangeStudyRangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/librangeStudyRangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/librangeStudyRangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/librangeStudyRangeStudy.a: FORCE
	$(MAKE) lib TARGET=librangeStudyRangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/librangeStudyRangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=librangeStudyRangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

