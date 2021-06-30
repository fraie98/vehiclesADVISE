OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lsimMain
MAINLIB_debug=-lsimMain_debug
SIMLIB=sim
SIMLIB_debug=sim_debug
SIMLIB_trace=sim_trace
PROJECTLIBS=-lrangeStudyRangeStudy -lRewardPV -ladvise_treeADVISE 
PROJECTLIBS_debug=-lrangeStudyRangeStudy_debug -lRewardPV_debug -ladvise_treeADVISE_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lADVISE -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lADVISE_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
simSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=simSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
simSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=simSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
simSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=simSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/advise_tree/ && $(MAKE) clean
	cd ../../Reward/Reward/ && $(MAKE) clean
	cd ../../Study/rangeStudy/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[advise_tree]"
	cd ../../Atomic/advise_tree/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[Reward]"
	cd ../../Reward/Reward/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[rangeStudy]"
	cd ../../Study/rangeStudy/ && $(MAKE) $(@F)


