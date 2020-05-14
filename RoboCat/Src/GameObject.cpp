#include<RoboCatPCH.h>

GameObject::GameObject() :
	mIndexInWorld( -1 ),
	mCollisionRadius( 1.f ),
	mDoesWantToDie( false ),
	mRotation( 0.f ),
	mNetworkId( 0 ),
	mColor( Colors::White ),
	mScale( 1.0f )
{
}

void GameObject::Update()
{
	//object don't do anything by default...	
}


Vector3 GameObject::GetForwardVector()	const
{
	//should we cache this when you turn?
	return Vector3( sinf( mRotation ), -cosf( mRotation ), 0.f );
}

Vector3 GameObject::GetForwardRadianVector()	const
{
	//should we cache this when you turn?
	return Vector3(sin((3.141f/180.f) * mRotation), -cosf((3.141f / 180.f) * mRotation), 0.f);
	//Vector3 newPos(playerPosition.mX + (1 * sin((3.141f / 180.f) * GetRotation()) ), playerPosition.mY + (1 * -cos((3.141f / 180.f) * GetRotation())), playerPosition.mZ);
}

void GameObject::SetNetworkId( int inNetworkId )
{ 
	//this doesn't put you in the map or remove you from it
	mNetworkId = inNetworkId; 

}

void GameObject::SetRotation( float inRotation )
{ 
	//should we normalize using fmodf?
	mRotation = inRotation;
}

void GameObject::SetRotation(uint8_t inRotation)
{
	GameObject::SetRotation(static_cast<float>(inRotation * 6));
}
