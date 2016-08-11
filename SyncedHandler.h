// SyncedHandler.h : Declaration of the CSyncedHandler

#pragma once
#include <Shlobj.h>
#include "resource.h"       // main symbols



#include "KBShellExt_i.h"

#include "StatusImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSyncedHandler

class ATL_NO_VTABLE CSyncedHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSyncedHandler, &CLSID_SyncedHandler>,
	public IShellIconOverlayIdentifier,
	public ISyncedHandler
{
public:
	CSyncedHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SYNCEDHANDLER)

DECLARE_NOT_AGGREGATABLE(CSyncedHandler)

BEGIN_COM_MAP(CSyncedHandler)
	COM_INTERFACE_ENTRY(ISyncedHandler)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(IsMemberOf)(THIS_ _In_ PCWSTR pwszPath, DWORD dwAttrib) { return _status.IsMemberOf(pwszPath, dwAttrib); }
	STDMETHOD(GetOverlayInfo)(THIS_ _Out_writes_(cchMax) PWSTR pwszIconFile, int cchMax, _Out_ int * pIndex, _Out_ DWORD * pdwFlags) { return _status.GetOverlayInfo(pwszIconFile, cchMax, pIndex, pdwFlags); }
	STDMETHOD(GetPriority)(THIS_ _Out_ int * pIPriority) { return  _status.GetPriority(pIPriority); }

private:
	StatusImpl<KBStatus::synced> _status;
};

OBJECT_ENTRY_AUTO(__uuidof(SyncedHandler), CSyncedHandler)
