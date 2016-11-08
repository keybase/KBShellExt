#pragma once
using namespace ATL;

#define KBFS_EXTENSION _T(".kbfs_status")

HRESULT MatchKBStatus(LPCWSTR pwszPath, CStringA status);

enum KBStatus { none, privateSynced, privateSyncing, publicSynced, publicSyncing
};

template<KBStatus K> class StatusImpl
{
public:
	STDMETHODIMP	GetOverlayInfo(LPWSTR pwszIconFile, int cchMax, int *pIndex, DWORD *pdwFlags)
	{ 
		if (!(pwszIconFile && cchMax && pIndex && pdwFlags))
			return E_INVALIDARG;

		// Get our module's full path
		GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), pwszIconFile, cchMax);

		// Use icons in the resource
		*pIndex = GetIconIndex();

		*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

		return S_OK;
	}
	STDMETHODIMP	GetPriority(int *pPriority)
	{
		if (pPriority)
		{
			*pPriority = 0;
			return S_OK;
		}
		return E_INVALIDARG;
	}
	STDMETHODIMP	IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib) { return MatchKBStatus(pwszPath, GetStatusLabelA()); }

private:
	CStringA GetStatusLabelA();
	int		GetIconIndex();
};

