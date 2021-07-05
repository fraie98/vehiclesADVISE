#ifndef _REWARD_PVS_
#define _REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class RewardPV0Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV0Worker();
  ~RewardPV0Worker();
  double Reward_Function();
};

class RewardPV0:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV0Worker *RewardPV0WorkerList;

  RewardPV0(int timeindex=0);
  ~RewardPV0();
  void CreateWorkerList(void);
};

class RewardPV1Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV1Worker();
  ~RewardPV1Worker();
  double Reward_Function();
};

class RewardPV1:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV1Worker *RewardPV1WorkerList;

  RewardPV1(int timeindex=0);
  ~RewardPV1();
  void CreateWorkerList(void);
};

class RewardPV2Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV2Worker();
  ~RewardPV2Worker();
  double Reward_Function();
};

class RewardPV2:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV2Worker *RewardPV2WorkerList;

  RewardPV2(int timeindex=0);
  ~RewardPV2();
  void CreateWorkerList(void);
};

class RewardPV3Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV3Worker();
  ~RewardPV3Worker();
  double Reward_Function();
};

class RewardPV3:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV3Worker *RewardPV3WorkerList;

  RewardPV3(int timeindex=0);
  ~RewardPV3();
  void CreateWorkerList(void);
};

class RewardPV4Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV4Worker();
  ~RewardPV4Worker();
  double Reward_Function();
};

class RewardPV4:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV4Worker *RewardPV4WorkerList;

  RewardPV4(int timeindex=0);
  ~RewardPV4();
  void CreateWorkerList(void);
};

class RewardPV5Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV5Worker();
  ~RewardPV5Worker();
  double Reward_Function();
};

class RewardPV5:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV5Worker *RewardPV5WorkerList;

  RewardPV5(int timeindex=0);
  ~RewardPV5();
  void CreateWorkerList(void);
};

class RewardPV6Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV6Worker();
  ~RewardPV6Worker();
  double Reward_Function();
};

class RewardPV6:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV6Worker *RewardPV6WorkerList;

  RewardPV6(int timeindex=0);
  ~RewardPV6();
  void CreateWorkerList(void);
};

class RewardPV7Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV7Worker();
  ~RewardPV7Worker();
  double Reward_Function();
};

class RewardPV7:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV7Worker *RewardPV7WorkerList;

  RewardPV7(int timeindex=0);
  ~RewardPV7();
  void CreateWorkerList(void);
};

class RewardPV8Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV8Worker();
  ~RewardPV8Worker();
  double Reward_Function();
};

class RewardPV8:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV8Worker *RewardPV8WorkerList;

  RewardPV8(int timeindex=0);
  ~RewardPV8();
  void CreateWorkerList(void);
};

class RewardPV9Worker:public InstantOfTime
{
 public:
  advise_treeADVISE *advise_tree;
  
  RewardPV9Worker();
  ~RewardPV9Worker();
  double Reward_Function();
};

class RewardPV9:public PerformanceVariableNode
{
 public:
  advise_treeADVISE *Theadvise_treeADVISE;

  RewardPV9Worker *RewardPV9WorkerList;

  RewardPV9(int timeindex=0);
  ~RewardPV9();
  void CreateWorkerList(void);
};

#endif
