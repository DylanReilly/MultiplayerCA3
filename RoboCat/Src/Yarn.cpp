#include <RoboCatPCH.h>
#include <cmath>

Yarn::Yarn() :
	mMuzzleSpeed( 400.f ),
	mVelocity( Vector3::Zero ),
	mPlayerId( 0 ),
	mTankType(0),
	mBulletId(0)
{
	SetScale( GetScale() * .02f );
	SetCollisionRadius( 15.f );
	SetRotation(GetRotation());
}



uint32_t Yarn::Write( OutputMemoryBitStream& inOutputStream, uint32_t inDirtyState ) const 
{
	uint32_t writtenState = 0;

	if( inDirtyState & EYRS_Pose )
	{
		inOutputStream.Write( (bool)true );

		Vector3 location = GetLocation();
		inOutputStream.Write( location.mX );
		inOutputStream.Write( location.mY );

		Vector3 velocity = GetVelocity();
		inOutputStream.Write( velocity.mX );
		inOutputStream.Write( velocity.mY );

		inOutputStream.Write( GetRotation() );

		writtenState |= EYRS_Pose;
	}
	else
	{
		inOutputStream.Write( (bool)false );
	}

	if( inDirtyState & EYRS_Color )
	{
		inOutputStream.Write( (bool)true );

		inOutputStream.Write( GetColor() );

		writtenState |= EYRS_Color;
	}
	else
	{
		inOutputStream.Write( (bool)false );
	}

	if( inDirtyState & EYRS_PlayerId )
	{
		inOutputStream.Write( (bool)true );

		inOutputStream.Write( mPlayerId, 8 );

		writtenState |= EYRS_PlayerId;
	}
	else
	{
		inOutputStream.Write( (bool)false );
	}

	if (inDirtyState & EYRS_BulletId) //Jason - Writes bullet ID
	{
		inOutputStream.Write((bool)true);

		inOutputStream.Write(mBulletId, 4);

		writtenState |= EYRS_BulletId;
	}
	else
	{
		inOutputStream.Write((bool)false);
	}




	return writtenState;
}



bool Yarn::HandleCollisionWithCat( RoboCat* inCat )
{
	( void ) inCat;

	//you hit a cat, so look like you hit a cat

	return false;
}

void Yarn::InitFromShooter( RoboCat* inShooter )//Jason - Set bullet texture based off of tank type
{
	SetColor( inShooter->GetColor() );
	SetPlayerId( inShooter->GetPlayerId() );
	SetTankType(inShooter->GetTankType()); //Jason - Gets tank type so we can change bullet type

	FindBulletID(mTankType);

	//Dylan - fixed projectiles shooting in the correct direction, don't what the hell that "thor" thing did
	Vector3 forward = inShooter->GetForwardRadianVector();
	//Vector3 vel = inShooter->GetVelocity();
	//sf::Vector2f normVel = thor::unitVector(sf::Vector2f(vel.mX, vel.mY));
	//Vector3 normVel = unitVector(vel);
	sf::Vector2f temp = sf::Vector2f(0, -1);
	//thor::rotate(temp, inShooter->GetRotation());

	//SetVelocity(normVel * mMuzzleSpeed);
	SetVelocity(forward * mMuzzleSpeed);
	//SetVelocity(Vector3(temp.x, temp.y, 0) * mMuzzleSpeed);
	SetLocation( inShooter->GetLocation() + GetForwardRadianVectorOffset(mOffSet) /*+ Vector3(temp.x,temp.y,0) * 0.55f*/ );
	SetRotation( inShooter->GetRotation());
}

void Yarn::FindBulletID(uint8_t tankType) { //Jason - sets ID for bullet to send over network
	switch (tankType)
	{
	case 0:
		SetBulletID(0);
		break;
	case 1:
		SetBulletID(1);
		break;
	case 2:
		SetBulletID(2);
		break;
	case 3:
		SetBulletID(3);
		break;
	default:
		SetBulletID(0);
		break;
	}
}

void Yarn::Update()
{
	
	float deltaTime = Timing::sInstance.GetDeltaTime();

	SetLocation( GetLocation() + mVelocity * deltaTime );
	

	//we'll let the cats handle the collisions
}
