#pragma once
#include <wx/filename.h>
#include <wx/wxcrtvararg.h>

namespace RenameFileSnippet
{
	void main()
	{
		wxFile file("rename_file_test.txt", wxFile::OpenMode::write);
		if (file.IsOpened())
		{
			file.Close();
			wxRenameFile("./rename_file_test.txt", "./rename_file_test_renamed.txt");
			wxPrintf("File renamed successfully\n");
		}
		else
		{
			wxPrintf("Could not create the file\n");
		}
	}
}
