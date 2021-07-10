
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


advise_treeADVISE::advise_treeADVISE() {
  ExploitAD.setParent(this);
  UnauthorizedRemoteLoginAD.setParent(this);
  TamperingAD.setParent(this);
  WebIntrusionAD.setParent(this);
  PivotingAD.setParent(this);
  PrivilegeEscalationAD.setParent(this);
  DatabaseDumpAD.setParent(this);
  QueryFloodingAD.setParent(this);
  FirmwareReversingAD.setParent(this);
  DoNothingAD.setParent(this);
  NetworkAttackAD.setParent(this);
  MalwareIntroductionAD.setParent(this);
  PortScanAD.setParent(this);
  ExploitFailure.setParent(this);
  ExploitSuccess.setParent(this);
  UnauthorizedRemoteLoginFaliure.setParent(this);
  UnauthorizedRemoteLoginSuccess.setParent(this);
  TamperingFailure.setParent(this);
  TamperingSuccess.setParent(this);
  WebIntrusionFaliure.setParent(this);
  WebIntrusionSuccess.setParent(this);
  Pivotingfaliure.setParent(this);
  Pivotingsuccess.setParent(this);
  PrivilegeEscalationfaliure.setParent(this);
  PrivilegeEscalationsuccess.setParent(this);
  DatabaseDumpFailure.setParent(this);
  DatabaseDumpSuccess.setParent(this);
  QueryFloodingFailure.setParent(this);
  QueryFloodingSuccess.setParent(this);
  FirmwareReversingFailure.setParent(this);
  FirmwareReversingObtainall.setParent(this);
  FirmwareReversingObtainaddressonly.setParent(this);
  DoNothingOutcome1.setParent(this);
  NetworkAttackfaliure.setParent(this);
  NetworkAttacksuccess.setParent(this);
  MalwareIntroductionfaliure.setParent(this);
  MalwareIntroductionsuccess.setParent(this);
  PortScanFailure.setParent(this);
  PortScanSuccess.setParent(this);
  ExploitGroup.initialize(2, "ExploitGroup");
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitFailure);
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitSuccess);

  UnauthorizedRemoteLoginGroup.initialize(2, "UnauthorizedRemoteLoginGroup");
  UnauthorizedRemoteLoginGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginFaliure);
  UnauthorizedRemoteLoginGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginSuccess);

  TamperingGroup.initialize(2, "TamperingGroup");
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingFailure);
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingSuccess);

  WebIntrusionGroup.initialize(2, "WebIntrusionGroup");
  WebIntrusionGroup.appendGroup((BaseGroupClass*) &WebIntrusionFaliure);
  WebIntrusionGroup.appendGroup((BaseGroupClass*) &WebIntrusionSuccess);

  PivotingGroup.initialize(2, "PivotingGroup");
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingfaliure);
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingsuccess);

  PrivilegeEscalationGroup.initialize(2, "PrivilegeEscalationGroup");
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationfaliure);
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationsuccess);

  DatabaseDumpGroup.initialize(2, "DatabaseDumpGroup");
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpFailure);
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpSuccess);

  QueryFloodingGroup.initialize(2, "QueryFloodingGroup");
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingFailure);
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingSuccess);

  FirmwareReversingGroup.initialize(3, "FirmwareReversingGroup");
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingFailure);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainall);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainaddressonly);

  NetworkAttackGroup.initialize(2, "NetworkAttackGroup");
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttackfaliure);
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttacksuccess);

  MalwareIntroductionGroup.initialize(2, "MalwareIntroductionGroup");
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionfaliure);
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionsuccess);

  PortScanGroup.initialize(2, "PortScanGroup");
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanFailure);
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanSuccess);

  AdversaryDecisionGroup.initialize(13, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExploitAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &UnauthorizedRemoteLoginAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &TamperingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &WebIntrusionAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PivotingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DatabaseDumpAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &QueryFloodingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &FirmwareReversingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkAttackAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PortScanAD);

  BaseADVISEAction* InitialActions[39] = {
    &ExploitAD, // 0
    &UnauthorizedRemoteLoginAD, // 1
    &TamperingAD, // 2
    &WebIntrusionAD, // 3
    &PivotingAD, // 4
    &PrivilegeEscalationAD, // 5
    &DatabaseDumpAD, // 6
    &QueryFloodingAD, // 7
    &FirmwareReversingAD, // 8
    &DoNothingAD, // 9
    &NetworkAttackAD, // 10
    &MalwareIntroductionAD, // 11
    &PortScanAD, // 12
    &ExploitFailure, // 13
    &ExploitSuccess, // 14
    &UnauthorizedRemoteLoginFaliure, // 15
    &UnauthorizedRemoteLoginSuccess, // 16
    &TamperingFailure, // 17
    &TamperingSuccess, // 18
    &WebIntrusionFaliure, // 19
    &WebIntrusionSuccess, // 20
    &Pivotingfaliure, // 21
    &Pivotingsuccess, // 22
    &PrivilegeEscalationfaliure, // 23
    &PrivilegeEscalationsuccess, // 24
    &DatabaseDumpFailure, // 25
    &DatabaseDumpSuccess, // 26
    &QueryFloodingFailure, // 27
    &QueryFloodingSuccess, // 28
    &FirmwareReversingFailure, // 29
    &FirmwareReversingObtainall, // 30
    &FirmwareReversingObtainaddressonly, // 31
    &DoNothingOutcome1, // 32
    &NetworkAttackfaliure, // 33
    &NetworkAttacksuccess, // 34
    &MalwareIntroductionfaliure, // 35
    &MalwareIntroductionsuccess, // 36
    &PortScanFailure, // 37
    &PortScanSuccess // 38
  };

  Step* InitialSteps[26] = {
      &ExploitFailure,
      &ExploitSuccess,
      &UnauthorizedRemoteLoginFaliure,
      &UnauthorizedRemoteLoginSuccess,
      &TamperingFailure,
      &TamperingSuccess,
      &WebIntrusionFaliure,
      &WebIntrusionSuccess,
      &Pivotingfaliure,
      &Pivotingsuccess,
      &PrivilegeEscalationfaliure,
      &PrivilegeEscalationsuccess,
      &DatabaseDumpFailure,
      &DatabaseDumpSuccess,
      &QueryFloodingFailure,
      &QueryFloodingSuccess,
      &FirmwareReversingFailure,
      &FirmwareReversingObtainall,
      &FirmwareReversingObtainaddressonly,
      &DoNothingOutcome1,
      &NetworkAttackfaliure,
      &NetworkAttacksuccess,
      &MalwareIntroductionfaliure,
      &MalwareIntroductionsuccess,
      &PortScanFailure,
      &PortScanSuccess
  };

  BaseGroupClass* InitialGroups[14] = {
    (BaseGroupClass*) &ExploitGroup, // 0
    (BaseGroupClass*) &UnauthorizedRemoteLoginGroup, // 1
    (BaseGroupClass*) &TamperingGroup, // 2
    (BaseGroupClass*) &WebIntrusionGroup, // 3
    (BaseGroupClass*) &PivotingGroup, // 4
    (BaseGroupClass*) &PrivilegeEscalationGroup, // 5
    (BaseGroupClass*) &DatabaseDumpGroup, // 6
    (BaseGroupClass*) &QueryFloodingGroup, // 7
    (BaseGroupClass*) &FirmwareReversingGroup, // 8
    (BaseGroupClass*) &DoNothingOutcome1, // 9
    (BaseGroupClass*) &NetworkAttackGroup, // 10
    (BaseGroupClass*) &MalwareIntroductionGroup, // 11
    (BaseGroupClass*) &PortScanGroup, // 12
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  VehicleServerRootAccess = new Access("VehicleServerRootAccess", 0);
  vehicleServerUnprivAccess = new Access("vehicleServerUnprivAccess", 0);
  PhysicalAccess = new Access("PhysicalAccess", 0);
  CorporateNetworkAccess = new Access("CorporateNetworkAccess", 0);
  SocketAddress = new Knowledge("SocketAddress", 0);
  VulnerabilityAwareness = new Knowledge("VulnerabilityAwareness", 0);
  BinaryDump = new Knowledge("BinaryDump", 1);
  EmoployeePersonalInfo = new Knowledge("EmoployeePersonalInfo", 0);
  HandshakeProtocol = new Knowledge("HandshakeProtocol", 0);
  CorporateServerLocation = new Knowledge("CorporateServerLocation", 0);
  CorporateInternetAddress = new Knowledge("CorporateInternetAddress", 0);
  ReverseEngineering = new Skill("ReverseEngineering", 5);
  Script = new Skill("Script", 7);
  DataBreach = new Goal("DataBreach", 0);
  DataBreach->setPayoff(150);
  VehicleUndesideredBehaviour = new Goal("VehicleUndesideredBehaviour", 0);
  VehicleUndesideredBehaviour->setPayoff(300);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(100);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  ExploitWeight = new StepWeight("ExploitWeight", 0);
  ExploitChosen = new StepChosen("ExploitChosen", 0);
  UnauthorizedRemoteLoginWeight = new StepWeight("UnauthorizedRemoteLoginWeight", 0);
  UnauthorizedRemoteLoginChosen = new StepChosen("UnauthorizedRemoteLoginChosen", 0);
  TamperingWeight = new StepWeight("TamperingWeight", 0);
  TamperingChosen = new StepChosen("TamperingChosen", 0);
  WebIntrusionWeight = new StepWeight("WebIntrusionWeight", 0);
  WebIntrusionChosen = new StepChosen("WebIntrusionChosen", 0);
  PivotingWeight = new StepWeight("PivotingWeight", 0);
  PivotingChosen = new StepChosen("PivotingChosen", 0);
  PrivilegeEscalationWeight = new StepWeight("PrivilegeEscalationWeight", 0);
  PrivilegeEscalationChosen = new StepChosen("PrivilegeEscalationChosen", 0);
  DatabaseDumpWeight = new StepWeight("DatabaseDumpWeight", 0);
  DatabaseDumpChosen = new StepChosen("DatabaseDumpChosen", 0);
  QueryFloodingWeight = new StepWeight("QueryFloodingWeight", 0);
  QueryFloodingChosen = new StepChosen("QueryFloodingChosen", 0);
  FirmwareReversingWeight = new StepWeight("FirmwareReversingWeight", 0);
  FirmwareReversingChosen = new StepChosen("FirmwareReversingChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  NetworkAttackWeight = new StepWeight("NetworkAttackWeight", 0);
  NetworkAttackChosen = new StepChosen("NetworkAttackChosen", 0);
  MalwareIntroductionWeight = new StepWeight("MalwareIntroductionWeight", 0);
  MalwareIntroductionChosen = new StepChosen("MalwareIntroductionChosen", 0);
  PortScanWeight = new StepWeight("PortScanWeight", 0);
  PortScanChosen = new StepChosen("PortScanChosen", 0);

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
    VulnerabilityAwareness, // 5
    BinaryDump, // 6
    EmoployeePersonalInfo, // 7
    HandshakeProtocol, // 8
    CorporateServerLocation, // 9
    CorporateInternetAddress, // 10
    ReverseEngineering, // 11
    Script, // 12
    DataBreach, // 13
    VehicleUndesideredBehaviour, // 14
    DoS, // 15
    ExploitChosen, // 16
    UnauthorizedRemoteLoginChosen, // 17
    TamperingChosen, // 18
    WebIntrusionChosen, // 19
    PivotingChosen, // 20
    PrivilegeEscalationChosen, // 21
    DatabaseDumpChosen, // 22
    QueryFloodingChosen, // 23
    FirmwareReversingChosen, // 24
    DoNothingChosen, // 25
    NetworkAttackChosen, // 26
    MalwareIntroductionChosen, // 27
    PortScanChosen, // 28
    ExploitWeight, // 29
    UnauthorizedRemoteLoginWeight, // 30
    TamperingWeight, // 31
    WebIntrusionWeight, // 32
    PivotingWeight, // 33
    PrivilegeEscalationWeight, // 34
    DatabaseDumpWeight, // 35
    QueryFloodingWeight, // 36
    FirmwareReversingWeight, // 37
    DoNothingWeight, // 38
    NetworkAttackWeight, // 39
    MalwareIntroductionWeight, // 40
    PortScanWeight, // 41
    MakeDecision // 42
};

  int outCounts[13] = { 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2 };

  commonInit("advise_tree", 43, InitialSVs, 39, InitialActions, 14, InitialGroups, 13, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = 0;
  advDetectPref = 0.1;
  advPayPref = 0.9;

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
    {36,13}, {37,13}, {38,13}, {39,13}, {40,13}, {41,13}, {0,13}, {5,13}, 
    {42,14}, {16,14}, {29,14}, {30,14}, {31,14}, {32,14}, {33,14}, {34,14}, 
    {35,14}, {36,14}, {37,14}, {38,14}, {39,14}, {40,14}, {41,14}, {0,14}, 
    {5,14}, {42,15}, {17,15}, {29,15}, {30,15}, {31,15}, {32,15}, {33,15}, 
    {34,15}, {35,15}, {36,15}, {37,15}, {38,15}, {39,15}, {40,15}, {41,15}, 
    {3,15}, {7,15}, {42,16}, {17,16}, {29,16}, {30,16}, {31,16}, {32,16}, 
    {33,16}, {34,16}, {35,16}, {36,16}, {37,16}, {38,16}, {39,16}, {40,16}, 
    {41,16}, {3,16}, {7,16}, {42,17}, {18,17}, {29,17}, {30,17}, {31,17}, 
    {32,17}, {33,17}, {34,17}, {35,17}, {36,17}, {37,17}, {38,17}, {39,17}, 
    {40,17}, {41,17}, {14,17}, {0,17}, {42,18}, {18,18}, {29,18}, {30,18}, 
    {31,18}, {32,18}, {33,18}, {34,18}, {35,18}, {36,18}, {37,18}, {38,18}, 
    {39,18}, {40,18}, {41,18}, {14,18}, {0,18}, {42,19}, {19,19}, {29,19}, 
    {30,19}, {31,19}, {32,19}, {33,19}, {34,19}, {35,19}, {36,19}, {37,19}, 
    {38,19}, {39,19}, {40,19}, {41,19}, {3,19}, {10,19}, {42,20}, {19,20}, 
    {29,20}, {30,20}, {31,20}, {32,20}, {33,20}, {34,20}, {35,20}, {36,20}, 
    {37,20}, {38,20}, {39,20}, {40,20}, {41,20}, {3,20}, {10,20}, {42,21}, 
    {20,21}, {29,21}, {30,21}, {31,21}, {32,21}, {33,21}, {34,21}, {35,21}, 
    {36,21}, {37,21}, {38,21}, {39,21}, {40,21}, {41,21}, {1,21}, {3,21}, 
    {42,22}, {20,22}, {29,22}, {30,22}, {31,22}, {32,22}, {33,22}, {34,22}, 
    {35,22}, {36,22}, {37,22}, {38,22}, {39,22}, {40,22}, {41,22}, {1,22}, 
    {3,22}, {42,23}, {21,23}, {29,23}, {30,23}, {31,23}, {32,23}, {33,23}, 
    {34,23}, {35,23}, {36,23}, {37,23}, {38,23}, {39,23}, {40,23}, {41,23}, 
    {0,23}, {1,23}, {42,24}, {21,24}, {29,24}, {30,24}, {31,24}, {32,24}, 
    {33,24}, {34,24}, {35,24}, {36,24}, {37,24}, {38,24}, {39,24}, {40,24}, 
    {41,24}, {0,24}, {1,24}, {42,25}, {22,25}, {29,25}, {30,25}, {31,25}, 
    {32,25}, {33,25}, {34,25}, {35,25}, {36,25}, {37,25}, {38,25}, {39,25}, 
    {40,25}, {41,25}, {13,25}, {0,25}, {42,26}, {22,26}, {29,26}, {30,26}, 
    {31,26}, {32,26}, {33,26}, {34,26}, {35,26}, {36,26}, {37,26}, {38,26}, 
    {39,26}, {40,26}, {41,26}, {13,26}, {0,26}, {42,27}, {23,27}, {29,27}, 
    {30,27}, {31,27}, {32,27}, {33,27}, {34,27}, {35,27}, {36,27}, {37,27}, 
    {38,27}, {39,27}, {40,27}, {41,27}, {15,27}, {8,27}, {4,27}, {42,28}, 
    {23,28}, {29,28}, {30,28}, {31,28}, {32,28}, {33,28}, {34,28}, {35,28}, 
    {36,28}, {37,28}, {38,28}, {39,28}, {40,28}, {41,28}, {15,28}, {8,28}, 
    {4,28}, {42,29}, {24,29}, {29,29}, {30,29}, {31,29}, {32,29}, {33,29}, 
    {34,29}, {35,29}, {36,29}, {37,29}, {38,29}, {39,29}, {40,29}, {41,29}, 
    {8,29}, {4,29}, {6,29}, {42,30}, {24,30}, {29,30}, {30,30}, {31,30}, 
    {32,30}, {33,30}, {34,30}, {35,30}, {36,30}, {37,30}, {38,30}, {39,30}, 
    {40,30}, {41,30}, {8,30}, {4,30}, {6,30}, {42,31}, {24,31}, {29,31}, 
    {30,31}, {31,31}, {32,31}, {33,31}, {34,31}, {35,31}, {36,31}, {37,31}, 
    {38,31}, {39,31}, {40,31}, {41,31}, {8,31}, {4,31}, {6,31}, {42,32}, 
    {25,32}, {29,32}, {30,32}, {31,32}, {32,32}, {33,32}, {34,32}, {35,32}, 
    {36,32}, {37,32}, {38,32}, {39,32}, {40,32}, {41,32}, {42,33}, {26,33}, 
    {29,33}, {30,33}, {31,33}, {32,33}, {33,33}, {34,33}, {35,33}, {36,33}, 
    {37,33}, {38,33}, {39,33}, {40,33}, {41,33}, {3,33}, {9,33}, {42,34}, 
    {26,34}, {29,34}, {30,34}, {31,34}, {32,34}, {33,34}, {34,34}, {35,34}, 
    {36,34}, {37,34}, {38,34}, {39,34}, {40,34}, {41,34}, {3,34}, {9,34}, 
    {42,35}, {27,35}, {29,35}, {30,35}, {31,35}, {32,35}, {33,35}, {34,35}, 
    {35,35}, {36,35}, {37,35}, {38,35}, {39,35}, {40,35}, {41,35}, {1,35}, 
    {2,35}, {42,36}, {27,36}, {29,36}, {30,36}, {31,36}, {32,36}, {33,36}, 
    {34,36}, {35,36}, {36,36}, {37,36}, {38,36}, {39,36}, {40,36}, {41,36}, 
    {1,36}, {2,36}, {42,37}, {28,37}, {29,37}, {30,37}, {31,37}, {32,37}, 
    {33,37}, {34,37}, {35,37}, {36,37}, {37,37}, {38,37}, {39,37}, {40,37}, 
    {41,37}, {5,37}, {4,37}, {42,38}, {28,38}, {29,38}, {30,38}, {31,38}, 
    {32,38}, {33,38}, {34,38}, {35,38}, {36,38}, {37,38}, {38,38}, {39,38}, 
    {40,38}, {41,38}, {5,38}, {4,38}
};
  for(int n = 0; n < 484;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[67][2] = {
    {42,0}, {42,1}, {42,2}, {42,3}, {42,4}, {42,5}, {42,6}, {42,7}, 
    {42,8}, {42,9}, {42,10}, {42,11}, {42,12}, {16,13}, {0,13}, {16,14}, 
    {0,14}, {17,15}, {3,15}, {17,16}, {3,16}, {18,17}, {14,17}, {18,18}, 
    {14,18}, {19,19}, {3,19}, {19,20}, {3,20}, {20,21}, {1,21}, {20,22}, 
    {1,22}, {21,23}, {0,23}, {21,24}, {0,24}, {22,25}, {13,25}, {22,26}, 
    {13,26}, {23,27}, {15,27}, {23,28}, {15,28}, {24,29}, {8,29}, {4,29}, 
    {24,30}, {8,30}, {4,30}, {24,31}, {8,31}, {4,31}, {25,32}, {26,33}, 
    {3,33}, {26,34}, {3,34}, {27,35}, {1,35}, {27,36}, {1,36}, {28,37}, 
    {5,37}, {28,38}, {5,38}
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
  ExploitFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  ExploitFailure.TamperingWeight = TamperingWeight;
  ExploitFailure.WebIntrusionWeight = WebIntrusionWeight;
  ExploitFailure.PivotingWeight = PivotingWeight;
  ExploitFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitFailure.QueryFloodingWeight = QueryFloodingWeight;
  ExploitFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitFailure.DoNothingWeight = DoNothingWeight;
  ExploitFailure.NetworkAttackWeight = NetworkAttackWeight;
  ExploitFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitFailure.PortScanWeight = PortScanWeight;
  ExploitFailure.MakeDecision = MakeDecision;
  ExploitFailure.setSVs(ExploitChosen, ExploitWeight);
  ExploitSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitSuccess.ExploitChosen = ExploitChosen;
  ExploitSuccess.ExploitWeight = ExploitWeight;
  ExploitSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  ExploitSuccess.TamperingWeight = TamperingWeight;
  ExploitSuccess.WebIntrusionWeight = WebIntrusionWeight;
  ExploitSuccess.PivotingWeight = PivotingWeight;
  ExploitSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitSuccess.QueryFloodingWeight = QueryFloodingWeight;
  ExploitSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitSuccess.DoNothingWeight = DoNothingWeight;
  ExploitSuccess.NetworkAttackWeight = NetworkAttackWeight;
  ExploitSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitSuccess.PortScanWeight = PortScanWeight;
  ExploitSuccess.MakeDecision = MakeDecision;
  ExploitSuccess.setSVs(ExploitChosen, ExploitWeight);
  UnauthorizedRemoteLoginFaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  UnauthorizedRemoteLoginFaliure.EmoployeePersonalInfo = EmoployeePersonalInfo;
  UnauthorizedRemoteLoginFaliure.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginFaliure.ExploitWeight = ExploitWeight;
  UnauthorizedRemoteLoginFaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  UnauthorizedRemoteLoginFaliure.TamperingWeight = TamperingWeight;
  UnauthorizedRemoteLoginFaliure.WebIntrusionWeight = WebIntrusionWeight;
  UnauthorizedRemoteLoginFaliure.PivotingWeight = PivotingWeight;
  UnauthorizedRemoteLoginFaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  UnauthorizedRemoteLoginFaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  UnauthorizedRemoteLoginFaliure.QueryFloodingWeight = QueryFloodingWeight;
  UnauthorizedRemoteLoginFaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  UnauthorizedRemoteLoginFaliure.DoNothingWeight = DoNothingWeight;
  UnauthorizedRemoteLoginFaliure.NetworkAttackWeight = NetworkAttackWeight;
  UnauthorizedRemoteLoginFaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  UnauthorizedRemoteLoginFaliure.PortScanWeight = PortScanWeight;
  UnauthorizedRemoteLoginFaliure.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginFaliure.setSVs(UnauthorizedRemoteLoginChosen, UnauthorizedRemoteLoginWeight);
  UnauthorizedRemoteLoginSuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  UnauthorizedRemoteLoginSuccess.EmoployeePersonalInfo = EmoployeePersonalInfo;
  UnauthorizedRemoteLoginSuccess.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginSuccess.ExploitWeight = ExploitWeight;
  UnauthorizedRemoteLoginSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  UnauthorizedRemoteLoginSuccess.TamperingWeight = TamperingWeight;
  UnauthorizedRemoteLoginSuccess.WebIntrusionWeight = WebIntrusionWeight;
  UnauthorizedRemoteLoginSuccess.PivotingWeight = PivotingWeight;
  UnauthorizedRemoteLoginSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  UnauthorizedRemoteLoginSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  UnauthorizedRemoteLoginSuccess.QueryFloodingWeight = QueryFloodingWeight;
  UnauthorizedRemoteLoginSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  UnauthorizedRemoteLoginSuccess.DoNothingWeight = DoNothingWeight;
  UnauthorizedRemoteLoginSuccess.NetworkAttackWeight = NetworkAttackWeight;
  UnauthorizedRemoteLoginSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  UnauthorizedRemoteLoginSuccess.PortScanWeight = PortScanWeight;
  UnauthorizedRemoteLoginSuccess.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginSuccess.setSVs(UnauthorizedRemoteLoginChosen, UnauthorizedRemoteLoginWeight);
  TamperingFailure.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingFailure.TamperingChosen = TamperingChosen;
  TamperingFailure.ExploitWeight = ExploitWeight;
  TamperingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  TamperingFailure.TamperingWeight = TamperingWeight;
  TamperingFailure.WebIntrusionWeight = WebIntrusionWeight;
  TamperingFailure.PivotingWeight = PivotingWeight;
  TamperingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingFailure.QueryFloodingWeight = QueryFloodingWeight;
  TamperingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingFailure.DoNothingWeight = DoNothingWeight;
  TamperingFailure.NetworkAttackWeight = NetworkAttackWeight;
  TamperingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingFailure.PortScanWeight = PortScanWeight;
  TamperingFailure.MakeDecision = MakeDecision;
  TamperingFailure.setSVs(TamperingChosen, TamperingWeight);
  TamperingSuccess.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingSuccess.TamperingChosen = TamperingChosen;
  TamperingSuccess.ExploitWeight = ExploitWeight;
  TamperingSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  TamperingSuccess.TamperingWeight = TamperingWeight;
  TamperingSuccess.WebIntrusionWeight = WebIntrusionWeight;
  TamperingSuccess.PivotingWeight = PivotingWeight;
  TamperingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  TamperingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingSuccess.DoNothingWeight = DoNothingWeight;
  TamperingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  TamperingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingSuccess.PortScanWeight = PortScanWeight;
  TamperingSuccess.MakeDecision = MakeDecision;
  TamperingSuccess.setSVs(TamperingChosen, TamperingWeight);
  WebIntrusionFaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  WebIntrusionFaliure.CorporateInternetAddress = CorporateInternetAddress;
  WebIntrusionFaliure.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionFaliure.ExploitWeight = ExploitWeight;
  WebIntrusionFaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  WebIntrusionFaliure.TamperingWeight = TamperingWeight;
  WebIntrusionFaliure.WebIntrusionWeight = WebIntrusionWeight;
  WebIntrusionFaliure.PivotingWeight = PivotingWeight;
  WebIntrusionFaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  WebIntrusionFaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  WebIntrusionFaliure.QueryFloodingWeight = QueryFloodingWeight;
  WebIntrusionFaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  WebIntrusionFaliure.DoNothingWeight = DoNothingWeight;
  WebIntrusionFaliure.NetworkAttackWeight = NetworkAttackWeight;
  WebIntrusionFaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  WebIntrusionFaliure.PortScanWeight = PortScanWeight;
  WebIntrusionFaliure.MakeDecision = MakeDecision;
  WebIntrusionFaliure.setSVs(WebIntrusionChosen, WebIntrusionWeight);
  WebIntrusionSuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  WebIntrusionSuccess.CorporateInternetAddress = CorporateInternetAddress;
  WebIntrusionSuccess.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionSuccess.ExploitWeight = ExploitWeight;
  WebIntrusionSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  WebIntrusionSuccess.TamperingWeight = TamperingWeight;
  WebIntrusionSuccess.WebIntrusionWeight = WebIntrusionWeight;
  WebIntrusionSuccess.PivotingWeight = PivotingWeight;
  WebIntrusionSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  WebIntrusionSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  WebIntrusionSuccess.QueryFloodingWeight = QueryFloodingWeight;
  WebIntrusionSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  WebIntrusionSuccess.DoNothingWeight = DoNothingWeight;
  WebIntrusionSuccess.NetworkAttackWeight = NetworkAttackWeight;
  WebIntrusionSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  WebIntrusionSuccess.PortScanWeight = PortScanWeight;
  WebIntrusionSuccess.MakeDecision = MakeDecision;
  WebIntrusionSuccess.setSVs(WebIntrusionChosen, WebIntrusionWeight);
  Pivotingfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingfaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingfaliure.PivotingChosen = PivotingChosen;
  Pivotingfaliure.ExploitWeight = ExploitWeight;
  Pivotingfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  Pivotingfaliure.TamperingWeight = TamperingWeight;
  Pivotingfaliure.WebIntrusionWeight = WebIntrusionWeight;
  Pivotingfaliure.PivotingWeight = PivotingWeight;
  Pivotingfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingfaliure.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingfaliure.DoNothingWeight = DoNothingWeight;
  Pivotingfaliure.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingfaliure.PortScanWeight = PortScanWeight;
  Pivotingfaliure.MakeDecision = MakeDecision;
  Pivotingfaliure.setSVs(PivotingChosen, PivotingWeight);
  Pivotingsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingsuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingsuccess.PivotingChosen = PivotingChosen;
  Pivotingsuccess.ExploitWeight = ExploitWeight;
  Pivotingsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  Pivotingsuccess.TamperingWeight = TamperingWeight;
  Pivotingsuccess.WebIntrusionWeight = WebIntrusionWeight;
  Pivotingsuccess.PivotingWeight = PivotingWeight;
  Pivotingsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingsuccess.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingsuccess.DoNothingWeight = DoNothingWeight;
  Pivotingsuccess.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingsuccess.PortScanWeight = PortScanWeight;
  Pivotingsuccess.MakeDecision = MakeDecision;
  Pivotingsuccess.setSVs(PivotingChosen, PivotingWeight);
  PrivilegeEscalationfaliure.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationfaliure.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationfaliure.ExploitWeight = ExploitWeight;
  PrivilegeEscalationfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PrivilegeEscalationfaliure.TamperingWeight = TamperingWeight;
  PrivilegeEscalationfaliure.WebIntrusionWeight = WebIntrusionWeight;
  PrivilegeEscalationfaliure.PivotingWeight = PivotingWeight;
  PrivilegeEscalationfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationfaliure.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationfaliure.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationfaliure.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationfaliure.PortScanWeight = PortScanWeight;
  PrivilegeEscalationfaliure.MakeDecision = MakeDecision;
  PrivilegeEscalationfaliure.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);
  PrivilegeEscalationsuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationsuccess.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationsuccess.ExploitWeight = ExploitWeight;
  PrivilegeEscalationsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PrivilegeEscalationsuccess.TamperingWeight = TamperingWeight;
  PrivilegeEscalationsuccess.WebIntrusionWeight = WebIntrusionWeight;
  PrivilegeEscalationsuccess.PivotingWeight = PivotingWeight;
  PrivilegeEscalationsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationsuccess.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationsuccess.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationsuccess.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationsuccess.PortScanWeight = PortScanWeight;
  PrivilegeEscalationsuccess.MakeDecision = MakeDecision;
  PrivilegeEscalationsuccess.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);
  DatabaseDumpFailure.DataBreach = DataBreach;
  DatabaseDumpFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpFailure.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpFailure.ExploitWeight = ExploitWeight;
  DatabaseDumpFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DatabaseDumpFailure.TamperingWeight = TamperingWeight;
  DatabaseDumpFailure.WebIntrusionWeight = WebIntrusionWeight;
  DatabaseDumpFailure.PivotingWeight = PivotingWeight;
  DatabaseDumpFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpFailure.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpFailure.DoNothingWeight = DoNothingWeight;
  DatabaseDumpFailure.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpFailure.PortScanWeight = PortScanWeight;
  DatabaseDumpFailure.MakeDecision = MakeDecision;
  DatabaseDumpFailure.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  DatabaseDumpSuccess.DataBreach = DataBreach;
  DatabaseDumpSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpSuccess.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpSuccess.ExploitWeight = ExploitWeight;
  DatabaseDumpSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DatabaseDumpSuccess.TamperingWeight = TamperingWeight;
  DatabaseDumpSuccess.WebIntrusionWeight = WebIntrusionWeight;
  DatabaseDumpSuccess.PivotingWeight = PivotingWeight;
  DatabaseDumpSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpSuccess.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpSuccess.DoNothingWeight = DoNothingWeight;
  DatabaseDumpSuccess.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpSuccess.PortScanWeight = PortScanWeight;
  DatabaseDumpSuccess.MakeDecision = MakeDecision;
  DatabaseDumpSuccess.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  QueryFloodingFailure.DoS = DoS;
  QueryFloodingFailure.Script = Script;
  QueryFloodingFailure.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingFailure.SocketAddress = SocketAddress;
  QueryFloodingFailure.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingFailure.ExploitWeight = ExploitWeight;
  QueryFloodingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  QueryFloodingFailure.TamperingWeight = TamperingWeight;
  QueryFloodingFailure.WebIntrusionWeight = WebIntrusionWeight;
  QueryFloodingFailure.PivotingWeight = PivotingWeight;
  QueryFloodingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingFailure.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingFailure.DoNothingWeight = DoNothingWeight;
  QueryFloodingFailure.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingFailure.PortScanWeight = PortScanWeight;
  QueryFloodingFailure.MakeDecision = MakeDecision;
  QueryFloodingFailure.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  QueryFloodingSuccess.DoS = DoS;
  QueryFloodingSuccess.Script = Script;
  QueryFloodingSuccess.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingSuccess.SocketAddress = SocketAddress;
  QueryFloodingSuccess.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingSuccess.ExploitWeight = ExploitWeight;
  QueryFloodingSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  QueryFloodingSuccess.TamperingWeight = TamperingWeight;
  QueryFloodingSuccess.WebIntrusionWeight = WebIntrusionWeight;
  QueryFloodingSuccess.PivotingWeight = PivotingWeight;
  QueryFloodingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingSuccess.DoNothingWeight = DoNothingWeight;
  QueryFloodingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingSuccess.PortScanWeight = PortScanWeight;
  QueryFloodingSuccess.MakeDecision = MakeDecision;
  QueryFloodingSuccess.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  FirmwareReversingFailure.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingFailure.SocketAddress = SocketAddress;
  FirmwareReversingFailure.BinaryDump = BinaryDump;
  FirmwareReversingFailure.ReverseEngineering = ReverseEngineering;
  FirmwareReversingFailure.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingFailure.ExploitWeight = ExploitWeight;
  FirmwareReversingFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingFailure.TamperingWeight = TamperingWeight;
  FirmwareReversingFailure.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingFailure.PivotingWeight = PivotingWeight;
  FirmwareReversingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingFailure.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingFailure.DoNothingWeight = DoNothingWeight;
  FirmwareReversingFailure.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingFailure.PortScanWeight = PortScanWeight;
  FirmwareReversingFailure.MakeDecision = MakeDecision;
  FirmwareReversingFailure.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainall.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainall.SocketAddress = SocketAddress;
  FirmwareReversingObtainall.BinaryDump = BinaryDump;
  FirmwareReversingObtainall.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainall.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainall.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainall.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingObtainall.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainall.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingObtainall.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainall.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainall.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainall.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainall.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainall.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainall.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainall.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainall.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainall.MakeDecision = MakeDecision;
  FirmwareReversingObtainall.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainaddressonly.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainaddressonly.SocketAddress = SocketAddress;
  FirmwareReversingObtainaddressonly.BinaryDump = BinaryDump;
  FirmwareReversingObtainaddressonly.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainaddressonly.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainaddressonly.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainaddressonly.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  FirmwareReversingObtainaddressonly.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainaddressonly.WebIntrusionWeight = WebIntrusionWeight;
  FirmwareReversingObtainaddressonly.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainaddressonly.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainaddressonly.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainaddressonly.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainaddressonly.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainaddressonly.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainaddressonly.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainaddressonly.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainaddressonly.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainaddressonly.MakeDecision = MakeDecision;
  FirmwareReversingObtainaddressonly.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.ExploitWeight = ExploitWeight;
  DoNothingOutcome1.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  DoNothingOutcome1.TamperingWeight = TamperingWeight;
  DoNothingOutcome1.WebIntrusionWeight = WebIntrusionWeight;
  DoNothingOutcome1.PivotingWeight = PivotingWeight;
  DoNothingOutcome1.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DoNothingOutcome1.DatabaseDumpWeight = DatabaseDumpWeight;
  DoNothingOutcome1.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingOutcome1.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.NetworkAttackWeight = NetworkAttackWeight;
  DoNothingOutcome1.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DoNothingOutcome1.PortScanWeight = PortScanWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  NetworkAttackfaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttackfaliure.CorporateServerLocation = CorporateServerLocation;
  NetworkAttackfaliure.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackfaliure.ExploitWeight = ExploitWeight;
  NetworkAttackfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  NetworkAttackfaliure.TamperingWeight = TamperingWeight;
  NetworkAttackfaliure.WebIntrusionWeight = WebIntrusionWeight;
  NetworkAttackfaliure.PivotingWeight = PivotingWeight;
  NetworkAttackfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttackfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttackfaliure.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttackfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttackfaliure.DoNothingWeight = DoNothingWeight;
  NetworkAttackfaliure.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttackfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttackfaliure.PortScanWeight = PortScanWeight;
  NetworkAttackfaliure.MakeDecision = MakeDecision;
  NetworkAttackfaliure.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  NetworkAttacksuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttacksuccess.CorporateServerLocation = CorporateServerLocation;
  NetworkAttacksuccess.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttacksuccess.ExploitWeight = ExploitWeight;
  NetworkAttacksuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  NetworkAttacksuccess.TamperingWeight = TamperingWeight;
  NetworkAttacksuccess.WebIntrusionWeight = WebIntrusionWeight;
  NetworkAttacksuccess.PivotingWeight = PivotingWeight;
  NetworkAttacksuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttacksuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttacksuccess.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttacksuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttacksuccess.DoNothingWeight = DoNothingWeight;
  NetworkAttacksuccess.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttacksuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttacksuccess.PortScanWeight = PortScanWeight;
  NetworkAttacksuccess.MakeDecision = MakeDecision;
  NetworkAttacksuccess.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  MalwareIntroductionfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionfaliure.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionfaliure.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionfaliure.ExploitWeight = ExploitWeight;
  MalwareIntroductionfaliure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  MalwareIntroductionfaliure.TamperingWeight = TamperingWeight;
  MalwareIntroductionfaliure.WebIntrusionWeight = WebIntrusionWeight;
  MalwareIntroductionfaliure.PivotingWeight = PivotingWeight;
  MalwareIntroductionfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionfaliure.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionfaliure.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionfaliure.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionfaliure.PortScanWeight = PortScanWeight;
  MalwareIntroductionfaliure.MakeDecision = MakeDecision;
  MalwareIntroductionfaliure.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  MalwareIntroductionsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionsuccess.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionsuccess.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionsuccess.ExploitWeight = ExploitWeight;
  MalwareIntroductionsuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  MalwareIntroductionsuccess.TamperingWeight = TamperingWeight;
  MalwareIntroductionsuccess.WebIntrusionWeight = WebIntrusionWeight;
  MalwareIntroductionsuccess.PivotingWeight = PivotingWeight;
  MalwareIntroductionsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionsuccess.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionsuccess.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionsuccess.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionsuccess.PortScanWeight = PortScanWeight;
  MalwareIntroductionsuccess.MakeDecision = MakeDecision;
  MalwareIntroductionsuccess.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  PortScanFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanFailure.SocketAddress = SocketAddress;
  PortScanFailure.PortScanChosen = PortScanChosen;
  PortScanFailure.ExploitWeight = ExploitWeight;
  PortScanFailure.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PortScanFailure.TamperingWeight = TamperingWeight;
  PortScanFailure.WebIntrusionWeight = WebIntrusionWeight;
  PortScanFailure.PivotingWeight = PivotingWeight;
  PortScanFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanFailure.QueryFloodingWeight = QueryFloodingWeight;
  PortScanFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanFailure.DoNothingWeight = DoNothingWeight;
  PortScanFailure.NetworkAttackWeight = NetworkAttackWeight;
  PortScanFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanFailure.PortScanWeight = PortScanWeight;
  PortScanFailure.MakeDecision = MakeDecision;
  PortScanFailure.setSVs(PortScanChosen, PortScanWeight);
  PortScanSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanSuccess.SocketAddress = SocketAddress;
  PortScanSuccess.PortScanChosen = PortScanChosen;
  PortScanSuccess.ExploitWeight = ExploitWeight;
  PortScanSuccess.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  PortScanSuccess.TamperingWeight = TamperingWeight;
  PortScanSuccess.WebIntrusionWeight = WebIntrusionWeight;
  PortScanSuccess.PivotingWeight = PivotingWeight;
  PortScanSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanSuccess.QueryFloodingWeight = QueryFloodingWeight;
  PortScanSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanSuccess.DoNothingWeight = DoNothingWeight;
  PortScanSuccess.NetworkAttackWeight = NetworkAttackWeight;
  PortScanSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanSuccess.PortScanWeight = PortScanWeight;
  PortScanSuccess.MakeDecision = MakeDecision;
  PortScanSuccess.setSVs(PortScanChosen, PortScanWeight);

  ExploitAD.MakeDecision = MakeDecision;
  ExploitAD.ExploitChosen = ExploitChosen;
  ExploitAD.ExploitWeight = ExploitWeight;
  UnauthorizedRemoteLoginAD.MakeDecision = MakeDecision;
  UnauthorizedRemoteLoginAD.UnauthorizedRemoteLoginChosen = UnauthorizedRemoteLoginChosen;
  UnauthorizedRemoteLoginAD.UnauthorizedRemoteLoginWeight = UnauthorizedRemoteLoginWeight;
  TamperingAD.MakeDecision = MakeDecision;
  TamperingAD.TamperingChosen = TamperingChosen;
  TamperingAD.TamperingWeight = TamperingWeight;
  WebIntrusionAD.MakeDecision = MakeDecision;
  WebIntrusionAD.WebIntrusionChosen = WebIntrusionChosen;
  WebIntrusionAD.WebIntrusionWeight = WebIntrusionWeight;
  PivotingAD.MakeDecision = MakeDecision;
  PivotingAD.PivotingChosen = PivotingChosen;
  PivotingAD.PivotingWeight = PivotingWeight;
  PrivilegeEscalationAD.MakeDecision = MakeDecision;
  PrivilegeEscalationAD.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationAD.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpAD.MakeDecision = MakeDecision;
  DatabaseDumpAD.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpAD.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingAD.MakeDecision = MakeDecision;
  QueryFloodingAD.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingAD.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingAD.MakeDecision = MakeDecision;
  FirmwareReversingAD.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingAD.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  NetworkAttackAD.MakeDecision = MakeDecision;
  NetworkAttackAD.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackAD.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionAD.MakeDecision = MakeDecision;
  MalwareIntroductionAD.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionAD.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanAD.MakeDecision = MakeDecision;
  PortScanAD.PortScanChosen = PortScanChosen;
  PortScanAD.PortScanWeight = PortScanWeight;
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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

/*====================== UnauthorizedRemoteLoginFaliureStep ========================*/

advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::UnauthorizedRemoteLoginFaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("UnauthorizedRemoteLoginFaliureStep", 1, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::~UnauthorizedRemoteLoginFaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::UnauthorizedRemoteLoginFaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  EmoployeePersonalInfo->Register(&EmoployeePersonalInfo_Mobius_Mark);
  UnauthorizedRemoteLoginChosen->Register(&UnauthorizedRemoteLoginChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
  commonInit("UnauthorizedRemoteLoginSuccessStep", 1, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::~UnauthorizedRemoteLoginSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::UnauthorizedRemoteLoginSuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  EmoployeePersonalInfo->Register(&EmoployeePersonalInfo_Mobius_Mark);
  UnauthorizedRemoteLoginChosen->Register(&UnauthorizedRemoteLoginChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

/*====================== TamperingFailureStep ========================*/

advise_treeADVISE::TamperingFailureStep::TamperingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingFailureStep", 2, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::TamperingFailureStep::~TamperingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingFailureStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.3;
}

/*====================== TamperingSuccessStep ========================*/

advise_treeADVISE::TamperingSuccessStep::TamperingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingSuccessStep", 2, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::TamperingSuccessStep::~TamperingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingSuccessStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.2;
}

/*====================== WebIntrusionFaliureStep ========================*/

advise_treeADVISE::WebIntrusionFaliureStep::WebIntrusionFaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("WebIntrusionFaliureStep", 3, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::WebIntrusionFaliureStep::~WebIntrusionFaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::WebIntrusionFaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateInternetAddress->Register(&CorporateInternetAddress_Mobius_Mark);
  WebIntrusionChosen->Register(&WebIntrusionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
  commonInit("WebIntrusionSuccessStep", 3, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::WebIntrusionSuccessStep::~WebIntrusionSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::WebIntrusionSuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateInternetAddress->Register(&CorporateInternetAddress_Mobius_Mark);
  WebIntrusionChosen->Register(&WebIntrusionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

/*====================== PivotingfaliureStep ========================*/

advise_treeADVISE::PivotingfaliureStep::PivotingfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingfaliureStep", 4, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PivotingfaliureStep::~PivotingfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingfaliureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.5;
}

/*====================== PivotingsuccessStep ========================*/

advise_treeADVISE::PivotingsuccessStep::PivotingsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingsuccessStep", 4, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PivotingsuccessStep::~PivotingsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.5;
}

/*====================== PrivilegeEscalationfaliureStep ========================*/

advise_treeADVISE::PrivilegeEscalationfaliureStep::PrivilegeEscalationfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationfaliureStep", 5, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PrivilegeEscalationfaliureStep::~PrivilegeEscalationfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationfaliureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.5;
}

/*====================== PrivilegeEscalationsuccessStep ========================*/

advise_treeADVISE::PrivilegeEscalationsuccessStep::PrivilegeEscalationsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationsuccessStep", 5, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PrivilegeEscalationsuccessStep::~PrivilegeEscalationsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationsuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.5;
}

/*====================== DatabaseDumpFailureStep ========================*/

advise_treeADVISE::DatabaseDumpFailureStep::DatabaseDumpFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpFailureStep", 6, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::DatabaseDumpFailureStep::~DatabaseDumpFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpFailureStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
  commonInit("DatabaseDumpSuccessStep", 6, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::DatabaseDumpSuccessStep::~DatabaseDumpSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

/*====================== QueryFloodingFailureStep ========================*/

advise_treeADVISE::QueryFloodingFailureStep::QueryFloodingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingFailureStep", 7, Exponential, RaceEnabled, 19, 1, false);}

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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingFailureStep::timeDistributionParameter0() {
return 5;
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
return 0;
}

double advise_treeADVISE::QueryFloodingFailureStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.4;
else return 0.9;
}

double advise_treeADVISE::QueryFloodingFailureStep::getDetection() {
return 0.6;
}

/*====================== QueryFloodingSuccessStep ========================*/

advise_treeADVISE::QueryFloodingSuccessStep::QueryFloodingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingSuccessStep", 7, Exponential, RaceEnabled, 19, 1, false);}

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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingSuccessStep::timeDistributionParameter0() {
return 5;
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
return 0;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.6;
else return 0.1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getDetection() {
return 0.5;
}

/*====================== FirmwareReversingFailureStep ========================*/

advise_treeADVISE::FirmwareReversingFailureStep::FirmwareReversingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingFailureStep", 8, Deterministic, RaceEnabled, 19, 2, false);}

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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingFailureStep::Weight() {
return 0.2;
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
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingFailureStep::executeEffects() {

}

double advise_treeADVISE::FirmwareReversingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getOutcomeProbability() {
return 0.2;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainallStep ========================*/

advise_treeADVISE::FirmwareReversingObtainallStep::FirmwareReversingObtainallStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainallStep", 8, Deterministic, RaceEnabled, 19, 2, false);}

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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainallStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::Weight() {
return 0.1;
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
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark());
	
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
return 0.1;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainaddressonlyStep ========================*/

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::FirmwareReversingObtainaddressonlyStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainaddressonlyStep", 8, Deterministic, RaceEnabled, 19, 2, false);}

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
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Weight() {
return 0.7;
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
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::executeEffects() {
SocketAddress->Mark() = 1;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getOutcomeProbability() {
return 0.7;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getDetection() {
return 0;
}

/*====================== DoNothingOutcome1Step ========================*/

advise_treeADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 9, Deterministic, RaceEnabled, 15, 0, false);}

advise_treeADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

/*====================== NetworkAttackfaliureStep ========================*/

advise_treeADVISE::NetworkAttackfaliureStep::NetworkAttackfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttackfaliureStep", 10, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::NetworkAttackfaliureStep::~NetworkAttackfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttackfaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::NetworkAttackfaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::NetworkAttackfaliureStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::NetworkAttackfaliureStep::Weight() {
return 0.3;
}

bool advise_treeADVISE::NetworkAttackfaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::NetworkAttackfaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::NetworkAttackfaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::NetworkAttackfaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::NetworkAttackfaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::NetworkAttackfaliureStep::preconditionsMet() {
return (CorporateServerLocation->Mark() && !CorporateNetworkAccess->Mark());
  return true;
}

void advise_treeADVISE::NetworkAttackfaliureStep::executeEffects() {

}

double advise_treeADVISE::NetworkAttackfaliureStep::getCost() {

}

double advise_treeADVISE::NetworkAttackfaliureStep::getOutcomeProbability() {
return 0.3;
}

double advise_treeADVISE::NetworkAttackfaliureStep::getDetection() {
return 0.4;
}

/*====================== NetworkAttacksuccessStep ========================*/

advise_treeADVISE::NetworkAttacksuccessStep::NetworkAttacksuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttacksuccessStep", 10, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::NetworkAttacksuccessStep::~NetworkAttacksuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttacksuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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
return 0.6;
}

/*====================== MalwareIntroductionfaliureStep ========================*/

advise_treeADVISE::MalwareIntroductionfaliureStep::MalwareIntroductionfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionfaliureStep", 11, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::MalwareIntroductionfaliureStep::~MalwareIntroductionfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionfaliureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::MalwareIntroductionfaliureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MalwareIntroductionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::MalwareIntroductionfaliureStep::timeDistributionParameter0() {
return 2;
}

double advise_treeADVISE::MalwareIntroductionfaliureStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::MalwareIntroductionfaliureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::MalwareIntroductionfaliureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::MalwareIntroductionfaliureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::MalwareIntroductionfaliureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::MalwareIntroductionfaliureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::MalwareIntroductionfaliureStep::preconditionsMet() {
return(PhysicalAccess->Mark() && !vehicleServerUnprivAccess->Mark());
  return true;
}

void advise_treeADVISE::MalwareIntroductionfaliureStep::executeEffects() {

}

double advise_treeADVISE::MalwareIntroductionfaliureStep::getCost() {

}

double advise_treeADVISE::MalwareIntroductionfaliureStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::MalwareIntroductionfaliureStep::getDetection() {
return 0.5;
}

/*====================== MalwareIntroductionsuccessStep ========================*/

advise_treeADVISE::MalwareIntroductionsuccessStep::MalwareIntroductionsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionsuccessStep", 11, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::MalwareIntroductionsuccessStep::~MalwareIntroductionsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
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

}

double advise_treeADVISE::MalwareIntroductionsuccessStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::MalwareIntroductionsuccessStep::getDetection() {
return 0.5;
}

/*====================== PortScanFailureStep ========================*/

advise_treeADVISE::PortScanFailureStep::PortScanFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanFailureStep", 12, Exponential, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PortScanFailureStep::~PortScanFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanFailureStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanFailureStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::PortScanFailureStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanFailureStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
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
return 0.1;
}

double advise_treeADVISE::PortScanFailureStep::getDetection() {
return 0.1;
}

/*====================== PortScanSuccessStep ========================*/

advise_treeADVISE::PortScanSuccessStep::PortScanSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanSuccessStep", 12, Exponential, RaceEnabled, 17, 1, false);}

advise_treeADVISE::PortScanSuccessStep::~PortScanSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanSuccessStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  UnauthorizedRemoteLoginWeight->Register(&UnauthorizedRemoteLoginWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  WebIntrusionWeight->Register(&WebIntrusionWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanSuccessStep::timeDistributionParameter0() {
return 3;
}

double advise_treeADVISE::PortScanSuccessStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanSuccessStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
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
return 0.9;
}

double advise_treeADVISE::PortScanSuccessStep::getDetection() {
return 0.1;
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

