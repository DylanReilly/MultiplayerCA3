class MouseServer : public Mouse
{
public:
	static GameObjectPtr	StaticCreate() { return NetworkManagerServer::sInstance->RegisterAndReturn( new MouseServer() ); }
	void HandleDying() override;
	virtual bool		HandleCollisionWithCat( RoboCat* inCat ) override;
	void SendTankData(RoboCat* inCat, int tankType, int tankVersion);
	void SendHealthData(RoboCat* inCat);

protected:
	MouseServer();
};