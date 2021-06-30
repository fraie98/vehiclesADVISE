OBJS=RewardPVNodes.o RewardPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRewardPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRewardPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRewardPV.a: FORCE
	$(MAKE) lib TARGET=libRewardPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRewardPV_debug.a: FORCE
	$(MAKE) lib TARGET=libRewardPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

