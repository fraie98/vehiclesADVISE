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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("handshakeProtocol",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("socketAddress",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("DoS",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("binaryDump",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("reverseEngineering",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
  double startpts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  double stoppts[13]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0};
  Initialize("script",(RewardType)0,13, startpts, stoppts, timeindex, 0,1, 1);
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
