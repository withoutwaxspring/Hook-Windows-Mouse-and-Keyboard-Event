#pragma once
class CTimer
{
public:
	CTimer();
	~CTimer();
	void start();
	void reset();
	void pause();
	DWORD get_timespan();
	BOOL is_start();
	BOOL is_pause();
	BOOL is_stop();

private:
	BOOL _is_start;
	BOOL _is_pause;
	BOOL _is_stop;
	DWORD _start_time;
	DWORD _pause_time;
	DWORD _stop_time;
};

