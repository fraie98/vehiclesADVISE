#ifndef _REWARD_PVMODEL_
#define _REWARD_PVMODEL_
#include "RewardPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/advise_tree/advise_treeADVISE.h"
class RewardPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  RewardPVModel(bool expandtimepoints);
};

#endif
