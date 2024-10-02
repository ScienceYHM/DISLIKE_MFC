
// DISLIKEDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DISLIKE.h"
#include "DISLIKEDlg.h"
#include "afxdialogex.h"
#include "教师端.h"
#include "程序信息.h"
#include <cassert>
#include "关于.h"
#include "歌单.h"
#include <windows.h>
#include <urlmon.h>
#include <iostream>
#include <fstream>
#include <string>
#include <shlobj.h>
#include <direct.h>

#pragma comment(lib, "urlmon.lib")

void DeleteDirectoryRecursively(const std::string& directory) {
	WIN32_FIND_DATAA findFileData;
	HANDLE hFind = FindFirstFileA((directory + "\\*").c_str(), &findFileData);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			std::string fileOrDir = directory + "\\" + findFileData.cFileName;
			if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
					DeleteDirectoryRecursively(fileOrDir);  // 递归删除子目录
					_rmdir(fileOrDir.c_str());  // 删除空目录
				}
			}
			else {
				DeleteFileA(fileOrDir.c_str());  // 删除文件
			}
		} while (FindNextFileA(hFind, &findFileData) != 0);
		FindClose(hFind);
	}
	_rmdir(directory.c_str());  // 删除根目录
}

/*int main() {
	// 创建DSVN文件夹
	const char* folderPath = "D:\\DSVN";
	CreateDirectoryA(folderPath, NULL);

	// 下载version.zip
	const char* versionZipUrl = "https://codeload.github.com/ScienceYHM/version/zip/refs/heads/main";
	std::string versionZipPath = std::string(folderPath) + "\\version.zip";
	URLDownloadToFileA(NULL, versionZipUrl, versionZipPath.c_str(), 0, NULL);

	// 解压version.zip
	const char* versionFolderPath = "D:\\DSVN\\version-main";
	ShellExecuteA(NULL, "open", "cmd.exe", ("/C powershell Expand-Archive -Path \"" + versionZipPath + "\" -DestinationPath \"" + folderPath + "\"").c_str(), NULL, SW_HIDE);

	// 读取version.txt
	std::ifstream versionFile("D:\\DSVN\\version-main\\version.txt");
	std::string versionStr;
	if (versionFile) {
		std::getline(versionFile, versionStr);
		versionFile.close();
	}
	else {
		std::cout << "无法读取version.txt" << std::endl;
		return 1;
	}

	int version = std::stoi(versionStr);
	if (version <= 15500) {
		std::cout << "不用更新" << std::endl;
	}
	else {
		std::cout << "需要更新" << std::endl;

		// 下载DISLIKE_NEW.zip
		const char* dislikeZipUrl = "https://codeload.github.com/ScienceYHM/DISLIKE_NEW/zip/refs/heads/main";
		std::string dislikeZipPath = std::string(folderPath) + "\\DISLIKE_NEW.zip";
		URLDownloadToFileA(NULL, dislikeZipUrl, dislikeZipPath.c_str(), 0, NULL);

		// 解压DISLIKE_NEW.zip
		ShellExecuteA(NULL, "open", "cmd.exe", ("/C powershell Expand-Archive -Path \"" + dislikeZipPath + "\" -DestinationPath \"" + folderPath + "\"").c_str(), NULL, SW_HIDE);

		// 移动DISLIKE.exe到桌面
		std::string dislikeExePath = std::string(folderPath) + "\\DISLIKE_NEW-main\\DISLIKE.exe";
		std::string desktopPath;
		char path[MAX_PATH];
		if (SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, path) == S_OK) {
			desktopPath = std::string(path) + "\\DISLIKE.exe";
			MoveFileA(dislikeExePath.c_str(), desktopPath.c_str());
		}

		// 删除文件夹
		RemoveDirectoryA(folderPath);
	}

	return 0;
}
*/


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDISLIKEDlg 对话框



CDISLIKEDlg::CDISLIKEDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DISLIKE_DIALOG, pParent)
	, m_Enabled(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDISLIKEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CDISLIKEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CDISLIKEDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &CDISLIKEDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDISLIKEDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDISLIKEDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDISLIKEDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CDISLIKEDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CDISLIKEDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDISLIKEDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &CDISLIKEDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDISLIKEDlg 消息处理程序

BOOL CDISLIKEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDISLIKEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDISLIKEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDISLIKEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDISLIKEDlg::OnBnClickedCancel()
{
	UpdateData();
	CDialog::EndDialog(0);
	
}



void CDISLIKEDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	教师端*pdlg;
	pdlg = new 教师端();
	pdlg->Create(IDD_DIALOG1);
	pdlg->ShowWindow(SW_NORMAL);
	
}


void CDISLIKEDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	关于* pdlg;
	pdlg = new 关于();
	pdlg->Create(IDD_ABOUTBOX);
	pdlg->ShowWindow(SW_NORMAL);
}


void CDISLIKEDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	程序信息* pdlg;
	pdlg = new 程序信息();
	pdlg->Create(IDD_DIALOG2);
	pdlg->ShowWindow(SW_NORMAL);
}

void CDISLIKEDlg::OnBnClickedButton5()
{
	UpdateData();
	const TCHAR szOperation[] = _T("open");
	const TCHAR szAddress[] = _T("https://codeload.github.com/ScienceYHM/DISLIKE_V1.0.2.5/zip/refs/heads/main");
	int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
	{
		HINSTANCE hRslt = ShellExecute(NULL, szOperation,
			szAddress, NULL, NULL, SW_SHOWNORMAL);
		assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

	}
}


void CDISLIKEDlg::OnBnClickedButton6()
{
	UpdateData();
	歌单* pdlg;
	pdlg = new 歌单();
	pdlg->Create(IDD_DIALOG3);
	pdlg->ShowWindow(SW_NORMAL);
}



void CDISLIKEDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	const TCHAR szOperation[] = _T("open");
	const TCHAR szAddress[] = _T("https://vscode.dev");
	int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
	{
		HINSTANCE hRslt = ShellExecute(NULL, szOperation,
			szAddress, NULL, NULL, SW_SHOWNORMAL);
		assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

	}
}


void CDISLIKEDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	const TCHAR szOperation[] = _T("open");
	const TCHAR szAddress[] = _T("https://mc.163.com/index.html");
	int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
	{
		HINSTANCE hRslt = ShellExecute(NULL, szOperation,
			szAddress, NULL, NULL, SW_SHOWNORMAL);
		assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

	}

}


void CDISLIKEDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	// 创建DSVN文件夹


// 用于删除文件夹及其所有内容的递归函数
	

		// 创建DSVN文件夹
		const char* folderPath = "D:\\DSVN";
		CreateDirectoryA(folderPath, NULL);

		// 下载version.zip
		const char* versionZipUrl = "https://codeload.github.com/ScienceYHM/version/zip/refs/heads/main";
		std::string versionZipPath = std::string(folderPath) + "\\version.zip";
		HRESULT hr = URLDownloadToFileA(NULL, versionZipUrl, versionZipPath.c_str(), 0, NULL);
		if (hr != S_OK) {
			MessageBoxA(NULL, "下载version.zip失败", "错误", MB_OK | MB_ICONERROR);
			
		}

		// 解压version.zip
		const char* versionFolderPath = "D:\\DSVN\\version-main";
		ShellExecuteA(NULL, "open", "cmd.exe", ("/C powershell Expand-Archive -Path \"" + versionZipPath + "\" -DestinationPath \"" + folderPath + "\"").c_str(), NULL, SW_HIDE);
		Sleep(2000); // 等待解压完成

		// 读取version.txt
		std::ifstream versionFile(std::string(versionFolderPath) + "\\version.txt");
		std::string versionStr;
		if (versionFile) {
			std::getline(versionFile, versionStr);
			versionFile.close();
		}
		else {
			MessageBoxA(NULL, "无法读取version.txt", "错误", MB_OK | MB_ICONERROR);
			
		}

		int version = std::stoi(versionStr);
		if (version <= 20000) {
			MessageBoxA(NULL, "不用更新", "提示", MB_OK | MB_ICONINFORMATION);

			// 删除所有文件
			DeleteFileA(versionZipPath.c_str());
			DeleteDirectoryRecursively(folderPath); // 删除整个DSVN文件夹
		}
		else {
			MessageBoxA(NULL, "需要更新", "提示", MB_OK | MB_ICONINFORMATION);

			// 下载DISLIKE_NEW.zip
			const char* dislikeZipUrl = "https://codeload.github.com/ScienceYHM/DISLIKE_NEW/zip/refs/heads/main";
			std::string dislikeZipPath = std::string(folderPath) + "\\DISLIKE_NEW.zip";
			hr = URLDownloadToFileA(NULL, dislikeZipUrl, dislikeZipPath.c_str(), 0, NULL);
			if (hr != S_OK) {
				MessageBoxA(NULL, "下载DISLIKE_NEW.zip失败", "错误", MB_OK | MB_ICONERROR);
				
			}

			// 解压DISLIKE_NEW.zip
			ShellExecuteA(NULL, "open", "cmd.exe", ("/C powershell Expand-Archive -Path \"" + dislikeZipPath + "\" -DestinationPath \"" + folderPath + "\"").c_str(), NULL, SW_HIDE);
			Sleep(2000); // 等待解压完成

			// 移动DISLIKE.exe到桌面
			std::string dislikeExePath = std::string(folderPath) + "\\DISLIKE_NEW-main\\DISLIKE.exe";
			char desktopPath[MAX_PATH];
			if (SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath) == S_OK) {
				std::string destPath = std::string(desktopPath) + "\\DISLIKE.exe";
				MoveFileA(dislikeExePath.c_str(), destPath.c_str());
			}
			else {
				MessageBoxA(NULL, "无法获取桌面路径", "错误", MB_OK | MB_ICONERROR);
				
			}

			// 删除所有下载文件和文件夹
			DeleteFileA(versionZipPath.c_str());
			DeleteFileA(dislikeZipPath.c_str());
			DeleteDirectoryRecursively(folderPath); 
			MessageBoxA(NULL, "更新成功", "提示", MB_OK | MB_ICONINFORMATION);// 删除整个DSVN文件夹
		}

		
	}

	


