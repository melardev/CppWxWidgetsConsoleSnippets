#pragma once
#include <wx/filename.h>
#include <wx/dir.h>


namespace FsDirectories
{
	void main()
	{
		const wxString dirPath = wxGetCwd() + wxFileName::GetPathSeparator() + "folder1";

		if (!wxDirExists(dirPath))
		{
			wxPrintf("%s does not exist, let's create it\n", dirPath);
			if (wxMkdir(dirPath))
			{
				wxPrintf("Directory created successfully\n\n");

				wxPrintf("Let's try to delete it now\n");
				// wxFileName::Rmdir(dirPath, wxPATH_RMDIR_FULL);
				if (wxFileName::Rmdir(dirPath))
					wxPrintf("Folder deleted successfully\n");
				else
					wxPrintf("Could not delete the directory %s\n", dirPath);
			}
		}
	}
}
