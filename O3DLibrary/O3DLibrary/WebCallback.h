#pragma once
#include "Object.h"
#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include "ActionInternal.h"

namespace Core
{
	namespace Net
	{
		class O3DLIBRARY_API WebCallback : public Object, public IBindStatusCallback
		{
#pragma region event 
		public:
			Action<float> OnDownloadProgress = nullptr;
#pragma endregion event 
#pragma region f/p
		private: 
			int lastPercent = 0;
#pragma endregion f/p
#pragma region IBindStatusCallback
		public:
			virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;
			virtual ULONG __stdcall AddRef(void) override;
			virtual ULONG __stdcall Release(void) override;
			virtual HRESULT __stdcall OnStartBinding(DWORD dwReserved, IBinding* pib) override;
			virtual HRESULT __stdcall GetPriority(LONG* pnPriority) override;
			virtual HRESULT __stdcall OnLowResource(DWORD reserved) override;
			virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText) override;
			virtual HRESULT __stdcall OnStopBinding(HRESULT hresult, LPCWSTR szError) override;
			virtual HRESULT __stdcall GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo) override;
			virtual HRESULT __stdcall OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed) override;
			virtual HRESULT __stdcall OnObjectAvailable(REFIID riid, IUnknown* punk) override;
#pragma endregion IBindStatusCallback
		};
	}
}