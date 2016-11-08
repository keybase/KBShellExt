#include "stdafx.h"
#include "StatusImpl.h"
#include <vector>

using namespace ATL;

HRESULT MatchKBStatus(LPCWSTR pwszPath, CStringA statusA)
{

	if(pwszPath == NULL)
	{
		return S_FALSE;
	}
	int pathlen = lstrlen(pwszPath);
	int extensionlen = lstrlen(KBFS_EXTENSION);
	if(pathlen < extensionlen)
	{
		return S_FALSE;
	}
	// See if this is our extension file - skip it if so
	if(lstrcmp(pwszPath + (pathlen - extensionlen), KBFS_EXTENSION) == 0)
	{
		return S_FALSE;
	}
	CString extPathName = pwszPath;
	extPathName += KBFS_EXTENSION;
	CAtlFile statusFile;
	if(statusFile.Create(extPathName, GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING, 0) != S_OK)
	{
		return S_FALSE;
	}
	CStringA targetStatusA;
	HRESULT readResult = statusFile.Read(targetStatusA.GetBuffer(statusA.GetLength() + 1), statusA.GetLength());
	targetStatusA.ReleaseBuffer();
	if (readResult != S_OK)
	{
		return S_FALSE;
	}
	if (targetStatusA == statusA)
	{
		return S_OK;
	}
	
	return S_FALSE;
}

template<> CStringA StatusImpl<KBStatus::privateSyncing>::GetStatusLabelA()
{
	return CStringA("private syncing");
}

template<> CStringA StatusImpl<KBStatus::privateSynced>::GetStatusLabelA()
{
	return CStringA("private synced");
}

template<> CStringA StatusImpl<KBStatus::publicSyncing>::GetStatusLabelA()
{
	return CStringA("public syncing");
}

template<> CStringA StatusImpl<KBStatus::publicSynced>::GetStatusLabelA()
{
	return CStringA("public synced");
}

template<> int StatusImpl<KBStatus::privateSyncing>::GetIconIndex()
{
	return 1;
}

template<> int StatusImpl<KBStatus::privateSynced>::GetIconIndex()
{
	return 0;
}

template<> int StatusImpl<KBStatus::publicSyncing>::GetIconIndex()
{
	return 3;
}

template<> int StatusImpl<KBStatus::publicSynced>::GetIconIndex()
{
	return 2;
}
