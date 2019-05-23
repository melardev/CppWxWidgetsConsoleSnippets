#pragma once
#include <wx/event.h>
#include <wx/wxcrtvararg.h>

namespace GetSetEnvVariables
{
	void main()
	{
		wxString osValue;
		wxGetEnv("OS", &osValue);
		wxPrintf("OS: %s\n", osValue);

		wxString myValue;
		wxGetEnv("MY_WX_VAR", &myValue);
		wxPrintf("MY_WX_VAR: %s\n", myValue);

		wxSetEnv("MY_WX_VAR", "MY_VALUE");

		wxGetEnv("MY_WX_VAR", &myValue);
		wxPrintf("MY_WX_VAR: %s\n", myValue);
	}
}
