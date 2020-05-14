#include <RoboCatPCH.h>

namespace
{
	void WriteSignedBinaryValue( OutputMemoryBitStream& inOutputStream, float inValue )
	{
		bool isNonZero = ( inValue != 0.f );
		inOutputStream.Write( isNonZero );
		if( isNonZero )
		{
			inOutputStream.Write( inValue > 0.f );
		}
	}

	void ReadSignedBinaryValue( InputMemoryBitStream& inInputStream, float& outValue )
	{
		bool isNonZero;
		inInputStream.Read( isNonZero );
		if( isNonZero )
		{
			bool isPositive;
			inInputStream.Read( isPositive );
			outValue = isPositive ? 1.f : -1.f;
		}
		else
		{
			outValue = 0.f;
		}
	}

	void WriteNonBinaryValue(OutputMemoryBitStream& inOutputStream, float inValue)
	{
		inOutputStream.Write(inValue);
	}

	void ReadNonBinaryValue(InputMemoryBitStream& inInputStream, float& outValue)
	{
		float val;
		inInputStream.Read(val);
		outValue = val;
	}
}

bool InputState::Write( OutputMemoryBitStream& inOutputStream ) const
{
	WriteSignedBinaryValue( inOutputStream, GetDesiredHorizontalDelta() );
	WriteSignedBinaryValue( inOutputStream, GetDesiredVerticalDelta() );
	//Dylan writes rotation to output stream
	WriteNonBinaryValue(inOutputStream, GetDesiredRotation());
	inOutputStream.Write( mIsShooting );

	return false;
}

bool InputState::Read( InputMemoryBitStream& inInputStream )
{
	
	ReadSignedBinaryValue( inInputStream, mDesiredRightAmount );
	ReadSignedBinaryValue( inInputStream, mDesiredForwardAmount );
	//Dylan reads rotation from output stream
    ReadNonBinaryValue(inInputStream, mDesiredRotation);
	inInputStream.Read( mIsShooting );

	return true;
}