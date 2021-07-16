
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


advise_treeADVISE::advise_treeADVISE() {
  ExploitAD.setParent(this);
  DoNothingAD.setParent(this);
  QueryFloodingAD.setParent(this);
  PrivilegeEscalationAD.setParent(this);
  UnauthorizedRemoteLoginAD.setParent(this);
  NetworkAttackAD.setParent(this);
  MalwareIntroductionAD.setParent(this);
  PivotingAD.setParent(this);
  DatabaseDumpAD.setParent(this);
  TamperingAD.setParent(this);
  PortScanAD.setParent(this);
  FirmwareReversingAD.setParent(this);
  WebIntrusionAD.setParent(this);
  ExploitFailure.setParent(this);
  ExploitSuccess.setParent(this);
  DoNothingOutcome1.setParent(this);
  QueryFloodingFailure.setParent(this);
  QueryFloodingSuccess.setParent(this);
  PrivilegeEscalationfaliure.setParent(this);
  PrivilegeEscalationsuccess.setParent(this);
  UnauthorizedRemoteLoginFaliure.setParent(this);
  UnauthorizedRemoteLoginSuccess.setParent(this);
  NetworkAttackfailure.setParent(this);
  NetworkAttacksuccess.setParent(this);
  MalwareIntroductionfailure.setParent(this);
  MalwareIntroductionsuccess.setParent(this);
  Pivotingfaliure.setParent(this);
  Pivotingsuccess.setParent(this);
  DatabaseDumpFailure.setParent(this);
  DatabaseDumpSuccess.setParent(this);
  TamperingFailure.setParent(this);
  TamperingSuccess.setParent(this);
  PortScanFailure.setParent(this);
  PortScanSuccess.setParent(this);
  FirmwareReversingFailure.setParent(this);
  FirmwareReversingObtainall.setParent(this);
  FirmwareReversingObtainaddressonly.setParent(this);
  WebIntrusionFaliure.setParent(this);
  WebIntrusionSuccess.setParent(this);
  ExploitGroup.initialize(2, "ExploitGroup");
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitFailure);
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitSuccess);

  QueryFloodingGroup.initialize(2, "QueryFloodingGroup");
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingFailure);
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingSuccess);

  PrivilegeEscalationGroup.initialize(2, "PrivilegeEscalationGroup");
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationfaliure);
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationsuccess);

  UnauthorizedRemoteLoginGroup.initialize(2, "UnauthorizedRemoteLoginGroup");
  UnauthorizedRemoteLoginGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginFaliure);
  UnauthorizedRemoteLoginGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginSuccess);

  NetworkAttackGroup.initialize(2, "NetworkAttackGroup");
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttackfailure);
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttacksuccess);

  MalwareIntroductionGroup.initialize(2, "MalwareIntroductionGroup");
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionfailure);
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionsuccess);

  PivotingGroup.initialize(2, "PivotingGroup");
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingfaliure);
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingsuccess);

  DatabaseDumpGroup.initialize(2, "DatabaseDumpGroup");
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpFailure);
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpSuccess);

  TamperingGroup.initialize(2, "TamperingGroup");
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingFailure);
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingSuccess);

  PortScanGroup.initialize(2, "PortScanGroup");
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanFailure);
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanSuccess);

  FirmwareReversingGroup.initialize(3, "FirmwareReversingGroup");
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingFailure);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainall);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainaddressonly);

  WebIntrusionGroup.initialize(2, "WebIntrusionGroup");
  WebIntrusionGroup.appendGroup((BaseGroupClass*) &WebIntrusionFaliure);
  WebIntrusionGroup.appendGroup((BaseGroupClass*) &WebIntrusionSuccess);

  AdversaryDecisionGroup.initialize(13, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExploitAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &QueryFloodingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkAttackAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PivotingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DatabaseDumpAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &TamperingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PortScanAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &FirmwareReversingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &WebIntrusionAD);

  BaseADVISEAction* InitialActions[39] = {
    &ExploitAD, // 0
    &DoNothingAD, // 1
    &QueryFloodingAD, // 2
    &PrivilegeEscalationAD, // 3
    &UnauthorizedRemoteLoginAD, // 4
    &NetworkAttackAD, // 5
    &MalwareIntroductionAD, // 6
    &PivotingAD, // 7
    &DatabaseDumpAD, // 8
    &TamperingAD, // 9
    &PortScanAD, // 10
    &FirmwareReversingAD, // 11
    &WebIntrusionAD, // 12
    &ExploitFailure, // 13
    &ExploitSuccess, // 14
    &DoNothingOutcome1, // 15
    &QueryFloodingFailure, // 16
    &QueryFloodingSuccess, // 17
    &PrivilegeEscalationfaliure, // 18
    &PrivilegeEscalationsuccess, // 19
    &UnauthorizedRemoteLoginFaliure, // 20
    &UnauthorizedRemoteLoginSuccess, // 21
    &NetworkAttackfailure, // 22
    &NetworkAttacksuccess, // 23
    &MalwareIntroductionfailure, // 24
    &MalwareIntroductionsuccess, // 25
    &Pivotingfaliure, // 26
    &Pivotingsuccess, // 27
    &DatabaseDumpFailure, // 28
    &DatabaseDumpSuccess, // 29
    &TamperingFailure, // 30
    &TamperingSuccess, // 31
    &PortScanFailure, // 32
    &PortScanSuccess, // 33
    &FirmwareReversingFailure, // 34
    &FirmwareReversingObtainall, // 35
    &FirmwareReversingObtainaddressonly, // 36
    &WebIntrusionFaliure, // 37
    &WebIntrusionSuccess // 38
  };

  Step* InitialSteps[26] = {
      &ExploitFailure,
      &ExploitSuccess,
      &DoNothingOutcome1,
      &QueryFloodingFailure,
      &QueryFloodingSuccess,
      &PrivilegeEscalationfaliure,
      &PrivilegeEscalationsuccess,
      &UnauthorizedRemoteLoginFaliure,
      &UnauthorizedRemoteLoginSuccess,
      &NetworkAttackfailure,
      &NetworkAttacksuccess,
      &MalwareIntroductionfailure,
      &MalwareIntroductionsuccess,
      &Pivotingfaliure,
      &Pivotingsuccess,
      &DatabaseDumpFailure,
      &DatabaseDumpSuccess,
      &TamperingFailure,
      &TamperingSuccess,
      &PortScanFailure,
      &PortScanSuccess,
      &FirmwareReversingFailure,
      &FirmwareReversingObtainall,
      &FirmwareReversingObtainaddressonly,
      &WebIntrusionFaliure,
      &WebIntrusionSuccess
  };

  BaseGroupClass* InitialGroups[14] = {
    (BaseGroupClass*) &ExploitGroup, // 0
    (BaseGroupClass*) &DoNothingOutcome1, // 1
    (BaseGroupClass*) &QueryFloodingGroup, // 2
    (BaseGroupClass*) &PrivilegeEscalationGroup, // 3
    (BaseGroupClass*) &UnauthorizedRemoteLoginGroup, // 4
    (BaseGroupClass*) &NetworkAttackGroup, // 5
    (BaseGroupClass*) &MalwareIntroductionGroup, // 6
    (BaseGroupClass*) &PivotingGroup, // 7
    (BaseGroupClass*) &DatabaseDumpGroup, // 8
    (BaseGroupClass*) &TamperingGroup, // 9
    (BaseGroupClass*) &PortScanGroup, // 10
    (BaseGroupClass*) &FirmwareReversingGroup, // 11
    (BaseGroupClass*) &WebIntrusionGroup, // 12
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  VehicleServerRootAccess = new Access("VehicleServerRootAccess", 0);
  vehicleServerUnprivAccess = new Access("vehicleServerUnprivAccess", attacker=='I');
  PhysicalAccess = new Access("PhysicalAccess", attacker=='P');
  CorporateNetworkAccess = new Access("CorporateNetworkAccess", attacker=='I');
  SocketAddress = new Knowledge("SocketAddress", attacker=='I');
  BinaryDump = new Knowledge("BinaryDump", attacker=='H');
  VulnerabilityAwareness = new Knowledge("VulnerabilityAwareness", attacker=='I');
  CorporateServerLocation = new Knowledge("CorporateServerLocation", attacker=='I');
  CorporateInternetAddress = new Knowledge("CorporateInternetAddress", attacker=='I');
  EmoployeePersonalInfo = new Knowledge("EmoployeePersonalInfo", attacker=='I');
  HandshakeProtocol = new Knowledge("HandshakeProtocol", attacker=='I');
  ReverseEngineering = new Skill("ReverseEngineering", (attacker=='H')?5:0);
  Script = new Skill("Script", (attacker=='H')?7:0);
  DataBreach = new Goal("DataBreach", 0);
  DataBreach->setPayoff(150);
  VehicleUndesideredBehaviour = new Goal("VehicleUndesideredBehaviour", 0);
  VehicleUndesideredBehaviour->setPayoff(300);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(100);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  ExploitWeight = new StepWeight("ExploitWeight", 0);
  ExploitChosen = new StepChosen("ExploitChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  QueryFloodingWeight = new StepWeight("QueryFloodingWeight", 0);
  QueryFloodingChosen = new StepChosen("QueryFloodingChosen", 0);
  PrivilegeEscalationWeight = new StepWeight("PrivilegeEscalationWeight", 0);
  PrivilegeEscalationChosen = new StepChosen("PrivilegeEscalationChosen", 0);
  UnauthorizedRemoteLoginWeight = new StepWeight("UnauthorizedRemoteLoginWeight", 0);
  UnauthorizedRemoteLoginChosen = new StepChosen("UnauthorizedRemoteLoginChosen", 0);
  NetworkAttackWeight = new StepWeight("NetworkAttackWeight", 0);
  NetworkAttackChosen = new StepChosen("NetworkAttackChosen", 0);
  MalwareIntroductionWeight = new StepWeight("MalwareIntroductionWeight", 0);
  MalwareIntroductionChosen = new StepChosen("MalwareIntroductionChosen", 0);
  PivotingWeight = new StepWeight("PivotingWeight", 0);
  PivotingChosen = new StepChosen("PivotingChosen", 0);
  DatabaseDumpWeight = new StepWeight("DatabaseDumpWeight", 0);
  DatabaseDumpChosen = new StepChosen("DatabaseDumpChosen", 0);
  TamperingWeight = new StepWeight("TamperingWeight", 0);
  TamperingChosen = new StepChosen("TamperingChosen", 0);
  PortScanWeight = new StepWeight("PortScanWeight", 0);
  PortScanChosen = new StepChosen("PortScanChosen", 0);
  FirmwareReversingWeight = new StepWeight("FirmwareReversingWeight", 0);
  FirmwareReversingChosen = new StepChosen("FirmwareReversingChosen", 0);
  WebIntrusionWeight = new StepWeight("WebIntrusionWeight", 0);
  WebIntrusionChosen = new StepChosen("WebIntrusionChosen", 0);

  Goal* InitialGoals[3] = {
      DataBreach,
      VehicleUndesideredBehaviour,
      DoS
  };

  ADVISEStateVariable* InitialSVs[43] = {
    VehicleServerRootAccess, // 0
    vehicleServerUnprivAccess, // 1
    PhysicalAccess, // 2
    CorporateNetworkAccess, // 3
    SocketAddress, // 4
    BinaryDump, // 5
    VulnerabilityAwareness, // 6
    CorporateServerLocation, // 7
    CorporateInternetAddress, // 8
    EmoployeePersonalInfo, // 9
    HandshakeProtocol, // 10
    ReverseEngineering, // 11
    Script, // 12
    DataBreach, // 13
    VehicleUndesideredBehaviour, // 14
    DoS, // 15
    ExploitChosen, // 16
    DoNothingChosen, // 17
    QueryFloodingChosen, // 18
    PrivilegeEscalationChosen, // 19
    UnauthorizedRemoteLoginChosen, // 20
    NetworkAttackChosen, // 21
    MalwareIntroductionChosen, // 22
    PivotingChosen, // 23
    DatabaseDumpChosen, // 24
    TamperingChosen, // 25
    PortScanChosen, // 26
    FirmwareReversingChosen, // 27
    WebIntrusionChosen, // 28
    ExploitWeight, // 29
    DoNothingWeight, // 30
    QueryFloodingWeight, // 31
    PrivilegeEscalationWeight, // 32
    UnauthorizedRemoteLoginWeight, // 33
    NetworkAttackWeight, // 34
    MalwareIntroductionWeight, // 35
    PivotingWeight, // 36
    DatabaseDumpWeight, // 37
    TamperingWeight, // 38
    PortScanWeight, // 39
    FirmwareReversingWeight, // 40
    WebIntrusionWeight, // 41
    MakeDecision // 42
};

  int outCounts[13] = { 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2 };

  commonInit("advise_tree", 43, InitialSVs, 39, InitialActions, 14, InitialGroups, 13, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = (attacker=='H')?0.1:(attacker=='I')?0.1:(attacker=='P')?0.2:0;
  advDetectPref = (attacker=='H')?0.1:(attacker=='I')?0.4:(attacker=='P')?0.3:0;
  advPayPref = (attacker=='H')?0.8:(attacker=='I')?0.5:(attacker=='P')?0.5:0;

  planningHorizon = 4;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[484][2] = {
    {42,0}, {16,0}, {29,0}, {42,1}, {17,1}, {30,1}, {42,2}, {18,2}, 
    {31,2}, {42,3}, {19,3}, {32,3}, {42,4}, {20,4}, {33,4}, {42,5}, 
    {21,5}, {34,5}, {42,6}, {22,6}, {35,6}, {42,7}, {23,7}, {36,7}, 
    {42,8}, {24,8}, {37,8}, {42,9}, {25,9}, {38,9}, {42,10}, {26,10}, 
    {39,10}, {42,11}, {27,11}, {40,11}, {42,12}, {28,12}, {41,12}, {42,13}, 
    {16,13}, {29,13}, {30,13}, {31,13}, {32,13}, {33,13}, {34,13}, {35,13}, 
    {36,13}, {37,13}, {38,13}, {39,13}, {40,13}, {41,13}, {0,13}, {6,13}, 
    {42,14}, {16,14}, {29,14}, {30,14}, {31,14}, {32,14}, {33,14}, {34,14}, 
    {35,14}, {36,14}, {37,14}, {38,14}, {39,14}, {40,14}, {41,14}, {0,14}, 
    {6,14}, {42,15}, {17,15}, {29,15}, {30,15}, {31,15}, {32,15}, {33,15}, 
    {34,15}, {35,15}, {36,15}, {37,15}, {38,15}, {39,15}, {40,15}, {41,15}, 
    {42,16}, {18,16}, {29,16}, {30,16}, {31,16}, {32,16}, {33,16}, {34,16}, 
    {35,16}, {36,16}, {37,16}, {38,16}, {39,16}, {40,16}, {41,16}, {15,16}, 
    {10,16}, {4,16}, {42,17}, {18,17}, {29,17}, {30,17}, {31,17}, {32,17}, 
    {33,17}, {34,17}, {35,17}, {36,17}, {37,17}, {38,17}, {39,17}, {40,17}, 
    {41,17}, {15,17}, {10,17}, {4,17}, {42,18}, {19,18}, {29,18}, {30,18}, 
    {31,18}, {32,18}, {33,18}, {34,18}, {35,18}, {36,18}, {37,18}, {38,18}, 
    {39,18}, {40,18}, {41,18}, {0,18}, {1,18}, {42,19}, {19,19}, {29,19}, 
    {30,19}, {31,19}, {32,19}, {33,19}, {34,19}, {35,19}, {36,19}, {37,19}, 
    {38,19}, {39,19}, {40,19}, {41,19}, {0,19}, {1,19}, {42,20}, {20,20}, 
    {29,20}, {30,20}, {31,20}, {32,20}, {33,20}, {34,20}, {35,20}, {36,20}, 
    {37,20}, {38,20}, {39,20}, {40,20}, {41,20}, {3,20}, {9,20}, {42,21}, 
    {20,21}, {29,21}, {30,21}, {31,21}, {32,21}, {33,21}, {34,21}, {35,21}, 
    {36,21}, {37,21}, {38,21}, {39,21}, {40,21}, {41,21}, {3,21}, {9,21}, 
    {42,22}, {21,22}, {29,22}, {30,22}, {31,22}, {32,22}, {33,22}, {34,22}, 
    {35,22}, {36,22}, {37,22}, {38,22}, {39,22}, {40,22}, {41,22}, {3,22}, 
    {7,22}, {42,23}, {21,23}, {29,23}, {30,23}, {31,23}, {32,23}, {33,23}, 
    {34,23}, {35,23}, {36,23}, {37,23}, {38,23}, {39,23}, {40,23}, {41,23}, 
    {3,23}, {7,23}, {42,24}, {22,24}, {29,24}, {30,24}, {31,24}, {32,24}, 
    {33,24}, {34,24}, {35,24}, {36,24}, {37,24}, {38,24}, {39,24}, {40,24}, 
    {41,24}, {1,24}, {2,24}, {42,25}, {22,25}, {29,25}, {30,25}, {31,25}, 
    {32,25}, {33,25}, {34,25}, {35,25}, {36,25}, {37,25}, {38,25}, {39,25}, 
    {40,25}, {41,25}, {1,25}, {2,25}, {42,26}, {23,26}, {29,26}, {30,26}, 
    {31,26}, {32,26}, {33,26}, {34,26}, {35,26}, {36,26}, {37,26}, {38,26}, 
    {39,26}, {40,26}, {41,26}, {1,26}, {3,26}, {42,27}, {23,27}, {29,27}, 
    {30,27}, {31,27}, {32,27}, {33,27}, {34,27}, {35,27}, {36,27}, {37,27}, 
    {38,27}, {39,27}, {40,27}, {41,27}, {1,27}, {3,27}, {42,28}, {24,28}, 
    {29,28}, {30,28}, {31,28}, {32,28}, {33,28}, {34,28}, {35,28}, {36,28}, 
    {37,28}, {38,28}, {39,28}, {40,28}, {41,28}, {13,28}, {0,28}, {42,29}, 
    {24,29}, {29,29}, {30,29}, {31,29}, {32,29}, {33,29}, {34,29}, {35,29}, 
    {36,29}, {37,29}, {38,29}, {39,29}, {40,29}, {41,29}, {13,29}, {0,29}, 
    {42,30}, {25,30}, {29,30}, {30,30}, {31,30}, {32,30}, {33,30}, {34,30}, 
    {35,30}, {36,30}, {37,30}, {38,30}, {39,30}, {40,30}, {41,30}, {14,30}, 
    {0,30}, {42,31}, {25,31}, {29,31}, {30,31}, {31,31}, {32,31}, {33,31}, 
    {34,31}, {35,31}, {36,31}, {37,31}, {38,31}, {39,31}, {40,31}, {41,31}, 
    {14,31}, {0,31}, {42,32}, {26,32}, {29,32}, {30,32}, {31,32}, {32,32}, 
    {33,32}, {34,32}, {35,32}, {36,32}, {37,32}, {38,32}, {39,32}, {40,32}, 
    {41,32}, {6,32}, {4,32}, {42,33}, {26,33}, {29,33}, {30,33}, {31,33}, 
    {32,33}, {33,33}, {34,33}, {35,33}, {36,33}, {37,33}, {38,33}, {39,33}, 
    {40,33}, {41,33}, {6,33}, {4,33}, {42,34}, {27,34}, {29,34}, {30,34}, 
    {31,34}, {32,34}, {33,34}, {34,34}, {35,34}, {36,34}, {37,34}, {38,34}, 
    {39,34}, {40,34}, {41,34}, {10,34}, {4,34}, {5,34}, {42,35}, {27,35}, 
    {29,35}, {30,35}, {31,35}, {32,35}, {33,35}, {34,35}, {35,35}, {36,35}, 
    {37,35}, {38,35}, {39,35}, {40,35}, {41,35}, {10,35}, {4,35}, {5,35}, 
    {42,36}, {27,36}, {29,36}, {30,36}, {31,36}, {32,36}, {33,36}, {34,36}, 
    {35,36}, {36,36}, {37,36}, {38,36}, {39,36}, {40,36}, {41,36}, {10,36}, 
    {4,36}, {5,36}, {42,37}, {28,37}, {29,37}, {30,37}, {31,37}, {32,37}, 
    {33,37}, {34,37}, {35,37}, {36,37}, {37,37}, {38,37}, {39,37}, {40,37}, 
    {41,37}, {3,37}, {8,37}, {42,38}, {28,38}, {29,38}, {30,38}, {31,38}, 
    {32,38}, {33,38}, {34,38}, {35,38}, {36,38}, {37,38}, {38,38}, {39,38}, 
    {40,38}, {41,38}, {3,38}, {8,38}
};
  for(int n = 0; n < 484;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[67][2] = {
    {42,0}, {42,1}, {42,2}, {42,3}, {42,4}, {42,5}, {42,6}, {42,7}, 
    {42,8}, {42,9}, {42,10}, {42,11}, {42,12}, {16,13}, {0,13}, {16,14}, 
    {0,14}, {17,15}, {18,16}, {15,16}, {18,17}, {15,17}, {19,18}, {0,18}, 
    {19,19}, {0,19}, {20,20}, {3,20}, {20,21}, {3,21}, {21,22}, {3,22}, 
    {21,23}, {3,23}, {22,24}, {1,24}, {22,25}, {1,25}, {23,26}, {1,26}, 
    {23,27}, {1,27}, {24,28}, {13,28}, {24,29}, {13,29}, {25,30}, {14,30}, 
    {25,31}, {14,31}, {26,32}, {6,32}, {26,33}, {6,33}, {27,34}, {10,34}, 
    {4,34}, {27,35}, {10,35}, {4,35}, {27,36}, {10,36}, {4,36}, {28,37}, 
    {3,37}, {28,38}, {3,38}
};
  for(int n = 0; n < 67;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 39; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

advise_treeADVISE::~advise_treeADVISE() {
}

void advise_treeADVISE::assignSVsToAttackSteps() {
  ExploitFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitFailure.ExploitChosen = ExploitChosen;
  ExploitFailure.ExploitWeight = ExploitWeight;
  ExploitFailure.DoNothingWeight = DoNothingWeight;
  ExploitFailure.QueryFloodingWeight = QueryFloodingWeight;
  ExploitFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  ExploitFailure.NetworkAttackWeight = NetworkAttackWeight;
  ExploitFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitFailure.PivotingWeight = PivotingWeight;
  ExploitFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitFailure.TamperingWeight = TamperingWeight;
  ExploitFailure.PortScanWeight = PortScanWeight;
  ExploitFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitFailure.WebIntrusionWeight = WebIntrusionWeight;
  ExploitFailure.MakeDecision = MakeDecision;
  ExploitFailure.setSVs(ExploitChosen, ExploitWeight);
  ExploitSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitSuccess.ExploitChosen = ExploitChosen;
  ExploitSuccess.ExploitWeight = ExploitWeight;
  ExploitSuccess.DoNothingWeight = DoNothingWeight;
  ExploitSuccess.QueryFloodingWeight = QueryFloodingWeight;
  ExploitSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  ExploitSuccess.NetworkAttackWeight = NetworkAttackWeight;
  ExploitSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitSuccess.PivotingWeight = PivotingWeight;
  ExploitSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitSuccess.TamperingWeight = TamperingWeight;
  ExploitSuccess.PortScanWeight = PortScanWeight;
  ExploitSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitSuccess.WebIntrusionWeight = WebIntrusionWeight;
  ExploitSuccess.MakeDecision = MakeDecision;
  ExploitSuccess.setSVs(ExploitChosen, ExploitWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.ExploitWeight = ExploitWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingOutcome1.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DoNothingOutcome1.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DoNothingOutcome1.NetworkAttackWeight = NetworkAttackWeight;
  DoNothingOutcome1.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DoNothingOutcome1.PivotingWeight = PivotingWeight;
  DoNothingOutcome1.DatabaseDumpWeight = DatabaseDumpWeight;
  DoNothingOutcome1.TamperingWeight = TamperingWeight;
  DoNothingOutcome1.PortScanWeight = PortScanWeight;
  DoNothingOutcome1.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingOutcome1.WebIntrusionWeight = WebIntrusionWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  QueryFloodingFailure.DoS = DoS;
  QueryFloodingFailure.Script = Script;
  QueryFloodingFailure.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingFailure.SocketAddress = SocketAddress;
  QueryFloodingFailure.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingFailure.ExploitWeight = ExploitWeight;
  QueryFloodingFailure.DoNothingWeight = DoNothingWeight;
  QueryFloodingFailure.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  QueryFloodingFailure.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingFailure.PivotingWeight = PivotingWeight;
  QueryFloodingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingFailure.TamperingWeight = TamperingWeight;
  QueryFloodingFailure.PortScanWeight = PortScanWeight;
  QueryFloodingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingFailure.WebIntrusionWeight = WebIntrusionWeight;
  QueryFloodingFailure.MakeDecision = MakeDecision;
  QueryFloodingFailure.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  QueryFloodingSuccess.DoS = DoS;
  QueryFloodingSuccess.Script = Script;
  QueryFloodingSuccess.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingSuccess.SocketAddress = SocketAddress;
  QueryFloodingSuccess.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingSuccess.ExploitWeight = ExploitWeight;
  QueryFloodingSuccess.DoNothingWeight = DoNothingWeight;
  QueryFloodingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  QueryFloodingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingSuccess.PivotingWeight = PivotingWeight;
  QueryFloodingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingSuccess.TamperingWeight = TamperingWeight;
  QueryFloodingSuccess.PortScanWeight = PortScanWeight;
  QueryFloodingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingSuccess.WebIntrusionWeight = WebIntrusionWeight;
  QueryFloodingSuccess.MakeDecision = MakeDecision;
  QueryFloodingSuccess.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  PrivilegeEscalationfaliure.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationfaliure.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationfaliure.ExploitWeight = ExploitWeight;
  PrivilegeEscalationfaliure.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationfaliure.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PrivilegeEscalationfaliure.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationfaliure.PivotingWeight = PivotingWeight;
  PrivilegeEscalationfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationfaliure.TamperingWeight = TamperingWeight;
  PrivilegeEscalationfaliure.PortScanWeight = PortScanWeight;
  PrivilegeEscalationfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationfaliure.WebIntrusionWeight = WebIntrusionWeight;
  PrivilegeEscalationfaliure.MakeDecision = MakeDecision;
  PrivilegeEscalationfaliure.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);
  PrivilegeEscalationsuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationsuccess.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationsuccess.ExploitWeight = ExploitWeight;
  PrivilegeEscalationsuccess.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationsuccess.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PrivilegeEscalationsuccess.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationsuccess.PivotingWeight = PivotingWeight;
  PrivilegeEscalationsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationsuccess.TamperingWeight = TamperingWeight;
  PrivilegeEscalationsuccess.PortScanWeight = PortScanWeight;
  PrivilegeEscalationsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationsuccess.WebIntrusionWeight = WebIntrusionWeight;
  PrivilegeEscalationsuccess.MakeDecision = MakeDecision;
  PrivilegeEscalationsuccess.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);
  UnauthorizedRemoteLoginFaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  UnauthorizedRemoteLoginFaliure.EmoployeePersonalInfo = EmoployeePersonalInfo;
  UnauthorizedRemoteLoginFaliure.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginFaliure.ExploitWeight = ExploitWeight;
  UnauthorizedRemoteLoginFaliure.DoNothingWeight = DoNothingWeight;
  UnauthorizedRemoteLoginFaliure.QueryFloodingWeight = QueryFloodingWeight;
  UnauthorizedRemoteLoginFaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  UnauthorizedRemoteLoginFaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  UnauthorizedRemoteLoginFaliure.NetworkAttackWeight = NetworkAttackWeight;
  UnauthorizedRemoteLoginFaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  UnauthorizedRemoteLoginFaliure.PivotingWeight = PivotingWeight;
  UnauthorizedRemoteLoginFaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  UnauthorizedRemoteLoginFaliure.TamperingWeight = TamperingWeight;
  UnauthorizedRemoteLoginFaliure.PortScanWeight = PortScanWeight;
  UnauthorizedRemoteLoginFaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  UnauthorizedRemoteLoginFaliure.WebIntrusionWeight = WebIntrusionWeight;
  UnauthorizedRemoteLoginFaliure.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginFaliure.setSVs(UnauthorizedRemoteLoginChosen, UnauthorizedRemoteLoginWeight);
  UnauthorizedRemoteLoginSuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  UnauthorizedRemoteLoginSuccess.EmoployeePersonalInfo = EmoployeePersonalInfo;
  UnauthorizedRemoteLoginSuccess.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginSuccess.ExploitWeight = ExploitWeight;
  UnauthorizedRemoteLoginSuccess.DoNothingWeight = DoNothingWeight;
  UnauthorizedRemoteLoginSuccess.QueryFloodingWeight = QueryFloodingWeight;
  UnauthorizedRemoteLoginSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  UnauthorizedRemoteLoginSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  UnauthorizedRemoteLoginSuccess.NetworkAttackWeight = NetworkAttackWeight;
  UnauthorizedRemoteLoginSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  UnauthorizedRemoteLoginSuccess.PivotingWeight = PivotingWeight;
  UnauthorizedRemoteLoginSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  UnauthorizedRemoteLoginSuccess.TamperingWeight = TamperingWeight;
  UnauthorizedRemoteLoginSuccess.PortScanWeight = PortScanWeight;
  UnauthorizedRemoteLoginSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  UnauthorizedRemoteLoginSuccess.WebIntrusionWeight = WebIntrusionWeight;
  UnauthorizedRemoteLoginSuccess.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginSuccess.setSVs(UnauthorizedRemoteLoginChosen, UnauthorizedRemoteLoginWeight);
  NetworkAttackfailure.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttackfailure.CorporateServerLocation = CorporateServerLocation;
  NetworkAttackfailure.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackfailure.ExploitWeight = ExploitWeight;
  NetworkAttackfailure.DoNothingWeight = DoNothingWeight;
  NetworkAttackfailure.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttackfailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttackfailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  NetworkAttackfailure.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttackfailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttackfailure.PivotingWeight = PivotingWeight;
  NetworkAttackfailure.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttackfailure.TamperingWeight = TamperingWeight;
  NetworkAttackfailure.PortScanWeight = PortScanWeight;
  NetworkAttackfailure.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttackfailure.WebIntrusionWeight = WebIntrusionWeight;
  NetworkAttackfailure.MakeDecision = MakeDecision;
  NetworkAttackfailure.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  NetworkAttacksuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttacksuccess.CorporateServerLocation = CorporateServerLocation;
  NetworkAttacksuccess.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttacksuccess.ExploitWeight = ExploitWeight;
  NetworkAttacksuccess.DoNothingWeight = DoNothingWeight;
  NetworkAttacksuccess.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttacksuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttacksuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  NetworkAttacksuccess.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttacksuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttacksuccess.PivotingWeight = PivotingWeight;
  NetworkAttacksuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttacksuccess.TamperingWeight = TamperingWeight;
  NetworkAttacksuccess.PortScanWeight = PortScanWeight;
  NetworkAttacksuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttacksuccess.WebIntrusionWeight = WebIntrusionWeight;
  NetworkAttacksuccess.MakeDecision = MakeDecision;
  NetworkAttacksuccess.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  MalwareIntroductionfailure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionfailure.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionfailure.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionfailure.ExploitWeight = ExploitWeight;
  MalwareIntroductionfailure.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionfailure.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionfailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionfailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  MalwareIntroductionfailure.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionfailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionfailure.PivotingWeight = PivotingWeight;
  MalwareIntroductionfailure.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionfailure.TamperingWeight = TamperingWeight;
  MalwareIntroductionfailure.PortScanWeight = PortScanWeight;
  MalwareIntroductionfailure.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionfailure.WebIntrusionWeight = WebIntrusionWeight;
  MalwareIntroductionfailure.MakeDecision = MakeDecision;
  MalwareIntroductionfailure.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  MalwareIntroductionsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionsuccess.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionsuccess.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionsuccess.ExploitWeight = ExploitWeight;
  MalwareIntroductionsuccess.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionsuccess.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  MalwareIntroductionsuccess.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionsuccess.PivotingWeight = PivotingWeight;
  MalwareIntroductionsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionsuccess.TamperingWeight = TamperingWeight;
  MalwareIntroductionsuccess.PortScanWeight = PortScanWeight;
  MalwareIntroductionsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionsuccess.WebIntrusionWeight = WebIntrusionWeight;
  MalwareIntroductionsuccess.MakeDecision = MakeDecision;
  MalwareIntroductionsuccess.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  Pivotingfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingfaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingfaliure.PivotingChosen = PivotingChosen;
  Pivotingfaliure.ExploitWeight = ExploitWeight;
  Pivotingfaliure.DoNothingWeight = DoNothingWeight;
  Pivotingfaliure.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  Pivotingfaliure.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingfaliure.PivotingWeight = PivotingWeight;
  Pivotingfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingfaliure.TamperingWeight = TamperingWeight;
  Pivotingfaliure.PortScanWeight = PortScanWeight;
  Pivotingfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingfaliure.WebIntrusionWeight = WebIntrusionWeight;
  Pivotingfaliure.MakeDecision = MakeDecision;
  Pivotingfaliure.setSVs(PivotingChosen, PivotingWeight);
  Pivotingsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingsuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingsuccess.PivotingChosen = PivotingChosen;
  Pivotingsuccess.ExploitWeight = ExploitWeight;
  Pivotingsuccess.DoNothingWeight = DoNothingWeight;
  Pivotingsuccess.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  Pivotingsuccess.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingsuccess.PivotingWeight = PivotingWeight;
  Pivotingsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingsuccess.TamperingWeight = TamperingWeight;
  Pivotingsuccess.PortScanWeight = PortScanWeight;
  Pivotingsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingsuccess.WebIntrusionWeight = WebIntrusionWeight;
  Pivotingsuccess.MakeDecision = MakeDecision;
  Pivotingsuccess.setSVs(PivotingChosen, PivotingWeight);
  DatabaseDumpFailure.DataBreach = DataBreach;
  DatabaseDumpFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpFailure.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpFailure.ExploitWeight = ExploitWeight;
  DatabaseDumpFailure.DoNothingWeight = DoNothingWeight;
  DatabaseDumpFailure.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DatabaseDumpFailure.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpFailure.PivotingWeight = PivotingWeight;
  DatabaseDumpFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpFailure.TamperingWeight = TamperingWeight;
  DatabaseDumpFailure.PortScanWeight = PortScanWeight;
  DatabaseDumpFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpFailure.WebIntrusionWeight = WebIntrusionWeight;
  DatabaseDumpFailure.MakeDecision = MakeDecision;
  DatabaseDumpFailure.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  DatabaseDumpSuccess.DataBreach = DataBreach;
  DatabaseDumpSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpSuccess.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpSuccess.ExploitWeight = ExploitWeight;
  DatabaseDumpSuccess.DoNothingWeight = DoNothingWeight;
  DatabaseDumpSuccess.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DatabaseDumpSuccess.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpSuccess.PivotingWeight = PivotingWeight;
  DatabaseDumpSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpSuccess.TamperingWeight = TamperingWeight;
  DatabaseDumpSuccess.PortScanWeight = PortScanWeight;
  DatabaseDumpSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpSuccess.WebIntrusionWeight = WebIntrusionWeight;
  DatabaseDumpSuccess.MakeDecision = MakeDecision;
  DatabaseDumpSuccess.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  TamperingFailure.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingFailure.TamperingChosen = TamperingChosen;
  TamperingFailure.ExploitWeight = ExploitWeight;
  TamperingFailure.DoNothingWeight = DoNothingWeight;
  TamperingFailure.QueryFloodingWeight = QueryFloodingWeight;
  TamperingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  TamperingFailure.NetworkAttackWeight = NetworkAttackWeight;
  TamperingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingFailure.PivotingWeight = PivotingWeight;
  TamperingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingFailure.TamperingWeight = TamperingWeight;
  TamperingFailure.PortScanWeight = PortScanWeight;
  TamperingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingFailure.WebIntrusionWeight = WebIntrusionWeight;
  TamperingFailure.MakeDecision = MakeDecision;
  TamperingFailure.setSVs(TamperingChosen, TamperingWeight);
  TamperingSuccess.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingSuccess.TamperingChosen = TamperingChosen;
  TamperingSuccess.ExploitWeight = ExploitWeight;
  TamperingSuccess.DoNothingWeight = DoNothingWeight;
  TamperingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  TamperingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  TamperingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  TamperingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingSuccess.PivotingWeight = PivotingWeight;
  TamperingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingSuccess.TamperingWeight = TamperingWeight;
  TamperingSuccess.PortScanWeight = PortScanWeight;
  TamperingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingSuccess.WebIntrusionWeight = WebIntrusionWeight;
  TamperingSuccess.MakeDecision = MakeDecision;
  TamperingSuccess.setSVs(TamperingChosen, TamperingWeight);
  PortScanFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanFailure.SocketAddress = SocketAddress;
  PortScanFailure.PortScanChosen = PortScanChosen;
  PortScanFailure.ExploitWeight = ExploitWeight;
  PortScanFailure.DoNothingWeight = DoNothingWeight;
  PortScanFailure.QueryFloodingWeight = QueryFloodingWeight;
  PortScanFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PortScanFailure.NetworkAttackWeight = NetworkAttackWeight;
  PortScanFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanFailure.PivotingWeight = PivotingWeight;
  PortScanFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanFailure.TamperingWeight = TamperingWeight;
  PortScanFailure.PortScanWeight = PortScanWeight;
  PortScanFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanFailure.WebIntrusionWeight = WebIntrusionWeight;
  PortScanFailure.MakeDecision = MakeDecision;
  PortScanFailure.setSVs(PortScanChosen, PortScanWeight);
  PortScanSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanSuccess.SocketAddress = SocketAddress;
  PortScanSuccess.PortScanChosen = PortScanChosen;
  PortScanSuccess.ExploitWeight = ExploitWeight;
  PortScanSuccess.DoNothingWeight = DoNothingWeight;
  PortScanSuccess.QueryFloodingWeight = QueryFloodingWeight;
  PortScanSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PortScanSuccess.NetworkAttackWeight = NetworkAttackWeight;
  PortScanSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanSuccess.PivotingWeight = PivotingWeight;
  PortScanSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanSuccess.TamperingWeight = TamperingWeight;
  PortScanSuccess.PortScanWeight = PortScanWeight;
  PortScanSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanSuccess.WebIntrusionWeight = WebIntrusionWeight;
  PortScanSuccess.MakeDecision = MakeDecision;
  PortScanSuccess.setSVs(PortScanChosen, PortScanWeight);
  FirmwareReversingFailure.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingFailure.SocketAddress = SocketAddress;
  FirmwareReversingFailure.BinaryDump = BinaryDump;
  FirmwareReversingFailure.ReverseEngineering = ReverseEngineering;
  FirmwareReversingFailure.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingFailure.ExploitWeight = ExploitWeight;
  FirmwareReversingFailure.DoNothingWeight = DoNothingWeight;
  FirmwareReversingFailure.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingFailure.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingFailure.PivotingWeight = PivotingWeight;
  FirmwareReversingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingFailure.TamperingWeight = TamperingWeight;
  FirmwareReversingFailure.PortScanWeight = PortScanWeight;
  FirmwareReversingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingFailure.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingFailure.MakeDecision = MakeDecision;
  FirmwareReversingFailure.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainall.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainall.SocketAddress = SocketAddress;
  FirmwareReversingObtainall.BinaryDump = BinaryDump;
  FirmwareReversingObtainall.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainall.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainall.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainall.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainall.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainall.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainall.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingObtainall.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainall.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainall.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainall.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainall.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainall.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainall.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainall.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingObtainall.MakeDecision = MakeDecision;
  FirmwareReversingObtainall.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainaddressonly.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainaddressonly.SocketAddress = SocketAddress;
  FirmwareReversingObtainaddressonly.BinaryDump = BinaryDump;
  FirmwareReversingObtainaddressonly.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainaddressonly.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainaddressonly.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainaddressonly.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainaddressonly.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainaddressonly.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainaddressonly.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingObtainaddressonly.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainaddressonly.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainaddressonly.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainaddressonly.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainaddressonly.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainaddressonly.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainaddressonly.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainaddressonly.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingObtainaddressonly.MakeDecision = MakeDecision;
  FirmwareReversingObtainaddressonly.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  WebIntrusionFaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  WebIntrusionFaliure.CorporateInternetAddress = CorporateInternetAddress;
  WebIntrusionFaliure.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionFaliure.ExploitWeight = ExploitWeight;
  WebIntrusionFaliure.DoNothingWeight = DoNothingWeight;
  WebIntrusionFaliure.QueryFloodingWeight = QueryFloodingWeight;
  WebIntrusionFaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  WebIntrusionFaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  WebIntrusionFaliure.NetworkAttackWeight = NetworkAttackWeight;
  WebIntrusionFaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  WebIntrusionFaliure.PivotingWeight = PivotingWeight;
  WebIntrusionFaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  WebIntrusionFaliure.TamperingWeight = TamperingWeight;
  WebIntrusionFaliure.PortScanWeight = PortScanWeight;
  WebIntrusionFaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  WebIntrusionFaliure.WebIntrusionWeight = WebIntrusionWeight;
  WebIntrusionFaliure.MakeDecision = MakeDecision;
  WebIntrusionFaliure.setSVs(WebIntrusionChosen, WebIntrusionWeight);
  WebIntrusionSuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  WebIntrusionSuccess.CorporateInternetAddress = CorporateInternetAddress;
  WebIntrusionSuccess.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionSuccess.ExploitWeight = ExploitWeight;
  WebIntrusionSuccess.DoNothingWeight = DoNothingWeight;
  WebIntrusionSuccess.QueryFloodingWeight = QueryFloodingWeight;
  WebIntrusionSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  WebIntrusionSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  WebIntrusionSuccess.NetworkAttackWeight = NetworkAttackWeight;
  WebIntrusionSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  WebIntrusionSuccess.PivotingWeight = PivotingWeight;
  WebIntrusionSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  WebIntrusionSuccess.TamperingWeight = TamperingWeight;
  WebIntrusionSuccess.PortScanWeight = PortScanWeight;
  WebIntrusionSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  WebIntrusionSuccess.WebIntrusionWeight = WebIntrusionWeight;
  WebIntrusionSuccess.MakeDecision = MakeDecision;
  WebIntrusionSuccess.setSVs(WebIntrusionChosen, WebIntrusionWeight);

  ExploitAD.MakeDecision = MakeDecision;
  ExploitAD.ExploitChosen = ExploitChosen;
  ExploitAD.ExploitWeight = ExploitWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  QueryFloodingAD.MakeDecision = MakeDecision;
  QueryFloodingAD.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingAD.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationAD.MakeDecision = MakeDecision;
  PrivilegeEscalationAD.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationAD.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  UnauthorizedRemoteLoginAD.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginAD.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginAD.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  NetworkAttackAD.MakeDecision = MakeDecision;
  NetworkAttackAD.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackAD.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionAD.MakeDecision = MakeDecision;
  MalwareIntroductionAD.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionAD.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PivotingAD.MakeDecision = MakeDecision;
  PivotingAD.PivotingChosen = PivotingChosen;
  PivotingAD.PivotingWeight = PivotingWeight;
  DatabaseDumpAD.MakeDecision = MakeDecision;
  DatabaseDumpAD.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpAD.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingAD.MakeDecision = MakeDecision;
  TamperingAD.TamperingChosen = TamperingChosen;
  TamperingAD.TamperingWeight = TamperingWeight;
  PortScanAD.MakeDecision = MakeDecision;
  PortScanAD.PortScanChosen = PortScanChosen;
  PortScanAD.PortScanWeight = PortScanWeight;
  FirmwareReversingAD.MakeDecision = MakeDecision;
  FirmwareReversingAD.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingAD.FirmwareReversingWeight = FirmwareReversingWeight;
  WebIntrusionAD.MakeDecision = MakeDecision;
  WebIntrusionAD.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionAD.WebIntrusionWeight = WebIntrusionWeight;
}

double advise_treeADVISE::convertCostToUtility(double cost) {
  const double esquared = 7.389056099; // e^(2)
  if(cost < 0)
    return 1.0;
  else if(cost > 100)
    return 0.0;
  else {
    return (esquared - exp(cost/50))/(-1 + esquared);
  }
}

double advise_treeADVISE::convertPayoffToUtility(double payoff) {
  const double etoten = 28.031624895; // e^(10/3)
  if(payoff < 0)
    return 0;
  else if(payoff > 1000)
    return 1;
  else {
    return (etoten - (etoten/exp(payoff/300)))/(-1 + etoten);
  }
}

double advise_treeADVISE::convertDetectionToUtility(double detection) {
  const double esquared = 7.389056099; // e^(2)
  if(detection < 0)
    return 1;
  else if(detection > 1)
    return 0;
  else {
    return (1-(esquared/exp(2*detection)))/(1-esquared);
  }
}

void advise_treeADVISE::customInitialization() {

}

/*****************************************************************/
/*                   Attack Step Definitions                     */
/*****************************************************************/

/*====================== ExploitFailureStep ========================*/

advise_treeADVISE::ExploitFailureStep::ExploitFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExploitFailureStep", 0, Exponential, RaceEnabled, 17, 1, false);}

advise_treeADVISE::ExploitFailureStep::~ExploitFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitFailureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitFailureStep::timeDistributionParameter0() {
return 0.2;
}

double advise_treeADVISE::ExploitFailureStep::Weight() {
return 0.8;
}

bool advise_treeADVISE::ExploitFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitFailureStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *advise_treeADVISE::ExploitFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::ExploitFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::ExploitFailureStep::preconditionsMet() {
return (VulnerabilityAwareness->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::ExploitFailureStep::executeEffects() {

}

double advise_treeADVISE::ExploitFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::ExploitFailureStep::getOutcomeProbability() {
return 0.8;
}

double advise_treeADVISE::ExploitFailureStep::getDetection() {
return 0.6;
}

/*====================== ExploitSuccessStep ========================*/

advise_treeADVISE::ExploitSuccessStep::ExploitSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExploitSuccessStep", 0, Exponential, RaceEnabled, 17, 1, false);}

advise_treeADVISE::ExploitSuccessStep::~ExploitSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitSuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitSuccessStep::timeDistributionParameter0() {
return 0.2;
}

double advise_treeADVISE::ExploitSuccessStep::Weight() {
return 0.2;
}

bool advise_treeADVISE::ExploitSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitSuccessStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *advise_treeADVISE::ExploitSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::ExploitSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::ExploitSuccessStep::preconditionsMet() {
return (VulnerabilityAwareness->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::ExploitSuccessStep::executeEffects() {
VehicleServerRootAccess->Mark()=1;
}

double advise_treeADVISE::ExploitSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::ExploitSuccessStep::getOutcomeProbability() {
return 0.2;
}

double advise_treeADVISE::ExploitSuccessStep::getDetection() {
return 0.2;
}

/*====================== DoNothingOutcome1Step ========================*/

advise_treeADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 1, Deterministic, RaceEnabled, 15, 0, false);}

advise_treeADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DoNothingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DoNothingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DoNothingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double advise_treeADVISE::DoNothingOutcome1Step::Weight() {
  return 1;
}

bool advise_treeADVISE::DoNothingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DoNothingOutcome1Step::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DoNothingOutcome1Step::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DoNothingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DoNothingOutcome1Step::Rank() {
  return 1;
}

bool advise_treeADVISE::DoNothingOutcome1Step::preconditionsMet() {

  return true;
}

void advise_treeADVISE::DoNothingOutcome1Step::executeEffects() {

}

double advise_treeADVISE::DoNothingOutcome1Step::getCost() {
return 0;
}

double advise_treeADVISE::DoNothingOutcome1Step::getOutcomeProbability() {
return 1;
}

double advise_treeADVISE::DoNothingOutcome1Step::getDetection() {
return 0;
}

/*====================== QueryFloodingFailureStep ========================*/

advise_treeADVISE::QueryFloodingFailureStep::QueryFloodingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingFailureStep", 2, Exponential, RaceEnabled, 19, 1, false);}

advise_treeADVISE::QueryFloodingFailureStep::~QueryFloodingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingFailureStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingFailureStep::timeDistributionParameter0() {
return 0.1;
}

double advise_treeADVISE::QueryFloodingFailureStep::Weight() {
if( HandshakeProtocol->Mark()) return 0.4;
else return 0.9;
}

bool advise_treeADVISE::QueryFloodingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingFailureStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *advise_treeADVISE::QueryFloodingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::QueryFloodingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::QueryFloodingFailureStep::preconditionsMet() {
return ((Script->Mark()>2) && SocketAddress->Mark() && !DoS->Mark());
  return true;
}

void advise_treeADVISE::QueryFloodingFailureStep::executeEffects() {

}

double advise_treeADVISE::QueryFloodingFailureStep::getCost() {
return 10;
}

double advise_treeADVISE::QueryFloodingFailureStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.4;
else return 0.9;
}

double advise_treeADVISE::QueryFloodingFailureStep::getDetection() {
return 0.1;
}

/*====================== QueryFloodingSuccessStep ========================*/

advise_treeADVISE::QueryFloodingSuccessStep::QueryFloodingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingSuccessStep", 2, Exponential, RaceEnabled, 19, 1, false);}

advise_treeADVISE::QueryFloodingSuccessStep::~QueryFloodingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingSuccessStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingSuccessStep::timeDistributionParameter0() {
return 0.1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::Weight() {
if( HandshakeProtocol->Mark()) return 0.6;
else return 0.1;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingSuccessStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *advise_treeADVISE::QueryFloodingSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::QueryFloodingSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::preconditionsMet() {
return ((Script->Mark()>2) && SocketAddress->Mark() && !DoS->Mark());
  return true;
}

void advise_treeADVISE::QueryFloodingSuccessStep::executeEffects() {
DoS->Mark() = 1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getCost() {
return 10;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.6;
else return 0.1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getDetection() {
return 0.1;
}

/*====================== PrivilegeEscalationfaliureStep ========================*/

advise_treeADVISE::PrivilegeEscalationfaliureStep::PrivilegeEscalationfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationfaliureStep", 3, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PrivilegeEscalationfaliureStep::~PrivilegeEscalationfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationfaliureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PrivilegeEscalationfaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PrivilegeEscalationChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::PrivilegeEscalationfaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PrivilegeEscalationfaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PrivilegeEscalationfaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PrivilegeEscalationfaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PrivilegeEscalationfaliureStep::preconditionsMet() {
return(vehicleServerUnprivAccess->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::PrivilegeEscalationfaliureStep::executeEffects() {

}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::getCost() {

}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::PrivilegeEscalationfaliureStep::getDetection() {
if(IDSsensitivity<1)return 0.1; return 0.3;
}

/*====================== PrivilegeEscalationsuccessStep ========================*/

advise_treeADVISE::PrivilegeEscalationsuccessStep::PrivilegeEscalationsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationsuccessStep", 3, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PrivilegeEscalationsuccessStep::~PrivilegeEscalationsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationsuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PrivilegeEscalationsuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PrivilegeEscalationChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::PrivilegeEscalationsuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PrivilegeEscalationsuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PrivilegeEscalationsuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PrivilegeEscalationsuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PrivilegeEscalationsuccessStep::preconditionsMet() {
return(vehicleServerUnprivAccess->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::PrivilegeEscalationsuccessStep::executeEffects() {
VehicleServerRootAccess->Mark()=1;
}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::getCost() {

}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::PrivilegeEscalationsuccessStep::getDetection() {
if(IDSsensitivity<1)return 0.1; return 0.5;
}

/*====================== UnauthorizedRemoteLoginFaliureStep ========================*/

advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::UnauthorizedRemoteLoginFaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("UnauthorizedRemoteLoginFaliureStep", 4, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::~UnauthorizedRemoteLoginFaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  EmoployeePersonalInfo->Register(&EmoployeePersonalInfo_Mobius_Mark);
  UnauthorizedRemoteLoginChosen->Register(&UnauthorizedRemoteLoginChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(UnauthorizedRemoteLoginChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::preconditionsMet() {
return (EmoployeePersonalInfo->Mark()&& !CorporateNetworkAccess->Mark());
  return true;
}

void advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::executeEffects() {

}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::getCost() {
return 0;
}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::getDetection() {
return 0.5;
}

/*====================== UnauthorizedRemoteLoginSuccessStep ========================*/

advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::UnauthorizedRemoteLoginSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("UnauthorizedRemoteLoginSuccessStep", 4, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::~UnauthorizedRemoteLoginSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  EmoployeePersonalInfo->Register(&EmoployeePersonalInfo_Mobius_Mark);
  UnauthorizedRemoteLoginChosen->Register(&UnauthorizedRemoteLoginChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(UnauthorizedRemoteLoginChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::preconditionsMet() {
return (EmoployeePersonalInfo->Mark()&& !CorporateNetworkAccess->Mark());
  return true;
}

void advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::executeEffects() {
CorporateNetworkAccess->Mark()=1;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::getDetection() {
return 0.2;
}

/*====================== NetworkAttackfailureStep ========================*/

advise_treeADVISE::NetworkAttackfailureStep::NetworkAttackfailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttackfailureStep", 5, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::NetworkAttackfailureStep::~NetworkAttackfailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttackfailureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::NetworkAttackfailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::NetworkAttackfailureStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::NetworkAttackfailureStep::Weight() {
return 0.3;
}

bool advise_treeADVISE::NetworkAttackfailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::NetworkAttackfailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::NetworkAttackfailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::NetworkAttackfailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::NetworkAttackfailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::NetworkAttackfailureStep::preconditionsMet() {
return (CorporateServerLocation->Mark() && !CorporateNetworkAccess->Mark());
  return true;
}

void advise_treeADVISE::NetworkAttackfailureStep::executeEffects() {

}

double advise_treeADVISE::NetworkAttackfailureStep::getCost() {

}

double advise_treeADVISE::NetworkAttackfailureStep::getOutcomeProbability() {
return 0.3;
}

double advise_treeADVISE::NetworkAttackfailureStep::getDetection() {
return 0;
}

/*====================== NetworkAttacksuccessStep ========================*/

advise_treeADVISE::NetworkAttacksuccessStep::NetworkAttacksuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttacksuccessStep", 5, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::NetworkAttacksuccessStep::~NetworkAttacksuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttacksuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::NetworkAttacksuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::NetworkAttacksuccessStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::NetworkAttacksuccessStep::Weight() {
return 0.7;
}

bool advise_treeADVISE::NetworkAttacksuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::NetworkAttacksuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::NetworkAttacksuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::NetworkAttacksuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::NetworkAttacksuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::NetworkAttacksuccessStep::preconditionsMet() {
return (CorporateServerLocation->Mark() && !CorporateNetworkAccess->Mark());
  return true;
}

void advise_treeADVISE::NetworkAttacksuccessStep::executeEffects() {
CorporateNetworkAccess->Mark()=1;
}

double advise_treeADVISE::NetworkAttacksuccessStep::getCost() {

}

double advise_treeADVISE::NetworkAttacksuccessStep::getOutcomeProbability() {
return 0.7;
}

double advise_treeADVISE::NetworkAttacksuccessStep::getDetection() {
return 0.3;
}

/*====================== MalwareIntroductionfailureStep ========================*/

advise_treeADVISE::MalwareIntroductionfailureStep::MalwareIntroductionfailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionfailureStep", 6, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::MalwareIntroductionfailureStep::~MalwareIntroductionfailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionfailureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::MalwareIntroductionfailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MalwareIntroductionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::MalwareIntroductionfailureStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::MalwareIntroductionfailureStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::MalwareIntroductionfailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::MalwareIntroductionfailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::MalwareIntroductionfailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::MalwareIntroductionfailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::MalwareIntroductionfailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::MalwareIntroductionfailureStep::preconditionsMet() {
return(PhysicalAccess->Mark() && !vehicleServerUnprivAccess->Mark());
  return true;
}

void advise_treeADVISE::MalwareIntroductionfailureStep::executeEffects() {

}

double advise_treeADVISE::MalwareIntroductionfailureStep::getCost() {
10;
}

double advise_treeADVISE::MalwareIntroductionfailureStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::MalwareIntroductionfailureStep::getDetection() {
return 0.1;
}

/*====================== MalwareIntroductionsuccessStep ========================*/

advise_treeADVISE::MalwareIntroductionsuccessStep::MalwareIntroductionsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionsuccessStep", 6, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::MalwareIntroductionsuccessStep::~MalwareIntroductionsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::MalwareIntroductionsuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MalwareIntroductionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::MalwareIntroductionsuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::MalwareIntroductionsuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::MalwareIntroductionsuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::MalwareIntroductionsuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::MalwareIntroductionsuccessStep::preconditionsMet() {
return(PhysicalAccess->Mark() && !vehicleServerUnprivAccess->Mark());
  return true;
}

void advise_treeADVISE::MalwareIntroductionsuccessStep::executeEffects() {
vehicleServerUnprivAccess->Mark()=1;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::getCost() {
10;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::getDetection() {
return 0.2;
}

/*====================== PivotingfaliureStep ========================*/

advise_treeADVISE::PivotingfaliureStep::PivotingfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingfaliureStep", 7, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PivotingfaliureStep::~PivotingfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingfaliureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PivotingfaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PivotingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PivotingfaliureStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::PivotingfaliureStep::Weight() {
return 0.3;
}

bool advise_treeADVISE::PivotingfaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PivotingfaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PivotingfaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PivotingfaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PivotingfaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PivotingfaliureStep::preconditionsMet() {
return (CorporateNetworkAccess->Mark() && !vehicleServerUnprivAccess->Mark());
  return true;
}

void advise_treeADVISE::PivotingfaliureStep::executeEffects() {

}

double advise_treeADVISE::PivotingfaliureStep::getCost() {

}

double advise_treeADVISE::PivotingfaliureStep::getOutcomeProbability() {
return 0.3;
}

double advise_treeADVISE::PivotingfaliureStep::getDetection() {
return 0.2;
}

/*====================== PivotingsuccessStep ========================*/

advise_treeADVISE::PivotingsuccessStep::PivotingsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingsuccessStep", 7, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PivotingsuccessStep::~PivotingsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PivotingsuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PivotingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PivotingsuccessStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::PivotingsuccessStep::Weight() {
return 0.7;
}

bool advise_treeADVISE::PivotingsuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PivotingsuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PivotingsuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PivotingsuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PivotingsuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PivotingsuccessStep::preconditionsMet() {
return (CorporateNetworkAccess->Mark() && !vehicleServerUnprivAccess->Mark());
  return true;
}

void advise_treeADVISE::PivotingsuccessStep::executeEffects() {
vehicleServerUnprivAccess->Mark()=1;
}

double advise_treeADVISE::PivotingsuccessStep::getCost() {

}

double advise_treeADVISE::PivotingsuccessStep::getOutcomeProbability() {
return 0.7;
}

double advise_treeADVISE::PivotingsuccessStep::getDetection() {
return 0.2;
}

/*====================== DatabaseDumpFailureStep ========================*/

advise_treeADVISE::DatabaseDumpFailureStep::DatabaseDumpFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpFailureStep", 8, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::DatabaseDumpFailureStep::~DatabaseDumpFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpFailureStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DatabaseDumpFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DatabaseDumpChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::DatabaseDumpFailureStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DatabaseDumpFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DatabaseDumpFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !DataBreach->Mark());
  return true;
}

void advise_treeADVISE::DatabaseDumpFailureStep::executeEffects() {

}

double advise_treeADVISE::DatabaseDumpFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::DatabaseDumpFailureStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::DatabaseDumpFailureStep::getDetection() {
return 0.1;
}

/*====================== DatabaseDumpSuccessStep ========================*/

advise_treeADVISE::DatabaseDumpSuccessStep::DatabaseDumpSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpSuccessStep", 8, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::DatabaseDumpSuccessStep::~DatabaseDumpSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DatabaseDumpSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DatabaseDumpChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DatabaseDumpSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DatabaseDumpSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !DataBreach->Mark());
  return true;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::executeEffects() {
DataBreach->Mark()=1;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getDetection() {
return 0.2;
}

/*====================== TamperingFailureStep ========================*/

advise_treeADVISE::TamperingFailureStep::TamperingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingFailureStep", 9, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::TamperingFailureStep::~TamperingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingFailureStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::TamperingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(TamperingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::TamperingFailureStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::TamperingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::TamperingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::TamperingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::TamperingFailureStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !VehicleUndesideredBehaviour->Mark());
  return true;
}

void advise_treeADVISE::TamperingFailureStep::executeEffects() {

}

double advise_treeADVISE::TamperingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::TamperingFailureStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::TamperingFailureStep::getDetection() {
return 0.1;
}

/*====================== TamperingSuccessStep ========================*/

advise_treeADVISE::TamperingSuccessStep::TamperingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingSuccessStep", 9, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::TamperingSuccessStep::~TamperingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingSuccessStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::TamperingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(TamperingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::TamperingSuccessStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::TamperingSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::TamperingSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::TamperingSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::TamperingSuccessStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !VehicleUndesideredBehaviour->Mark());
  return true;
}

void advise_treeADVISE::TamperingSuccessStep::executeEffects() {
VehicleUndesideredBehaviour->Mark()=1;
}

double advise_treeADVISE::TamperingSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::TamperingSuccessStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::TamperingSuccessStep::getDetection() {
return 0.1;
}

/*====================== PortScanFailureStep ========================*/

advise_treeADVISE::PortScanFailureStep::PortScanFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanFailureStep", 10, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PortScanFailureStep::~PortScanFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanFailureStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanFailureStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::PortScanFailureStep::Weight() {
if(firewallSensitivity==0) return 0.1; 
if(firewallSensitivity==1) return 0.8; 
if(firewallSensitivity==2) return 0.9; 
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PortScanFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PortScanFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PortScanFailureStep::preconditionsMet() {
return (SocketAddress->Mark() && !VulnerabilityAwareness->Mark());
  return true;
}

void advise_treeADVISE::PortScanFailureStep::executeEffects() {

}

double advise_treeADVISE::PortScanFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::PortScanFailureStep::getOutcomeProbability() {
if(firewallSensitivity==0) return 0.1; 
if(firewallSensitivity==1) return 0.8; 
if(firewallSensitivity==2) return 0.9; 
}

double advise_treeADVISE::PortScanFailureStep::getDetection() {
if(firewallSensitivity<1) return 0.2; return 0.5;
}

/*====================== PortScanSuccessStep ========================*/

advise_treeADVISE::PortScanSuccessStep::PortScanSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanSuccessStep", 10, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PortScanSuccessStep::~PortScanSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanSuccessStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanSuccessStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::PortScanSuccessStep::Weight() {
if(firewallSensitivity==0) return 0.9;
if(firewallSensitivity==1) return 0.2; 
if(firewallSensitivity==2) return 0.1; 
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PortScanSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PortScanSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PortScanSuccessStep::preconditionsMet() {
return (SocketAddress->Mark() && !VulnerabilityAwareness->Mark());
  return true;
}

void advise_treeADVISE::PortScanSuccessStep::executeEffects() {
VulnerabilityAwareness->Mark()=1;
}

double advise_treeADVISE::PortScanSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::PortScanSuccessStep::getOutcomeProbability() {
if(firewallSensitivity==0) return 0.9;
if(firewallSensitivity==1) return 0.2; 
if(firewallSensitivity==2) return 0.1; 
}

double advise_treeADVISE::PortScanSuccessStep::getDetection() {
if(firewallSensitivity<1) return 0.1; return 0.5;
}

/*====================== FirmwareReversingFailureStep ========================*/

advise_treeADVISE::FirmwareReversingFailureStep::FirmwareReversingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingFailureStep", 11, Deterministic, RaceEnabled, 19, 2, false);}

advise_treeADVISE::FirmwareReversingFailureStep::~FirmwareReversingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingFailureStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingFailureStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::FirmwareReversingFailureStep::Weight() {
if(codeObfuscation<1) return 0.2; return 0.9;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingFailureStep::executeEffects() {

}

double advise_treeADVISE::FirmwareReversingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getOutcomeProbability() {
if(codeObfuscation<1) return 0.2; return 0.9;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainallStep ========================*/

advise_treeADVISE::FirmwareReversingObtainallStep::FirmwareReversingObtainallStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainallStep", 11, Deterministic, RaceEnabled, 19, 2, false);}

advise_treeADVISE::FirmwareReversingObtainallStep::~FirmwareReversingObtainallStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainallStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainallStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::Weight() {
if(codeObfuscation<1) return 0.1; return 0;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingObtainallStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingObtainallStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingObtainallStep::executeEffects() {
HandshakeProtocol->Mark() = 1;
SocketAddress->Mark() = 1;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getOutcomeProbability() {
if(codeObfuscation<1) return 0.1; return 0;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainaddressonlyStep ========================*/

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::FirmwareReversingObtainaddressonlyStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainaddressonlyStep", 11, Deterministic, RaceEnabled, 19, 2, false);}

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::~FirmwareReversingObtainaddressonlyStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Weight() {
if(codeObfuscation<1) return 0.7; return 0.1;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::executeEffects() {
SocketAddress->Mark() = 1;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getOutcomeProbability() {
if(codeObfuscation<1) return 0.7; return 0.1;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getDetection() {
return 0;
}

/*====================== WebIntrusionFaliureStep ========================*/

advise_treeADVISE::WebIntrusionFaliureStep::WebIntrusionFaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("WebIntrusionFaliureStep", 12, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::WebIntrusionFaliureStep::~WebIntrusionFaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::WebIntrusionFaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateInternetAddress->Register(&CorporateInternetAddress_Mobius_Mark);
  WebIntrusionChosen->Register(&WebIntrusionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::WebIntrusionFaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(WebIntrusionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::WebIntrusionFaliureStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::WebIntrusionFaliureStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::WebIntrusionFaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::WebIntrusionFaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::WebIntrusionFaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::WebIntrusionFaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::WebIntrusionFaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::WebIntrusionFaliureStep::preconditionsMet() {
return CorporateInternetAddress->Mark() && !CorporateNetworkAccess->Mark();
  return true;
}

void advise_treeADVISE::WebIntrusionFaliureStep::executeEffects() {

}

double advise_treeADVISE::WebIntrusionFaliureStep::getCost() {
return 0;
}

double advise_treeADVISE::WebIntrusionFaliureStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::WebIntrusionFaliureStep::getDetection() {
return 0;
}

/*====================== WebIntrusionSuccessStep ========================*/

advise_treeADVISE::WebIntrusionSuccessStep::WebIntrusionSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("WebIntrusionSuccessStep", 12, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::WebIntrusionSuccessStep::~WebIntrusionSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::WebIntrusionSuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateInternetAddress->Register(&CorporateInternetAddress_Mobius_Mark);
  WebIntrusionChosen->Register(&WebIntrusionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::WebIntrusionSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(WebIntrusionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::WebIntrusionSuccessStep::timeDistributionParameter0() {
return 4;
}

double advise_treeADVISE::WebIntrusionSuccessStep::Weight() {
return 0.5;
}

bool advise_treeADVISE::WebIntrusionSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::WebIntrusionSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::WebIntrusionSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::WebIntrusionSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::WebIntrusionSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::WebIntrusionSuccessStep::preconditionsMet() {
return CorporateInternetAddress->Mark() && !CorporateNetworkAccess->Mark();
  return true;
}

void advise_treeADVISE::WebIntrusionSuccessStep::executeEffects() {
CorporateNetworkAccess->Mark()=1;
}

double advise_treeADVISE::WebIntrusionSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::WebIntrusionSuccessStep::getOutcomeProbability() {
return 0.5;
}

double advise_treeADVISE::WebIntrusionSuccessStep::getDetection() {
return 0;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== ExploitAdversaryDecision ========================*/

advise_treeADVISE::ExploitAdversaryDecision::ExploitAdversaryDecision() {
  commonInit("ExploitAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::ExploitAdversaryDecision::~ExploitAdversaryDecision() {
}

void advise_treeADVISE::ExploitAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
}

bool advise_treeADVISE::ExploitAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitAdversaryDecision::Weight() {
  return ExploitWeight->Mark();
}

bool advise_treeADVISE::ExploitAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::ExploitAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::ExploitAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::ExploitAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ExploitWeight_Mobius_Mark))--;
  (*(ExploitChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

advise_treeADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::DoNothingAdversaryDecision::~DoNothingAdversaryDecision() {
}

void advise_treeADVISE::DoNothingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
}

bool advise_treeADVISE::DoNothingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DoNothingAdversaryDecision::Weight() {
  return DoNothingWeight->Mark();
}

bool advise_treeADVISE::DoNothingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DoNothingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DoNothingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::DoNothingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::DoNothingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::DoNothingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DoNothingWeight_Mobius_Mark))--;
  (*(DoNothingChosen_Mobius_Mark))++;
  return this;
}

/*====================== QueryFloodingAdversaryDecision ========================*/

advise_treeADVISE::QueryFloodingAdversaryDecision::QueryFloodingAdversaryDecision() {
  commonInit("QueryFloodingAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::QueryFloodingAdversaryDecision::~QueryFloodingAdversaryDecision() {
}

void advise_treeADVISE::QueryFloodingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingAdversaryDecision::Weight() {
  return QueryFloodingWeight->Mark();
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::QueryFloodingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::QueryFloodingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::QueryFloodingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(QueryFloodingWeight_Mobius_Mark))--;
  (*(QueryFloodingChosen_Mobius_Mark))++;
  return this;
}

/*====================== PrivilegeEscalationAdversaryDecision ========================*/

advise_treeADVISE::PrivilegeEscalationAdversaryDecision::PrivilegeEscalationAdversaryDecision() {
  commonInit("PrivilegeEscalationAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::PrivilegeEscalationAdversaryDecision::~PrivilegeEscalationAdversaryDecision() {
}

void advise_treeADVISE::PrivilegeEscalationAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
}

bool advise_treeADVISE::PrivilegeEscalationAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PrivilegeEscalationAdversaryDecision::Weight() {
  return PrivilegeEscalationWeight->Mark();
}

bool advise_treeADVISE::PrivilegeEscalationAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PrivilegeEscalationAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PrivilegeEscalationAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::PrivilegeEscalationAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::PrivilegeEscalationAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::PrivilegeEscalationAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PrivilegeEscalationWeight_Mobius_Mark))--;
  (*(PrivilegeEscalationChosen_Mobius_Mark))++;
  return this;
}

/*====================== UnauthorizedRemoteLoginAdversaryDecision ========================*/

advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::UnauthorizedRemoteLoginAdversaryDecision() {
  commonInit("UnauthorizedRemoteLoginAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::~UnauthorizedRemoteLoginAdversaryDecision() {
}

void advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  UnauthorizedRemoteLoginChosen->Register(&UnauthorizedRemoteLoginChosen_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
}

bool advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::Weight() {
  return UnauthorizedRemoteLoginWeight->Mark();
}

bool advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::UnauthorizedRemoteLoginAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(UnauthorizedRemoteLoginWeight_Mobius_Mark))--;
  (*(UnauthorizedRemoteLoginChosen_Mobius_Mark))++;
  return this;
}

/*====================== NetworkAttackAdversaryDecision ========================*/

advise_treeADVISE::NetworkAttackAdversaryDecision::NetworkAttackAdversaryDecision() {
  commonInit("NetworkAttackAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::NetworkAttackAdversaryDecision::~NetworkAttackAdversaryDecision() {
}

void advise_treeADVISE::NetworkAttackAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
}

bool advise_treeADVISE::NetworkAttackAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::NetworkAttackAdversaryDecision::Weight() {
  return NetworkAttackWeight->Mark();
}

bool advise_treeADVISE::NetworkAttackAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::NetworkAttackAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::NetworkAttackAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::NetworkAttackAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::NetworkAttackAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::NetworkAttackAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(NetworkAttackWeight_Mobius_Mark))--;
  (*(NetworkAttackChosen_Mobius_Mark))++;
  return this;
}

/*====================== MalwareIntroductionAdversaryDecision ========================*/

advise_treeADVISE::MalwareIntroductionAdversaryDecision::MalwareIntroductionAdversaryDecision() {
  commonInit("MalwareIntroductionAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::MalwareIntroductionAdversaryDecision::~MalwareIntroductionAdversaryDecision() {
}

void advise_treeADVISE::MalwareIntroductionAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
}

bool advise_treeADVISE::MalwareIntroductionAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::MalwareIntroductionAdversaryDecision::Weight() {
  return MalwareIntroductionWeight->Mark();
}

bool advise_treeADVISE::MalwareIntroductionAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::MalwareIntroductionAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::MalwareIntroductionAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::MalwareIntroductionAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::MalwareIntroductionAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::MalwareIntroductionAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(MalwareIntroductionWeight_Mobius_Mark))--;
  (*(MalwareIntroductionChosen_Mobius_Mark))++;
  return this;
}

/*====================== PivotingAdversaryDecision ========================*/

advise_treeADVISE::PivotingAdversaryDecision::PivotingAdversaryDecision() {
  commonInit("PivotingAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::PivotingAdversaryDecision::~PivotingAdversaryDecision() {
}

void advise_treeADVISE::PivotingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
}

bool advise_treeADVISE::PivotingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PivotingAdversaryDecision::Weight() {
  return PivotingWeight->Mark();
}

bool advise_treeADVISE::PivotingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PivotingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PivotingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::PivotingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::PivotingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::PivotingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PivotingWeight_Mobius_Mark))--;
  (*(PivotingChosen_Mobius_Mark))++;
  return this;
}

/*====================== DatabaseDumpAdversaryDecision ========================*/

advise_treeADVISE::DatabaseDumpAdversaryDecision::DatabaseDumpAdversaryDecision() {
  commonInit("DatabaseDumpAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::DatabaseDumpAdversaryDecision::~DatabaseDumpAdversaryDecision() {
}

void advise_treeADVISE::DatabaseDumpAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpAdversaryDecision::Weight() {
  return DatabaseDumpWeight->Mark();
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::DatabaseDumpAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::DatabaseDumpAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::DatabaseDumpAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DatabaseDumpWeight_Mobius_Mark))--;
  (*(DatabaseDumpChosen_Mobius_Mark))++;
  return this;
}

/*====================== TamperingAdversaryDecision ========================*/

advise_treeADVISE::TamperingAdversaryDecision::TamperingAdversaryDecision() {
  commonInit("TamperingAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::TamperingAdversaryDecision::~TamperingAdversaryDecision() {
}

void advise_treeADVISE::TamperingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
}

bool advise_treeADVISE::TamperingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingAdversaryDecision::Weight() {
  return TamperingWeight->Mark();
}

bool advise_treeADVISE::TamperingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::TamperingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::TamperingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::TamperingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(TamperingWeight_Mobius_Mark))--;
  (*(TamperingChosen_Mobius_Mark))++;
  return this;
}

/*====================== PortScanAdversaryDecision ========================*/

advise_treeADVISE::PortScanAdversaryDecision::PortScanAdversaryDecision() {
  commonInit("PortScanAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::PortScanAdversaryDecision::~PortScanAdversaryDecision() {
}

void advise_treeADVISE::PortScanAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
}

bool advise_treeADVISE::PortScanAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanAdversaryDecision::Weight() {
  return PortScanWeight->Mark();
}

bool advise_treeADVISE::PortScanAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::PortScanAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::PortScanAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::PortScanAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PortScanWeight_Mobius_Mark))--;
  (*(PortScanChosen_Mobius_Mark))++;
  return this;
}

/*====================== FirmwareReversingAdversaryDecision ========================*/

advise_treeADVISE::FirmwareReversingAdversaryDecision::FirmwareReversingAdversaryDecision() {
  commonInit("FirmwareReversingAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::FirmwareReversingAdversaryDecision::~FirmwareReversingAdversaryDecision() {
}

void advise_treeADVISE::FirmwareReversingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingAdversaryDecision::Weight() {
  return FirmwareReversingWeight->Mark();
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::FirmwareReversingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::FirmwareReversingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::FirmwareReversingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(FirmwareReversingWeight_Mobius_Mark))--;
  (*(FirmwareReversingChosen_Mobius_Mark))++;
  return this;
}

/*====================== WebIntrusionAdversaryDecision ========================*/

advise_treeADVISE::WebIntrusionAdversaryDecision::WebIntrusionAdversaryDecision() {
  commonInit("WebIntrusionAdversaryDecision", 13, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::WebIntrusionAdversaryDecision::~WebIntrusionAdversaryDecision() {
}

void advise_treeADVISE::WebIntrusionAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  WebIntrusionChosen->Register(&WebIntrusionChosen_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
}

bool advise_treeADVISE::WebIntrusionAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::WebIntrusionAdversaryDecision::Weight() {
  return WebIntrusionWeight->Mark();
}

bool advise_treeADVISE::WebIntrusionAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::WebIntrusionAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::WebIntrusionAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::WebIntrusionAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::WebIntrusionAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::WebIntrusionAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(WebIntrusionWeight_Mobius_Mark))--;
  (*(WebIntrusionChosen_Mobius_Mark))++;
  return this;
}

