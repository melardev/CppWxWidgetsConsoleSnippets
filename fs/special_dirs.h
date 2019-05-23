#pragma once
#include <wx/filename.h>
#include <wx/wxcrtvararg.h>
#include <wx/stdpaths.h>

namespace SpecialDirectories
{
	void main()
	{
		wxPrintf("Current working directory: %s\n", wxGetCwd());

		wxPrintf("HomeDir: %s\n", wxFileName::GetHomeDir());
		wxPrintf("ConfigDir: %s\n", wxStandardPaths::Get().GetConfigDir());

		wxPrintf("TempDir: %s\n", wxFileName::GetTempDir());
		wxPrintf("TempDir: %s\n", wxStandardPaths::Get().GetTempDir());


		wxPrintf("UserLocalDir: %s\n", wxStandardPaths::Get().GetUserLocalDataDir());
		wxPrintf("ResourceDir: %s\n", wxStandardPaths::Get().GetResourcesDir());

		wxPrintf("ExecutablePath: %s\n", wxStandardPaths::Get().GetExecutablePath());
	}
}
