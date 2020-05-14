class YarnClient : public Yarn
{
public:
	static	GameObjectPtr	StaticCreate()		{ return GameObjectPtr( new YarnClient() ); }

	virtual void		Read( InputMemoryBitStream& inInputStream ) override;
	virtual bool		HandleCollisionWithCat( RoboCat* inCat ) override;
	void				SetBulletTexture();
	void				PlayBulletSound();

protected:
	YarnClient();

private:
	SFSpriteComponentPtr m_sprite;
	uint8_t mBullet;
};