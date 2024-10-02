// 歌单.cpp: 实现文件
//

#include "pch.h"
#include "DISLIKE.h"
#include "afxdialogex.h"
#include "歌单.h"
#include <cassert>


// 歌单 对话框

IMPLEMENT_DYNAMIC(歌单, CDialogEx)

歌单::歌单(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

歌单::~歌单()
{
}

void 歌单::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(歌单, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &歌单::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON2, &歌单::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &歌单::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON1, &歌单::OnBnClickedButton1)
END_MESSAGE_MAP()


// 歌单 消息处理程序


void 歌单::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
    const TCHAR szOperation[] = _T("open");
    const TCHAR szAddress[] = _T("https://music.163.com/outchain/player?type=1&id=405493&auto=1&height=430");
    int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
    {
        HINSTANCE hRslt = ShellExecute(NULL, szOperation,
            szAddress, NULL, NULL, SW_SHOWNORMAL);
        assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

    }

}


void 歌单::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    const TCHAR szOperation[] = _T("open");
    const TCHAR szAddress[] = _T("https://music.163.com/outchain/player?type=1&id=2700855&auto=1&height=430");
    int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
    {
        HINSTANCE hRslt = ShellExecute(NULL, szOperation,
            szAddress, NULL, NULL, SW_SHOWNORMAL);
        assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

    }
}


void 歌单::OnBnClickedButton3()
{
    // TODO: 在此添加控件通知处理程序代码
    const TCHAR szOperation[] = _T("open");
    const TCHAR szAddress[] = _T("https://music.163.com/outchain/player?type=1&id=85021938&auto=1&height=430");
    int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
    {
        HINSTANCE hRslt = ShellExecute(NULL, szOperation,
            szAddress, NULL, NULL, SW_SHOWNORMAL);
        assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

    }
}


void 歌单::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    const TCHAR szOperation[] = _T("open");
    const TCHAR szAddress[] = _T("https://music.163.com/outchain/player?type=1&id=495259&auto=1&height=430");
    int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow);
    {
        HINSTANCE hRslt = ShellExecute(NULL, szOperation,
            szAddress, NULL, NULL, SW_SHOWNORMAL);
        assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

    }
}
