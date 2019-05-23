#pragma once
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/string.h>

namespace wxFileNameUsage
{
	void main()
	{
		wxFileName fileName(wxGetCwd() + "/wx_archive.zip");
		if (fileName.HasExt())
			wxPrintf("Has Extension %s\n", fileName.GetExt());

		if (fileName.HasVolume())
			wxPrintf("Has Volume %s\n", fileName.GetVolume());

		if (fileName.HasName())
			wxPrintf("Has Name %s\n", fileName.GetName());

		wxPrintf("\n");

		wxPrintf("Native style %s\n", fileName.GetFullPath(wxPathFormat::wxPATH_NATIVE));
		wxPrintf("Windows style %s\n", fileName.GetFullPath(wxPathFormat::wxPATH_WIN));
		wxPrintf("Unix style %s\n\n", fileName.GetFullPath(wxPathFormat::wxPATH_UNIX));

		wxFileName fileName2("./wx_text.txt");

		if (fileName2.IsRelative())
		{
			wxPrintf("Filename2: %s\n", fileName2.GetPath());
			wxPrintf("Filename2 FullPath(): %s\n\n", fileName2.GetFullPath());

			if (fileName2.MakeAbsolute())
			{
				wxPrintf("Filename2: %s\n", fileName2.GetPath());
				wxPrintf("Filename2 FullPath(): %s\n", fileName2.GetFullPath());
				const wxString fileNameStr = fileName2.GetFullPath();
				wxPrintf("FileName2: %s\n", fileNameStr);
			}
		}
	}
}
