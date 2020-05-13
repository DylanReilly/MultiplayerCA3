#include <RoboCatServerPCH.h>


MouseServer::MouseServer()
{
}

void MouseServer::HandleDying()
{
	NetworkManagerServer::sInstance->UnregisterGameObject( this );
}


bool MouseServer::HandleCollisionWithCat( RoboCat* inCat )
{
	if (!picked)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 100);

		if (result >= 1 && result <= 25) {
			if (inCat->GetHealth() <= 15)
				inCat->GetHealth()++;
		}
		else if (result >= 26 && result <= 50) {
			inCat->SetTankType(1);
		}
		else if (result >= 51 && result <= 75) {
			inCat->SetTankType(2);
		}
		else {
			inCat->SetTankType(3);
		}

		/*if (inCat->GetHealth() <= 15)
			inCat->GetHealth()++;*/

		picked = true;

		// Hacked in here.d
		int ECRS_Health = 1 << 3;
		NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_Health);

		int ECRS_TankType = 1 << 4;
		NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_TankType);
	}
	//kill yourself!
	SetDoesWantToDie( true );
	return false;
}


