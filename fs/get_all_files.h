#pragma once
#include <wx/filename.h>
#include <wx/dir.h>
#include <wx/wxcrtvararg.h>

namespace GetAllFiles
{
	void main()
	{
		wxArrayString files;

		// This traverses the directory recursively and saves the files into the wxArrayString
		// Never use this, it may take a lot of time before finishing its scan.
		// Up to that point, your app is blocked waiting for GetAllFiles to finish
		// I recommend using wxDir::Traverse which allows you to process files as they are found
		// and you can stop the scan at any time, the snippet is in traverse_dir.h
		wxDir::GetAllFiles(wxGetCwd(), &files);


		if (files.IsEmpty()) return;

		std::vector<wxFileName> filesToFormat;

		for (size_t i = 0; i < files.GetCount(); ++i)
		{
			const wxString item = files.Item(i);
			wxPrintf("%s\n", item);
		}
	}
}
