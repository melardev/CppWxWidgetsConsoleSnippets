#pragma once
#include <wx/wx.h>

namespace GetBasicInfo
{
	void main()
	{
		const wxString OSInfo = wxGetOsDescription();

		const wxString OSVersion = std::to_wstring(wxGetOsVersion());

		const wxString userId = wxGetUserId();

		const wxString host = wxGetHostName();
		const wxString userName = wxGetUserName();

		const wxString homeDirectory = wxGetHomeDir();

		const bool is64Bit = wxIsPlatform64Bit();

		wxSize displaySize = wxGetDisplaySize();

		wxPrintf("OS Description: %s\nOS Version: %s\nUser Id: %s\nHost: %s\nUsername: %s\nIs 64 bit: %s\n"
		         "Home directory: %s\nDisplaySize: (%d,%d) %dx%d\n",
		         OSInfo, OSVersion,
		         userId, host, userName,
		         is64Bit ? "Yes" : "No",
		         homeDirectory,
		         displaySize.GetX(), displaySize.GetY(),
		         displaySize.GetWidth(), displaySize.GetHeight());
	}
}
