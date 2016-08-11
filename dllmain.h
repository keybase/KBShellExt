// dllmain.h : Declaration of module class.

class CKBShellExtModule : public ATL::CAtlDllModuleT< CKBShellExtModule >
{
public :
	DECLARE_LIBID(LIBID_KBShellExtLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_KBSHELLEXT, "{79FACD4C-EFBE-46DD-9457-EE070A00B53E}")
};

extern class CKBShellExtModule _AtlModule;
