#include "stdafx.h"
#include "Timer.h"


CTimer::CTimer()
{
	_is_pause = FALSE;
	_is_start = FALSE;
	_is_stop = TRUE;
	_start_time = 0;
	_pause_time = 0;
	_stop_time = 0;
}


CTimer::~CTimer()
{
}

void CTimer::start()
{
	if (_is_pause)
	{
		_start_time += GetTickCount() - _pause_time;
		return;
	}
	
	if(_is_stop)
	{
		reset();
		_start_time = GetTickCount();
		_is_start = TRUE;
		return;
	}
}

void CTimer::reset()
{
	_is_pause = FALSE;
	_is_start = FALSE;
	_is_stop = TRUE;
	_start_time = 0;
	_pause_time = 0;
	_stop_time = 0;
}

void CTimer::pause()
{
	if (_is_start & (!_is_pause))
	{
		_pause_time = GetTickCount();
		_is_pause = TRUE;
	}
}

DWORD CTimer::get_timespan()
{
	
	return GetTickCount()-_start_time;
}

BOOL CTimer::is_start()
{
	return _is_start;
}

BOOL CTimer::is_pause()
{
	return _is_pause;
}

BOOL CTimer::is_stop()
{
	return _is_stop;
}
