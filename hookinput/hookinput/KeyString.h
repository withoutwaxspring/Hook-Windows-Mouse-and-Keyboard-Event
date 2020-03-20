#pragma once
class CKeyString
{
public:
	CKeyString();
	~CKeyString();
	DWORD ToVkeyVal(CString keyname);
	CString ToVkeyName(DWORD vkeyval);
private:
	CString keylist[256];
};

