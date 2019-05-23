#pragma once
#include <wx/wx.h>

namespace LaunchBrowser
{
	void main()
	{
		wxLaunchDefaultBrowser(wxT("http://melardev.com"));
	}
}
