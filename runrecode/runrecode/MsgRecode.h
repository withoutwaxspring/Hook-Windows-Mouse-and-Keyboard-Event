#pragma once
#include "KeyString.h"
#include <map>
#include <vector>

#define TIMESPAN 0x0001
using namespace std;
class CMsgRecode
{
public:
	CMsgRecode();
	~CMsgRecode();
	BOOL LoadRecodeFile(CString strfilename);
	void RunRecode(CString strfilename);
private:
	CString recodestr;
	CKeyString keystr;
	map <CString,UINT> eventstrs;
	vector<CString> recodelines;
	POINT getmousepointbystr(CString mouseparamstr);
};

