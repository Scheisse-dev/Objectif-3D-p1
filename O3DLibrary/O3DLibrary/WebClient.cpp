#include "WebClient.h"
#pragma comment(lib, "Urlmon.lib")
#include <urlmon.h>
#include "Exception.h"
#include "Process.h"
#include "WebCallBack.h"



#pragma region constructor
Core::Net::WebClient::WebClient(const Uri& _uri)
{
	uri = _uri;
}

Core::Net::WebClient::WebClient(const WebClient& _copy)
{
	uri = _copy.uri;
}



#pragma endregion constructor
#pragma region methods
void Core::Net::WebClient::DownloadFile(const PrimitiveType::FString& _pathFile)
{
	const std::wstring _uriWstr = uri.Path().ToWString();
	const LPCWSTR _uri = _uriWstr.c_str();
	const std::wstring _pathWstr = _pathFile.ToWString();
	const LPCWSTR _path = _pathWstr.c_str();
	Core::Net::WebCallback* _callback = new Core::Net::WebCallback();
	_callback->OnDownloadProgress.AddDynamic(&OnDownloadProgress, &Action<float>::Invoke); 
	const HRESULT _result = URLDownloadToFile(nullptr, _uri, _path, 0, _callback); 

	if (_result != S_OK) throw Exception("[WebClient] => uri doesn't valid !"); 
	else
	{
		Diagnostics::Process::Start(_pathFile, "");
	}
}
#pragma endregion methods
