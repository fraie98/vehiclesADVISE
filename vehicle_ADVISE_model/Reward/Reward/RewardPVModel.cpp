#include "RewardPVModel.h"

RewardPVModel::RewardPVModel(bool expandTimeArrays) {
  TheModel=new advise_treeADVISE();
  DefineName("RewardPVModel");
  CreatePVList(13, expandTimeArrays);
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
  case 6:
    return new RewardPV6(timeindex);
    break;
  case 7:
    return new RewardPV7(timeindex);
    break;
  case 8:
    return new RewardPV8(timeindex);
    break;
  case 9:
    return new RewardPV9(timeindex);
    break;
  case 10:
    return new RewardPV10(timeindex);
    break;
  case 11:
    return new RewardPV11(timeindex);
    break;
  case 12:
    return new RewardPV12(timeindex);
    break;
  }
  return NULL;
}
