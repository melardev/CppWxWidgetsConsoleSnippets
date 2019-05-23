#pragma once
#include <wx/wx.h>
#include <wx/wfstream.h>
#include <wx/filename.h>
#include <wx/zipstrm.h>

namespace ZipCompression
{
	bool ZipFile()
	{
		wxString archivePath = wxGetCwd() + "/wx_archive.zip";
		wxFFileOutputStream fileOutputStream(archivePath);

		if (!fileOutputStream.IsOk())
		{
			wxPrintf("Could not create the file");
			return false;
		}

		wxZipOutputStream zipOutputStream(fileOutputStream);
		if (!zipOutputStream.IsOk())
		{
			wxPrintf("Could not open the archive for writing %s\n", archivePath);
			return false;
		}


		zipOutputStream.PutNextEntry("EmptyFileJustForTest");
		wxString fileNameStr = "./wx_file.txt";

		wxFileName fileName(fileNameStr);
		if (fileName.Exists())
		{
			zipOutputStream.PutNextEntry(fileName.GetName() + "." + fileName.GetExt());
			{
				wxFileInputStream fileInputStream(fileNameStr);
				if (!fileInputStream.IsOk())
				{
					wxPrintf("Could not open the file %s\n", fileNameStr);
					return false;
				}
				zipOutputStream.Write(fileInputStream);
			}

			zipOutputStream.PutNextEntry("dir1/dir2/copy_txt_file.txt");
			{
				wxFileInputStream fileInputStream(fileNameStr);
				if (!fileInputStream.IsOk())
				{
					wxPrintf("Could not open the file %s\n", fileNameStr);
					return false;
				}
				zipOutputStream.Write(fileInputStream);
			}
		}
		else
		{
			wxPrintf("File does not exist");
		}
		zipOutputStream.Close();
		return true;
	}

	void main()
	{
		ZipFile();
	}
}
