#include "RewardPVNodes.h"

RewardPV0Worker::RewardPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV0Worker::~RewardPV0Worker() {
  delete [] TheModelPtr;
}

double RewardPV0Worker::Reward_Function(void) {

return advise_tree->HandshakeProtocol->Mark();

return (0);



}

RewardPV0::RewardPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("handshakeProtocol",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("HandshakeProtocol","advise_tree");
}

RewardPV0::~RewardPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV0Worker;
}
RewardPV1Worker::RewardPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV1Worker::~RewardPV1Worker() {
  delete [] TheModelPtr;
}

double RewardPV1Worker::Reward_Function(void) {

return advise_tree->SocketAddress->Mark();

return (0);



}

RewardPV1::RewardPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("socketAddress",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("SocketAddress","advise_tree");
}

RewardPV1::~RewardPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV1Worker;
}
RewardPV2Worker::RewardPV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV2Worker::~RewardPV2Worker() {
  delete [] TheModelPtr;
}

double RewardPV2Worker::Reward_Function(void) {

return advise_tree->DoS->Mark();

return (0);



}

RewardPV2::RewardPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("DoS",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("DoS","advise_tree");
}

RewardPV2::~RewardPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV2Worker;
}
RewardPV3Worker::RewardPV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV3Worker::~RewardPV3Worker() {
  delete [] TheModelPtr;
}

double RewardPV3Worker::Reward_Function(void) {

return advise_tree->BinaryDump->Mark();

return (0);



}

RewardPV3::RewardPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("binaryDump",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("BinaryDump","advise_tree");
}

RewardPV3::~RewardPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV3Worker;
}
RewardPV4Worker::RewardPV4Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV4Worker::~RewardPV4Worker() {
  delete [] TheModelPtr;
}

double RewardPV4Worker::Reward_Function(void) {

return advise_tree->ReverseEngineering->Mark();

return (0);



}

RewardPV4::RewardPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("reverseEngineering",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("ReverseEngineering","advise_tree");
}

RewardPV4::~RewardPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV4::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV4Worker;
}
RewardPV5Worker::RewardPV5Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV5Worker::~RewardPV5Worker() {
  delete [] TheModelPtr;
}

double RewardPV5Worker::Reward_Function(void) {

return advise_tree->Script->Mark();

return (0);



}

RewardPV5::RewardPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("script",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("Script","advise_tree");
}

RewardPV5::~RewardPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV5::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV5Worker;
}
RewardPV6Worker::RewardPV6Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV6Worker::~RewardPV6Worker() {
  delete [] TheModelPtr;
}

double RewardPV6Worker::Reward_Function(void) {

return advise_tree->VulnerabilityAwareness->Mark();

return (0);



}

RewardPV6::RewardPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("vulnerabilityAwareness",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("VulnerabilityAwareness","advise_tree");
}

RewardPV6::~RewardPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV6::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV6Worker;
}
RewardPV7Worker::RewardPV7Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV7Worker::~RewardPV7Worker() {
  delete [] TheModelPtr;
}

double RewardPV7Worker::Reward_Function(void) {

return advise_tree->VehicleServerRootAccess->Mark();

return (0);



}

RewardPV7::RewardPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("vehicleServerRootAccess",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("VehicleServerRootAccess","advise_tree");
}

RewardPV7::~RewardPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV7::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV7Worker;
}
RewardPV8Worker::RewardPV8Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV8Worker::~RewardPV8Worker() {
  delete [] TheModelPtr;
}

double RewardPV8Worker::Reward_Function(void) {

advise_tree->DataBreach->Mark();

return (0);



}

RewardPV8::RewardPV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("dataBreach",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 0);
  AddModelDependency("advise_tree");
}

RewardPV8::~RewardPV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV8::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV8Worker;
}
RewardPV9Worker::RewardPV9Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&advise_tree);
}

RewardPV9Worker::~RewardPV9Worker() {
  delete [] TheModelPtr;
}

double RewardPV9Worker::Reward_Function(void) {

advise_tree->VehicleUndesideredBehaviour->Mark();

return (0);



}

RewardPV9::RewardPV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theadvise_treeADVISE);
  double startpts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  double stoppts[41]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0};
  Initialize("vehicleUndesideredBehaviour",(RewardType)0,41, startpts, stoppts, timeindex, 0,1, 0);
  AddModelDependency("advise_tree");
}

RewardPV9::~RewardPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardPV9::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardPV9Worker;
}
