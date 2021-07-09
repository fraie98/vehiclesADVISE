
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


advise_treeADVISE::advise_treeADVISE() {
  QueryFloodingAD.setParent(this);
  FirmwareReversingAD.setParent(this);
  DoNothingAD.setParent(this);
  PortScanAD.setParent(this);
  DatabaseDumpAD.setParent(this);
  TamperingAD.setParent(this);
  NetworkAttackAD.setParent(this);
  ExploitAD.setParent(this);
  PivotingAD.setParent(this);
  MalwareIntroductionAD.setParent(this);
  PrivilegeEscalationAD.setParent(this);
  QueryFloodingFailure.setParent(this);
  QueryFloodingSuccess.setParent(this);
  FirmwareReversingFailure.setParent(this);
  FirmwareReversingObtainall.setParent(this);
  FirmwareReversingObtainaddressonly.setParent(this);
  DoNothingOutcome1.setParent(this);
  PortScanFailure.setParent(this);
  PortScanSuccess.setParent(this);
  DatabaseDumpFailure.setParent(this);
  DatabaseDumpSuccess.setParent(this);
  TamperingFailure.setParent(this);
  TamperingSuccess.setParent(this);
  NetworkAttacksuccess.setParent(this);
  NetworkAttackfaliure.setParent(this);
  ExploitFailure.setParent(this);
  ExploitSuccess.setParent(this);
  Pivotingsuccess.setParent(this);
  Pivotingfaliure.setParent(this);
  MalwareIntroductionsuccess.setParent(this);
  MalwareIntroductionfaliure.setParent(this);
  PrivilegeEscalationsuccess.setParent(this);
  PrivilegeEscalationfaliure.setParent(this);
  QueryFloodingGroup.initialize(2, "QueryFloodingGroup");
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingFailure);
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingSuccess);

  FirmwareReversingGroup.initialize(3, "FirmwareReversingGroup");
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingFailure);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainall);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainaddressonly);

  PortScanGroup.initialize(2, "PortScanGroup");
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanFailure);
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanSuccess);

  DatabaseDumpGroup.initialize(2, "DatabaseDumpGroup");
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpFailure);
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpSuccess);

  TamperingGroup.initialize(2, "TamperingGroup");
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingFailure);
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingSuccess);

  NetworkAttackGroup.initialize(2, "NetworkAttackGroup");
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttacksuccess);
  NetworkAttackGroup.appendGroup((BaseGroupClass*) &NetworkAttackfaliure);

  ExploitGroup.initialize(2, "ExploitGroup");
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitFailure);
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitSuccess);

  PivotingGroup.initialize(2, "PivotingGroup");
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingsuccess);
  PivotingGroup.appendGroup((BaseGroupClass*) &Pivotingfaliure);

  MalwareIntroductionGroup.initialize(2, "MalwareIntroductionGroup");
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionsuccess);
  MalwareIntroductionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionfaliure);

  PrivilegeEscalationGroup.initialize(2, "PrivilegeEscalationGroup");
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationsuccess);
  PrivilegeEscalationGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationfaliure);

  AdversaryDecisionGroup.initialize(11, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &QueryFloodingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &FirmwareReversingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PortScanAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DatabaseDumpAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &TamperingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkAttackAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExploitAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PivotingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &MalwareIntroductionAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PrivilegeEscalationAD);

  BaseADVISEAction* InitialActions[33] = {
    &QueryFloodingAD, // 0
    &FirmwareReversingAD, // 1
    &DoNothingAD, // 2
    &PortScanAD, // 3
    &DatabaseDumpAD, // 4
    &TamperingAD, // 5
    &NetworkAttackAD, // 6
    &ExploitAD, // 7
    &PivotingAD, // 8
    &MalwareIntroductionAD, // 9
    &PrivilegeEscalationAD, // 10
    &QueryFloodingFailure, // 11
    &QueryFloodingSuccess, // 12
    &FirmwareReversingFailure, // 13
    &FirmwareReversingObtainall, // 14
    &FirmwareReversingObtainaddressonly, // 15
    &DoNothingOutcome1, // 16
    &PortScanFailure, // 17
    &PortScanSuccess, // 18
    &DatabaseDumpFailure, // 19
    &DatabaseDumpSuccess, // 20
    &TamperingFailure, // 21
    &TamperingSuccess, // 22
    &NetworkAttacksuccess, // 23
    &NetworkAttackfaliure, // 24
    &ExploitFailure, // 25
    &ExploitSuccess, // 26
    &Pivotingsuccess, // 27
    &Pivotingfaliure, // 28
    &MalwareIntroductionsuccess, // 29
    &MalwareIntroductionfaliure, // 30
    &PrivilegeEscalationsuccess, // 31
    &PrivilegeEscalationfaliure // 32
  };

  Step* InitialSteps[22] = {
      &QueryFloodingFailure,
      &QueryFloodingSuccess,
      &FirmwareReversingFailure,
      &FirmwareReversingObtainall,
      &FirmwareReversingObtainaddressonly,
      &DoNothingOutcome1,
      &PortScanFailure,
      &PortScanSuccess,
      &DatabaseDumpFailure,
      &DatabaseDumpSuccess,
      &TamperingFailure,
      &TamperingSuccess,
      &NetworkAttacksuccess,
      &NetworkAttackfaliure,
      &ExploitFailure,
      &ExploitSuccess,
      &Pivotingsuccess,
      &Pivotingfaliure,
      &MalwareIntroductionsuccess,
      &MalwareIntroductionfaliure,
      &PrivilegeEscalationsuccess,
      &PrivilegeEscalationfaliure
  };

  BaseGroupClass* InitialGroups[12] = {
    (BaseGroupClass*) &QueryFloodingGroup, // 0
    (BaseGroupClass*) &FirmwareReversingGroup, // 1
    (BaseGroupClass*) &DoNothingOutcome1, // 2
    (BaseGroupClass*) &PortScanGroup, // 3
    (BaseGroupClass*) &DatabaseDumpGroup, // 4
    (BaseGroupClass*) &TamperingGroup, // 5
    (BaseGroupClass*) &NetworkAttackGroup, // 6
    (BaseGroupClass*) &ExploitGroup, // 7
    (BaseGroupClass*) &PivotingGroup, // 8
    (BaseGroupClass*) &MalwareIntroductionGroup, // 9
    (BaseGroupClass*) &PrivilegeEscalationGroup, // 10
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  CorporateNetworkAccess = new Access("CorporateNetworkAccess", 0);
  VehicleServerRootAccess = new Access("VehicleServerRootAccess", 0);
  vehicleServerUnprivAccess = new Access("vehicleServerUnprivAccess", 0);
  PhysicalAccess = new Access("PhysicalAccess", 1);
  HandshakeProtocol = new Knowledge("HandshakeProtocol", 0);
  VulnerabilityAwareness = new Knowledge("VulnerabilityAwareness", 0);
  SocketAddress = new Knowledge("SocketAddress", 0);
  BinaryDump = new Knowledge("BinaryDump", 1);
  CorporateServerLocation = new Knowledge("CorporateServerLocation", 1);
  ReverseEngineering = new Skill("ReverseEngineering", 5);
  Script = new Skill("Script", 7);
  DataBreach = new Goal("DataBreach", 0);
  DataBreach->setPayoff(150);
  VehicleUndesideredBehaviour = new Goal("VehicleUndesideredBehaviour", 0);
  VehicleUndesideredBehaviour->setPayoff(300);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(100);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  QueryFloodingWeight = new StepWeight("QueryFloodingWeight", 0);
  QueryFloodingChosen = new StepChosen("QueryFloodingChosen", 0);
  FirmwareReversingWeight = new StepWeight("FirmwareReversingWeight", 0);
  FirmwareReversingChosen = new StepChosen("FirmwareReversingChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  PortScanWeight = new StepWeight("PortScanWeight", 0);
  PortScanChosen = new StepChosen("PortScanChosen", 0);
  DatabaseDumpWeight = new StepWeight("DatabaseDumpWeight", 0);
  DatabaseDumpChosen = new StepChosen("DatabaseDumpChosen", 0);
  TamperingWeight = new StepWeight("TamperingWeight", 0);
  TamperingChosen = new StepChosen("TamperingChosen", 0);
  NetworkAttackWeight = new StepWeight("NetworkAttackWeight", 0);
  NetworkAttackChosen = new StepChosen("NetworkAttackChosen", 0);
  ExploitWeight = new StepWeight("ExploitWeight", 0);
  ExploitChosen = new StepChosen("ExploitChosen", 0);
  PivotingWeight = new StepWeight("PivotingWeight", 0);
  PivotingChosen = new StepChosen("PivotingChosen", 0);
  MalwareIntroductionWeight = new StepWeight("MalwareIntroductionWeight", 0);
  MalwareIntroductionChosen = new StepChosen("MalwareIntroductionChosen", 0);
  PrivilegeEscalationWeight = new StepWeight("PrivilegeEscalationWeight", 0);
  PrivilegeEscalationChosen = new StepChosen("PrivilegeEscalationChosen", 0);

  Goal* InitialGoals[3] = {
      DataBreach,
      VehicleUndesideredBehaviour,
      DoS
  };

  ADVISEStateVariable* InitialSVs[37] = {
    CorporateNetworkAccess, // 0
    VehicleServerRootAccess, // 1
    vehicleServerUnprivAccess, // 2
    PhysicalAccess, // 3
    HandshakeProtocol, // 4
    VulnerabilityAwareness, // 5
    SocketAddress, // 6
    BinaryDump, // 7
    CorporateServerLocation, // 8
    ReverseEngineering, // 9
    Script, // 10
    DataBreach, // 11
    VehicleUndesideredBehaviour, // 12
    DoS, // 13
    QueryFloodingChosen, // 14
    FirmwareReversingChosen, // 15
    DoNothingChosen, // 16
    PortScanChosen, // 17
    DatabaseDumpChosen, // 18
    TamperingChosen, // 19
    NetworkAttackChosen, // 20
    ExploitChosen, // 21
    PivotingChosen, // 22
    MalwareIntroductionChosen, // 23
    PrivilegeEscalationChosen, // 24
    QueryFloodingWeight, // 25
    FirmwareReversingWeight, // 26
    DoNothingWeight, // 27
    PortScanWeight, // 28
    DatabaseDumpWeight, // 29
    TamperingWeight, // 30
    NetworkAttackWeight, // 31
    ExploitWeight, // 32
    PivotingWeight, // 33
    MalwareIntroductionWeight, // 34
    PrivilegeEscalationWeight, // 35
    MakeDecision // 36
};

  int outCounts[11] = { 2, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2 };

  commonInit("advise_tree", 37, InitialSVs, 33, InitialActions, 12, InitialGroups, 11, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = 0;
  advDetectPref = 0.1;
  advPayPref = 0.9;

  planningHorizon = 6;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[366][2] = {
    {36,0}, {14,0}, {25,0}, {36,1}, {15,1}, {26,1}, {36,2}, {16,2}, 
    {27,2}, {36,3}, {17,3}, {28,3}, {36,4}, {18,4}, {29,4}, {36,5}, 
    {19,5}, {30,5}, {36,6}, {20,6}, {31,6}, {36,7}, {21,7}, {32,7}, 
    {36,8}, {22,8}, {33,8}, {36,9}, {23,9}, {34,9}, {36,10}, {24,10}, 
    {35,10}, {36,11}, {14,11}, {25,11}, {26,11}, {27,11}, {28,11}, {29,11}, 
    {30,11}, {31,11}, {32,11}, {33,11}, {34,11}, {35,11}, {13,11}, {4,11}, 
    {6,11}, {36,12}, {14,12}, {25,12}, {26,12}, {27,12}, {28,12}, {29,12}, 
    {30,12}, {31,12}, {32,12}, {33,12}, {34,12}, {35,12}, {13,12}, {4,12}, 
    {6,12}, {36,13}, {15,13}, {25,13}, {26,13}, {27,13}, {28,13}, {29,13}, 
    {30,13}, {31,13}, {32,13}, {33,13}, {34,13}, {35,13}, {4,13}, {6,13}, 
    {7,13}, {36,14}, {15,14}, {25,14}, {26,14}, {27,14}, {28,14}, {29,14}, 
    {30,14}, {31,14}, {32,14}, {33,14}, {34,14}, {35,14}, {4,14}, {6,14}, 
    {7,14}, {36,15}, {15,15}, {25,15}, {26,15}, {27,15}, {28,15}, {29,15}, 
    {30,15}, {31,15}, {32,15}, {33,15}, {34,15}, {35,15}, {4,15}, {6,15}, 
    {7,15}, {36,16}, {16,16}, {25,16}, {26,16}, {27,16}, {28,16}, {29,16}, 
    {30,16}, {31,16}, {32,16}, {33,16}, {34,16}, {35,16}, {36,17}, {17,17}, 
    {25,17}, {26,17}, {27,17}, {28,17}, {29,17}, {30,17}, {31,17}, {32,17}, 
    {33,17}, {34,17}, {35,17}, {5,17}, {6,17}, {36,18}, {17,18}, {25,18}, 
    {26,18}, {27,18}, {28,18}, {29,18}, {30,18}, {31,18}, {32,18}, {33,18}, 
    {34,18}, {35,18}, {5,18}, {6,18}, {36,19}, {18,19}, {25,19}, {26,19}, 
    {27,19}, {28,19}, {29,19}, {30,19}, {31,19}, {32,19}, {33,19}, {34,19}, 
    {35,19}, {11,19}, {1,19}, {36,20}, {18,20}, {25,20}, {26,20}, {27,20}, 
    {28,20}, {29,20}, {30,20}, {31,20}, {32,20}, {33,20}, {34,20}, {35,20}, 
    {11,20}, {1,20}, {36,21}, {19,21}, {25,21}, {26,21}, {27,21}, {28,21}, 
    {29,21}, {30,21}, {31,21}, {32,21}, {33,21}, {34,21}, {35,21}, {12,21}, 
    {1,21}, {36,22}, {19,22}, {25,22}, {26,22}, {27,22}, {28,22}, {29,22}, 
    {30,22}, {31,22}, {32,22}, {33,22}, {34,22}, {35,22}, {12,22}, {1,22}, 
    {36,23}, {20,23}, {25,23}, {26,23}, {27,23}, {28,23}, {29,23}, {30,23}, 
    {31,23}, {32,23}, {33,23}, {34,23}, {35,23}, {0,23}, {8,23}, {36,24}, 
    {20,24}, {25,24}, {26,24}, {27,24}, {28,24}, {29,24}, {30,24}, {31,24}, 
    {32,24}, {33,24}, {34,24}, {35,24}, {0,24}, {8,24}, {36,25}, {21,25}, 
    {25,25}, {26,25}, {27,25}, {28,25}, {29,25}, {30,25}, {31,25}, {32,25}, 
    {33,25}, {34,25}, {35,25}, {1,25}, {5,25}, {36,26}, {21,26}, {25,26}, 
    {26,26}, {27,26}, {28,26}, {29,26}, {30,26}, {31,26}, {32,26}, {33,26}, 
    {34,26}, {35,26}, {1,26}, {5,26}, {36,27}, {22,27}, {25,27}, {26,27}, 
    {27,27}, {28,27}, {29,27}, {30,27}, {31,27}, {32,27}, {33,27}, {34,27}, 
    {35,27}, {2,27}, {0,27}, {36,28}, {22,28}, {25,28}, {26,28}, {27,28}, 
    {28,28}, {29,28}, {30,28}, {31,28}, {32,28}, {33,28}, {34,28}, {35,28}, 
    {2,28}, {0,28}, {36,29}, {23,29}, {25,29}, {26,29}, {27,29}, {28,29}, 
    {29,29}, {30,29}, {31,29}, {32,29}, {33,29}, {34,29}, {35,29}, {2,29}, 
    {3,29}, {36,30}, {23,30}, {25,30}, {26,30}, {27,30}, {28,30}, {29,30}, 
    {30,30}, {31,30}, {32,30}, {33,30}, {34,30}, {35,30}, {2,30}, {3,30}, 
    {36,31}, {24,31}, {25,31}, {26,31}, {27,31}, {28,31}, {29,31}, {30,31}, 
    {31,31}, {32,31}, {33,31}, {34,31}, {35,31}, {1,31}, {2,31}, {36,32}, 
    {24,32}, {25,32}, {26,32}, {27,32}, {28,32}, {29,32}, {30,32}, {31,32}, 
    {32,32}, {33,32}, {34,32}, {35,32}, {1,32}, {2,32}
};
  for(int n = 0; n < 366;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[57][2] = {
    {36,0}, {36,1}, {36,2}, {36,3}, {36,4}, {36,5}, {36,6}, {36,7}, 
    {36,8}, {36,9}, {36,10}, {14,11}, {13,11}, {14,12}, {13,12}, {15,13}, 
    {4,13}, {6,13}, {15,14}, {4,14}, {6,14}, {15,15}, {4,15}, {6,15}, 
    {16,16}, {17,17}, {5,17}, {17,18}, {5,18}, {18,19}, {11,19}, {18,20}, 
    {11,20}, {19,21}, {12,21}, {19,22}, {12,22}, {20,23}, {0,23}, {20,24}, 
    {0,24}, {21,25}, {1,25}, {21,26}, {1,26}, {22,27}, {2,27}, {22,28}, 
    {2,28}, {23,29}, {2,29}, {23,30}, {2,30}, {24,31}, {1,31}, {24,32}, 
    {1,32}
};
  for(int n = 0; n < 57;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 33; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

advise_treeADVISE::~advise_treeADVISE() {
}

void advise_treeADVISE::assignSVsToAttackSteps() {
  QueryFloodingFailure.DoS = DoS;
  QueryFloodingFailure.Script = Script;
  QueryFloodingFailure.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingFailure.SocketAddress = SocketAddress;
  QueryFloodingFailure.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingFailure.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingFailure.DoNothingWeight = DoNothingWeight;
  QueryFloodingFailure.PortScanWeight = PortScanWeight;
  QueryFloodingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingFailure.TamperingWeight = TamperingWeight;
  QueryFloodingFailure.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingFailure.ExploitWeight = ExploitWeight;
  QueryFloodingFailure.PivotingWeight = PivotingWeight;
  QueryFloodingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingFailure.MakeDecision = MakeDecision;
  QueryFloodingFailure.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  QueryFloodingSuccess.DoS = DoS;
  QueryFloodingSuccess.Script = Script;
  QueryFloodingSuccess.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingSuccess.SocketAddress = SocketAddress;
  QueryFloodingSuccess.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingSuccess.DoNothingWeight = DoNothingWeight;
  QueryFloodingSuccess.PortScanWeight = PortScanWeight;
  QueryFloodingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingSuccess.TamperingWeight = TamperingWeight;
  QueryFloodingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  QueryFloodingSuccess.ExploitWeight = ExploitWeight;
  QueryFloodingSuccess.PivotingWeight = PivotingWeight;
  QueryFloodingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  QueryFloodingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  QueryFloodingSuccess.MakeDecision = MakeDecision;
  QueryFloodingSuccess.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  FirmwareReversingFailure.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingFailure.SocketAddress = SocketAddress;
  FirmwareReversingFailure.BinaryDump = BinaryDump;
  FirmwareReversingFailure.ReverseEngineering = ReverseEngineering;
  FirmwareReversingFailure.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingFailure.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingFailure.DoNothingWeight = DoNothingWeight;
  FirmwareReversingFailure.PortScanWeight = PortScanWeight;
  FirmwareReversingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingFailure.TamperingWeight = TamperingWeight;
  FirmwareReversingFailure.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingFailure.ExploitWeight = ExploitWeight;
  FirmwareReversingFailure.PivotingWeight = PivotingWeight;
  FirmwareReversingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingFailure.MakeDecision = MakeDecision;
  FirmwareReversingFailure.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainall.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainall.SocketAddress = SocketAddress;
  FirmwareReversingObtainall.BinaryDump = BinaryDump;
  FirmwareReversingObtainall.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainall.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainall.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainall.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainall.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainall.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainall.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainall.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainall.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainall.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainall.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainall.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainall.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainall.MakeDecision = MakeDecision;
  FirmwareReversingObtainall.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainaddressonly.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainaddressonly.SocketAddress = SocketAddress;
  FirmwareReversingObtainaddressonly.BinaryDump = BinaryDump;
  FirmwareReversingObtainaddressonly.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainaddressonly.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainaddressonly.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainaddressonly.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainaddressonly.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainaddressonly.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainaddressonly.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainaddressonly.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainaddressonly.NetworkAttackWeight = NetworkAttackWeight;
  FirmwareReversingObtainaddressonly.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainaddressonly.PivotingWeight = PivotingWeight;
  FirmwareReversingObtainaddressonly.MalwareIntroductionWeight = MalwareIntroductionWeight;
  FirmwareReversingObtainaddressonly.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  FirmwareReversingObtainaddressonly.MakeDecision = MakeDecision;
  FirmwareReversingObtainaddressonly.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingOutcome1.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.PortScanWeight = PortScanWeight;
  DoNothingOutcome1.DatabaseDumpWeight = DatabaseDumpWeight;
  DoNothingOutcome1.TamperingWeight = TamperingWeight;
  DoNothingOutcome1.NetworkAttackWeight = NetworkAttackWeight;
  DoNothingOutcome1.ExploitWeight = ExploitWeight;
  DoNothingOutcome1.PivotingWeight = PivotingWeight;
  DoNothingOutcome1.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DoNothingOutcome1.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  PortScanFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanFailure.SocketAddress = SocketAddress;
  PortScanFailure.PortScanChosen = PortScanChosen;
  PortScanFailure.QueryFloodingWeight = QueryFloodingWeight;
  PortScanFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanFailure.DoNothingWeight = DoNothingWeight;
  PortScanFailure.PortScanWeight = PortScanWeight;
  PortScanFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanFailure.TamperingWeight = TamperingWeight;
  PortScanFailure.NetworkAttackWeight = NetworkAttackWeight;
  PortScanFailure.ExploitWeight = ExploitWeight;
  PortScanFailure.PivotingWeight = PivotingWeight;
  PortScanFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanFailure.MakeDecision = MakeDecision;
  PortScanFailure.setSVs(PortScanChosen, PortScanWeight);
  PortScanSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanSuccess.SocketAddress = SocketAddress;
  PortScanSuccess.PortScanChosen = PortScanChosen;
  PortScanSuccess.QueryFloodingWeight = QueryFloodingWeight;
  PortScanSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanSuccess.DoNothingWeight = DoNothingWeight;
  PortScanSuccess.PortScanWeight = PortScanWeight;
  PortScanSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanSuccess.TamperingWeight = TamperingWeight;
  PortScanSuccess.NetworkAttackWeight = NetworkAttackWeight;
  PortScanSuccess.ExploitWeight = ExploitWeight;
  PortScanSuccess.PivotingWeight = PivotingWeight;
  PortScanSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PortScanSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PortScanSuccess.MakeDecision = MakeDecision;
  PortScanSuccess.setSVs(PortScanChosen, PortScanWeight);
  DatabaseDumpFailure.DataBreach = DataBreach;
  DatabaseDumpFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpFailure.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpFailure.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpFailure.DoNothingWeight = DoNothingWeight;
  DatabaseDumpFailure.PortScanWeight = PortScanWeight;
  DatabaseDumpFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpFailure.TamperingWeight = TamperingWeight;
  DatabaseDumpFailure.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpFailure.ExploitWeight = ExploitWeight;
  DatabaseDumpFailure.PivotingWeight = PivotingWeight;
  DatabaseDumpFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpFailure.MakeDecision = MakeDecision;
  DatabaseDumpFailure.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  DatabaseDumpSuccess.DataBreach = DataBreach;
  DatabaseDumpSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpSuccess.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpSuccess.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpSuccess.DoNothingWeight = DoNothingWeight;
  DatabaseDumpSuccess.PortScanWeight = PortScanWeight;
  DatabaseDumpSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpSuccess.TamperingWeight = TamperingWeight;
  DatabaseDumpSuccess.NetworkAttackWeight = NetworkAttackWeight;
  DatabaseDumpSuccess.ExploitWeight = ExploitWeight;
  DatabaseDumpSuccess.PivotingWeight = PivotingWeight;
  DatabaseDumpSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  DatabaseDumpSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  DatabaseDumpSuccess.MakeDecision = MakeDecision;
  DatabaseDumpSuccess.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  TamperingFailure.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingFailure.TamperingChosen = TamperingChosen;
  TamperingFailure.QueryFloodingWeight = QueryFloodingWeight;
  TamperingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingFailure.DoNothingWeight = DoNothingWeight;
  TamperingFailure.PortScanWeight = PortScanWeight;
  TamperingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingFailure.TamperingWeight = TamperingWeight;
  TamperingFailure.NetworkAttackWeight = NetworkAttackWeight;
  TamperingFailure.ExploitWeight = ExploitWeight;
  TamperingFailure.PivotingWeight = PivotingWeight;
  TamperingFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingFailure.MakeDecision = MakeDecision;
  TamperingFailure.setSVs(TamperingChosen, TamperingWeight);
  TamperingSuccess.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingSuccess.TamperingChosen = TamperingChosen;
  TamperingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  TamperingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingSuccess.DoNothingWeight = DoNothingWeight;
  TamperingSuccess.PortScanWeight = PortScanWeight;
  TamperingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingSuccess.TamperingWeight = TamperingWeight;
  TamperingSuccess.NetworkAttackWeight = NetworkAttackWeight;
  TamperingSuccess.ExploitWeight = ExploitWeight;
  TamperingSuccess.PivotingWeight = PivotingWeight;
  TamperingSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  TamperingSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  TamperingSuccess.MakeDecision = MakeDecision;
  TamperingSuccess.setSVs(TamperingChosen, TamperingWeight);
  NetworkAttacksuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttacksuccess.CorporateServerLocation = CorporateServerLocation;
  NetworkAttacksuccess.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttacksuccess.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttacksuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttacksuccess.DoNothingWeight = DoNothingWeight;
  NetworkAttacksuccess.PortScanWeight = PortScanWeight;
  NetworkAttacksuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttacksuccess.TamperingWeight = TamperingWeight;
  NetworkAttacksuccess.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttacksuccess.ExploitWeight = ExploitWeight;
  NetworkAttacksuccess.PivotingWeight = PivotingWeight;
  NetworkAttacksuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttacksuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttacksuccess.MakeDecision = MakeDecision;
  NetworkAttacksuccess.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  NetworkAttackfaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  NetworkAttackfaliure.CorporateServerLocation = CorporateServerLocation;
  NetworkAttackfaliure.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackfaliure.QueryFloodingWeight = QueryFloodingWeight;
  NetworkAttackfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  NetworkAttackfaliure.DoNothingWeight = DoNothingWeight;
  NetworkAttackfaliure.PortScanWeight = PortScanWeight;
  NetworkAttackfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  NetworkAttackfaliure.TamperingWeight = TamperingWeight;
  NetworkAttackfaliure.NetworkAttackWeight = NetworkAttackWeight;
  NetworkAttackfaliure.ExploitWeight = ExploitWeight;
  NetworkAttackfaliure.PivotingWeight = PivotingWeight;
  NetworkAttackfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  NetworkAttackfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  NetworkAttackfaliure.MakeDecision = MakeDecision;
  NetworkAttackfaliure.setSVs(NetworkAttackChosen, NetworkAttackWeight);
  ExploitFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitFailure.ExploitChosen = ExploitChosen;
  ExploitFailure.QueryFloodingWeight = QueryFloodingWeight;
  ExploitFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitFailure.DoNothingWeight = DoNothingWeight;
  ExploitFailure.PortScanWeight = PortScanWeight;
  ExploitFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitFailure.TamperingWeight = TamperingWeight;
  ExploitFailure.NetworkAttackWeight = NetworkAttackWeight;
  ExploitFailure.ExploitWeight = ExploitWeight;
  ExploitFailure.PivotingWeight = PivotingWeight;
  ExploitFailure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitFailure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitFailure.MakeDecision = MakeDecision;
  ExploitFailure.setSVs(ExploitChosen, ExploitWeight);
  ExploitSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitSuccess.ExploitChosen = ExploitChosen;
  ExploitSuccess.QueryFloodingWeight = QueryFloodingWeight;
  ExploitSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitSuccess.DoNothingWeight = DoNothingWeight;
  ExploitSuccess.PortScanWeight = PortScanWeight;
  ExploitSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitSuccess.TamperingWeight = TamperingWeight;
  ExploitSuccess.NetworkAttackWeight = NetworkAttackWeight;
  ExploitSuccess.ExploitWeight = ExploitWeight;
  ExploitSuccess.PivotingWeight = PivotingWeight;
  ExploitSuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  ExploitSuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  ExploitSuccess.MakeDecision = MakeDecision;
  ExploitSuccess.setSVs(ExploitChosen, ExploitWeight);
  Pivotingsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingsuccess.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingsuccess.PivotingChosen = PivotingChosen;
  Pivotingsuccess.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingsuccess.DoNothingWeight = DoNothingWeight;
  Pivotingsuccess.PortScanWeight = PortScanWeight;
  Pivotingsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingsuccess.TamperingWeight = TamperingWeight;
  Pivotingsuccess.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingsuccess.ExploitWeight = ExploitWeight;
  Pivotingsuccess.PivotingWeight = PivotingWeight;
  Pivotingsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingsuccess.MakeDecision = MakeDecision;
  Pivotingsuccess.setSVs(PivotingChosen, PivotingWeight);
  Pivotingfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  Pivotingfaliure.CorporateNetworkAccess = CorporateNetworkAccess;
  Pivotingfaliure.PivotingChosen = PivotingChosen;
  Pivotingfaliure.QueryFloodingWeight = QueryFloodingWeight;
  Pivotingfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  Pivotingfaliure.DoNothingWeight = DoNothingWeight;
  Pivotingfaliure.PortScanWeight = PortScanWeight;
  Pivotingfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  Pivotingfaliure.TamperingWeight = TamperingWeight;
  Pivotingfaliure.NetworkAttackWeight = NetworkAttackWeight;
  Pivotingfaliure.ExploitWeight = ExploitWeight;
  Pivotingfaliure.PivotingWeight = PivotingWeight;
  Pivotingfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  Pivotingfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  Pivotingfaliure.MakeDecision = MakeDecision;
  Pivotingfaliure.setSVs(PivotingChosen, PivotingWeight);
  MalwareIntroductionsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionsuccess.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionsuccess.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionsuccess.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionsuccess.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionsuccess.PortScanWeight = PortScanWeight;
  MalwareIntroductionsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionsuccess.TamperingWeight = TamperingWeight;
  MalwareIntroductionsuccess.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionsuccess.ExploitWeight = ExploitWeight;
  MalwareIntroductionsuccess.PivotingWeight = PivotingWeight;
  MalwareIntroductionsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionsuccess.MakeDecision = MakeDecision;
  MalwareIntroductionsuccess.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  MalwareIntroductionfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  MalwareIntroductionfaliure.PhysicalAccess = PhysicalAccess;
  MalwareIntroductionfaliure.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionfaliure.QueryFloodingWeight = QueryFloodingWeight;
  MalwareIntroductionfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  MalwareIntroductionfaliure.DoNothingWeight = DoNothingWeight;
  MalwareIntroductionfaliure.PortScanWeight = PortScanWeight;
  MalwareIntroductionfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  MalwareIntroductionfaliure.TamperingWeight = TamperingWeight;
  MalwareIntroductionfaliure.NetworkAttackWeight = NetworkAttackWeight;
  MalwareIntroductionfaliure.ExploitWeight = ExploitWeight;
  MalwareIntroductionfaliure.PivotingWeight = PivotingWeight;
  MalwareIntroductionfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  MalwareIntroductionfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  MalwareIntroductionfaliure.MakeDecision = MakeDecision;
  MalwareIntroductionfaliure.setSVs(MalwareIntroductionChosen, MalwareIntroductionWeight);
  PrivilegeEscalationsuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationsuccess.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationsuccess.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationsuccess.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationsuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationsuccess.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationsuccess.PortScanWeight = PortScanWeight;
  PrivilegeEscalationsuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationsuccess.TamperingWeight = TamperingWeight;
  PrivilegeEscalationsuccess.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationsuccess.ExploitWeight = ExploitWeight;
  PrivilegeEscalationsuccess.PivotingWeight = PivotingWeight;
  PrivilegeEscalationsuccess.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationsuccess.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationsuccess.MakeDecision = MakeDecision;
  PrivilegeEscalationsuccess.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);
  PrivilegeEscalationfaliure.VehicleServerRootAccess = VehicleServerRootAccess;
  PrivilegeEscalationfaliure.vehicleServerUnprivAccess = vehicleServerUnprivAccess;
  PrivilegeEscalationfaliure.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationfaliure.QueryFloodingWeight = QueryFloodingWeight;
  PrivilegeEscalationfaliure.FirmwareReversingWeight = FirmwareReversingWeight;
  PrivilegeEscalationfaliure.DoNothingWeight = DoNothingWeight;
  PrivilegeEscalationfaliure.PortScanWeight = PortScanWeight;
  PrivilegeEscalationfaliure.DatabaseDumpWeight = DatabaseDumpWeight;
  PrivilegeEscalationfaliure.TamperingWeight = TamperingWeight;
  PrivilegeEscalationfaliure.NetworkAttackWeight = NetworkAttackWeight;
  PrivilegeEscalationfaliure.ExploitWeight = ExploitWeight;
  PrivilegeEscalationfaliure.PivotingWeight = PivotingWeight;
  PrivilegeEscalationfaliure.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationfaliure.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
  PrivilegeEscalationfaliure.MakeDecision = MakeDecision;
  PrivilegeEscalationfaliure.setSVs(PrivilegeEscalationChosen, PrivilegeEscalationWeight);

  QueryFloodingAD.MakeDecision = MakeDecision;
  QueryFloodingAD.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingAD.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingAD.MakeDecision = MakeDecision;
  FirmwareReversingAD.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingAD.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  PortScanAD.MakeDecision = MakeDecision;
  PortScanAD.PortScanChosen = PortScanChosen;
  PortScanAD.PortScanWeight = PortScanWeight;
  DatabaseDumpAD.MakeDecision = MakeDecision;
  DatabaseDumpAD.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpAD.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingAD.MakeDecision = MakeDecision;
  TamperingAD.TamperingChosen = TamperingChosen;
  TamperingAD.TamperingWeight = TamperingWeight;
  NetworkAttackAD.MakeDecision = MakeDecision;
  NetworkAttackAD.NetworkAttackChosen = NetworkAttackChosen;
  NetworkAttackAD.NetworkAttackWeight = NetworkAttackWeight;
  ExploitAD.MakeDecision = MakeDecision;
  ExploitAD.ExploitChosen = ExploitChosen;
  ExploitAD.ExploitWeight = ExploitWeight;
  PivotingAD.MakeDecision = MakeDecision;
  PivotingAD.PivotingChosen = PivotingChosen;
  PivotingAD.PivotingWeight = PivotingWeight;
  MalwareIntroductionAD.MakeDecision = MakeDecision;
  MalwareIntroductionAD.MalwareIntroductionChosen = MalwareIntroductionChosen;
  MalwareIntroductionAD.MalwareIntroductionWeight = MalwareIntroductionWeight;
  PrivilegeEscalationAD.MakeDecision = MakeDecision;
  PrivilegeEscalationAD.PrivilegeEscalationChosen = PrivilegeEscalationChosen;
  PrivilegeEscalationAD.PrivilegeEscalationWeight = PrivilegeEscalationWeight;
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

/*====================== QueryFloodingFailureStep ========================*/

advise_treeADVISE::QueryFloodingFailureStep::QueryFloodingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingFailureStep", 0, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::QueryFloodingFailureStep::~QueryFloodingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingFailureStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingFailureStep::timeDistributionParameter0() {
return 3;
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
  return TheDistribution->Deterministic(timeDistributionParameter0());
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
  commonInit("QueryFloodingSuccessStep", 0, Deterministic, RaceEnabled, 17, 1, false);}

advise_treeADVISE::QueryFloodingSuccessStep::~QueryFloodingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingSuccessStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingSuccessStep::timeDistributionParameter0() {
return 3;
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
  return TheDistribution->Deterministic(timeDistributionParameter0());
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
  commonInit("FirmwareReversingFailureStep", 1, Deterministic, RaceEnabled, 17, 2, false);}

advise_treeADVISE::FirmwareReversingFailureStep::~FirmwareReversingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingFailureStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("FirmwareReversingObtainallStep", 1, Deterministic, RaceEnabled, 17, 2, false);}

advise_treeADVISE::FirmwareReversingObtainallStep::~FirmwareReversingObtainallStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainallStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("FirmwareReversingObtainaddressonlyStep", 1, Deterministic, RaceEnabled, 17, 2, false);}

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::~FirmwareReversingObtainaddressonlyStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("DoNothingOutcome1Step", 2, Deterministic, RaceEnabled, 13, 0, false);}

advise_treeADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== PortScanFailureStep ========================*/

advise_treeADVISE::PortScanFailureStep::PortScanFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanFailureStep", 3, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PortScanFailureStep::~PortScanFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanFailureStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PortScanFailureStep::Weight() {
return 0.3;
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
return 0.3;
}

double advise_treeADVISE::PortScanFailureStep::getDetection() {
return 0.1;
}

/*====================== PortScanSuccessStep ========================*/

advise_treeADVISE::PortScanSuccessStep::PortScanSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanSuccessStep", 3, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PortScanSuccessStep::~PortScanSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanSuccessStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PortScanSuccessStep::Weight() {
return 0.7;
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
return 0.7;
}

double advise_treeADVISE::PortScanSuccessStep::getDetection() {
return 0.1;
}

/*====================== DatabaseDumpFailureStep ========================*/

advise_treeADVISE::DatabaseDumpFailureStep::DatabaseDumpFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpFailureStep", 4, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::DatabaseDumpFailureStep::~DatabaseDumpFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpFailureStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("DatabaseDumpSuccessStep", 4, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::DatabaseDumpSuccessStep::~DatabaseDumpSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("TamperingFailureStep", 5, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::TamperingFailureStep::~TamperingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingFailureStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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
  commonInit("TamperingSuccessStep", 5, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::TamperingSuccessStep::~TamperingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingSuccessStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== NetworkAttacksuccessStep ========================*/

advise_treeADVISE::NetworkAttacksuccessStep::NetworkAttacksuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttacksuccessStep", 6, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::NetworkAttacksuccessStep::~NetworkAttacksuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttacksuccessStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== NetworkAttackfaliureStep ========================*/

advise_treeADVISE::NetworkAttackfaliureStep::NetworkAttackfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkAttackfaliureStep", 6, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::NetworkAttackfaliureStep::~NetworkAttackfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::NetworkAttackfaliureStep::LinkVariables() {
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  CorporateServerLocation->Register(&CorporateServerLocation_Mobius_Mark);
  NetworkAttackChosen->Register(&NetworkAttackChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== ExploitFailureStep ========================*/

advise_treeADVISE::ExploitFailureStep::ExploitFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExploitFailureStep", 7, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::ExploitFailureStep::~ExploitFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitFailureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitFailureStep::timeDistributionParameter0() {
return 5;
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
  return TheDistribution->Deterministic(timeDistributionParameter0());
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
  commonInit("ExploitSuccessStep", 7, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::ExploitSuccessStep::~ExploitSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitSuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitSuccessStep::timeDistributionParameter0() {
return 5;
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
  return TheDistribution->Deterministic(timeDistributionParameter0());
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

/*====================== PivotingsuccessStep ========================*/

advise_treeADVISE::PivotingsuccessStep::PivotingsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingsuccessStep", 8, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PivotingsuccessStep::~PivotingsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== PivotingfaliureStep ========================*/

advise_treeADVISE::PivotingfaliureStep::PivotingfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PivotingfaliureStep", 8, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PivotingfaliureStep::~PivotingfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PivotingfaliureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  CorporateNetworkAccess->Register(&CorporateNetworkAccess_Mobius_Mark);
  PivotingChosen->Register(&PivotingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== MalwareIntroductionsuccessStep ========================*/

advise_treeADVISE::MalwareIntroductionsuccessStep::MalwareIntroductionsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionsuccessStep", 9, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::MalwareIntroductionsuccessStep::~MalwareIntroductionsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionsuccessStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== MalwareIntroductionfaliureStep ========================*/

advise_treeADVISE::MalwareIntroductionfaliureStep::MalwareIntroductionfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("MalwareIntroductionfaliureStep", 9, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::MalwareIntroductionfaliureStep::~MalwareIntroductionfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::MalwareIntroductionfaliureStep::LinkVariables() {
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PhysicalAccess->Register(&PhysicalAccess_Mobius_Mark);
  MalwareIntroductionChosen->Register(&MalwareIntroductionChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== PrivilegeEscalationsuccessStep ========================*/

advise_treeADVISE::PrivilegeEscalationsuccessStep::PrivilegeEscalationsuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationsuccessStep", 10, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PrivilegeEscalationsuccessStep::~PrivilegeEscalationsuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationsuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*====================== PrivilegeEscalationfaliureStep ========================*/

advise_treeADVISE::PrivilegeEscalationfaliureStep::PrivilegeEscalationfaliureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PrivilegeEscalationfaliureStep", 10, Deterministic, RaceEnabled, 15, 1, false);}

advise_treeADVISE::PrivilegeEscalationfaliureStep::~PrivilegeEscalationfaliureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PrivilegeEscalationfaliureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  vehicleServerUnprivAccess->Register(&vehicleServerUnprivAccess_Mobius_Mark);
  PrivilegeEscalationChosen->Register(&PrivilegeEscalationChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  NetworkAttackWeight->Register(&NetworkAttackWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  PivotingWeight->Register(&PivotingWeight_Mobius_Mark);
  MalwareIntroductionWeight->Register(&MalwareIntroductionWeight_Mobius_Mark);
  PrivilegeEscalationWeight->Register(&PrivilegeEscalationWeight_Mobius_Mark);
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

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== QueryFloodingAdversaryDecision ========================*/

advise_treeADVISE::QueryFloodingAdversaryDecision::QueryFloodingAdversaryDecision() {
  commonInit("QueryFloodingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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
  commonInit("FirmwareReversingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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
  commonInit("DoNothingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== PortScanAdversaryDecision ========================*/

advise_treeADVISE::PortScanAdversaryDecision::PortScanAdversaryDecision() {
  commonInit("PortScanAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== DatabaseDumpAdversaryDecision ========================*/

advise_treeADVISE::DatabaseDumpAdversaryDecision::DatabaseDumpAdversaryDecision() {
  commonInit("DatabaseDumpAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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
  commonInit("TamperingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== NetworkAttackAdversaryDecision ========================*/

advise_treeADVISE::NetworkAttackAdversaryDecision::NetworkAttackAdversaryDecision() {
  commonInit("NetworkAttackAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== ExploitAdversaryDecision ========================*/

advise_treeADVISE::ExploitAdversaryDecision::ExploitAdversaryDecision() {
  commonInit("ExploitAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== PivotingAdversaryDecision ========================*/

advise_treeADVISE::PivotingAdversaryDecision::PivotingAdversaryDecision() {
  commonInit("PivotingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== MalwareIntroductionAdversaryDecision ========================*/

advise_treeADVISE::MalwareIntroductionAdversaryDecision::MalwareIntroductionAdversaryDecision() {
  commonInit("MalwareIntroductionAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== PrivilegeEscalationAdversaryDecision ========================*/

advise_treeADVISE::PrivilegeEscalationAdversaryDecision::PrivilegeEscalationAdversaryDecision() {
  commonInit("PrivilegeEscalationAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

