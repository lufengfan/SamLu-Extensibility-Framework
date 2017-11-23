// dllmain.h: 模块类的声明。

class CslefoleModule : public ATL::CAtlDllModuleT< CslefoleModule >
{
public :
	DECLARE_LIBID(LIBID_slefole)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SLEFOLE, "{0D296798-02F7-4E3B-84CA-A832EEDEE0EB}")
};

extern class CslefoleModule _AtlModule;
