#pragma once
#include <wx/filename.h>
#include <wx/wxcrtvararg.h>

namespace RemoveFileSnippet
{
	void main()
	{
		// On Windows, the prefix is up to 3 characters, so only the first 3 chars will be taken
		wxString tempFile = wxFileName::CreateTempFileName("wxSnippets");

		if (!tempFile.IsEmpty())
		{
			wxPrintf("%s has been created successfully\n", tempFile);
			if (wxRemoveFile(tempFile))
			{
				wxPrintf("%s Has been deleted successfully\n", tempFile);
			}
		}
		else
		{
			wxPrintf("Could not create a temporary file\n");
		}
	}
}
