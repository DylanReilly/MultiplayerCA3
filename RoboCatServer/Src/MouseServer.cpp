#include <RoboCatServerPCH.h>


MouseServer::MouseServer()
{
}

void MouseServer::HandleDying()
{
	NetworkManagerServer::sInstance->UnregisterGameObject(this);
}


bool MouseServer::HandleCollisionWithCat(RoboCat* inCat) //Jason - When player hits pickup it generates a random effect.
{
	uint8_t tankType = inCat->GetTankType();
	uint8_t tankVersion = inCat->GetTankVersion();
	if (!picked)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 100);

		if (result >= 1 && result <= 25) { //Jason - Restores health
			SendHealthData(inCat);
		}
		else if (result >= 26 && result <= 50) { //Jason - Sets tank to heavy
			uint8_t type = inCat->GetTankType();

			if (inCat->GetTankType()==1) {
				SendTankData(inCat, 1, 1);
				//inCat->SetTankVersion(1);
			}
			else {
				SendTankData(inCat, 1, 20); //Jason - 20 is a value well above any texture value so nothing changes
			}
		}
		else if (result >= 51 && result <= 75) { //Jason - Sets tank to gatling
			uint8_t type = inCat->GetTankType();
			
			if (type == 2) {
				SendTankData(inCat, 2, 2);
			}
			else {
				SendTankData(inCat, 2, 20);
			}
		}
		else { //Jason - Sets tank to tesla 
			uint8_t type = inCat->GetTankType();

			if (type == 3) {
				SendTankData(inCat, 3, 3);
			}
			else {
				SendTankData(inCat, 3, 20);
			}
		}

			/*inCat->SetTankType(tankType);
			inCat->SetTankVersion(tankVersion);*/

		/*if (inCat->GetHealth() <= 15)
			inCat->GetHealth()++;*/

		picked = true;
	}
	//kill yourself!
	SetDoesWantToDie(true);
	return false;
}

void MouseServer::SendTankData(RoboCat* inCat, int tankType, int tankVersion) {
	inCat->SetTankType(tankType);
	inCat->SetTankVersion(tankVersion);

	int ECRS_TankType = 1 << 4;
	NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_TankType); //Jason - Sends new tank type

	int ECRS_TankVersion = 1 << 5;
	NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_TankVersion); //Jason - Sends new tank type
}

void MouseServer::SendHealthData(RoboCat* inCat) {
	if (inCat->GetHealth() <= 15)
		inCat->GetHealth()++;

	// Hacked in here.d
	int ECRS_Health = 1 << 3;
	NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_Health); //Sends new health value
}


