// 教师端.cpp: 实现文件
//

#include "pch.h"
#include "DISLIKE.h"
#include "afxdialogex.h"
#include "教师端.h"
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <chrono>
#include <thread>


// 教师端 对话框

IMPLEMENT_DYNAMIC(教师端, CDialogEx)

教师端::教师端(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_Enabled(FALSE)
{

}

教师端::~教师端()
{
}

void 教师端::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_Enabled);
}


BEGIN_MESSAGE_MAP(教师端, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &教师端::OnBnClickedCheck1)
	ON_BN_CLICKED(IDOK, &教师端::OnBnClickedOk)
END_MESSAGE_MAP()


// 教师端 消息处理程序


void 教师端::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	for (int i = 0; i < 4; i++)
		GetDlgItem(IDC_RADIO1 + i)->EnableWindow(m_Enabled);
}


void 教师端::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if (!m_Enabled)return;
	int nID = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO4);
	if (nID == IDC_RADIO1)
	{
		MessageBox(_T("1.禁止使用此软件扰乱课堂秩序，后果与作者无关;\n2.此软件版权归C10所有\n3.此软件是为了让使用者学会用C/C++程序删除、打开、关闭文件\n4.未经作者许可，禁止复制和转载此文件\n"), _T("DISLIKE-协议"), MB_ICONWARNING);
		while (true) {
			//速度最快
			// 创建一个系统快照，包含所有进程
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapshot == INVALID_HANDLE_VALUE) {
				std::cerr << "Failed to create snapshot." << std::endl;

			}

			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(PROCESSENTRY32);

			// 获取快照中的第一个进程
			if (Process32First(hSnapshot, &pe32)) {
				do {

					// 检查进程名是否是我们想要关闭的
					if (_wcsicmp(pe32.szExeFile, L"DISLIKE_V1.0.2.5.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"REDAgent.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"Yistart.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"StudentMain.exe") == 0) {

						// 打开进程
						HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
						if (hProcess != NULL) {
							// 终止进程
							TerminateProcess(hProcess, 0);
							CloseHandle(hProcess);
						}
					}
				} while (Process32Next(hSnapshot, &pe32)); // 遍历快照中的所有进程
			}

			CloseHandle(hSnapshot);

			// 每隔0.0001秒刷新一次
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
	}if (nID == IDC_RADIO2)
	{
		//速度一般
		MessageBox(_T("1.禁止使用此软件扰乱课堂秩序，后果与作者无关;\n2.此软件版权归C10所有\n3.此软件是为了让使用者学会用C/C++程序删除、打开、关闭文件\n4.未经作者许可，禁止复制和转载此文件\n"), _T("DISLIKE-协议"), MB_ICONWARNING);
		while (true) {
			// 创建一个系统快照，包含所有进程
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapshot == INVALID_HANDLE_VALUE) {
				std::cerr << "Failed to create snapshot." << std::endl;

			}

			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(PROCESSENTRY32);

			// 获取快照中的第一个进程
			if (Process32First(hSnapshot, &pe32)) {
				do {

					// 检查进程名是否是我们想要关闭的
					if (_wcsicmp(pe32.szExeFile, L"DISLIKE_V1.0.2.5.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"REDAgent.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"Yistart.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"StudentMain.exe") == 0) {

						// 打开进程
						HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
						if (hProcess != NULL) {
							// 终止进程
							TerminateProcess(hProcess, 0);
							CloseHandle(hProcess);
						}
					}
				} while (Process32Next(hSnapshot, &pe32)); // 遍历快照中的所有进程
			}

			CloseHandle(hSnapshot);

			// 每隔0.0001秒刷新一次
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
	}if (nID == IDC_RADIO3)
	{
		//效果好
		MessageBox(_T("1.禁止使用此软件扰乱课堂秩序，后果与作者无关;\n2.此软件版权归C10所有\n3.此软件是为了让使用者学会用C/C++程序删除、打开、关闭文件\n4.未经作者许可，禁止复制和转载此文件\n"), _T("DISLIKE-协议"), MB_ICONWARNING);
		while (true) {
			// 创建一个系统快照，包含所有进程
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapshot == INVALID_HANDLE_VALUE) {
				std::cerr << "Failed to create snapshot." << std::endl;

			}

			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(PROCESSENTRY32);

			// 获取快照中的第一个进程
			if (Process32First(hSnapshot, &pe32)) {
				do {

					// 检查进程名是否是我们想要关闭的
					if (_wcsicmp(pe32.szExeFile, L"DISLIKE_V1.0.2.5.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"REDAgent.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"Yistart.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"StudentMain.exe") == 0) {

						// 打开进程
						HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
						if (hProcess != NULL) {
							// 终止进程
							TerminateProcess(hProcess, 0);
							CloseHandle(hProcess);
						}
					}
				} while (Process32Next(hSnapshot, &pe32)); // 遍历快照中的所有进程
			}

			CloseHandle(hSnapshot);

			// 每隔0.0001秒刷新一次
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
	}if (nID == IDC_RADIO4)
	{
		//又快又好
		MessageBox(_T("1.禁止使用此软件扰乱课堂秩序，后果与作者无关;\n2.此软件版权归C10所有\n3.此软件是为了让使用者学会用C/C++程序删除、打开、关闭文件\n4.未经作者许可，禁止复制和转载此文件\n"), _T("DISLIKE-协议"), MB_ICONWARNING);
		while (true) {
			// 创建一个系统快照，包含所有进程
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapshot == INVALID_HANDLE_VALUE) {
				std::cerr << "Failed to create snapshot." << std::endl;

			}

			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(PROCESSENTRY32);

			// 获取快照中的第一个进程
			if (Process32First(hSnapshot, &pe32)) {
				do {

					// 检查进程名是否是我们想要关闭的
					if (_wcsicmp(pe32.szExeFile, L"DISLIKE_V1.0.2.5.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"REDAgent.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"Yistart.exe") == 0 ||
						_wcsicmp(pe32.szExeFile, L"StudentMain.exe") == 0) {

						// 打开进程
						HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
						if (hProcess != NULL) {
							// 终止进程
							TerminateProcess(hProcess, 0);
							CloseHandle(hProcess);
						}
					}
				} while (Process32Next(hSnapshot, &pe32)); // 遍历快照中的所有进程
			}

			CloseHandle(hSnapshot);

			// 每隔0.0001秒刷新一次
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
	}
}
