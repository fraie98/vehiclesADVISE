OBJS=advise_treeADVISE.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libadvise_treeADVISE.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libadvise_treeADVISE_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libadvise_treeADVISE.a: FORCE
	$(MAKE) lib TARGET=libadvise_treeADVISE.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libadvise_treeADVISE_debug.a: FORCE
	$(MAKE) lib TARGET=libadvise_treeADVISE_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

