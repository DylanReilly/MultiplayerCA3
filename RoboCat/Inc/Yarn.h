class Yarn : public GameObject
{
public:

	CLASS_IDENTIFICATION( 'YARN', GameObject )

	enum EYarnReplicationState
	{
		EYRS_Pose			= 1 << 0,
		EYRS_Color			= 1 << 1,
		EYRS_PlayerId		= 1 << 2,
		EYRS_BulletId		= 1	<<	3,

		EYRS_AllState	= EYRS_Pose | EYRS_Color | EYRS_PlayerId | EYRS_BulletId
	};

	static	GameObject*	StaticCreate() { return new Yarn(); }

	virtual uint32_t	GetAllStateMask()	const override	{ return EYRS_AllState; }

	virtual uint32_t	Write( OutputMemoryBitStream& inOutputStream, uint32_t inDirtyState ) const override;

	void			SetVelocity( const Vector3& inVelocity )	{ mVelocity = inVelocity; }
	const Vector3&	GetVelocity() const					{ return mVelocity; }

	void		SetPlayerId( int inPlayerId )	{ mPlayerId = inPlayerId; }
	void		SetTankType(uint8_t tankType) { mTankType = tankType; }
	int			GetPlayerId() const				{ return mPlayerId; }
	uint8_t		GetBulletId() { return mBulletId; }

	void		SetOffSet(float offset) { mOffSet = offset; }

	void		InitFromShooter( RoboCat* inShooter );
	void		FindBulletID(uint8_t tankType);
	void		SetBulletID(uint8_t bulletID) { mBulletId = bulletID; }

	virtual void Update() override;

	virtual bool HandleCollisionWithCat( RoboCat* inCat ) override;

protected:
	Yarn();


	Vector3		mVelocity;

	float		mMuzzleSpeed;
	int			mPlayerId;
	uint8_t		mTankType;
	uint8_t		mBulletId;
	float		mOffSet;

};

typedef shared_ptr< Yarn >	YarnPtr;