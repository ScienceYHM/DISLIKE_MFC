// Cemeg.cpp: 实现文件
//

#include "pch.h"
#include "DISLIKE.h"
#include "afxdialogex.h"
#include "Cemeg.h"


// Cemeg 对话框

IMPLEMENT_DYNAMIC(Cemeg, CDialog)

Cemeg::Cemeg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	
	, m_mz(0)
	, m_mm(0)
{

}


Cemeg::~Cemeg()
{
}

void Cemeg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_mz);
	DDX_Text(pDX, IDC_EDIT2, m_mm);
}


BEGIN_MESSAGE_MAP(Cemeg, CDialog)
	ON_BN_CLICKED(IDOK, &Cemeg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cemeg::OnBnClickedCancel)
	
END_MESSAGE_MAP()


// Cemeg 消息处理程序


void Cemeg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	UpdateData();
	if (m_mz == 1) {
		if (m_mm == 142857) {
			MessageBoxA(NULL, "即将进入程序", "DISLIKE-提示", MB_OK | MB_ICONINFORMATION);
		}
		else {
			MessageBoxA(NULL, "密码错误，即将退出", "DISLIKE-错误", MB_OK | MB_ICONERROR);
			exit(0);
		}
	}
	else {
		MessageBoxA(NULL, "用户名错误,即将退出", "DISLIKE-错误", MB_OK | MB_ICONERROR);
		exit(0);
	}
}


void Cemeg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
	exit(0);
}


