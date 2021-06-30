#include "RewardPVModel.h"

RewardPVModel::RewardPVModel(bool expandTimeArrays) {
  TheModel=new advise_treeADVISE();
  DefineName("RewardPVModel");
  CreatePVList(6, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* RewardPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new RewardPV0(timeindex);
    break;
  case 1:
    return new RewardPV1(timeindex);
    break;
  case 2:
    return new RewardPV2(timeindex);
    break;
  case 3:
    return new RewardPV3(timeindex);
    break;
  case 4:
    return new RewardPV4(timeindex);
    break;
  case 5:
    return new RewardPV5(timeindex);
    break;
  }
  return NULL;
}
