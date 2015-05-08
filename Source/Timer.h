////////////////////////////////////////////////////////////////////////////////
// -------------------------------------------------------------------------- //
//                                                                            //
//                       (C) 2010-2015 Robot Developers                       //
//                       See LICENSE for licensing info                       //
//                                                                            //
// -------------------------------------------------------------------------- //
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
// Prefaces                                                                   //
//----------------------------------------------------------------------------//

#ifndef ROBOT_TIMER_H
#define ROBOT_TIMER_H

#include "Types.h"
namespace Robot {



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class ROBOT_EXPORT Timer
{
public:
	Timer							(void);

public:
	void			Start			(void);
	void			Reset			(void);
	uint64			Restart			(void);

	uint64			GetElapsed		(void) const;
	bool			HasStarted		(void) const;
	bool			HasExpired		(uint64 time) const;

	static void		Sleep			(const Range& time);
	static void		Sleep			(uint32 minimum,
									 uint32 maximum);

	static uint64	GetCpuTime		(void);

public:
	uint64			operator ()		(void) const;

	bool			operator <		(const Timer& timer) const;
	bool			operator >		(const Timer& timer) const;
	bool			operator <=		(const Timer& timer) const;
	bool			operator >=		(const Timer& timer) const;

	bool			operator ==		(const Timer& timer) const;
	bool			operator !=		(const Timer& timer) const;

private:
	uint64			mStarted;		// Time started (milliseconds)
};

}
#endif // ROBOT_TIMER_H
