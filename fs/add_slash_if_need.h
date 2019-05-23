#pragma once
#include <wx/filename.h>
#include <wx/wxcrtvararg.h>

namespace AddSlashIfNeeded
{
	void AddSlashIfNeeded(wxString& path)
	{
		if (!path.EndsWith(wxFileName::GetPathSeparator()))
			path += wxFileName::GetPathSeparator();

		// Or using macros
		// if (!path.EndsWith(wxFILE_SEP_PATH))
	}

	void main()
	{
		wxString myDirPath("/root/Desktop");
		wxPrintf("%s\n", myDirPath);

		AddSlashIfNeeded(myDirPath);
		wxPrintf("%s\n", myDirPath);
	}
}
