// 程序信息.cpp: 实现文件
//

#include "pch.h"
#include "DISLIKE.h"
#include "afxdialogex.h"
#include "程序信息.h"


// 程序信息 对话框

IMPLEMENT_DYNAMIC(程序信息, CDialogEx)

程序信息::程序信息(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

程序信息::~程序信息()
{
}

void 程序信息::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(程序信息, CDialogEx)
END_MESSAGE_MAP()


// 程序信息 消息处理程序
