#pragma once
#include <wx/filename.h>
#include <wx/wxcrtvararg.h>

namespace GetFileSizeSnippet
{
	unsigned long long GetFileSize(const wxString& path)
	{
		// If file does not exist then return -1
		if (!wxFileExists(path)) return -1;

		wxULongLong result = wxFileName::GetSize(path);

		if (result != wxInvalidSize)
			return result.GetValue();

		return wxInvalidSize.GetValue();
	}

	void main()
	{
		const unsigned long long size = GetFileSize("./wx_file.txt");
		if (size != wxInvalidSize)
			wxPrintf("./wx_file.txt has a size of %llu\n", size);
		else
			wxPrintf("Invalid file size\n");
	}
}
